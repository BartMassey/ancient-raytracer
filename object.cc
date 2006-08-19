/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple ray-traceable object class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

object::object( texture *t ) {
  ot = t;
  nextobj = 0;
}

void object::tune_texture( model &m ) {
  texture *ft = ot->tune_texture( m );
  ot = ft;
}

#endif

#ifdef INLINE

inline object *object::next( void ) {
  return nextobj;
}

inline void object::append( object &o ) {
  assert( !nextobj );
  nextobj = &o;
}

inline texture &object::get_texture( void ) {
  return *ot;
}

#endif

