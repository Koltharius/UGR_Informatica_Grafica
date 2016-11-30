//**************************************************************************
// Practica 3
//
// David Sanchez Jimenez
//
// GPL
//**************************************************************************

#include "objetos.h"
#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>

// Creacion de objetos
string modo = "s";
int figura = 5;
_cubo _cubo(2.0);
_piramide _piramide(2.0, 3.0);
_ply _beethoven("beethoven.ply");
_ply _peon("peon.ply");
_minecraft minecraft;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width, Window_height, Front_plane, Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 500,
    UI_window_height = 500;

//**************************************************************************
//
//***************************************************************************

void clear_window() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection() {

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  //  Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(-Window_width, Window_width, -Window_height, Window_height,
            Front_plane, Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer() {

  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -Observer_distance);
  glRotatef(Observer_angle_x, 1, 0, 0);
  glRotatef(Observer_angle_y, 0, 1, 0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis() {
  glBegin(GL_LINES);
  // eje X, color rojo
  glColor3f(1, 0, 0);
  glVertex3f(-AXIS_SIZE, 0, 0);
  glVertex3f(AXIS_SIZE, 0, 0);
  // eje Y, color verde
  glColor3f(0, 1, 0);
  glVertex3f(0, -AXIS_SIZE, 0);
  glVertex3f(0, AXIS_SIZE, 0);
  // eje Z, color azul
  glColor3f(0, 0, 1);
  glVertex3f(0, 0, -AXIS_SIZE);
  glVertex3f(0, 0, AXIS_SIZE);
  glEnd();
}

//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects() {

  // Cubo
  if (figura == 1) {
    if (modo == "p")
      _cubo.draw_puntos(1, 0, 1, 5);
    else if (modo == "l")
      _cubo.draw_aristas(0, 1, 1, 4);
    else if (modo == "s")
      _cubo.draw_solido(2, 0, 1);
    else if (modo == "a")
      _cubo.draw_solido_ajedrez(1, 1, 0, 0, 0, 0.3);
  }

  // Piramide
  if (figura == 2) {
    if (modo == "p")
      _piramide.draw_puntos(1, 0, 1, 5);
    else if (modo == "l")
      _piramide.draw_aristas(0, 1, 1, 4);
    else if (modo == "s")
      _piramide.draw_solido(2, 0, 1);
    else if (modo == "a")
      _piramide.draw_solido_ajedrez(1, 1, 0, 0, 0, 0.3);
  }

  // Beethoven
  if (figura == 3) {
    if (modo == "p")
      _beethoven.draw_puntos(1, 0, 1, 5);
    else if (modo == "l")
      _beethoven.draw_aristas(0, 1, 1, 4);
    else if (modo == "s")
      _beethoven.draw_solido(2, 0, 1);
    else if (modo == "a")
      _beethoven.draw_solido_ajedrez(1, 1, 0, 0, 0, 0.3);
  }

  // Peon
  if (figura == 4) {
    _revolucion _revolucion(_peon, Y, 8.0);
    if (modo == "p")
      _revolucion.draw_puntos(1, 0, 1, 5);
    else if (modo == "l")
      _revolucion.draw_aristas(0, 1, 1, 4);
    else if (modo == "s")
      _revolucion.draw_solido(2, 0, 1);
    else if (modo == "a")
      _revolucion.draw_solido_ajedrez(1, 1, 0, 0, 0, 0.3);
    else if (modo == "f")
      _revolucion.draw_franjas(1, 1, 0, 0, 0, 0.3);
  }

  // minecraft
  if (figura == 5) {
    if (modo == "p") {
      minecraft.munieco(1);
    } else if (modo == "l") {
      minecraft.munieco(2);
    } else if (modo == "s") {
      minecraft.munieco(3);
    } else if (modo == "a") {
      minecraft.munieco(4);
    }
  }
}

//**************************************************************************
//
//***************************************************************************

void draw_scene(void) {
  clear_window();
  change_observer();
  draw_axis();
  draw_objects();
  glutSwapBuffers();
}

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1, int Alto1) {
  change_projection();
  glViewport(0, 0, Ancho1, Alto1);
  glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1, int x, int y) {
  switch (toupper(Tecla1)) {

  // Salida
  case 'Q':
    exit(0);

  // Modo Puntos
  case 'P':
    modo = "p";
    glutPostRedisplay();
    break;

  // Modo Lineas
  case 'L':
    modo = "l";
    glutPostRedisplay();
    break;

  // Modo Solido
  case 'S':
    modo = "s";
    glutPostRedisplay();
    break;

  // Modo Ajedrez
  case 'A':
    modo = "a";
    glutPostRedisplay();
    break;

  // Modo franjas
  case 'F':
    modo = "f";
    glutPostRedisplay();
    break;

  // Cubo
  case '1':
    figura = 1;
    break;

  // Tetraedro
  case '2':
    figura = 2;
    break;

  // Beethoven
  case '3':
    figura = 3;
    break;

  // Peon
  case '4':
    figura = 4;
    break;

  // minecraft
  case '5':
    figura = 5;
    break;

  case 'Z':
    minecraft.aumentar_brazos(0);
    minecraft.disminuir_brazos(1);
    break;

  case 'X':
    minecraft.disminuir_brazos(0);
    minecraft.aumentar_brazos(1);
    break;

  case 'C':
    minecraft.aumentar_piernas(2);
    minecraft.disminuir_piernas(3);
    break;

  case 'V':
    minecraft.disminuir_piernas(2);
    minecraft.aumentar_piernas(3);
    break;

  case 'B':
    minecraft.mover_cabeza_dcha(4);
    break;

  case 'N':
    minecraft.mover_cabeza_izda(4);
    break;

  case '.':
    minecraft.aumentar_brazos(0);
    minecraft.disminuir_brazos(1);
    minecraft.aumentar_piernas(2);
    minecraft.disminuir_piernas(3);
    break;

  case '-':
    minecraft.disminuir_brazos(0);
    minecraft.aumentar_brazos(1);
    minecraft.disminuir_piernas(2);
    minecraft.aumentar_piernas(3);
    break;
  }

  glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1, int x, int y) {

  switch (Tecla1) {
  case GLUT_KEY_LEFT:
    Observer_angle_y--;
    break;
  case GLUT_KEY_RIGHT:
    Observer_angle_y++;
    break;
  case GLUT_KEY_UP:
    Observer_angle_x--;
    break;
  case GLUT_KEY_DOWN:
    Observer_angle_x++;
    break;
  case GLUT_KEY_PAGE_UP:
    Observer_distance *= 1.2;
    break;
  case GLUT_KEY_PAGE_DOWN:
    Observer_distance /= 1.2;
    break;
  }
  glutPostRedisplay();
}

