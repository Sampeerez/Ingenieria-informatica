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

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

template<class T> 
class matrix_t {
 public: 
  matrix_t(const int = 0, const int = 0); 
  ~matrix_t(); 
  void resize(const int, const int); 
  // getters
  int get_m(void) const;
  int get_n(void) const;
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);
  bool Simetrica();
  //LECTURA/ESCRITURA
  void write(std::ostream& = std::cout) const;
  void read(std::istream& = std::cin);

 private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template<class T>
bool matrix_t<T>::matrix_t::Simetrica() {
  if (get_m() != get_n()) return false;
  for (int i = 1; i <= get_m(); i++) {
    for (int j = 1; j <= get_n(); j++) {
      if (v_[pos(i,j)] != v_[pos(j,i)]) return false;
    }
  }
  return true;
}


template<class T>
matrix_t<T>::~matrix_t() {}



template<class T>
void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int matrix_t<T>::get_m() const {
  return m_;
}



template<class T>
inline int matrix_t<T>::get_n() const {
  return n_;
}



template<class T>
T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}



template<class T>
const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}



template<class T>
void matrix_t<T>::write(std::ostream& os) const { 
  os << get_m() << "x" << get_n() << std::endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << std::endl;
  }
  os << std::endl;
}



template<class T>
void matrix_t<T>::read(std::istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III
template<class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());

  for (int i = 1; i <= A.get_m(); ++i) { 
    for (int j = 1; j <= B.get_n(); ++j) {
      at(i,j) = 0; 
      for (int k = 1; k <= B.get_m(); ++k) { 
        at(i,j) = at(i,j) + A(i,k) * B(k,j);
      }
    }
  }
}

template<class T>
bool matrix_t<T>::matrix_t::Simetrica() {
  if (get_m() != get_n()) return false;
  for (int i = 1; i <= get_m(); i++) {
    for (int j = 1; j <= get_n(); j++) {
      if (v_[pos(i,j)] != v_[pos(j,i)]) return false;
    }
  }
  return true;
}


/**

- Indexar:

int i = x, j = y, pos = (i - 1) * n + (j - 1); 

- Recorrer matriz:

for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++)
    cout << A[i][j] << " ";
  cout << endl;
}

- Suma elementos:

int suma = 0;
for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++)
    suma += A[i][j];
}

- Diagonal principal:

for (int i = 0; i < m; i++)
  cout << B[i][i] << " ";
cout << endl;

- Diagonal secundaria:

for (int i = 0; i < m; i++)
  cout << B[i][m - 1 - i] << " ";
cout << endl;

- Submatriz triangular inferior:

for (int i = 0; i < m; i++) {
  for (int j = 0; j <= i; j++)
    cout << B[i][j] << " ";
  cout << endl;
}

- Submatriz triangular superior:

for (int i = 0; i < m; i++) {
  for (int j = i; j < m; j++)
    cout << B[i][j] << " ";
  cout << endl;
}

- Suma de matrices:

for (int i = 0; i < m; i++) {
  for (int j = 0; j < n; j++)
    cout << C[i][j] << " ";
  cout << endl;
}

- Producto de matrices:

for (int i = 0; i < m; i++)
  for (int j = 0; j < p; j++) {
    C[i][j] = 0;
    for (int k = 0; k < n; k++)
      C[i][j] += A[i][k] * B[k][j];
  }

for (int i = 0; i < m; i++) {
  for (int j = 0; j < p; j++)
    cout << C[i][j] << " ";
  cout << endl;
}

**/