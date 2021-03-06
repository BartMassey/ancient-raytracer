/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */


// -*- C++ -*-

// a simple checkerboard texture class -- interface
// Bart 2/91

class texture;
class light;
class point;
class model;

class board_texture : public texture {
private:
  texture *red_texture;
  texture *black_texture;
public:
  board_texture( texture *, texture * );
  board_texture( const board_texture & );
  virtual ~board_texture( void );
  virtual texture *tune_texture( model & );
  inline virtual point value( point &, point &, point &, model &, int );
  inline virtual void operator=( board_texture & );
};
