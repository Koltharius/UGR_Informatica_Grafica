#include "file_ply_stl.h"
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
}

//*************************************************************************
// clase Ply
//*************************************************************************

_ply::_ply() {}

_ply::_ply(const char *filename) {
  cout << filename << endl;
  vector<float> Vertices;
  vector<int> Caras;

  _file_ply file = _file_ply();
  file.open((char *)filename);
  file.read(Vertices, Caras);
  file.close();

  int totalVertices = Vertices.size();
  int totalCaras = Caras.size();

  _vertex3f v = _vertex3f(0.0, 0.0, 0.0);
  for (int i = 0; i < totalVertices; i = i + 3) {
    v.x = Vertices[i];
    v.y = Vertices[i + 1];
    v.z = Vertices[i + 2];
    vertices.push_back(v);
  }

  _vertex3i c;
  for (int i = 0; i < totalCaras; i = i + 3) {
    c._0 = Caras[i];
    c._1 = Caras[i + 1];
    c._2 = Caras[i + 2];
    caras.push_back(c);
  }
}

_ply &_ply::operator=(const _ply &ply) {
  vertices = ply.vertices;
  caras = ply.caras;
}

//*************************************************************************
// clase Revolucion
//*************************************************************************

_revolucion::_revolucion(_ply &ply, int eje, float numPasos) {
  vertices = ply.vertices;
  caras = ply.caras;
  numPerfil = numPasos;
  float angulo = (2 * M_PI) / numPerfil;
  numVerticesPerfil = vertices.size();

  if (eje == X) {
    rotarX(angulo);
  } else if (eje == Y) {
    rotarY(angulo);
  } else {
    rotarZ(angulo);
  }

  getPerfilVertices();
  getPerfilCaras();
  getTapas(eje);
}

void _revolucion::getPerfilVertices() {
  for (int i = 0; i < numPerfil - 1; i++) {
    for (int j = 0; j < numVerticesPerfil; j++) {
      _vertex3f verticeActual = vertices[i * numVerticesPerfil + j];

      _vertex3f nuevoVertice;
      nuevoVertice = verticeActual * matrizObj;
      vertices.push_back(nuevoVertice);
    }
  }
}

void _revolucion::getPerfilCaras() {
  caras.clear();
  int verticesTotales = vertices.size();
  int verticeAux1, verticeAux2;

  for (int i = 0; i < numPerfil - 1; i++) {
    for (int j = 0; j < numVerticesPerfil - 1; j++) {
      verticeAux1 = i * numVerticesPerfil + j;
      verticeAux2 = i * numVerticesPerfil + j + 1;

      _vertex3i caraAux;
      caraAux._0 = verticeAux1;
      caraAux._1 = verticeAux2;
      caraAux._2 = (verticeAux1 + numVerticesPerfil) % verticesTotales;
      caras.push_back(caraAux);

      caraAux._0 = verticeAux2;
      caraAux._1 = (verticeAux2 + numVerticesPerfil) % verticesTotales;
      caraAux._2 = (verticeAux1 + numVerticesPerfil) % verticesTotales;
      caras.push_back(caraAux);
    }
  }

  for (int i = 0; i < numVerticesPerfil - 1; i++) {
    verticeAux1 = (numPerfil - 1) * numVerticesPerfil + i;
    verticeAux2 = i + 1;

    _vertex3i caraAux;
    caraAux._0 = verticeAux1;
    caraAux._1 = verticeAux2;
    caraAux._2 = verticeAux2 - 1;
    caras.push_back(caraAux);

    caraAux._0 = verticeAux2;
    caraAux._1 = verticeAux1;
    caraAux._2 = verticeAux1 + 1;
    caras.push_back(caraAux);
  }
}

void _revolucion::getTapas(int eje) {
  int verticesTotales = vertices.size();
  _vertex3f verticesTapaArriba = _vertex3f(0.0, 0.0, 0.0);
  _vertex3f verticesTapaAbajo = _vertex3f(0.0, 0.0, 0.0);

  if (eje == X) {
    verticesTapaAbajo.x = vertices[0].x;
    verticesTapaArriba.x = vertices[numVerticesPerfil - 1].x;
  } else if (eje == Y) {
    verticesTapaAbajo.y = vertices[0].y;
    verticesTapaArriba.y = vertices[numVerticesPerfil - 1].y;
  } else {
    verticesTapaAbajo.z = vertices[0].z;
    verticesTapaArriba.z = vertices[numVerticesPerfil - 1].z;
  }

  vertices.push_back(verticesTapaAbajo);
  vertices.push_back(verticesTapaArriba);

  int verticePerfilActualAbajo;
  int verticePerfilActualArriba;
  int verticePerfilSiguienteAbajo;
  int verticePerfilSiguienteArriba;
  int verticeCentralAbajo = vertices.size() - 2;
  int verticeCentralArriba = vertices.size() - 1;

  for (int i = 0; i < numPerfil; i++) {
    verticePerfilActualAbajo = i * numVerticesPerfil;
    verticePerfilSiguienteAbajo =
        ((i + 1) * numVerticesPerfil) % verticesTotales;

    _vertex3i caraTapaAbajo =
        _vertex3i(verticePerfilActualAbajo, verticeCentralAbajo,
                  verticePerfilSiguienteAbajo);
    caras.push_back(caraTapaAbajo);
  }

  for (int i = 0; i < numPerfil; i++) {
    verticePerfilActualArriba = (i * numVerticesPerfil) + numVerticesPerfil - 1;
    verticePerfilSiguienteArriba =
        (((i + 1) * numVerticesPerfil) % verticesTotales) + numVerticesPerfil -
        1;

    _vertex3i caraTapaArriba =
        _vertex3i(verticePerfilActualArriba, verticePerfilSiguienteArriba,
                  verticeCentralArriba);
    caras.push_back(caraTapaArriba);
  }
}

void _revolucion::rotarX(float angulo) {
  matrizObj.matrizIdentidad();
  matrizObj.set(1, 1, cos(angulo));
  matrizObj.set(1, 2, -sin(angulo));
  matrizObj.set(2, 1, sin(angulo));
  matrizObj.set(2, 2, cos(angulo));
}

void _revolucion::rotarY(float angulo) {
  matrizObj.matrizIdentidad();
  matrizObj.set(0, 0, cos(angulo));
  matrizObj.set(0, 2, -sin(angulo));
  matrizObj.set(2, 0, sin(angulo));
  matrizObj.set(2, 2, cos(angulo));
}

void _revolucion::rotarZ(float angulo) {
  matrizObj.matrizIdentidad();
  matrizObj.set(0, 0, cos(angulo));
  matrizObj.set(0, 1, -sin(angulo));
  matrizObj.set(1, 0, sin(angulo));
  matrizObj.set(1, 1, cos(angulo));
}
