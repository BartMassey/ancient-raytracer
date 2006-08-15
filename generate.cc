// -*- C++ -*-

// model to be ray-traced
// Bart 10/92

#include "render.h"
#include "generate.h"

#define ZB (D * cos( A ))
#define JOGGLE (100 * TINY * (frandom() - 0.5))

object *generate(void) {
  poly *p;
  sphere *s1, *s2, *s3;
  point ll( -4.0, -4.0 );
  point ul( -4.0, 4.0 );
  point ur( 4.0, 4.0 );
  point lr( 4.0, -4.0 );
  point kyellow( 1.0, 0.85, 0.5 );
  point kblue( 0.3, 0.3, 1.0 );
  point kgreen( 0.3, 1.0, 0.3 );
  point kwhite( 1.0, 1.0, 1.0 );
  point kblack( 0.0, 0.0, 0.0 );
  texture tgreen( kblack, kgreen * 0.2, kgreen * 0.75, 100 );
  texture tyellow( kblack, kyellow * 0.85, kwhite * 0.05, 10 );
  texture tblue( kblack, kblue * 0.2, kblue * 0.75, 100 );
  board_texture tboard( tyellow, tblue );

  p = new poly( 4, tboard );
  p->set( 0, ll );
  p->set( 1, ul );
  p->set( 2, ur );
  p->set( 3, lr );
  p->transform( xform( XFORM_ROTATE_Y, -PI / 2 ) );
  p->transform( xform( XFORM_SCALE, point( 1, D / 8, D / 8 ) ) );
  p->transform( xform( XFORM_TRANSLATE,
   point( -JOGGLE, JOGGLE, ZB + JOGGLE ) ) );
  p->complete();
  s1 = new sphere( tgreen );
  s1->transform( xform( XFORM_SCALE, point( 1.5, 1.5, 1.5 ) ) );
  s1->transform( xform( XFORM_TRANSLATE,
   point( 1.5 + JOGGLE, JOGGLE, ZB + JOGGLE ) ) );
  s1->append( *p );
  s1->complete();
  s2 = new sphere( tblue );
  s2->transform( xform( XFORM_TRANSLATE,
   point( 1 + JOGGLE, -D / 3 + JOGGLE, ZB - D / 5 + JOGGLE ) ) );
  s2->append( *s1 );
  s2->complete();
  s3 = new sphere( tyellow );
  s3->transform( xform( XFORM_TRANSLATE,
   point( 1 + JOGGLE, D / 3 + JOGGLE, ZB - D / 3 + JOGGLE ) ) );
  s3->append( *s2 );
  s3->complete();
  return s3;
}
