/*
 * Copyright © 1991-2006 Bart Massey
 * ALL RIGHTS RESERVED
 * [This program is licensed under the "3-clause ('new') BSD License"]
 * Please see the end of this file for license terms.
 */


// -*- C++ -*-

// a simple point class -- interface
// Bart 2/91

class xform;

class point {
private:  
  static const int ncmax = 4;
  int nc;
  float c[ncmax];
protected:  
  inline virtual float *ref( int );
public:  
  inline point( const point & );
  inline point( int );
  inline point( float, float );
  inline point( float, float, float );
  inline point( float, float, float, float );
  inline virtual ~point( void ) {};
  inline virtual float at( int );
  inline virtual point &set( int, float );
  inline virtual float &operator[] ( int );
  inline virtual float operator* ( point );
  inline virtual point operator- ( void );
//  inline virtual void negate ( point & );
  inline virtual void negate ( void );
  inline virtual point operator- ( point );
  inline virtual point operator+ ( point );
  inline virtual void operator+= ( point );
  inline virtual void operator-= ( point );
  inline virtual void operator*= ( float );
  inline virtual point operator* ( float );
  inline virtual void transform ( xform & );
  inline virtual point operator^ ( point );
  inline virtual point vproduct( point );
  inline virtual float mag( void );
  inline virtual float mag2( void );
  inline virtual void unitize( void );
  inline virtual point unit( void );
  inline virtual void homogenize( void );
  inline virtual point homogeneous( void );
  inline virtual point dilation( float );
  inline virtual void dilate( float );
  inline virtual point contraction( void );
  inline virtual void contract( void );
  inline virtual int d( void );
};

#ifdef DEBUG
extern float X( point & );
extern float Y( point & );
extern float Z( point & );
extern float W( point & );
extern float R( point & );
extern float G( point & );
extern float B( point & );
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
