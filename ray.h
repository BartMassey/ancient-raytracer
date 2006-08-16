// -*- C++ -*-

// a simple ray class -- interface
// Bart 2/91

class point;
class xform;

class ray {
private:  
  point ro; // origin
  point rd; // normalized direction
public:
  inline ray( point &, point & );
  inline ray( const ray & );
  inline virtual ~ray( void ) {};
  virtual void transform( xform & );
  inline virtual point at( float );
  inline virtual point o( void );
  inline virtual point d( void );
};
