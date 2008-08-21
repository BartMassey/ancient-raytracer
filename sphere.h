/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
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
