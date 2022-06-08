// AUTOR: Samuel Pérez López
// FECHA: 07/04/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol) : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
  void PrintLower(const double x, const double eps = EPS) const;
  void SumIndex() const;
  void SumVal() const;
  void PrintConsecutive() const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << GetSize() << ": [ ";
  bool first{true};
  for (int i{0}; i < GetSize(); i++)
    if (IsNotZero(At(i), eps)) {
      os << (!first ? " + " : "") << At(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < GetSize(); ++i) {
    result += At(i) * pow(x, i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  int size = GetSize() < pol.GetSize() ? GetSize() : pol.GetSize();
  for (int i = 0; i < size; ++i) {
    if (fabs(At(i) - pol.At(i)) > eps){
      return false;
    }
  }
  return true;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << Get_n() << "(" << GetNotZero() << "): [ ";
  bool first{true};
  for (int i{0}; i < GetNotZero(); i++) {
    int inx{At(i).GetInx()};
    os << (!first ? " + " : "") << At(i).GetVal()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < GetNotZero(); ++i) {
    result += At(i).GetVal() * pow(x, At(i).GetInx());
  }
  return result;
}


// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = false;
  if (GetNotZero() != spol.GetNotZero()) {
    differents = true;
    for (int i = 0; i < GetNotZero() && !differents; ++i) {
      if (At(i).GetInx() == spol.At(i).GetInx()) {
        if (IsNotZero(At(i).GetVal() - spol.At(i).GetVal(), eps)) {
          differents = true;
        }
      }
    }
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  int not_zero = 0;
  for (int i = 0; i < pol.GetSize(); ++i) {
    if (pol.At(i) != 0) {
      ++not_zero;
    }
  }
  if (GetNotZero() == not_zero) {
    for (int i = 0; i < GetNotZero(); ++i) {
      if (fabs(At(i).GetVal() - pol.At(i)) < eps) {
        return true;
      }
    }
  } else {
    return false;
  }
  return true;
}

void SparsePolynomial::PrintLower(const double x, const double eps) const {
  for (int i = 0; i < GetNotZero(); ++i) {
    if (x - At(i).GetVal() > eps) {
      std::cout << i << ", ";
    }
  }
  std::cout << std::endl;
}

void SparsePolynomial::SumIndex() const {
  int index{0};
  for (int i = 0; i < GetNotZero(); ++i) {
    index += At(i).GetInx();
  }
  std::cout << index << std::endl;
}

void SparsePolynomial::PrintConsecutive() const {
  for (int i = 0; i < GetNotZero() - 1; ++i) {
    int first_exponent = At(i).GetInx();
    int second_exponent = At(i + 1).GetInx();
    if (first_exponent + 1 == second_exponent)
      std::cout << At(i).GetVal() << ", " << At(i + 1).GetVal() << " ";
  }
  std::cout << std::endl;
}

void SparsePolynomial::SumVal() const { 
  double suma{0};
  for (int i = 0; i < GetNotZero(); ++i) {
    suma += At(i).GetVal();
  }
  std::cout << "La suma de los exponentes del polinomio es: " << suma << std::endl;
}

#endif  // POLYNOMIAL_H_