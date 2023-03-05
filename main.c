#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// a Área e a orientação (norte,sul, leste e oeste) será fornecida pelo usuário.

//Casa quadrada de 1 andar com sala de jogos, 3 quartos, 2 banheiros e 1 closet
//Todas as casas tem que ter pelo menos uma cozinha, uma sala de estar, uma sala de janta, uma área de serviço e um banheiro social
//Deve existir pelo menos uma porta e uma janela em cada comodo, obrigatório a existência de uma porta para área externa
//Sua casa pode ter tantos pátios, sacadas e jadins internos quanto considerar necessário

// Recebe o tamanho da guia e initializa (incluindo a rosa dos ventos para orientação)
void initialize_glut(void) 
{
   glClearColor(255, 255, 255, 255); //cor de fundo da janela (branca)
   glMatrixMode(GL_PROJECTION); //matriz de projeção: GL_PROJECTION ou GL_MODELVIEW
   glLoadIdentity();
   gluOrtho2D(0, 1, 0, 1); //Define as coordenadas do mundo -> gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top): Left é a coordenada x do limite esquerdo, right é x do limite direito, bottom é y do limite inferior, top é y do limite superior
}

// Desenha o terreno
void draw_terrain ()
{
   
}

//x1: larg max/proporcao 
// Recebe dois pontos e desenha a linha/parede
void draw_wall (int x1, int y1, int x2, int y2)
{  

}

// Recebe dois pontos para desenhar a parede e o ponto

// Caso seja feito com linhas -> Termino da linha 1 da parede: ponto da linha da janela
// Começo da linha 2 da parede: ponto do termino da janela 

// Caso seja feito com retângulos -> pegar o ponto x ou y de um vertice e utilizar como pontos para fazer linha da janela
void draw_wall_with_window (int x, int y)
{  

}

void draw_wall_with_door (int x, int y, int door_start, int )
{  

}

int main(int argc, char** argv) 
{
   glutInit(&argc, argv); //inicializar o GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de exibição da janela
   glutInitWindowsize(500, 500); // Tamanho da janela
   glutInitWindowPosition(100, 100); // Posição da janela na tela
   glutCreateWindow("Planta baixa de uma casa quadrada"); // Título da janela
   initialize_glut();
   return 0;
}