#ifndef UTILITIES_H
#define UTILITIES_H

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

#ifndef VAR_DECLS
# define _DECL extern
# define _INIT(x)
#else
# define _DECL
# define _INIT(x)  = x
#endif



_DECL float COMPRIMENTO_TERRENO;
_DECL float LARGURA_TERRENO;
_DECL float SCALE;
_DECL int DEGREES;


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct point{
   double x;
   double y;
} point;


typedef struct door{
   point point_1;
   point point__2;
} door;

typedef struct place{
   point point_1;
   point point_2;
   door doors[2];
   char name[12];
} place;

void draw_terrain ();
void draw_window(point p1, point p2, GLfloat color[3], int dupla, int vertical);
void draw_door(point p1, point p2, GLfloat color[3]);
void draw_high_window(point p1, point p2, GLfloat color[3], int dupla, int vertical);
void draw_place(point p1, point p2);
void teste();

#endif