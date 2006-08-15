// -*- C++ -*-

// a simple fast texture class -- interface
// Bart 2/91

class point;
class model;
class texture;

class fast_texture : public texture {
protected:
  point pl;	// light-point
  point pli;    // light intensity
  point pe;	// eye-point
public:
  fast_texture( model &, texture & );
  fast_texture( fast_texture & );
  virtual texture *dup( void );
  virtual texture *tune_texture( model & );
  virtual point value( const point &, const point &, const point &, const model &, int );
};
