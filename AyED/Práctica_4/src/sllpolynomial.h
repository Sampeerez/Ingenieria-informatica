// AUTOR: Samuel Pérez López
// FECHA: 16/04/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <cmath> 
#include <vector>

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"


#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
  const SllPolynomial& EliminarMonomioGrado(int);
  const SllPolynomial& EliminarMonomioCoeficiente(double);
  void ImprimeMissings();
  void ordena();
  void ImprimeMenos(int i);
  void SumaConsecutivos();
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for (int i = v.get_size() - 1; i >= 0; --i) {
    SllPolyNode* aux = new SllPolyNode;
    pair_double_t pair_aux{v.at(i), i};  
    aux->set_data(pair_aux);
    if (fabs(pair_aux.get_val()) > eps) {
      push_front(aux);
    }
  }  
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux;
  aux = get_head();
  while (aux->get_next() != NULL) {
    result += (aux->get_data().get_val() * pow(x, aux->get_data().get_inx()));
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool equal = true;
	SllPolyNode* aux1 = get_head();
	SllPolyNode* aux2 = sllpol.get_head();
	while (aux1->get_next() != NULL && equal) {
		if (fabs(aux1->get_data().get_val() - aux2->get_data().get_val()) > eps || fabs(aux1->get_data().get_inx() - aux2->get_data().get_inx()) > eps) {
			return !equal;
		} else {
			aux1 = aux1->get_next();
			aux2 = aux2->get_next();
		}
	}
  return equal;
}


// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {
  SllPolyNode* aux{get_head()};
  SllPolyNode* aux2{sllpol.get_head()};
  SllPolynomial listaAux;
  int contadorAux{0};
  int contadorAux2{0};
  //Contamos la cantidad de elementos de cada lista
  while (aux != NULL){
    contadorAux++;
    aux = aux->get_next();
  }

  while (aux2 != NULL){
    contadorAux2++;
    aux2 = aux2->get_next();
  }
  //Creamos los vectores donde se almacenaran los elementos de la lista
  vector_t<pair_t<double>> vectorSll(contadorAux);
  vector_t<pair_t<double>> vectorSll2(contadorAux2);
  //Rellenamos los vectores
  aux = get_head();
  for(int i{0}; i < vectorSll.get_size(); i++){
    pair_t<double> parAux (aux->get_data().get_val(), aux->get_data().get_inx());
    vectorSll[i] = parAux;
    aux = aux->get_next();
  }

  aux2 = sllpol.get_head();
  for(int i{0}; i < vectorSll2.get_size(); i++){
    pair_t<double> parAux2 (aux2->get_data().get_val(), aux2->get_data().get_inx());
    vectorSll2[i] = parAux2;
    aux2 = aux2->get_next();
  }

  //Realizamos la suma de los elementos con igual indice
  bool introducido = false;
  for(int i{0}; i < vectorSll.get_size(); i++){
    introducido = false;
    for(int j{0}; j < vectorSll2.get_size(); j++){
      if(vectorSll[i].get_inx() == vectorSll2[j].get_inx()){
        pair_double_t parAux(vectorSll[i].get_val() + vectorSll2[j].get_val(), vectorSll[i].get_inx());
        listaAux.push_front(new SllPolyNode (parAux));
        introducido = true;
      }
    }
    if(!introducido){
      pair_double_t parAux(vectorSll[i].get_val(), vectorSll[i].get_inx());
      listaAux.push_front(new SllPolyNode (parAux));
    }
  }
  //introducimos los elementos que no tienen igual indice
  introducido = false;
  int indice = -1;
  SllPolyNode* aux3 = listaAux.get_head();

  for(int i{0}; i < vectorSll2.get_size(); i++){
    introducido = false;
    while(aux3 != NULL){
      if(aux3->get_data().get_inx() == vectorSll2[i].get_inx()){
        introducido = true;
        indice = i;
      }
      aux3 = aux3->get_next();
    }
    if(!introducido){
      pair_double_t parAux(vectorSll2[i].get_val(), vectorSll2[i].get_inx());
      listaAux.push_front(new SllPolyNode (parAux));
    }
    aux3 = listaAux.get_head();
  }

  //Quitamos los ceros resultantes
  aux3 = listaAux.get_head();
  while(!listaAux.empty()){
    pair_t<double> nodoAux = listaAux.pop_front()->get_data();
    if(IsNotZero(nodoAux.get_val(), eps)){
      sllpolsum.push_front(new SllPolyNode (nodoAux));
    }
  }
}

const SllPolynomial& SllPolynomial::EliminarMonomioGrado(int grado) {
  bool inx_encontrado{false};
  auto ptr = this->get_head();
  auto prev = ptr;
  while (ptr != nullptr) {
    if (ptr->get_data().get_inx() == grado) {
      inx_encontrado = true;
      break;
    }
    prev = ptr;
    ptr = ptr->get_next();
  }
  if (inx_encontrado) {
    if (ptr == prev) {
      this->pop_front();
    } else {
      prev->set_next(ptr->get_next());
      delete ptr;
    }
  }
  return *this;
}


