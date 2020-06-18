#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"
#include "gmath.h"

int main(int argc, char **argv) {

  screen s;
  zbuffer zbuf;
  struct stack * gstack;
  struct matrix * tris;
  struct matrix * edges;
  //ambient light
  color ambient;
  double light[2][3];
  double view[3];
  double areflect[3];
  double dreflect[3];
  double sreflect[3];

  ambient.red = 150;
  ambient.green = 150;
  ambient.blue = 150;
  light[LOCATION][0] = 0.5;
  light[LOCATION][1] = 0.75;
  light[LOCATION][2] = 1;

  light[COLOR][RED] = 0;
  light[COLOR][GREEN] = 255;
  light[COLOR][BLUE] = 255;

  // view vector
  view[0] = 0;
  view[1] = 0;
  view[2] = 1;

  // reflective constants
  areflect[RED] = 0.1;
  areflect[GREEN] = 0.1;
  areflect[BLUE] = 0.1;

  dreflect[RED] = 0.5;
  dreflect[GREEN] = 0.5;
  dreflect[BLUE] = 0.5;

  sreflect[RED] = 0.2;
  sreflect[GREEN] = 0.2;
  sreflect[BLUE] = 0.2;


  gstack = new_stack();
  tris = new_matrix(4, 0);
  edges = new_matrix(4, 4);
  if ( argc == 2 )
    parse_file( argv[1],gstack, edges, tris, s,zbuf,view, ambient, light, areflect, dreflect, sreflect);
  else
    parse_file( "stdin",gstack, edges, tris, s,zbuf,view, ambient, light, areflect, dreflect, sreflect);
  free_matrix( tris );
  free_matrix( edges );
  free_stack(gstack);
}  
