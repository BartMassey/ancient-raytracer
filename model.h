/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */


// -*- C++ -*-

// a simple model class -- interface
// Bart 2/91

class point;
class light;
class object;

class model {
public:
  point &eye;
  light &thelight;
  object &scene;
  point &bg;
  int maxdepth;
  inline model( point &, light &, object &, point & );
};
