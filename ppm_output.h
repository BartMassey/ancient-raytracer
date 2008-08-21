/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */


// -*- C++ -*-

// PPM (rawbits) frame buffer output class -- interface
// Bart 2/91

class output;

class ppm_output : public output {
protected:
  int curx, cury;
  ppm_output( char *, char *, int, int );
public:
  ppm_output( char *, int, int );
  inline virtual void putpixel( int, int, point & );
  inline virtual void flushrow( int );
};
