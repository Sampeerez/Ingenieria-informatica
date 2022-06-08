// AUTOR: Samuel Pérez López
// FECHA: 16/04/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);
  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);
  sll_node_t<T>* search(const T&) const;
  void sort();
  void push_sorted(sll_node_t<T>*);
  T remove_last();
  void swap12();
  void duplicate();
  void erase_evens();
  sll_t<T> move_odds();

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  sll_node_t<T>* head_;
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev, sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

/**
template <class T> void sll_t<T>::sort() {

  sll_node_t<T>* min = head_;
  sll_node_t<T>* max = head_;
  while (min != NULL) {
    
  }
  





  sll_node_t<T>* min = aux;
  while (aux != NULL) {
    if (aux -> get_data() > aux -> get_next() -> get_data()) {
      sll_node_t<T>* node_aux = (pop_front());
      sll_node_t<T>* aux_2 = aux;
      while (aux != NULL) {
        if (aux -> get_data() > aux -> get_next() -> get_data()) {
          aux_2 = aux_2 -> get_next();
          aux_2 -> set_next(node_aux);
          break;
        }
      }
    }
    if (aux -> get_data() < aux -> get_next() -> get_data()) {
      aux = aux -> get_next();
    }
  }
}
**/

template <class T> 
void sll_t<T>::push_sorted(sll_node_t<T>* nodo) {
  if (empty() || nodo -> get_data() <= get_head() -> get_data()) { 
    push_front(nodo);
    return;
  }
  sll_node_t<T>* aux = get_head(); 
  // Dos casos:
  // 1. Si el siguiente a aux es NULL, entonces tengo que insertar n después de aux (final de la lista)
  // 2. Si el siguiente a aux tiene un dato mayor que n, tengo que insertar n después de aux.
  while (aux -> get_next() != NULL && aux -> get_next -> get_data() < nodo -> get_data()) { // Recorro la lista con las propias comparaciones.
    aux = aux -> get_next(); // Si no cumple las condiciones del while, cogemos el siguiente elemento.
  }
  insert_after(aux, nodo); 
}

template <class T> 
T sll_t<T>::remove_last() {
  assert(!empty());
  sll_node_t<T>* aux = get_head();
  sll_node_t<T>* prev = NULL;
  while (aux->get_next() != NULL) { 
    prev = aux;
    aux = aux->get_next();
  }
  sll_node_t<T>* node;
  if (prev == NULL) node = pop_front();
  else node = erase_after(prev);
  T dato = node->get_data();
  delete node; 
  return dato; 
}

template <class T> 
void sll_t<T>::swap12() {
  assert(!empty());
  assert(get_head()->get_next() != NULL);
  push_front(erase_after(get_head()));
}

template <class T> 
void sll_t<T>::duplicate() {
  sll_node_t<T>* aux = get_head();
  while (aux != NULL) {
    insert_after(aux, new sll_node_t<T>(aux -> get_data()));
    aux = aux->get_next()->get_next();
  }
}

template <class T> 
void sll_t<T>::erase_evens() {
  sll_node_t<T>* aux = get_head();
  while (aux != NULL && aux->get_next() != NULL) {
    delete erase_after(aux); 
    aux = aux->get_next(); 
  }
}

// Eliminar los nodos de posiciones impares de una lista trasladándolos en orden inverso a una nueva lista
template <class T>
sll_t<T> sll_t<T>::move_odds() {
  sll_t<T> odds_list;
  sll_node_t<T>* aux = get_head();
  if (!empty()) {
    odds_list.push_front(pop_front());
    aux = get_head();
  }
  while (aux != NULL && aux->get_next() != NULL) {
    odds_list.push_front(erase_after(aux));
    aux = aux->get_next(); 
  }
  return odds_list; 
}

#endif  // SLLT_H_
