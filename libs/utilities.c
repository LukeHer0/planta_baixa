#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.141592654
#define VAR_DECLS
#include "./utilities.h"




void draw_place(point p1, point p2)
{
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(.235, .235, .2901); // Define a cor do quadrado (branco)
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(0.65, 0.48, 0.38); // Define a cor do quadrado (branco)
   glVertex2f(p1.x + 0.2, p1.y + 0.2); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x - 0.2, p1.y + 0.2); // Define o segundo ponto do quadrado
   glVertex2f(p2.x - 0.2, p2.y - 0.2); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x + 0.2, p2.y - 0.2); // Define o quarto ponto do quadrado
   glEnd();
   return;
}

void rotaciona()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glRotatef(DEGREES, 0.0f, 0.0f, 1.0f);
}

void draw_terrain ()
{ 
   float centro_x = SCALE; //centro do plano no eixo X (coordenadas do glut)
   float centro_y = SCALE; //centro do plano no eixo Y (coordenadas do glut)
   float variavel = ((SCALE/13)>1.36?1.36:(SCALE/13));
   point p1 = {centro_x - ((11.58/2)*variavel), centro_y - (11.58/2*variavel)};
   point p2 = {centro_x + (11.58/2*variavel), centro_y + (11.58/2*variavel)};

   float x1 = centro_x - (LARGURA_TERRENO/2);
   float x2 = centro_x + (LARGURA_TERRENO/2);
   float y1 = centro_y - (COMPRIMENTO_TERRENO/2);
   float y2 = centro_y + (COMPRIMENTO_TERRENO/2);

   glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor da janela
   glColor3f(1.0, 1.0, 1.0); // Define a cor do quadrado (branco)
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glVertex2f(x1, y1); // Define o primeiro ponto do quadrado
   glVertex2f(x2, y1); // Define o segundo ponto do quadrado
   glVertex2f(x2, y2); // Define o terceiro ponto do quadrado
   glVertex2f(x1, y2); // Define o quarto ponto do quadrado

   glEnd();

   rotaciona();
   draw_place(p1, p2);
   
   //Quarto 1 (inferior esquerdo)
   point pq1 = {p1.x + 3.22*variavel, p1.y + 4.23*variavel};
   
   //Closet
   point pcl_1 = {p1.x, p1.y+10.38*variavel};

   point pcl_2 = {p1.x + 3.18*variavel , p2.y};

   //Quarto 2 (Superior esquerdo)
   point pq2_1 = {p1.x, p2.y-5.56*variavel};

   point pq2_2 = {p1.x + 3.18*variavel, p1.y+10.58*variavel};

   //Quarto3 (Superior direito)
   point pq3 = {p2.x-4.61*variavel, p2.y-2.94*variavel};

   //Sala de Jogos
   point psj_1 = {p1.x + 2.98*variavel, p2.y-5.56*variavel};

   point psj_2 = {p2.x-4.41*variavel, p2.y};

   //Banheiro 1
   point pb1_1 = {p1.x+9.2*variavel,p1.y};

   point pb1_2 = {p2.x, p1.y + 1.6*variavel};

   //Banheiro 2
   point pb2_1 = {p1.x+9.2*variavel,p1.y + 7.14*variavel};

   point pb2_2 = {p2.x, p2.y-2.74*variavel};


   draw_place(p1, pq1);
   draw_place(pcl_1, pcl_2);
   draw_place(pq2_1, pq2_2);
   draw_place(psj_1, psj_2);
   draw_place(pq3, p2);
   draw_place(pb1_1, pb1_2);
   draw_place(pb2_1, pb2_2);
   //Desenhando portas
   GLfloat doorColor[3] = {.69,.67,.65};
   //Porta de entrada
   point ppE_1_d = {p1.x+6.61*variavel, p1.y};
   point ppE_2_d = {p1.x+7.91*variavel, p1.y+0.2*variavel};
   

   draw_door(ppE_1_d, ppE_2_d, doorColor);

   //Porta do quarto 1
   point pq1_1_d = {p1.x+0.94*variavel, p1.y+4.03*variavel};
   point pq1_2_d = {p1.x+2.1*variavel, p1.y+4.23*variavel};

   draw_door(pq1_1_d, pq1_2_d, doorColor);
   //Porta do quarto 2
   point pq2_1_d = {p1.x+0.94*variavel, p1.y+6.02*variavel};
   point pq2_2_d = {p1.x+2.1*variavel, p1.y+6.22*variavel};

   draw_door(pq2_1_d, pq2_2_d, doorColor);
   //Closet quarto 2
   point pc_1_d = {p1.x+1.06*variavel, p1.y+10.39*variavel};
   point pc_2_d = {p1.x+2.27*variavel, p1.y+10.59*variavel};
   
   draw_door(pc_1_d, pc_2_d, doorColor);
   //Porta do quarto 3
   point pq3_1_d = {p1.x+7.96*variavel, p1.y+8.63*variavel};
   point pq3_2_d = {p1.x+9.03*variavel, p1.y+8.83*variavel};

   draw_door(pq3_1_d, pq3_2_d, doorColor);
   //Porta do banheiro quarto 3
   point pbq3_1_d = {p1.x+10.43*variavel, p1.y+8.63*variavel};
   point pbq3_2_d = {p1.x+11.33*variavel, p1.y+8.83*variavel};

   draw_door(pbq3_1_d, pbq3_2_d, doorColor);
   //Porta do banheiro 1
   point pb1_1_d = {p1.x+9.2*variavel, p1.y+0.25*variavel};
   point pb1_2_d = {p1.x+9.4*variavel, p1.y+1.01*variavel};

   draw_door(pb1_1_d, pb1_2_d, doorColor);
   //Porta do banheiro 2
   point pb2_1_d = {p1.x+9.2*variavel, p1.y+0.25*variavel};
   point pb2_2_d = {p1.x+9.4*variavel, p1.y+1.01*variavel};

   draw_door(pb2_1_d, pb2_2_d, doorColor);
   //Porta sala de jogos
   point psj_1_d = {p1.x+6.97*variavel, p1.y+6.41*variavel};
   point psj_2_d = {p1.x+7.17*variavel, p1.y+8.31*variavel};

   draw_door(psj_1_d, psj_2_d, doorColor);

   // Ponto pessoa juridica? ponto joao? ponto j????
   GLfloat windowColor[3] = {1.0f,0.96f,0.0f};
   point pjs_1 = {p1.x+3.8*variavel, p1.y};
   point pjs_2 = {p1.x+5.2*variavel, p1.y+0.2*variavel};

   draw_window(pjs_1, pjs_2, windowColor, 1, 0);
   
   point pjcor_1 = {p1.x, p1.y+4.69*variavel};
   point pjcor_2 = {p1.x+0.2*variavel, p1.y+5.5*variavel};

   draw_window(pjcor_1, pjcor_2, windowColor, 0, 1);

   point pjq1_1 = {p1.x, p1.y+1.95*variavel};
   point pjq1_2 = {p1.x+0.2*variavel, p1.y+3.36*variavel};

   draw_window(pjq1_1, pjq1_2, windowColor, 1,1);

   point pjsj1_1 = {p1.x+3.6*variavel, p1.y+11.38*variavel};
   point pjsj1_2 = {p1.x+4.3*variavel, p1.y+11.58*variavel};

   draw_window(pjsj1_1, pjsj1_2, windowColor, 0,0);

   point pjsj2_1 = {p1.x+6*variavel, p1.y+11.38*variavel};
   point pjsj2_2 = {p1.x+6.7*variavel, p1.y+11.58*variavel};

   draw_window(pjsj2_1, pjsj2_2, windowColor, 0,0);

   point pjq2_1 = {p1.x, p1.y+8.50*variavel};
   point pjq2_2 = {p1.x+0.2*variavel, p1.y+9.92*variavel};

   draw_window(pjq2_1, pjq2_2, windowColor, 1,1);

   point pjq3_1 = {p1.x+11.38*variavel, p1.y+9.15*variavel};
   point pjq3_2 = {p1.x+11.58*variavel, p1.y+10.55*variavel};

   draw_window(pjq3_1, pjq3_2, windowColor, 1,1);

   point pjcoz_1 = {p1.x+11.38*variavel, p1.y+2.24*variavel};
   point pjcoz_2 = {p1.x+11.58*variavel, p1.y+3.64*variavel};

   draw_window(pjcoz_1, pjcoz_2, windowColor, 1,1);

   point pjba_1 = {p1.x + 11.38*variavel, p1.y + 0.7*variavel};
   point pjba_2 = {p1.x + 11.58*variavel, p1.y + 1.24*variavel};

   draw_high_window(pjba_1, pjba_2, windowColor, 0, 1);

   point pjba2_1 = {p1.x + 11.38*variavel, p1.y + 7.77*variavel};
   point pjba2_2 = {p1.x + 11.58*variavel, p1.y + 8.34*variavel};

   draw_high_window(pjba2_1, pjba2_2, windowColor, 0, 1);

   // Encerra o desenho do quadrado
   glFlush(); // Desenha os comandos pendentes na tela
   

}

