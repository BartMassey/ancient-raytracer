// -*- C++ -*-

// a simple model class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

#endif

#ifdef INLINE

inline model::model( point &p, light &l, object &o, point &p2 ) :
 eye( p ), thelight( l ), scene( o ), bg( p2 ) {
  object *op;

  maxdepth = 10;
  for( op = &scene; op; op = op->next() )
    op->tune_texture( *this );
}

#endif
