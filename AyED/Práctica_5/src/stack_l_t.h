// AUTOR: Samuel Pérez López
// FECHA: 13/05/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  int count_();
  int sum_pair(void) const;
  int sum(void) const;
  void swap12(stack_l_t<T>);
  void inversa(stack_l_t<T>);
  void elimina_impares(stack_l_t<T>);
  void mayores_menores(stack_l_t<T>, int);
  void maximo(stack_l_t<T>);

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


// operaciones
template<class T> 
  void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template<class T> 
  void stack_l_t<T>::pop() {
  assert(!empty());
  delete l_.pop_front();
}

template<class T> 
  const T& stack_l_t<T>::top() const {
  assert(!empty());
  return l_.get_head()->get_data();
}

template<class T> 
  bool stack_l_t<T>::empty() const {
  return l_.empty();
}

// E/S
template<class T> 
  std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

template<class T> 
int stack_l_t<T>::sum_pair() const {
  int suma_pares = 0;

  dll_node_t<T>* aux = l_.get_head();

  while (aux != NULL){
    if (aux->get_data() % 2 == 0) {
      suma_pares += aux->get_data();
    }
    aux = aux->get_next();
  }
  return suma_pares;
}

template<class T>
int stack_l_t<T>::count_() {
  return l_.get_size();
}

template<class T> 
int stack_l_t<T>::sum() const {
  int suma = 0;
  dll_node_t<T>* aux = l_.get_head();

  while (aux != NULL){
    suma += aux->get_data();
    aux = aux->get_next();
  }
  return suma;
}

// Intercambiar el orden de los dos primeros elementos en el top de la pila
template<class T> 
void stack_l_t<T>::swap12(stack_l_t<T> pila) {
  T elem1 = pila.top();
  pila.pop();
  T elem2 = pila.top();
  pila.pop();
  pila.push(elem1);
  pila.push(elem2);
}

//A partir de una pila, generar otra con los elementos en orden inverso, dejando la pila original vacía
template<class T> 
void stack_l_t<T>::inversa(stack_l_t<T> pila) {
  stack_v_t <T> inversa;  // o stack_l_t
  while (!pila.empty()) {
    inversa.push(pila.top());
    pila.pop();
  }
}

// Eliminar todos los elementos de posiciones impares de una pila. Considere que el elemento en el fondo de la pila es impar
template<class T> 
void stack_l_t<T>::elimina_impares(stack_l_t<T> pila) {
  stack_v_t <T> aux;
  while (!pila.empty()) {    // se invierte la pila
    aux.push(pila.top());
    pila.pop();
  }
  while (!aux.empty()) {
    aux.pop();               // elimina elemento impar
    if (!aux.empty()) {
      pila.push(aux.top());  // añade elemento par
      aux.pop();
    }
  }
}

// Para un valor dado, traslade los elementos de una pila a otras dos pilas, 
// una para los mayores o iguales y otra para los menores. Los elementos en las nuevas pilas quedarán en 
// orden inverso al original
template<class T> 
void stack_l_t<T>::mayores_menores(stack_l_t<T> pila, int x) {
  T valor(x);
  stack_v_t <T> mayores;
  stack_v_t <T> menores;
  while (!pila.empty()) {
    if (pila.top() >= valor) mayores.push(pila_vector.top());
    else menores.push(pila_vector.top());
    pila_vector.pop();
  }
}

// Obtener el valor máximo de los elementos de una pila, reemplazando sucesivamente dos elementos del top y por el máximo de ambos
template<class T> 
void stack_l_t<T>::maximo(stack_l_t<T> pila) {
  assert(!pila.empty());     
  T elem1;
  while (!pila.empty()) {
    elem1 = pila.top();   
    pila.pop();
    if (!pila.empty()) {
      T elem2 = pila.top(); 
      pila.pop();
      pila.push(elem1 > elem2 ? elem1 : elem2);
    }                     
  }
  pila.push(elem1);  
}

#endif  // STACKL_H_