void draw_window(point p1, point p2, GLfloat color[3], int dupla, int vertical){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();
   
   glColor3f(.235f, .235f, .29f);

   
   if(!vertical || dupla){
      //horizontal
      glBegin(GL_LINES);
      glVertex2f(p1.x, (p1.y+p2.y)/2);
      glVertex2f(p2.x, (p1.y+p2.y)/2);
      glEnd();
   }
   if(vertical || dupla){
      // vertical
      glBegin(GL_LINES);
      glVertex2f((p1.x+p2.x)/2, p1.y);
      glVertex2f((p1.x+p2.x)/2, p2.y);
      glEnd();
   }
}

void draw_door(point p1, point p2, GLfloat color[3]){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y);
   glEnd();
}


void draw_high_window(point p1, point p2, GLfloat color[3], int dupla, int vertical){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();
   
   glColor3f(.235f, .235f, .29f);

   
   if(!vertical || dupla){
      //horizontal
      glBegin(GL_LINES);
      glVertex2f(p1.x, (p1.y+p2.y)/2);
      glVertex2f((p1.x + 0.2), (p1.y+p2.y)/2);
      glEnd();
      glBegin(GL_LINES);
      glVertex2f((p1.x + 0.4), (p1.y+p2.y)/2);
      glVertex2f((p1.x + 0.6), (p1.y+p2.y)/2);
      glEnd();
      glBegin(GL_LINES);
      glVertex2f((p1.x + 0.8), (p1.y+p2.y)/2);
      glVertex2f((p1.x + 0.1), (p1.y+p2.y)/2);
      glEnd();
   }
   if(vertical || dupla){
      // vertical
      glBegin(GL_LINES);
      glVertex2f((p1.x+p2.x)/2, p1.y);
      glVertex2f((p1.x+p2.x)/2, p2.y);
      glEnd();
   }
}