// -*- C++ -*-

// PPM (rawbits) frame buffer output class -- interface
// Bart 2/91

extern "C" {
#include <stdio.h>
}

class output;

class ppm_output : public output {
protected:
  int curx, cury;
  ppm_output( char *, char *, int, int );
public:
  ppm_output( char *, int, int );
  inline virtual void putpixel( int, int, point & );
  inline virtual void flushrow( int );
};
