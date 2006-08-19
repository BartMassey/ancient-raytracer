/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
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
