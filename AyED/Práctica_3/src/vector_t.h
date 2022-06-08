// AUTOR: Samuel Pérez López
// FECHA: 07/04/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {
 public:
  // constructores
  vector_t(const int = 0);
  vector_t(const vector_t&); // constructor de copia

  // operador de asignación
  vector_t<T>& operator=(const vector_t<T>&);

  // destructor
  ~vector_t();
  
  // getters
  T GetVal(const int) const;
  int GetSize(void) const;
  
  // setters
  void SetVal(const int, const T);
  
  // getters-setters
  T& At(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& At(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void Resize(const int);
  
  // E/S
  void Read(std::istream& = std::cin);
  void Write(std::ostream& = std::cout) const;

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

// constructor de copia
template<class T> vector_t<T>::vector_t(const vector_t<T>& w)
    : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  Resize(w.GetSize());
  for (int i = 0; i < GetSize(); i++)
    At(i) = w.At(i);
  
  return *this;
}

template<class T> vector_t<T>::~vector_t() {
  destroy();
}

template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T> void vector_t<T>::Resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template<class T> inline T vector_t<T>::GetVal(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> inline int vector_t<T>::GetSize() const {
  return sz_;
}

template<class T> void vector_t<T>::SetVal(const int i, const T d) {
  assert(i >= 0 && i < GetSize());
  v_[i] = d;
}

template<class T> T& vector_t<T>::At(const int i) {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> T& vector_t<T>::operator[](const int i) {
  return At(i);
}

template<class T> const T& vector_t<T>::At(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template<class T> const T& vector_t<T>::operator[](const int i) const {
  return At(i);
}

template<class T> void vector_t<T>::Read(std::istream& is) {
  is >> sz_;
  Resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> At(i);
}

template<class T> void vector_t<T>::Write(std::ostream& os) const {
  os << GetSize() << ": [ ";
  for (int i = 0; i < GetSize(); i++)
    os << At(i) << (i != GetSize() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) {
  v.Read(is);
  return is;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const vector_t<T>& v) {
  v.Write(os);
  return os;
}

#endif  // VECTORT_H_