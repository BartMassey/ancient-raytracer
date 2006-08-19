/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple light class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

#endif

#ifdef INLINE

inline light::light( point l, point i ) : loc( l ), intensity( i ) {
  // do nothing
}

inline point &light::at( void ) {
  return loc;
}

inline point &light::i( void ) {
  return intensity;
}

#endif