void SllPolynomial::ImprimeMenos(int grado) {
  // Aux
  SllPolyNode* aux{get_head()};
  // Calcula longitud de lista
  int longitud{0};
  while (aux != NULL) {
    aux = aux->get_next();
    ++longitud;
  }
  aux = get_head();     // Resetea de nuevo
  for (int i = 0; i < longitud; ++i) {
    if (aux->get_data().get_inx() != grado) {
      double valor{aux->get_data().get_val()};
      int exp{aux->get_data().get_inx()};
      // Imprime
      std::cout << "[ ";
      std::cout << valor << " x^" << exp << " ";
    }
    aux =  aux->get_next();
    std::cout << "] ";
  }
  std::cout << std::endl;
}

void SllPolynomial::SumaConsecutivos() {
  std::cout << "El resultado de las sumas de consecutivos son: " << std::endl;
  // Aux
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    // Valores
    double valor{aux->get_data().get_val()};
    int exp{aux->get_data().get_inx()};
    // Valores siguientes
    if (aux->get_next() != NULL) {
      aux = aux->get_next();
      double valor_next{aux->get_data().get_val()};
      int exp_next{aux->get_data().get_inx()};
      // Resultado
      double result{0};
      if(exp == exp_next - 1) {
        result = valor + valor_next;
      }
      if (result != 0) {
        std::cout << "Coeficientes: " << exp << " + " << exp_next << ": " << result << std::endl;
      }
    } else {
      break;
    } 
  }
}

void SllPolynomial::ImprimeMissings() {
  SllPolyNode* aux{get_head()};
  int longitud{0};
  while (aux != NULL) {
    ++longitud;
    aux = aux->get_next();
  }
  aux = get_head();
  std::vector<int> exponentes;
  for(int i = 0; i <= longitud; ++i) {
    // exponentes.set_val(i, 0);
    exponentes.push_back(0);
  }
  while (aux != NULL) {
    int expo{aux->get_data().get_inx()};
    // exponentes.set_val(expo, 1);
    exponentes[expo] = 1;
    aux = aux->get_next();
  }

  for(int i = 0; i <= longitud; ++i) {
    if (exponentes[i] == 0) {
      std::cout << " " << i;
    }
  }
  std::cout << std::endl;
}

void SllPolynomial::ordena() {
  SllPolyNode* aux{get_head()};
  SllPolynomial result;
  SllPolyNode* aux2{result.get_head()};
  int longitud{0};
  while (aux != NULL) {
    ++longitud;
    aux = aux->get_next();
  }
  aux = get_head();

  int expo{aux->get_data().get_inx()};
  std::vector<int> exponentes;
  for(int i = 0; i <= longitud; ++i) {
    // exponentes.set_val(i, 0);
    exponentes.push_back(0);
  }
  while (aux != NULL) {
    int expo{aux->get_data().get_inx()};
    // exponentes.set_val(expo, expo);
    exponentes[expo] = expo;
    aux = aux->get_next();
  }

  pair_double_t pares;
  bool primero{true};
  for (int i = 0; i < longitud; ++i) {
    if (IsNotZero(exponentes.at(i))) {
      pares.set(exponentes[i], i);   
      // Metemos el valor y el indice de los V que sean distintos de 0
      if (primero) {
        result.push_front(new SllPolyNode (pares));
        // Inserta al principio un nodo, con el valor de "pares"  
        aux = get_head();
        primero = false;
      } else {
        result.insert_after(aux, new SllPolyNode (pares));
        // Inserta despues del puntero aux, un nuevo nodo
        aux = aux->get_next();
        // aux irá apuntando a los nuevos nodos
      }
    }
  }
}


  const SllPolynomial& SllPolynomial::EliminarMonomioCoeficiente(double coeficiente) {
  bool coef_encontrado{false};
  auto ptr = this->get_head();
  auto prev = ptr;
  // Mientras que el puntero no sea null
  while (ptr != nullptr) {
    // Si el valor coincide con el coeficiente introducido, se pone true coef_encontrado
    if (ptr->get_data().get_val() == coeficiente) {
      coef_encontrado = true;
      break;
    }
    // Se pasa al siguiente elemento de la lista
    prev = ptr;
    ptr = ptr->get_next();
  }
  // Si se encontró el coeficiente
  if (coef_encontrado) {
    // Si el ptr coincide con el anterior
    if (ptr == prev) {
      // Se elimina el monomio
      this->pop_front();
    } else {
      // Se asigna al prev su siguiente que será el sigiente de ptr, y se elimina ptr
      prev->set_next(ptr->get_next());
      delete ptr;
    }
  }
  return *this;
}


#endif  // SLLPOLYNOMIAL_H_