/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */


// -*- C++ -*-

// a simple poly class -- interface
// Bart 2/91

class ray;
class texture;
class xform;
struct intersection;

class poly: public object {
private:
  int np, dp;
  point **p;
  xform to, toi;
  point *cnormal;
  inline virtual point ** ref( int );
  inline virtual point &get( int );
  virtual int contains( point & );
  inline virtual point *inormal( void );
public:
  poly( int, texture * );
  poly( const poly & );
  virtual void operator= ( const poly & );
  inline virtual ~poly( void );
  inline virtual poly &set( int, point & );
  inline virtual point &operator[] ( int );
  inline virtual int d( void );
  inline virtual int n( void );
  inline virtual void dilate( float );
  inline virtual void contract( void );
  // abstract in superclass
  virtual void complete( void );
  inline virtual void transform( xform );
  virtual int intersect( ray, intersection & );
};
