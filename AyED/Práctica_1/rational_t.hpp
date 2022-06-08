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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

double const kEpsilon = 1e-6;

class Rational {
 public:
  // Constructor.
  Rational() : numerator_{0}, denominator_{1} {};
  Rational(int numerator) : numerator_{numerator}, denominator_{1} {}
  Rational(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator} {}
  // Destructor.
  ~Rational() {}
  // Getters
  int GetNumerator() const { return numerator_; };
  int GetDenominator() const { return denominator_; };
  // Setters
  void SetNumerator(const int numerator) { numerator_ = numerator; };
  void SetDenominator(const int denominator) { denominator_ = denominator; };
  // Methods
  double Value() const;
  void Simplify();
  bool IsEqual(const Rational&, const double precision = kEpsilon) const;
  bool IsGreater(const Rational&, const double precision = kEpsilon) const;
  bool IsLess(const Rational&, const double precision = kEpsilon) const;
  bool is_integer(void);
  Rational Add(const Rational&);
  Rational Substract(const Rational&);
  Rational Multiply(const Rational&);
  Rational Divide(const Rational&);
  
  void Write(std::ostream& = std::cout) const;
  void Read(std::istream& = std::cin);
  
 private:
  int numerator_;
  int denominator_;
};

int gcd(long long number_1, long long number_2);