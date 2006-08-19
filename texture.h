/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple texture class -- interface
// Bart 2/91

class light;
class point;
class model;

class texture {
protected:
  point ka, kd, ks;
  float ns;
public:
  texture( point, point, point, float );
  texture( const texture & );
  virtual ~texture( void );
  virtual texture *tune_texture( model & );
  virtual point value( point &, point &, point &, model &, int );
};
