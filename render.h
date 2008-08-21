/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the end of this file for license terms.
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

/*
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the
 * following conditions are met:
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the
 *       above copyright notice, this list of conditions and the
 *       following disclaimer in the documentation and/or other
 *       materials provided with the distribution.
 *     * Neither the name of the copyright holder, nor the names
 *       of other affiliated organizations, nor the names
 *       of other contributors may be used to endorse or promote
 *       products derived from this software without specific prior
 *       written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
