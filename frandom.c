/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */


#include <math.h>
#include "frandom.h"

extern unsigned long random( void );

#define RES 100000

double frandom(void) {
  unsigned long n = (random() >> 3);
  return (n % (RES + 1)) / RES;
}

double fnurandom1( double centricity ) {
  return pow( frandom(), 1 / (1 - centricity) );
}

double fnurandom2( double centricity ) {
  double x = frandom() * 2;
  int sign = 1;

  if( x > 1 ) {
    x -= 1;
    sign = -1;
  }
  return sign * pow( x, 1 / (1 - centricity) );
}
