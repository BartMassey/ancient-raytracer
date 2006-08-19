/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple checkerboard texture class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

board_texture::board_texture( texture *r, texture *b )
  : texture(point(0,0,0), point(0,0,0), point(0,0,0), 0.0f)
{
  red_texture = r;
  black_texture = b;
}

board_texture::board_texture( const board_texture &t )
  : texture(point(0,0,0), point(0,0,0), point(0,0,0), 0)
{
  red_texture = new texture(*t.red_texture);
  black_texture = new texture(*t.black_texture);
}

board_texture::~board_texture( void ) {
}

texture *board_texture::tune_texture( model &m ) {
  assert( red_texture );
  assert( black_texture );

  texture *nr = red_texture->tune_texture( m );
  texture *nb = black_texture->tune_texture( m );
  return new board_texture( nr, nb );
}

#endif

#ifdef INLINE

inline point board_texture::value( point &at, point &gc, point &normal,
 model &m, int depth ) {
  int x = (int) floor( X( at ) );
  int y = (int) floor( Y( at ) );

  if( (x & 1) ^ (y & 1) )
    return red_texture->value( at, gc, normal, m, depth );
  else
    return black_texture->value( at, gc, normal, m, depth );
}

inline void board_texture::operator=( board_texture &t )
{
  // in with the new
  red_texture = new texture(*t.red_texture);
  black_texture = new texture(*t.black_texture);
}

#endif
