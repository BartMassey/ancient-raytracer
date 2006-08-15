// -*- C++ -*-

// old PPM (ASCII) frame buffer output class -- interface
// Bart 2/91

extern "C" {
#include <stdio.h>
}

class ppm_output;

class oldppm_output : public ppm_output {
public:
  oldppm_output( char *, int, int );
  inline virtual void putpixel( int, int, point & );
  inline virtual void flushrow( int );
};
