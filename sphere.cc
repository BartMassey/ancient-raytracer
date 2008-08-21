
// -*- C++ -*-

// a simple class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

void sphere::transform( xform t ) {
  to *= t;
  toi = to.inverse();
}

int sphere::intersect( ray r, intersection &s ) {
  r.transform( toi );  // now we have the ray in object coords...
  
  float a = r.d().mag2();
  float b = r.o() * r.d();
  float c = r.o().mag2() - 1.0;
  float d = b*b - a*c;
  float t;

  if( d < TINY ) {
    // ray misses sphere
    return 0;
  }
  if( a < 0 )
    t = (-b + sqrt( d )) / a;
  else
    t = (-b - sqrt( d )) / a;
  if( t < TINY ) {
    // ray is travelling away from sphere, so no hit
    return 0;
  }
  point i( r.o() + r.d() * t );  // the intersection point in object coords
  i.transform(toi);
	
  // there are many possible mappings -- here's a lame one
  s.t = t;
  s.at = new point( X(i), Y(i) );
  s.normal = new point( (i - tr).unit() );
  
  return 1;
}

#endif

#ifdef INLINE

inline sphere::sphere( texture *t ) :
 object( t ), to( XFORM_IDENTITY ), toi( XFORM_IDENTITY ), tr( 0.0, 0.0, 0.0 ) {
  // do nothing
}


inline void sphere::complete( void ) {
  point o( 0.0, 0.0, 0.0 );

  o.transform( toi );
  tr = o;
}

#endif
