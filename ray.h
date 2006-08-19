/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple ray class -- interface
// Bart 2/91

class point;
class xform;

class ray {
private:  
  point ro; // origin
  point rd; // normalized direction
public:
  inline ray( point &, point & );
  inline ray( const ray & );
  inline virtual ~ray( void ) {};
  virtual void transform( xform & );
  inline virtual point at( float );
  inline virtual point o( void );
  inline virtual point d( void );
};
