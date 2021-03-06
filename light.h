/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
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
