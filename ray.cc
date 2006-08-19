/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple ray class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

void ray::transform( xform &t ) {
  point dorg(0.0,0.0,0.0);

  ro.transform( t );
  dorg.transform( t );
  rd.transform( t );
  rd -= dorg;
}

#endif

#ifdef INLINE

inline ray::ray( point & po, point & pd ) : ro(po), rd(pd) {
  rd.unitize();
}

inline ray::ray( const ray & r ) : ro(r.ro), rd(r.rd) {
  // OK
}

inline point ray::at( float t ) {
  return (rd * t) + ro;
}

inline point ray::o( void ) {
  return ro;
}

inline point ray::d( void ) {
  return rd;
}

#endif
