/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
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
