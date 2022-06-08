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
#include <cmath>

# define EPSILON 1e-6

class rational_t {
 public: 
  rational_t(const int = 0, const int = 1); //constructor
  ~rational_t() {} //destructor
  // getters
  int get_num() const;
  int get_den() const;
  // setters
  void set_num(const int);
  void set_den(const int);
  double value(void) const; 
  rational_t opposite(void) const; 
  rational_t reciprocal(void) const; 
  // methods
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;
  //LECTURA/ESCRITURA
  void write(std::ostream& os = std::cout) const;
  void read(std::istream& is = std::cin);
 private: 
  int num_, den_;
};

std::ostream& operator<<(std::ostream& os, const rational_t&);
std::istream& operator>>(std::istream& is, rational_t&);

// FASE I
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);