/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple fast texture class -- interface
// Bart 2/91

class point;
class model;
class texture;

class fast_texture : public texture {
protected:
  point pl;	// light-point
  point pli;    // light intensity
  point pe;	// eye-point
public:
  fast_texture( model &, texture & );
  fast_texture( const fast_texture & );
  virtual texture * tune_texture( model & );
  virtual point value( point &, point &, point &, model &, int );
};
