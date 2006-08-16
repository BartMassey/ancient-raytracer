// -*- C++ -*-

// a simple ray-traceable sphere class -- interface
// Bart 2/91

class ray;
class texture;
class xform;
struct intersection;

class sphere : public object {
private:
  xform to, toi;
  point tr;
public:
  inline sphere( texture & );
  inline virtual void complete( void );
  virtual void transform( xform );
  virtual int intersect( ray, intersection & );
};
