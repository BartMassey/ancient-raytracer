// -*- C++ -*-

// a simple checkerboard texture class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

board_texture::board_texture( texture &r, texture &b )
  : texture(point(0,0,0), point(0,0,0), point(0,0,0), 0)
{
  red_texture = r.dup();
  black_texture = b.dup();
}

board_texture::board_texture( board_texture &t )
  : texture(point(0,0,0), point(0,0,0), point(0,0,0), 0)
{
  red_texture = t.red_texture->dup();
  black_texture = t.black_texture->dup();
}

board_texture::~board_texture( void ) {
  if( red_texture )
    delete red_texture;
  if( black_texture )
    delete black_texture;
}

texture *board_texture::dup( void ) {
  return new board_texture( *this );
}

texture *board_texture::tune_texture( model &m ) {
  assert( red_texture );
  assert( black_texture );

  texture *nr = red_texture->tune_texture( m );
  texture *nb = black_texture->tune_texture( m );
  board_texture result( *nr, *nb );
  delete nr;
  delete nb;
  return new board_texture( result );
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
  // out with the old
  delete red_texture;
  delete black_texture;
  // in with the new
  red_texture = t.red_texture->dup();
  black_texture = t.black_texture->dup();
}

#endif
