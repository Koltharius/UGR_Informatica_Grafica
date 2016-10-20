#include "objetos.h"

//*************************************************************************
// clase punto
//*************************************************************************
_puntos3D::_puntos3D() {}

void _puntos3D::draw_puntos(float r, float g, float b, int grosor) {
  glColor3f(r, g, b);
  glPointSize(grosor);
  glBegin(GL_POINTS);
  for (int i = 0; i < vertices.size(); i++) {
    glVertex3f(vertices[i]._0, vertices[i]._1, vertices[i]._2);
  }
  glEnd();
}

//*************************************************************************
// clase triángulo
//*************************************************************************

_triangulos3D::_triangulos3D() {}

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor) {
  glColor3f(r, g, b);
  glLineWidth(grosor);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < caras.size(); i++) {
    int v1 = caras[i]._0;
    int v2 = caras[i]._1;
    int v3 = caras[i]._2;
    glVertex3f(vertices[v1]._0, vertices[v1]._1, vertices[v1]._2);
    glVertex3f(vertices[v2]._0, vertices[v2]._1, vertices[v2]._2);
    glVertex3f(vertices[v3]._0, vertices[v3]._1, vertices[v3]._2);
  }
  glEnd();
}

void _triangulos3D::draw_solido(float r, float g, float b) {
  glColor3f(r, g, b);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < caras.size(); i++) {
    int v1 = caras[i]._0;
    int v2 = caras[i]._1;
    int v3 = caras[i]._2;
    glVertex3f(vertices[v1]._0, vertices[v1]._1, vertices[v1]._2);
    glVertex3f(vertices[v2]._0, vertices[v2]._1, vertices[v2]._2);
    glVertex3f(vertices[v3]._0, vertices[v3]._1, vertices[v3]._2);
  }
  glEnd();
}

