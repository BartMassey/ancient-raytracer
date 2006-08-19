/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple ray-traceable sphere class -- interface
// Bart 2/91

class ray;
class texture;
class xform;
struct intersection;

class sphere : public object {
private:
  xform to, toi;
  point tr;
public:
  inline sphere( texture * );
  inline virtual void complete( void );
  virtual void transform( xform );
  virtual int intersect( ray, intersection & );
};
