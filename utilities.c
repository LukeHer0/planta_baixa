#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

int TERRAIN_WIDTH = 0;
int TERRAIN_HEIGHT = 0;

int SCALE = 100;

void output(int x, int y, char *string)
{
  glColor3f(0,0,0);
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
  }
}

void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}
// Recebe o tamanho da guia e initializa (incluindo a rosa dos ventos para orientação)
void initialize_glut(void) 
{
   glClearColor(0, 0, 0, 0); //cor de fundo da janela (branca)
   glMatrixMode(GL_PROJECTION); //matriz de projeção: GL_PROJECTION ou GL_MODELVIEW
   glLoadIdentity();
   // SCALE * 2
   gluOrtho2D(0, SCALE * 2, 0, SCALE * 2); //Define as coordenadas do mundo -> gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top): Left é a coordenada x do limite esquerdo, right é x do limite direito, bottom é y do limite inferior, top é y do limite superior
   glutReshapeFunc(resize);
   glutMainLoop(); // Inicia o loop principal do GLUT
}

// Desenha o terreno
void draw_terrain ()
{

   int center_x = SCALE; //centro do plano no eixo X (coordenadas do glut)
   int center_y = SCALE; //centro do plano no eixo Y (coordenadas do glut)

   float x1 = center_x - (TERRAIN_WIDTH/2);
   float x2 = center_x + (TERRAIN_WIDTH/2);
   float y1 = center_y - (TERRAIN_HEIGHT/2);
   float y2 = center_y + (TERRAIN_HEIGHT/2);

   glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor da janela
   glColor3f(1.0, 1.0, 1.0); // Define a cor do quadrado (branco)
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glVertex2f(x1, y1); // Define o primeiro ponto do quadrado
   glVertex2f(x2, y1); // Define o segundo ponto do quadrado
   glVertex2f(x2, y2); // Define o terceiro ponto do quadrado
   glVertex2f(x1, y2); // Define o quarto ponto do quadrado
   //glViewport((width - desired_w))
   glEnd(); // Encerra o desenho do quadrado
   glFlush(); // Desenha os comandos pendentes na tela
}

//x1: larg max/proporcao 
// Recebe dois pontos e desenha a linha/parede
void draw_wall (int x1, int y1, int x2, int y2)
{  
   glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
   glEnd();
}

// Recebe dois pontos para desenhar a parede e o ponto

// Caso seja feito com linhas -> Termino da linha 1 da parede: ponto da linha da janela
// Começo da linha 2 da parede: ponto do termino da janela 

// Caso seja feito com retângulos -> pegar o ponto x ou y de um vertice e utilizar como pontos para fazer linha da janela