// Test
void _triangulos3D::draw_solido_colores() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < caras.size(); i++) {
    glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);
    int v1 = caras[i]._0;
    int v2 = caras[i]._1;
    int v3 = caras[i]._2;
    glVertex3f(vertices[v1]._0, vertices[v1]._1, vertices[v1]._2);
    glVertex3f(vertices[v2]._0, vertices[v2]._1, vertices[v2]._2);
    glVertex3f(vertices[v3]._0, vertices[v3]._1, vertices[v3]._2);
  }
  glEnd();
}
// Fin test

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2,
                                        float g2, float b2) {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < caras.size(); i++) {
    if (i & 1) {
      glColor3f(r1, g1, b1);
    } else {
      glColor3f(r2, g2, b2);
    }
    int v1 = caras[i]._0;
    int v2 = caras[i]._1;
    int v3 = caras[i]._2;
    glVertex3f(vertices[v1]._0, vertices[v1]._1, vertices[v1]._2);
    glVertex3f(vertices[v2]._0, vertices[v2]._1, vertices[v2]._2);
    glVertex3f(vertices[v3]._0, vertices[v3]._1, vertices[v3]._2);
  }
  glEnd();
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam) {

  // Vertices
  _vertex3f v1 = _vertex3f(-tam, -tam, -tam);
  _vertex3f v2 = _vertex3f(tam, -tam, -tam);
  _vertex3f v3 = _vertex3f(tam, tam, -tam);
  _vertex3f v4 = _vertex3f(-tam, tam, -tam);
  _vertex3f v5 = _vertex3f(-tam, -tam, tam);
  _vertex3f v6 = _vertex3f(tam, -tam, tam);
  _vertex3f v7 = _vertex3f(tam, tam, tam);
  _vertex3f v8 = _vertex3f(-tam, tam, tam);

  vertices.push_back(v1);
  vertices.push_back(v2);
  vertices.push_back(v3);
  vertices.push_back(v4);
  vertices.push_back(v5);
  vertices.push_back(v6);
  vertices.push_back(v7);
  vertices.push_back(v8);

  // Caras
  _vertex3i c1 = _vertex3i(0, 3, 1);
  _vertex3i c2 = _vertex3i(1, 3, 2);
  _vertex3i c3 = _vertex3i(1, 2, 5);
  _vertex3i c4 = _vertex3i(5, 2, 6);
  _vertex3i c5 = _vertex3i(5, 6, 4);
  _vertex3i c6 = _vertex3i(4, 6, 7);
  _vertex3i c7 = _vertex3i(4, 7, 0);
  _vertex3i c8 = _vertex3i(0, 7, 3);
  _vertex3i c9 = _vertex3i(4, 0, 5);
  _vertex3i c10 = _vertex3i(5, 0, 1);
  _vertex3i c11 = _vertex3i(3, 7, 2);
  _vertex3i c12 = _vertex3i(2, 7, 6);

  caras.push_back(c1);
  caras.push_back(c2);
  caras.push_back(c3);
  caras.push_back(c4);
  caras.push_back(c5);
  caras.push_back(c6);
  caras.push_back(c7);
  caras.push_back(c8);
  caras.push_back(c9);
  caras.push_back(c10);
  caras.push_back(c11);
  caras.push_back(c12);

  // Colores
  _vertex3f cl1 = _vertex3f(0, 0, 0);
  _vertex3f cl2 = _vertex3f(0, 0, 1);
  _vertex3f cl3 = _vertex3f(0, 1, 0);
  _vertex3f cl4 = _vertex3f(0, 1, 1);
  _vertex3f cl5 = _vertex3f(1, 0, 0);
  _vertex3f cl6 = _vertex3f(1, 0, 1);
  _vertex3f cl7 = _vertex3f(1, 1, 0);
  _vertex3f cl8 = _vertex3f(0.7, 0.5, 0.3);
  _vertex3f cl9 = _vertex3f(0.5, 0.5, 0.5);
  _vertex3f cl10 = _vertex3f(0.5, 0, 0.5);
  _vertex3f cl11 = _vertex3f(0.5, 0.5, 0);
  _vertex3f cl12 = _vertex3f(0, 0, 0.5);

  colores_caras.push_back(cl1);
  colores_caras.push_back(cl2);
  colores_caras.push_back(cl3);
  colores_caras.push_back(cl4);
  colores_caras.push_back(cl5);
  colores_caras.push_back(cl6);
  colores_caras.push_back(cl7);
  colores_caras.push_back(cl8);
  colores_caras.push_back(cl9);
  colores_caras.push_back(cl10);
  colores_caras.push_back(cl11);
  colores_caras.push_back(cl12);
}

//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al) {
  // Vertices
  _vertex3f v1 = _vertex3f(tam, -tam, tam);
  _vertex3f v2 = _vertex3f(-tam, -tam, tam);
  _vertex3f v3 = _vertex3f(0, -tam, -tam);
  _vertex3f v4 = _vertex3f(0, al, 0);

  vertices.push_back(v1);
  vertices.push_back(v2);
  vertices.push_back(v3);
  vertices.push_back(v4);

  // Caras
  _vertex3i c1 = _vertex3i(1, 2, 3);
  _vertex3i c2 = _vertex3i(1, 0, 2);
  _vertex3i c3 = _vertex3i(2, 0, 3);
  _vertex3i c4 = _vertex3i(3, 0, 1);

  caras.push_back(c1);
  caras.push_back(c2);
  caras.push_back(c3);
  caras.push_back(c4);

  // Colores
  _vertex3f cl1 = _vertex3f(0, 0, 1);
  _vertex3f cl2 = _vertex3f(0, 1, 0);
  _vertex3f cl3 = _vertex3f(0, 1, 1);
  _vertex3f cl4 = _vertex3f(1, 0, 0);

  colores_caras.push_back(cl1);
  colores_caras.push_back(cl2);
  colores_caras.push_back(cl3);
  colores_caras.push_back(cl4);
}
