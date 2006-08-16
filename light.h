// -*- C++ -*-

// a simple light class -- interface
// Bart 2/91

class point;

class light {
private:
  point loc;
  point intensity;
public:
  inline light( point, point );
  inline virtual ~light( void ) {};
  inline virtual point &at( void );
  inline virtual point &i( void );
};
