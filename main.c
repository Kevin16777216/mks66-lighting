#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"

int main(int argc, char **argv) {

  screen s;
  zbuffer zbuf;
  struct stack * gstack;
  struct matrix * tris;
  struct matrix * edges;
  clock_t start,end;

  gstack = new_stack();
  tris = new_matrix(4, 0);
  edges = new_matrix(4, 4);
  if ( argc == 2 ){
    start=clock();
    int cyc = 1000;
    int t = 0;
    while(t++ < cyc){
      parse_file( argv[1],gstack, edges, tris, s,zbuf);
    }
    end=clock();
    printf("%f", (((double)(end-start))/CLOCKS_PER_SEC));
  }else{
    parse_file( "stdin",gstack, edges, tris, s,zbuf);
  }
  free_matrix( tris );
  free_matrix( edges );
  free_stack(gstack);
}  
