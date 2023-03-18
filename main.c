#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

int TERRAIN_WIDTH = 20;
int TERRAIN_HEIGHT = 20;

int SCALE = 100;


typedef struct point{
   double x;
   double y;
}point;

void resize(int width, int height);
void initialize_glut(void);
void draw_terrain();
void draw_lines (int x1, int y1, int x2, int y2);
void draw_wall_with_window (int x, int y);
void draw_wall_with_door (int x, int y, int door_start);
void draw_place(point p1, point p2);


int main(int argc, char** argv) 
{
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
   //Closet
   point pcl_1 = {p1.x, p1.y+10.38};
   point pcl_2 = {p1.x + 3.18 , p2.y};
   //Quarto 2 (Superior esquerdo)
   point pq2_1 = {p1.x, p2.y-5.56};
   point pq2_2 = {p1.x + 3.18, p1.y+10.58};
   //Quarto3 (Superior direito)
   point pq3 = {p2.x-4.61, p2.y-2.94};
   //Sala de Jogos
   point psj_1 = {p1.x + 2.98, p2.y-5.56};
   point psj_2 = {p2.x-4.41, p2.y};
   //Banheiro 1
   point pb1_1 = {p1.x+9.2,p1.y};
   point pb1_2 = {p2.x, p1.y + 1.6};
   //Banheiro 2
   point pb2_1 = {p1.x+9.2,p1.y + 7.14};
   point pb2_2 = {p2.x, p2.y-2.74};
   draw_place(p1, pq1);
   draw_place(pcl_1, pcl_2);
   draw_place(pq2_1, pq2_2);
   draw_place(psj_1, psj_2);
   draw_place(pq3, p2);
   draw_place(pb1_1, pb1_2);
   draw_place(pb2_1, pb2_2);

    // Encerra o desenho do quadrado
   glFlush(); // Desenha os comandos pendentes na tela

   // output(0, 0, "Terreno");
}

void draw_place(point p1, point p2){

   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(.5, .5, .5); // Define a cor do quadrado (branco)
   glVertex2f(p1.x, p1.y); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x, p1.y); // Define o segundo ponto do quadrado
   glVertex2f(p2.x, p2.y); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x, p2.y); // Define o quarto ponto do quadrado
   glEnd();

   glBegin(GL_QUADS); // Inicia o desenho de um quadrado
   glColor3f(1.0, 1.0, 1.0); // Define a cor do quadrado (branco)
   glVertex2f(p1.x + 0.2, p1.y + 0.2); // Define o primeiro ponto do quadrado
   glVertex2f(p2.x - 0.2, p1.y + 0.2); // Define o segundo ponto do quadrado
   glVertex2f(p2.x - 0.2, p2.y - 0.2); // Define o terceiro ponto do quadrado
   glVertex2f(p1.x + 0.2, p2.y - 0.2); // Define o quarto ponto do quadrado
   glEnd();

}

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
}