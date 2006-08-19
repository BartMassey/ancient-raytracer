// -*- C++ -*-

// a simple point class -- interface
// Bart 2/91

class xform;

class point {
private:  
  static const int ncmax = 4;
  int nc;
  float c[ncmax];
protected:  
  inline virtual float *ref( int );
public:  
  inline point( const point & );
  inline point( int );
  inline point( float, float );
  inline point( float, float, float );
  inline point( float, float, float, float );
  inline virtual ~point( void ) {};
  inline virtual float at( int );
  inline virtual point &set( int, float );
  inline virtual float &operator[] ( int );
  inline virtual float operator* ( point );
  inline virtual point operator- ( void );
//  inline virtual void negate ( point & );
  inline virtual void negate ( void );
  inline virtual point operator- ( point );
  inline virtual point operator+ ( point );
  inline virtual void operator+= ( point );
  inline virtual void operator-= ( point );
  inline virtual void operator*= ( float );
  inline virtual point operator* ( float );
  inline virtual void transform ( xform & );
  inline virtual point operator^ ( point );
  inline virtual point vproduct( point );
  inline virtual float mag( void );
  inline virtual float mag2( void );
  inline virtual void unitize( void );
  inline virtual point unit( void );
  inline virtual void homogenize( void );
  inline virtual point homogeneous( void );
  inline virtual point dilation( float );
  inline virtual void dilate( float );
  inline virtual point contraction( void );
  inline virtual void contract( void );
  inline virtual int d( void );
};

#ifdef DEBUG
extern float X( point & );
extern float Y( point & );
extern float Z( point & );
extern float W( point & );
extern float R( point & );
extern float G( point & );
extern float B( point & );
#endif
