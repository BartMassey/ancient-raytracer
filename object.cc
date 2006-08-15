// -*- C++ -*-

// a simple ray-traceable object class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

object::object( texture &t ) {
  ot = t.dup();
  nextobj = 0;
}

void object::tune_texture( model &m ) {
  // "class" keyword is necessary here
  // because texture() is a method of object
  class texture *ft = ot->tune_texture( m );
  delete ot;
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

