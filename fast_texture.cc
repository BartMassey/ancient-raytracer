
// -*- C++ -*-

// a simple fast texture class -- implementation
// Bart 2/91

#ifndef NOOUTLINE

#include "render.h"

fast_texture::fast_texture( model &m, texture &t )
  : texture( t ),
    pl( m.thelight.at() ),
    pli( m.thelight.i() ),
    pe( m.eye )
{
  // do nothing
}

fast_texture::fast_texture( const fast_texture &t )
  : texture( t ),
    pl( t.pl ),
    pli( t.pli ),
    pe( t.pe )
{
  // do nothing
}

texture *fast_texture::tune_texture( model &m ) {
  return new fast_texture( m, *this );
}

point fast_texture::value( point &at, point &gc, point &normal,
 model &m, int depth ) {
  point result( ka );  // ambient term
  point lv( (pl - gc).unit() );  // unit vector from target toward light
  
  // diffuse term
  float fd = lv * normal;
  if( fd > TINY )
    result += kd.vproduct( pli ) * fd;
    
  // specular terms
  point pt = (gc - pe).unit();  // unit vector from eye toward target
  point ps = pt - normal * ( ( pt * normal ) * 2.0 );  // specular direction

  // specular diffusion term
  float fs = ps * lv;
  if( fs > 0 ) {
    fs = exp( ns * log( fs ) );
    if( fs > TINY )
        result += ks.vproduct( pli ) * fs;
  }
  
  // ray tracing term
  return result + ks.vproduct( trace( ray( gc, ps ), m, depth ).contraction() );
}

#endif
