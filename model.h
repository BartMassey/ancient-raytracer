// -*- C++ -*-

// a simple model class -- interface
// Bart 2/91

class point;
class light;
class object;

struct model {
  point &eye;
  light &thelight;
  object &scene;
  point &bg;
  int maxdepth;
  inline model( point &, light &, object &, point & );
};
