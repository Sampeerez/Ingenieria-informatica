// AUTOR: Samuel Pérez López
// FECHA: 25/03/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2


#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main() {
  rational_t a(1, 2), b(3);

  std::cout << "a + b: ";
  (a + b).write();

  std::cout << "b - a: ";
  (b - a).write();

  std::cout << "a * b: ";
  (a * b).write();
  
  std::cout << "a / b: ";
  (a / b).write();
  
  std::cout << std::endl;

  //std::vector<int> move1position(std::vector<int>& v);
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  std::cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << std::endl << std::endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  std::cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << std::endl << std::endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  std::cout << "Multiplicación de matrices A y B: " << std::endl;
  C.write();

  matrix_t<int> M;
  M.read(), M.write();
  std::cout << std::endl << "Rollito examen" << std::endl;
  if (M.Simetrica()) {
    std::cout << "si bby" << std::endl;
  } else {
    std::cout << "nooooooooo" << std::endl;
  }
}