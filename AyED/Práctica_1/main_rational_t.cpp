/**
 * AUTOR: Samuel Pérez López
 * FECHA: 25/02/2022
 * EMAIL: alu0101481524@ull.edu.es - samperezlopez@gmail.com
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 1
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
 *              "C++ Programming Style Guidelines"
 *              https://geosoft.no/development/cppstyle.html
 * COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t
**/

#include "rational_t.hpp"

int main() {
  Rational a(1, 2), b(3), c;

  std::cout << "This program operates and calculates rational numbers.";
  std::cout << "a.value()= " << a.Value() << std::endl;
  std::cout << "b.value()= " << b.Value() << std::endl;
  std::cout << "c.value()= " << c.Value() << std::endl;

  std::cout << "a: ";
  a.Write();
  std::cout << "b: ";
  b.Write();
  c.Read();
  std::cout << "c: ";
  c.Write();

  Rational x(1, 3), y(2, 3);
  x.Write();
  y.Write();

  std::cout << "x == y? " << (x.IsEqual(y) ? "true" : "false") << std::endl;
  std::cout << "x < y? " << (x.IsGreater(y) ? "true" : "false") << std::endl;
  std::cout << "x > y? " << (x.IsLess(y) ? "true" : "false") << std::endl;
  std::cout << "a + b: ";

  a.Add(b).Write();
  std::cout << "b - a: ";
  b.Substract(a).Write();
  std::cout << "a * b: ";
  a.Multiply(b).Write();
  std::cout << "a / b: ";
  a.Divide(b).Write();

  std::cout << "El número racional: " << std::endl; c.Write();
  std::cout << (c.is_integer()? "Entero" : "No entero") << std::endl;
  
  return 0;
}