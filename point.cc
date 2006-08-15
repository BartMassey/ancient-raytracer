// -*- C++ -*-

// a simple point class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

#endif

#ifdef INLINE


inline point::point( point &p ) {
  int i;

  nc = p.nc;
  for( i = 0; i < nc; i++ )
    c[i] = p.c[i];
}


inline point::point( int n ) {
  assert( n > 0 && n <= ncmax );
  nc = n;
}


inline point::point( float p0, float p1 ) {
  nc = 2;
  c[0] = p0;
  c[1] = p1;
}


inline point::point( float p0, float p1, float p2 ) {
  nc = 3;
  c[0] = p0;
  c[1] = p1;
  c[2] = p2;
}


inline point::point( float p0, float p1, float p2, float p3 ) {
  nc = 4;
  c[0] = p0;
  c[1] = p1;
  c[2] = p2;
  c[3] = p3;
}


inline float *point::ref( int i ) {
  assert( i < nc );
  return &c[i];
}


inline float point::at( int i ) {
  return *ref(i);
}


inline point & point::set( int i, float f ) {
  *ref(i) = f;
  return (*this);
}

inline float & point::operator[] ( int i ) {
  return *ref(i);
}

inline float point::operator* ( point &p ) {
  int i;
  float r;
  
  assert( nc == p.nc );
  r = c[0] * p.c[0];
  for( i = 1; i < nc ; i++ )
    r += c[i] * p.c[i];
  return r;
}

inline void point::negate ( point &p ) {
  int i;

  for( i = 0; i < nc ; i++ )
    p.c[i] = -p.c[i];
}

inline point point::operator- ( void ) {
  point r(*this);
  negate(r);
  return r;
}

inline point & point::operator+= ( point &p ) {
  int i;
  
  assert( nc == p.nc );
  for( i = 0; i < nc ; i++ )
    c[i] += p.c[i];
  return (*this);
}

inline point & point::operator-= ( point &p ) {
  point minusp(p);
  (*this) += minusp;
  return (*this);
}

inline point point::operator+ ( point &p ) {
  point r(*this);

  r += p;
  return r;
}

inline point point::operator- ( point &p ) {
  point r(*this);

  r -= p;
  return r;
}

inline point & point::operator*= ( float s ) {
  int i;

  for( i = 0; i < nc; i++ )
    c[i] *= s;
  return *this;
}

inline point point::operator* ( float s ) {
  point r(*this);
  
  return (r *= s);
}

inline point &point::transform ( xform &m ) {
  int i, n;
  float t[4];

  assert( nc < 5 );
  for( n = 0; n < nc; n++ )
    t[n] = c[n];
  while( n < 3 )
    t[n++] = 0;
  if( n < 4 )
    t[n++] = 1;
  for( i = 0; i < nc; i++ )
    c[i] = m.rowmult( i, t );
  return (*this);
}

// cross-product
inline point point::operator^( point &p ) {
  point r(3);
  
  assert( nc == 3 && p.nc == 3 );
  r.c[0] = c[1] * p.c[2] - c[2] * p.c[1];
  r.c[1] = c[2] * p.c[0] - c[0] * p.c[2];
  r.c[2] = c[0] * p.c[1] - c[1] * p.c[0];
  return r;
}

inline point point::vproduct( point &p ) {
  int i;
  point r(nc);

  assert( nc == p.nc );
  for( i = 0; i < nc; i++ )
    r.c[i] = c[i] * p.c[i];
  return r;
}

inline float point::mag2( void ) {
  int i;
  float r;

  r = c[0] * c[0];
  for( i = 1; i < nc ; i++ )
    r += c[i] * c[i];
  return r;
}

inline float point::mag( void ) {
  return sqrt( mag2() );
}

inline point & point::unitize( void ) {
  float m = mag();
  
  assert( m > TINY );
  return (*this) *= (1.0 / m);
}

inline point point::unit( void ) {
  point r(*this);

  r.unitize();
  return r;
}

inline point & point::homogenize( void ) {
  assert( nc == 4 );
  return (*this) *= (1.0 / c[3]);
}

inline point point::homogeneous( void ) {
  point r(*this);

  r.homogenize();
  return r;
}

inline point point::dilation( float n ) {
  int i;
  point r(nc + 1);

  for( i = 0; i < nc; i++ )
    r.c[i] = c[i];
  r.c[nc] = n;
  return r;
}

inline point &point::dilate( float n ) {
  assert( nc < ncmax );
  c[nc] = n;
  nc++;
  return (*this);
}

inline point point::contraction( void ) {
  int i;
  point r( nc - 1 );

  for( i = 0; i < nc - 1; i++ )
    r.c[i] = c[i];
  return r;
}

inline point &point::contract( void ) {
  nc--;
  return (*this);
}

inline int point::d( void ) {
  return nc;
}

// utility functions

inline float X( point &p ) {
  assert( p.d() > 0 );
  return p[0];
}

inline float Y( point &p ) {
  assert( p.d() > 1 );
  return p[1];
}

inline float Z( point &p ) {
  assert( p.d() > 2 );
  return p[2];
}

inline float W( point &p ) {
  assert( p.d() > 3 );
  return p[3];
}

inline float R( point &p ) {
  assert( p.d() >= 3 );
  return p[0];
}

inline float G( point &p ) {
  assert( p.d() >= 3 );
  return p[1];
}

inline float B( point &p ) {
  assert( p.d() >= 3 );
  return p[2];
}

#endif
