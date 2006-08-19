/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// generic frame buffer output class -- implementation
// Bart 2/91

extern "C" {
#include <string.h>
#include <stdio.h>
#ifndef __GNUC__  
extern void fputc( char, FILE * );
extern void fclose( FILE * );
extern void fprintf( FILE *, const char *, ... );
extern void perror( char * );
#endif
}

#ifndef NOOUTLINE

#include "render.h"

output::output( char *fn, char *ext, int w, int h ) {
  xsize = w;
  ysize = h;
  name = new char[ strlen( fn ) + strlen( ext ) + 1 ];
  (void) strcpy( name, fn );
  (void) strcat( name, ext );
  outfile = fopen( name, "w" );
  if( !outfile ) {
    perror( "fopen" );
    assert( 0 );
  }
}

output::~output( void ) {
  fclose( outfile );
  delete[] name;
}

#endif

#ifdef INLINE

inline unsigned char output::gamma( float v ) {
  float vclamped = MAX( MIN( v, 1.0 ), 0.0 );
  
  return (unsigned char) floor( vclamped * 255 + 0.5 );
}

#endif
