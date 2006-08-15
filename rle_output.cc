// -*- C++ -*-

// RLE frame buffer output class - implementation
// Bart 9/93

extern "C" {
#include <string.h>
#include <stdio.h>
#ifndef __GNUC__
extern void fputc( char, FILE * );
extern void fclose( FILE * );
extern void fprintf( FILE *, const char *, ... );
#endif
}

#ifndef NOOUTLINE

#include "render.h"

rle_output::rle_output( char *n, int w, int h ) :
  output( n, ".rle", w, h )
{
  buffer = new point[w * h];
  curx = 0;
  cury = 0;
}

#endif

#ifdef INLINE

inline void rle_output::flushrow( int y ) {
  assert( y < ysize && cury == y );
  cury++;
  curx = 0;
#if DEBUGLEVEL == 1
  if( !(y % 10) )
#endif
#if DEBUGLEVEL >= 1
    printf( "output row: %d\n", y );
#endif
}


inline void rle_output::putpixel( int x, int y, point &c ) {
  assert( x < xsize && curx == x && cury == y );
  curx++;
#if DEBUGLEVEL > 1
  printf( "output: %f %f %f\n", c[0], c[1], c[2] );
#endif
  buffer[ y * ysize + x ] = c;
}

inline void rle_output::putword( int w ) {
  putc( w & 0xff, outfile );
  putc( (w >> 16) & 0xff, outfile );
}

inline void rle_output::putbyte( int w ) {
  putc( w & 0xff, outfile );
}

inline void rle_output::putopcode( enum opcodes opcode, int datum ) {
  putc( w & 0xff, outfile );
}

inline void rle_output::flush(void) {
  // header
  putword( 0x4c52 );  // magic
  putword( 0 );  // x
  putword( 0 );  // y
  putword( w );
  putword( h );
  putbyte( 0x2 );  // no background
  putbyte( 3 );  // 3 channels
  putbyte( 8 );  // 8 bits per channel
  putbyte( 0 );  // no colormap channels
  putbyte( 0 );  // no colormap
  // colormap
  // picture
  unsigned char r = gamma(R(c));
  unsigned char g = gamma(G(c));
  unsigned char b = gamma(B(c));

  fputc( r, outfile );
  fputc( g, outfile );
  fputc( b, outfile );
}

#endif
