/* Copyright (c) 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 *
 * This source code is made available under the terms of the
 * GNU General Public License, version 2.  Please see the file
 * COPYING in this directory for the complete license text.
 */


// -*- C++ -*-

// main header file for renderer
// Bart 2/91

#include <stdio.h>

#include <math.h>
#ifndef PI
#define PI 3.14159265358979
#endif
#include <string.h>

#include <assert.h>

#define TINY 0.00001

#ifndef DEBUGLEVEL
#ifdef DEBUG
#define DEBUGLEVEL DEBUG
#else   //!DEBUG
#define DEBUGLEVEL 0
#endif  //!DEBUG
#endif  //DEBUGLEVEL

#ifdef DEBUG
#define inline /* inline */
#endif  //DEBUG
#if DEBUGLEVEL > 0
extern "C" {
#ifndef __GNUC__  
extern void printf( const char *, ... );
#endif
}
#endif

#include "point.h"
#include "xform.h"
#include "texture.h"
#include "fast_texture.h"
#include "board_texture.h"
#include "object.h"
#include "poly.h"
#include "sphere.h"
#include "ray.h"
#include "output.h"
#include "ppm_output.h"
#include "oldppm_output.h"
#include "light.h"
#include "model.h"

#define MIN(X,Y)\
  (((X)<(Y))?(X):(Y))
#define MAX(X,Y)\
  (((X)>(Y))?(X):(Y))

extern point trace( ray, model &, int );

#ifdef DEBUG

#undef NOOUTLINE
#define INLINE

#else

#define NOOUTLINE
#define INLINE
#include "point.cc"
#include "xform.cc"
#include "texture.cc"
#include "fast_texture.cc"
#include "board_texture.cc"
#include "object.cc"
#include "poly.cc"
#include "sphere.cc"
#include "ray.cc"
#include "output.cc"
#include "ppm_output.cc"
#include "oldppm_output.cc"
#include "light.cc"
#include "model.cc"
#undef INLINE
#undef NOOUTLINE

#endif
