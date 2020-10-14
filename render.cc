
// -*- C++ -*-

// ray-tracer
// Bart 2/91

#include "render.h"
#include "generate.h"

#define HS (D * tan( A ))
#define HE (D * sin( A ))

point trace( ray r, model &m, int depth ) {
  object *p, *current = 0;
  intersection s, sb;

  if( depth > m.maxdepth ) {
    point value( m.bg );
    
    value.dilate(0);
    return value;
  }
  // find an object struct by the ray
  for( p = &m.scene; p; p = p->next() )
    if( p->intersect( r, s ) ) {
	sb = s;
	current = p;
	break;
    }
  if (!current) {
    point value( m.bg );
    
    value.dilate(0);
    return value;
  }
  // if there are other intersections,
  // choose the nearest
  for( p = p->next(); p; p = p->next() )
    if( p->intersect( r, s ) && s.t < sb.t ) {
      delete sb.normal;
      delete sb.at;
      sb = s;
      current = p;
    }
  // determine the pixel value
  point nr(r.at( sb.t ));
  point value( (current->get_texture()).value(
   *sb.at, nr, *sb.normal, m, depth + 1 ) );

  delete sb.normal;
  delete sb.at;
  value.dilate(1);
  return value;
}

#ifdef ANTIALIAS
static inline double dojoggle( double (*f)( double ), int i, int n, double t ) {
  double a = (double) i / n + t;
  while( a > 0.5 )
    a -= 1.0;
  return 0.5 * f( PI * a );
}
#endif

static void render( object *scene, char *imgtype, int w, int h ) {
  light thelight( point( 2 * HE, -HE, 0 ), point( 1.25, 1.25, 1.15 ) );
  point eye( HE, 0, 0 );
  xform view_xform( XFORM_ROTATE_Y, -A );
  int i, j;

  output *out = 0;
  point dkgray( 0.2, 0.2, 0.2 );
  model m( eye, thelight, *scene, dkgray );

  // create the appropriate output object
  if( !strcmp( imgtype, "-oldppm" ) )
    out = new oldppm_output( (char *)"render.out", w, h );
  else if( !strcmp( imgtype, "-ppm" ) )
    out = new ppm_output( (char *)"render.out", w, h );
  else
    assert( 0 );
  // sweep over the whole viewplane
  for( j = h - 1; j >= 0; j-- ) {
    for( i = 0; i < w; i++ ) {
#ifdef ANTIALIAS
      int aa = ANTIALIAS;
      point ave( 0.0, 0.0, 0.0, 0.0 );
      double joggle = frandom();
      for( int k = 0; k < aa; k++ ) {
        point rt(
         2 * HS * (j + dojoggle( cos, k, aa, joggle )) / h - HS,
         2 * HS * (i + dojoggle( sin, k, aa, joggle )) / w - HS,
         D );
	rt.transform( view_xform );
        ray r( eye, rt );

	ave += trace( r, m, 0 ) * (1.0 / aa);
      }
#else
      point rt(
       2 * HS * j / h - HS,
       2 * HS * i / w - HS,
       D );
      rt.transform( view_xform );
      ray r( eye, rt );
      point ave( trace( r, m, 0 ) );
#endif
      out->putpixel( i, h - j - 1, ave );
    }
    out->flushrow( h - j - 1 );
  }
  out->flush();
  delete out;
}

int main( int argc, char **argv ) {
  char *imgtype = (char *)"-ppm";
  int x, y;

  object *scene = generate();
  if( argc == 4 && argv[1][1] == '-' ) {
    imgtype = argv[1];
    argv++;
    argc--;
  }
  if( argc == 3 && (x = atoi( argv[1] )) && (y = atoi( argv[2] )) ) {
    render( scene, imgtype, x, y );
    // all done
    return 0;
  }
  fprintf( stderr, "usage: render [-oldppm|-ppm] x y\n" );
  return 1;
}
