// -*- C++ -*-

// a simple polygon class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

/*
 * note that this assumes that the x and y coordinates are the
 * only significant ones of both poly and point.
 */
int poly::contains( point &v )
{
  int pn = np;
  float xx = X(v);
  float yy = Y(v);
  int nr = 0;
  int i, j;
  float x0,x1,y0,y1,xl,xr,yi,yj;
  point *r[4];

  for( i = 0; i < pn; i++ ) {
    j = i + 1;
    if( j >= pn )
      j -= pn;
    yi = Y(get(i));
    yj = Y(get(j));
    if( yi < yy && yj >= yy ) {
      r[ nr++ ] = &get(i);
      r[ nr++ ] = &get(j);
    } else if( yi >= yy && yj < yy ) {
      r[ nr++ ] = &get(j);
      r[ nr++ ] = &get(i);
    }
  }
  /* if we haven't found a trapezoid, continue */
  if( nr < 4 )
    return 0;
  /* intercept first line */
  x0 = X(*r[0]);
  y0 = Y(*r[0]);
  x1 = X(*r[1]);
  y1 = Y(*r[1]);
  if( y1 - y0 < TINY ) {
    if( xx < x0 && xx < x1 )
      xl = MIN( x0, x1 );
    else if( xx > x0 && xx > x1 )
      xl = MAX( x0, x1 );
    else
      return 0;
  }
  xl = x0 + (x1 - x0) * (yy - y0) / (y1 - y0);
  /* intercept second line */
  x0 = X(*r[2]);
  y0 = Y(*r[2]);
  x1 = X(*r[3]);
  y1 = Y(*r[3]);
  if( y1 - y0 < TINY ) {
    if( xx < x0 && xx < x1 )
      xl = MIN( x0, x1 );
    else if( xx > x0 && xx > x1 )
      xl = MAX( x0, x1 );
    else
      return 0;
  }
  xr = x0 + (x1 - x0) * (yy - y0) / (y1 - y0);
  /* containment test */
  if( xl < xr && xl < xx && xx < xr )
    return 1;
  if( xl > xr && xl > xx && xx > xr )
    return 1;
  return 0;
}

int poly::intersect( ray r, intersection &s ) {
  float b, t;
  
  r.transform( toi );
  
  // now we have the ray in object coords...
  point rd( r.d() );
  point ro( r.o() );
  
  b = Z( rd );
  if( fabs( b ) < TINY ) {
    // ray is parallel to plane, so no hit
    return 0;
  }
  t = -Z( ro ) / b;
  if( t < TINY ) {
    // ray is behind plane, so no hit
    return 0;
  }
  point i( ro + (rd * t) );
#if DEBUGLEVEL > 0
  assert( fabs( Z(i) ) < TINY );
#endif  
  if( !contains( i ) ) {
    // ray is outside poly
    return 0;
  }
#if DEBUGLEVEL > 0
  assert( cnormal );
#endif
  s.normal = new point( *cnormal );
  s.at = new point( X(i), Y(i) );
  s.t = t;

  return 1;
}

poly::poly( int n, texture &t )
 : object( t ), to( XFORM_IDENTITY ), toi( XFORM_IDENTITY ) {
  int i;
  typedef point *pp;

  np = n;
  dp = 0;
  p = new pp[ np ];
  for( i = 0; i < np; i++ )
    p[i] = 0;
  cnormal = 0;
}

poly::poly( const poly &q ) : object( *q.ot ), to( q.to ), toi( q.toi ) {
  int i;
  typedef point *pp;

  np = q.np;
  dp = q.dp;
  p = new pp[ np ];
  for( i = 0; i < np; i++ )
    if( q.p[i] )
      p[i] = new point( *q.p[i] );
    else
      p[i] = 0;
  cnormal = 0;
  if( q.cnormal )
    cnormal = new point( *q.cnormal );
}

void poly::operator= ( const poly &q ) {
  int i;
  typedef point *pp;

  // out with the old
  for( i = 0; i < np; i++ )
    if( p[i] )
      delete p[i];
  delete p;
  if( cnormal )
    delete cnormal;
  // in with the new
  np = q.np;
  dp = q.dp;
  p = new pp[ np ];
  for( i = 0; i < np; i++ )
    if( q.p[i] )
      p[i] = new point( *q.p[i] );
    else
      p[i] = 0;
  cnormal = 0;
  if( q.cnormal )
    cnormal = new point( *q.cnormal );
}

void poly::complete( void ) {
  int i;

  for( i = 0; i < np; i++ )
    assert( p[i] );
  cnormal = inormal();
#if DEBUGLEVEL > 2
  printf( "new poly: %d\n", np );
  for( i = 0; i < np; i++ ) {
    point q( *p[i] );

    q.dilate( 0 );
    q.transform( to );
    printf( "\t%f %f %f\n", q[0], q[1], q[2] );
  }
#endif
}

#endif

#ifdef INLINE

inline point ** poly::ref( int i ) {
  assert( i < np );
  return &p[i];
}

inline point & poly::get( int i ) {
  point **p = ref( i );

  assert( *p );
  return **p;
}

inline poly::~poly() {
  int i;

  if( np ) {
    for( i = 0; i < np; i++ )
      if( p[i] )
        delete p[i];
    delete p;
  }
  if( cnormal )
    delete( cnormal );
}

inline poly & poly::set( int i, point & f ) {
  point **p = ref(i);

  assert( !(*p) );
  if( dp )
    assert( dp == f.d() );
  else
    dp = f.d();
  *p = new point( f );
  return (*this);
}

inline point & poly::operator[] ( int i ) {
  return get(i);
}

inline int poly::n( void ) {
  return np;
}

inline int poly::d( void ) {
  return dp;
}

inline void poly::transform( xform t ) {
  to *= t;
  toi = to.inverse();
}

inline void poly::contract( void ) {
  int i;

  for( i = 0; i < np; i++ )
    if( p[i] )
      p[i]->contract();
  dp--;
}

inline void poly::dilate( float n ) {
  int i;

  for( i = 0; i < np; i++ )
    if( p[i] )
      p[i]->dilate( n );
  dp++;
}

inline point *poly::inormal( void ) {
  point *r;
  point o( 0.0, 0.0, 0.0 );
  
  r = new point(0.0,0.0,1.0);
  r->transform( toi );
  o.transform( toi );
  *r -= o;
  r->unitize();
  return r;
}

#endif
