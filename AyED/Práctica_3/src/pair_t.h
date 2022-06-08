// AUTOR: Samuel Pérez López
// FECHA: 07/04/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T GetVal(void) const;
  int GetInx(void) const;
  void Set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T val_;
  int inx_;
};


template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

template<class T> pair_t<T>::~pair_t() {}

template<class T> void pair_t<T>::Set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

template<class T> int pair_t<T>::GetInx() const {
  return inx_;
}

template<class T> T pair_t<T>::GetVal() const {
  return val_;
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_