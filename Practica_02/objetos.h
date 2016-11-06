//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "vertex.h"
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
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

  vector<_vertex3i> caras;
};

//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo : public _triangulos3D {
public:
  _cubo(float tam);
};

//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide : public _triangulos3D {
public:
  _piramide(float tam, float al);
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
  _ply &operator=(const _ply &ply);
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
  _revolucion(_ply &ply, int eje, float numPasos);
  void getPerfilVertices();
  void getPerfilCaras();
  void getTapas(int eje);
  void rotarX(float angulo);
  void rotarY(float angulo);
  void rotarZ(float angulo);
};
