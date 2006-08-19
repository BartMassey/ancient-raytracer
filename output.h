// -*- C++ -*-

// generic frame buffer output class -- interface
// Bart 2/91

class output {
public:
  inline virtual void putpixel( int, int, point & ) = 0;
  inline virtual void flushrow( int ) = 0;
  inline virtual void flush(void) {};
  output( char *, char *, int, int );
  virtual ~output( void );
protected:
  int xsize, ysize;
  char *name;
  FILE *outfile;
  inline virtual unsigned char gamma( float );
};
