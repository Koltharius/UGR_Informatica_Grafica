//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "file_ply_stl.h"
#include "vertex.h"
#include <GL/glut.h>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

#define X 0
#define Y 1
#define Z 2

const int AXIS_SIZE = 5000;

using namespace std;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D {
public:
  _puntos3D();
  void draw_puntos(float r, float g, float b, int grosor);
  vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D : public _puntos3D {
public:
  _triangulos3D();
  void draw_aristas(float r, float g, float b, int grosor);
  void draw_solido(float r, float g, float b);
  void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2,
                           float b2);
  void draw_franjas(float r1, float g1, float b1, float r2, float g2, float b2);
  vector<_vertex3i> caras;
};

//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo : public _triangulos3D {
public:
  _cubo(float tam = 5);
  _cubo &operator=(const _cubo &otro);
};

//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide : public _triangulos3D {
public:
  _piramide(float tam = 2.0, float al = 3.0);
  _piramide &operator=(const _piramide &otro);
};

//*************************************************************************
// clase Ply
//*************************************************************************

class _ply : public _triangulos3D {
private:
  const char *filename;

public:
  _ply();
  _ply(const char *filename);
  _ply &operator=(const _ply &otro);
};

//*************************************************************************
// clase Revolucion
//*************************************************************************

class _revolucion : public _triangulos3D {
private:
  _matrix4<float> matrizObj;
  int numVerticesPerfil;
  float numPerfil;

public:
  _revolucion();
  _revolucion(_ply &ply, int eje, float numPasos);
  _revolucion &operator=(const _revolucion &otro);
  _revolucion(vector<_vertex3f> ver, int num_caras, bool tapas);
  void getPerfilVertices();
  void getPerfilCaras();
  void getTapas(int eje);
  void rotarX(float angulo);
  void rotarY(float angulo);
  void rotarZ(float angulo);
};

//*************************************************************************
// clase minecraft
//*************************************************************************

class _minecraft {
private:
  float maximo_brazos;
  float minimo_brazos;
  float maximo_piernas;
  float minimo_piernas;
  float maximo_cabeza;
  float minimo_cabeza;
  float peso;
  float ancho_cuerpo;
  float longitud_cuerpo;
  float altura_brazo;
  float ancho_brazo;
  float longitud_brazo;
  float altura_pierna;
  float ancho_pierna;
  float longitud_pierna;
  vector<float> posicion;
  _cubo *cubo;

public:
  _minecraft();

  void draw_minecraft(int modo, float r1, float g1, float b1, float r2,
                      float g2, float b2);

  void cuerpo(int modo, float r, float g, float b);
  void brazo_derecho(int modo, float r, float g, float b);
  void mano_derecha(int modo, float r, float g, float b);
  void brazo_izquierdo(int modo, float r, float g, float b);
  void mano_izquierda(int modo, float r, float g, float b);
  void pierna_derecha(int modo, float r, float g, float b);
  void pie_derecho(int modo, float r, float g, float b);
  void pierna_izquierda(int modo, float r, float g, float b);
  void pie_izquierdo(int modo, float r, float g, float b);
  void cabeza(int modo, float r, float g, float b);
  void munieco(int modo);
  void aumentar_brazos(int parte);
  void disminuir_brazos(int parte);
  void aumentar_piernas(int parte);
  void disminuir_piernas(int parte);
  void mover_cabeza_dcha(int parte);
  void mover_cabeza_izda(int parte);
};
