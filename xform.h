// -*- C++ -*-

// a simple transformation matrix class -- interface
// Bart 2/91

enum xform_types {
  XFORM_IDENTITY,
  XFORM_TRANSLATE,
  XFORM_SCALE,
  XFORM_ROTATE_X,
  XFORM_ROTATE_Y,
  XFORM_ROTATE_Z
};
class point;

typedef float gmatrix[4][4];

class xform {
private:
  gmatrix *m, *mi;
  gmatrix mv, miv;
public:
  xform( enum xform_types );
  xform( enum xform_types, point );
  xform( enum xform_types, float );
  xform( const xform & );
  inline virtual ~xform( void );
  inline void operator= ( const xform & );
  inline virtual float at( int, int );
  inline virtual point row( int );
  inline virtual float rowmult( int, float [4] );
  inline virtual point col( int );
  inline virtual void operator*= ( xform );
  inline virtual xform operator* ( xform );
  inline virtual void invert( void );
  inline virtual xform inverse( void );
};