//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void) {
  // se inicalizan la ventana y los planos de corte
  Window_width = 5;
  Window_height = 5;
  Front_plane = 10;
  Back_plane = 1000;

  // se inicia la posicion del observador, en el eje z
  Observer_distance = 2 * Front_plane;
  Observer_angle_x = 0;
  Observer_angle_y = 0;

  // se indica cual sera el color para limpiar la ventana	(r,v,a,al)
  // blanco=(1,1,1,1) rojo=(1,0,0,1), ...
  glClearColor(1, 1, 1, 1);

  // se habilita el z-bufer
  glEnable(GL_DEPTH_TEST);
  //
  change_projection();
  //
  glViewport(0, 0, UI_window_width, UI_window_height);
}

//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

  // se llama a la inicialización de glut
  glutInit(&argc, argv);

  // se indica las caracteristicas que se desean para la visualización con
  // OpenGL
  // Las posibilidades son:
  // GLUT_SIMPLE -> memoria de imagen simple
  // GLUT_DOUBLE -> memoria de imagen doble
  // GLUT_INDEX -> memoria de imagen con color indizado
  // GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para
  // cada
  // pixel
  // GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa
  // para cada pixel
  // GLUT_DEPTH -> memoria de profundidad o z-bufer
  // GLUT_STENCIL -> memoria de estarcido
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  // posicion de la esquina inferior izquierdad de la ventana
  glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);

  // tamaño de la ventana (ancho y alto)
  glutInitWindowSize(UI_window_width, UI_window_height);

  // llamada para crear la ventana, indicando el titulo (no se visualiza hasta
  // que se llama
  // al bucle de eventos)
  glutCreateWindow("Practica 3");

  // asignación de la funcion llamada "dibujar" al evento de dibujo
  glutDisplayFunc(draw_scene);
  // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento
  // correspondiente
  glutReshapeFunc(change_window_size);
  // asignación de la funcion llamada "tecla_normal" al evento correspondiente
  glutKeyboardFunc(normal_keys);
  // asignación de la funcion llamada "tecla_Especial" al evento
  // correspondiente
  glutSpecialFunc(special_keys);

  // funcion de inicialización
  initialize();

  // inicio del bucle de eventos
  glutMainLoop();
  return 0;
}
