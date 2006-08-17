// -*- C++ -*-

// PPM (rawbits) frame buffer output class - implementation
// Bart 2/91

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

ppm_output::ppm_output( char *n, int w, int h ) :
  output( n, ".ppm", w, h )
{
  fprintf( outfile, "P6\n%d\n%d\n%d\n", w, h, 255 );
  curx = 0;
  cury = 0;
}

// used by oldppm_output::oldppm_output
ppm_output::ppm_output( char *n, char *ext, int w, int h ) :
  output( n, ext, w, h )
{
  curx = 0;
  cury = 0;
}

#endif

#ifdef INLINE

inline void ppm_output::flushrow( int y ) {
  assert( y < ysize && cury == y );
  cury++;
  curx = 0;
#if DEBUGLEVEL == 2
  if( !(y % 10) )
#endif
#if DEBUGLEVEL >= 2
    printf( "output row: %d\n", y );
#endif
}


inline void ppm_output::putpixel( int x, int y, point &c ) {
  unsigned char r = gamma(R(c));
  unsigned char g = gamma(G(c));
  unsigned char b = gamma(B(c));

  assert( x < xsize && curx == x && cury == y );
  curx++;
#if DEBUGLEVEL > 3
  printf( "output: %f %f %f\n", c[0], c[1], c[2] );
#endif
  fputc( r, outfile );
  fputc( g, outfile );
  fputc( b, outfile );
}

#endif
