/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// old PPM (ASCII) frame buffer output class -- interface
// Bart 2/91

class ppm_output;

class oldppm_output : public ppm_output {
public:
  oldppm_output( char *, int, int );
  inline virtual void putpixel( int, int, point & );
  inline virtual void flushrow( int );
};
