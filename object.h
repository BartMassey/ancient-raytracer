// -*- C++ -*-

// a simple ray-traceable object class -- interface
// Bart 2/91

class point;
class xform;
class ray;
class texture;

struct intersection {
  float t;
  point *normal;
  point *at;
};

class object {
protected:  
  texture *ot;
  object *nextobj;
public:
  object( texture );
  virtual void tune_texture( model & );
// these should be here, since otherwise the texture is never disposed of
// but I'm just too lazy.
//  object( object & );
//  virtual ~object( void );
//  virtual void operator=( object & );
  virtual ~object( void ) {};
  virtual void complete( void ) = 0;
  virtual void transform( xform ) = 0;
  inline virtual int intersect( ray, intersection & ) = 0;
  inline virtual object * next( void );
  inline virtual void append( object & );
  inline virtual texture &get_texture( void );
};
