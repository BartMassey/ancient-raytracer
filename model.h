/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple model class -- interface
// Bart 2/91

class point;
class light;
class object;

struct model {
  point &eye;
  light &thelight;
  object &scene;
  point &bg;
  int maxdepth;
  inline model( point &, light &, object &, point & );
};
