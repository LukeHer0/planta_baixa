#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

int TERRAIN_WIDTH = 12;
int TERRAIN_HEIGHT = 12;

int SCALE = 100;
int DEGREES = 0;


typedef struct point{
   double x;
   double y;
}point;

void resize(int width, int height);
void initialize_glut(void);
void draw_terrain();
void draw_place(point p1, point p2);
void draw_door(point p1, point p2, GLfloat color[3]);
void draw_window(point p1, point p2, GLfloat color[3], int dupla, int vertical);
void rotate(point p, int degrees);

int main(int argc, char** argv) 
{
   int orientacao;
   printf("Digite a direção da casa:\n\t0 - Sul\n\t1 - Leste\n\t2 - Norte\n\t3 - Oeste\n");
   scanf("%d", &orientacao);
   DEGREES = orientacao * 90;
   // rotate(, degrees);
   // printf("Digite a largura e comprimento do terreno: ");
   // scanf("%d %d", &TERRAIN_WIDTH, &TERRAIN_HEIGHT);

   if(TERRAIN_WIDTH > TERRAIN_HEIGHT)
   {
      SCALE = TERRAIN_WIDTH;
   }
   else
   {
      SCALE = TERRAIN_HEIGHT;
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

// Recebe o tamanho da guia e initializa (incluindo a rosa dos ventos para orientação)

void initialize_glut(void) 
{
   // glClearColor(0, 0, 0, 0); //cor de fundo da janela (preta)
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // (branca)
   glMatrixMode(GL_PROJECTION); //matriz de projeção: GL_PROJECTION ou GL_MODELVIEW
   glLoadIdentity();
   // SCALE * 2
   gluOrtho2D(0, SCALE * 2, 0, SCALE * 2); //Define as coordenadas do mundo -> gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top): Left é a coordenada x do limite esquerdo, right é x do limite direito, bottom é y do limite inferior, top é y do limite superior
   glutReshapeFunc(resize);
   glFlush();

    // Inicia o loop principal do GLUT
}


// Recebe o ponto e deg;
void rotate(point p, int degrees)
{
   p.x = p.x * cos(degrees) + p.y * sin(degrees);
   p.y = p.y * cos(degrees) - p.x * sin(degrees);
}

// Desenha o terreno
void draw_terrain ()
{

   int center_x = SCALE; //centro do plano no eixo X (coordenadas do glut)
   int center_y = SCALE; //centro do plano no eixo Y (coordenadas do glut)
  
   point p1 = {center_x - (11.58/2), center_y - (11.58/2)};
   point p2 = {center_x + (11.58/2), center_y + (11.58/2)};
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
   glEnd();
   //glViewport((width - desired_w));
   draw_place(p1, p2);
   //Quarto 1 (inferior esquerdo)
   point pq1 = {p1.x + 3.22, p1.y + 4.23};
   rotate(pq1, DEGREES);
   
   //Closet
   point pcl_1 = {p1.x, p1.y+10.38};
   rotate(pcl_1, DEGREES);
   point pcl_2 = {p1.x + 3.18 , p2.y};
   rotate(pcl_2, DEGREES);
   //Quarto 2 (Superior esquerdo)
   point pq2_1 = {p1.x, p2.y-5.56};
   rotate(pq2_1, DEGREES);
   point pq2_2 = {p1.x + 3.18, p1.y+10.58};
   rotate(pq2_2, DEGREES);
   //Quarto3 (Superior direito)
   point pq3 = {p2.x-4.61, p2.y-2.94};
   rotate(pq3, DEGREES);
   //Sala de Jogos
   point psj_1 = {p1.x + 2.98, p2.y-5.56};
   rotate(psj_1, DEGREES);
   point psj_2 = {p2.x-4.41, p2.y};
   rotate(psj_2, DEGREES);
   //Banheiro 1
   point pb1_1 = {p1.x+9.2,p1.y};
   rotate(pb1_1, DEGREES);
   point pb1_2 = {p2.x, p1.y + 1.6};
   rotate(pb1_2, DEGREES);
   //Banheiro 2
   point pb2_1 = {p1.x+9.2,p1.y + 7.14};
   rotate(pb2_1, DEGREES);
   point pb2_2 = {p2.x, p2.y-2.74};
   rotate(pb2_2, DEGREES);

   draw_place(p1, pq1);
   draw_place(pcl_1, pcl_2);
   draw_place(pq2_1, pq2_2);
   draw_place(psj_1, psj_2);
   draw_place(pq3, p2);
   draw_place(pb1_1, pb1_2);
   draw_place(pb2_1, pb2_2);
   // //Desenhando portas
   // // GLfloat doorColor[3] = {.211,.101,.0509};
   // GLfloat doorColor[3] = {.69,.67,.65};
   // //Porta de entrada
   // point ppE_1_d = {p1.x+6.61, p1.y};
   // point ppE_2_d = {p1.x+7.91, p1.y+0.2};
   // draw_door(ppE_1_d, ppE_2_d, doorColor);
   // //Porta do quarto 1
   // point pq1_1_d = {p1.x+0.94, p1.y+4.03};
   // point pq1_2_d = {p1.x+2.1, p1.y+4.23};
   // draw_door(pq1_1_d, pq1_2_d, doorColor);
   // //Porta do quarto 2
   // point pq2_1_d = {p1.x+0.94, p1.y+6.02};
   // point pq2_2_d = {p1.x+2.1, p1.y+6.22};
   // draw_door(pq2_1_d, pq2_2_d, doorColor);
   // //Closet quarto 2
   // point pc_1_d = {p1.x+1.06, p1.y+10.39};
   // point pc_2_d = {p1.x+2.27, p1.y+10.59};
   // draw_door(pc_1_d, pc_2_d, doorColor);
   // //Porta do quarto 3
   // point pq3_1_d = {p1.x+7.96, p1.y+8.63};
   // point pq3_2_d = {p1.x+9.03, p1.y+8.83};
   // draw_door(pq3_1_d, pq3_2_d, doorColor);
   // //Porta do banheiro quarto 3
   // point pbq3_1_d = {p1.x+10.43, p1.y+8.63};
   // point pbq3_2_d = {p1.x+11.33, p1.y+8.83};
   // draw_door(pbq3_1_d, pbq3_2_d, doorColor);
   // //Porta do banheiro 1
   // point pb1_1_d = {p1.x+9.2, p1.y+0.25};
   // point pb1_2_d = {p1.x+9.4, p1.y+1.01};
   // draw_door(pb1_1_d, pb1_2_d, doorColor);
   // //Porta do banheiro 2
   // point pb2_1_d = {p1.x+9.2, p1.y+0.25};
   // point pb2_2_d = {p1.x+9.4, p1.y+1.01};
   // draw_door(pb2_1_d, pb2_2_d, doorColor);
   // //Porta sala de jogos
   // point psj_1_d = {p1.x+6.97, p1.y+6.41};
   // point psj_2_d = {p1.x+7.17, p1.y+8.31};
   // draw_door(psj_1_d, psj_2_d, doorColor);

   // // Ponto pessoa juridica? ponto joao? ponto j????
   // GLfloat windowColor[3] = {1.0f,0.96f,0.0f};
   // point pjs_1 = {p1.x+3.8, p1.y};
   // point pjs_2 = {p1.x+5.2, p1.y+0.2};
   // draw_window(pjs_1, pjs_2, windowColor, 1, 0);
   // point pjcor_1 = {p1.x, p1.y+4.69};
   // point pjcor_2 = {p1.x+0.2, p1.y+5.5};
   // draw_window(pjcor_1, pjcor_2, windowColor, 0, 1);

   // point pjq1_1 = {p1.x, p1.y+1.95};
   // point pjq1_2 = {p1.x+0.2, p1.y+3.36};
   // draw_window(pjq1_1, pjq1_2, windowColor, 1,1);

   // point pjsj1_1 = {p1.x+3.6, p1.y+11.38};
   // point pjsj1_2 = {p1.x+4.3, p1.y+11.58};
   // draw_window(pjsj1_1, pjsj1_2, windowColor, 0,0);

   // point pjsj2_1 = {p1.x+6, p1.y+11.38};
   // point pjsj2_2 = {p1.x+6.7, p1.y+11.58};
   // draw_window(pjsj2_1, pjsj2_2, windowColor, 0,0);

   // point pjq2_1 = {p1.x, p1.y+8.50};
   // point pjq2_2 = {p1.x+0.2, p1.y+9.92};
   // draw_window(pjq2_1, pjq2_2, windowColor, 1,1);

   // point pjq3_1 = {p1.x+11.38, p1.y+9.15};
   // point pjq3_2 = {p1.x+11.58, p1.y+10.55};
   // draw_window(pjq3_1, pjq3_2, windowColor, 1,1);

   // point pjcoz_1 = {p1.x+11.38, p1.y+2.24};
   // point pjcoz_2 = {p1.x+11.58, p1.y+3.64};
   // draw_window(pjcoz_1, pjcoz_2, windowColor, 1,1);

   // point pjba_1 = {p1.x + 11.38, p1.y + 0.7};
   // point pjba_2 = {p1.x + 11.58, p1.y + 1.24};
   // draw_high_window(pjba_1, pjba_2, windowColor, 0, 1);

   // point pjba2_1 = {p1.x + 11.38, p1.y + 7.77};
   // point pjba2_2 = {p1.x + 11.58, p1.y + 8.34};
   // draw_high_window(pjba2_1, pjba2_2, windowColor, 0, 1);
    // Encerra o desenho do quadrado
   glFlush(); // Desenha os comandos pendentes na tela

   // output(0, 0, "Terreno");
}

//cor da janela -> 1,0.96,0
void draw_door(point p1, point p2, GLfloat color[3]){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y);
   glEnd();
}

void draw_window(point p1, point p2, GLfloat color[3], int dupla, int vertical){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();
   
   //glClear(GL_COLOR_BUFFER_BIT);
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

draw_high_window(point p1, point p2, GLfloat color[3], int dupla, int vertical){
   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(color[0], color[1], color[2]);
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();
   
   //glClear(GL_COLOR_BUFFER_BIT);
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

void draw_place(point p1, point p2){

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

}
/*
void write_text(){
   // Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,1);
	//glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(2,2); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"OpenGl");
	// Exibe o desenha na janela
	glutSwapBuffers();
}

void write_strange_text(){
    // Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor para os textos: preto
	glColor3f(1,0,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(20,20,0);
	glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
   //glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(2); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Teste");
	glPopMatrix();
}

void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}*/