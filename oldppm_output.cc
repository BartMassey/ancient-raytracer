/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// old PPM (ASCII) frame buffer output class - implementation
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

oldppm_output::oldppm_output( char *n, int w, int h ) :
  ppm_output( n, ".oldppm", w, h )
{
  fprintf( outfile, "P3\n%d\n%d\n%d\n", w, h, 255 );
}

#endif

#ifdef INLINE

inline void oldppm_output::putpixel( int x, int y, point &c ) {
  unsigned char r = gamma(R(c));
  unsigned char g = gamma(G(c));
  unsigned char b = gamma(B(c));

  assert( x < xsize && curx == x && cury == y );
  curx++;
#if DEBUGLEVEL > 3
  printf( "output: %f %f %f\n", c[0], c[1], c[2] );
#endif
  fprintf( outfile, "%3d ", r );
  fprintf( outfile, "%3d ", g );
  fprintf( outfile, "%3d ", b );
}


inline void oldppm_output::flushrow( int y ) {
  assert( y < ysize && cury == y );
  cury++;
  curx = 0;
#if DEBUGLEVEL == 2
  if( !(y % 10) )
#endif
#if DEBUGLEVEL >= 2
    printf( "output row: %d\n", y );
#endif
  fprintf( outfile, "\n" );
}


#endif
