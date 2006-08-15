// -*- C++ -*-

// a simple texture class -- interface
// Bart 2/91

class light;
class point;
class model;

class texture {
protected:
  point ka, kd, ks;
  float ns;
public:
  texture( point &, point &, point &, float );
  texture( texture & );
  virtual ~texture( void );
  virtual texture *dup( void );
  virtual texture *tune_texture( model & );
  virtual point value( point &, point &, point &, model &, int );
};
