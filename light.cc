
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
