// -*- C++ -*-

// a simple transformation matrix class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

xform::xform( enum xform_types t ) {
  int i, j;

  assert( t == XFORM_IDENTITY );
  m = &this->mv;
  mi = &this->miv;
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = (i == j);
      (*mi)[i][j] = (i == j);
    }
}

xform::xform( enum xform_types t, float a ) {
  int i, j;
  float ca = cos(a);
  float sa = sin(a);

#if DEBUGLEVEL > 0
  // check for small floating-point errors in trig functions
  assert( ca <= 1 );
  assert( ca >= -1 );
  assert( sa <= 1 );
  assert( ca >= -1 );
#endif
  // now generate the xform
  m = &this->mv;
  mi = &this->miv;
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = 0;
      (*mi)[i][j] = 0;
    }
  switch( t ) {
  case XFORM_ROTATE_X:
    (*m)[0][0] = 1;
    (*m)[3][3] = 1;
    (*m)[1][1] = ca;
    (*m)[2][2] = ca;
    (*m)[1][2] = -sa;
    (*m)[2][1] = sa;
    (*mi)[0][0] = 1;
    (*mi)[3][3] = 1;
    (*mi)[1][1] = ca;
    (*mi)[2][2] = ca;
    (*mi)[1][2] = sa;
    (*mi)[2][1] = -sa;
    break;
  case XFORM_ROTATE_Y:
    (*m)[1][1] = 1;
    (*m)[3][3] = 1;
    (*m)[0][0] = ca;
    (*m)[2][2] = ca;
    (*m)[2][0] = -sa;
    (*m)[0][2] = sa;
    (*mi)[1][1] = 1;
    (*mi)[3][3] = 1;
    (*mi)[0][0] = ca;
    (*mi)[2][2] = ca;
    (*mi)[2][0] = sa;
    (*mi)[0][2] = -sa;
    break;
  case XFORM_ROTATE_Z:
    (*m)[2][2] = 1;
    (*m)[3][3] = 1;
    (*m)[0][0] = ca;
    (*m)[1][1] = ca;
    (*m)[0][1] = -sa;
    (*m)[1][0] = sa;
    (*mi)[2][2] = 1;
    (*mi)[3][3] = 1;
    (*mi)[0][0] = ca;
    (*mi)[1][1] = ca;
    (*mi)[0][1] = sa;
    (*mi)[1][0] = -sa;
    break;
  default:
    assert( 0 );
  }
}

xform::xform( enum xform_types t, point r ) {
  int i, j;

  assert( r.d() > 2 );
  m = &this->mv;
  mi = &this->miv;
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = 0;
      (*mi)[i][j] = 0;
    }
  switch( t ) {
  case XFORM_TRANSLATE:
    (*m)[0][0] = 1;
    (*m)[1][1] = 1;
    (*m)[2][2] = 1;
    (*m)[3][3] = 1;
    (*m)[0][3] = r[0];
    (*m)[1][3] = r[1];
    (*m)[2][3] = r[2];
    (*mi)[0][0] = 1;
    (*mi)[1][1] = 1;
    (*mi)[2][2] = 1;
    (*mi)[3][3] = 1;
    (*mi)[0][3] = -r[0];
    (*mi)[1][3] = -r[1];
    (*mi)[2][3] = -r[2];
    break;
  case XFORM_SCALE:
    assert( r[0] > TINY && r[1] > TINY && r[2] > TINY );
    (*m)[0][0] = r[0];
    (*m)[1][1] = r[1];
    (*m)[2][2] = r[2];
    (*m)[3][3] = 1;
    (*mi)[0][0] = 1.0/r[0];
    (*mi)[1][1] = 1.0/r[1];
    (*mi)[2][2] = 1.0/r[2];
    (*mi)[3][3] = 1;
    break;
  default:
    assert( 0 );
  }
}

xform::xform( const xform &t ) {
  int i, j;

  m = &this->mv;
  mi = &this->miv;
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = (*t.m)[i][j];
      (*mi)[i][j] = (*t.mi)[i][j];
    }
}

#endif

#ifdef INLINE

inline xform::~xform( void ) {
}

inline void xform::operator=( const xform &t ) {
  int i, j;

  m = &this->mv;
  mi = &this->miv;
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = (*t.m)[i][j];
      (*mi)[i][j] = (*t.mi)[i][j];
    }
}

inline point xform::row( int i ) {
  int k;
  point p(4);

  for( k = 0; k < 4; k++ )
    p.set( k, (*m)[i][k] );
  return p;
}

inline float xform::rowmult( int i, float t[4] ) {
  // inline expand for speed
  return
      (*m)[i][0] * t[0]
    + (*m)[i][1] * t[1]
    + (*m)[i][2] * t[2]
    + (*m)[i][3] * t[3];
}

inline point xform::col( int j ) {
  int i;
  point p(4);

  for( i = 0; i < 4; i++ )
    p.set( j, (*m)[i][j] );
  return p;
}

inline void xform::operator*= ( xform n ) {
  int i, j, k;
  xform l(*this);

  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*m)[i][j] = (*n.m)[i][0] * (*l.m)[0][j];
      for( k = 1; k < 4; k++ )
        (*m)[i][j] += (*n.m)[i][k] * (*l.m)[k][j];
    }
  for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
      (*mi)[i][j] = (*l.mi)[i][0] * (*n.mi)[0][j];
      for( k = 1; k < 4; k++ )
        (*mi)[i][j] += (*l.mi)[i][k] * (*n.mi)[k][j];
    }
}

inline xform xform::operator* ( xform n ) {
  xform r(*this);

  r *= n;
  return r;
}

inline void xform::invert( void ) {
  gmatrix *tmp;

  tmp = m;
  m = mi;
  mi = tmp;
}

inline xform xform::inverse( void ) {
  xform t(*this);
  
  t.invert();
  return t;
}

inline float xform::at( int i, int j ) {
  return (*m)[i][j];
}
 
#endif
