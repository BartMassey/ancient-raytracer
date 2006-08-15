// -*- C++ -*-

// a simple texture class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

texture::texture( point &nka, point &nkd, point &nks, float nns ) :
 ka( nka ), kd( nkd ), ks( nks ), ns( nns ) {
  // do nothing
}

texture::texture( texture &t ) :
 ka( t.ka ), kd( t.kd ), ks( t.ks ), ns( t.ns ) {
  // do nothing
}

texture::~texture( void ) {
  // do nothing
}

texture *texture::dup( void ) {
  return new texture(*this);
}

texture *texture::tune_texture( model &m ) {
  return new fast_texture( m, *this );
}

point texture::value( point &at, point &gc, point &normal,
 model &m, int depth ) {

  // this now should never be called
  assert( 0 );
  return ka;
}

#endif
