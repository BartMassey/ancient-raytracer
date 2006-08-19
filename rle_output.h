// -*- C++ -*-

// RLE frame buffer output class -- interface
// Bart 9/93

class output;

class rle_output : public output {
protected:
  point &(buffer[]);
  virtual void putword( int );
  virtual void putbyte( int );
  int curx, cury;
public:
  rle_output( char *, int, int );
  inline virtual void putpixel( int, int, point & );
  inline virtual void flushrow( int );
  inline virtual void flush(void);
};
