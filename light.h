/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// a simple light class -- interface
// Bart 2/91

class point;

class light {
private:
  point loc;
  point intensity;
public:
  inline light( point, point );
  inline virtual ~light( void ) {};
  inline virtual point &at( void );
  inline virtual point &i( void );
};
