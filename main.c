#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "libs\utilities.h"

void resize(int width, int height);
void initialize_glut(void);
// void draw_terrain();
// void draw_place(point p1, point p2);
// void draw_door(point p1, point p2, GLfloat color[3]);
// void draw_window(point p1, point p2, GLfloat color[3], int dupla, int vertical);
void rotate(point p, int degrees);
int verificaDimensoes(float comp, float larg);
int verificaOrientacao(int orientacao);


int main(int argc, char** argv) 
{
   int orientacao;
   
   do{
      printf("Digite os comprimento e largura do terreno: ");
      scanf("%f %f", &COMPRIMENTO_TERRENO, &LARGURA_TERRENO);
      if (!verificaDimensoes(COMPRIMENTO_TERRENO, LARGURA_TERRENO))
      {
         printf("Reinsira sua entrada. O comprimento e largura mínimos do terreno é de 13 metros\n");
      }
   }while(!verificaDimensoes(COMPRIMENTO_TERRENO, LARGURA_TERRENO));
   
   do{
      printf("\nDigite a direção da casa:\n\t0 - Sul\n\t1 - Leste\n\t2 - Norte\n\t3 - Oeste\n");
      scanf("%d", &orientacao);
      if (!verificaOrientacao(orientacao))printf("Reinsira sua entrada. Insira um valor válido.\n");
   }while(!verificaOrientacao(orientacao));
   
   DEGREES = orientacao * 90;

   if(LARGURA_TERRENO <= COMPRIMENTO_TERRENO)
   {
      SCALE = LARGURA_TERRENO;
   }
   else
   {
      SCALE = COMPRIMENTO_TERRENO;
   }

   glutInit(&argc, argv); //inicializar o GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de exibição da janela
   glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Tamanho da janela
   // glfwSetWindowSizeLimits(window, 0, 800, 0, 500);
   
   glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-WINDOW_WIDTH)/2, (glutGet(GLUT_SCREEN_HEIGHT)-WINDOW_HEIGHT)/2); // Posição da janela na tela
   glutCreateWindow("Planta baixa de uma casa quadrada"); // Título da janela
   
   
   glutDisplayFunc(draw_terrain);


   initialize_glut();
   glutMainLoop();
  

   return 0;
}

void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

int verificaDimensoes(float comprimento, float largura){
   if (comprimento<13 || largura<13){
      return 0;
   }
   return 1;
}

int verificaOrientacao(int orientacao){
   if (orientacao<0 || orientacao>3){
      return 0;
   }
   return 1;
}
// Recebe o tamanho da guia e initializa (incluindo a rosa dos ventos para orientação)

void initialize_glut(void) 
{
   glClearColor(0, 0, 0, 0); //cor de fundo da janela (preta)
   // glClearColor(255.0f, 255.0f, 255.0f, 255.0f); // (preto)
   glMatrixMode(GL_MODELVIEW); //matriz de projeção: GL_PROJECTION ou GL_MODELVIEW
   glLoadIdentity();
   // SCALE * 2
   gluOrtho2D(0, SCALE * 2, 0, SCALE * 2); //Define as coordenadas do mundo -> gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top): Left é a coordenada x do limite esquerdo, right é x do limite direito, bottom é y do limite inferior, top é y do limite superior
   glutReshapeFunc(resize);
   glFlush();

    // Inicia o loop principal do GLUT
}

// Recebe o ponto e deg;

// Desenha o terreno

//cor da janela -> 1,0.96,0