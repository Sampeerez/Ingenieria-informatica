// AUTOR: Samuel Pérez López
// FECHA: 13/05/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);
  dll_node_t<T>* erase(dll_node_t<T>*);
  void insert_after(dll_node_t<T>*, dll_node_t<T>* );
  void swap_lasts();
  void duplicate_end();
  void erase_odds();
  dll_t<T> move_evens();

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


// destructor
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

// E/S
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

template <class T>
void dll_t<T>::insert_after(dll_node_t<T>* prev, dll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);
  n->set_next(prev->get_next());  // Sig. de n apunta a sig. de prev
  prev->set_next(n);              // Siguiente de prev apunta a n
  n->set_prev(prev);              // Previo de n apunta a prev
  if (n->get_next() != NULL)      // Si n no es el último nodo,
    n->get_next()->set_prev(n);   // Previo de sig. de n apunta a n
  else
    tail_ = n;  // n último nodo
  sz_++;
}

template <class T>
void dll_t<T>::swap_lasts() {
  assert(!empty());
  assert(get_head()->get_next() != NULL);
  // Sacar el penúltimo y meterlo por la cola
  push_back(erase(get_tail()->get_prev()));
}

template <class T>
void dll_t<T>::duplicate_end() {
  if (empty())
    return;
  dll_node_t<T>* aux = get_head();
  dll_node_t<T>* end = get_tail();
  while (aux->get_prev() != end)  // Recorrer toda la lista
  { // Insertar un nodo por la cola duplicando sus campo dato
    push_back(new dll_node_t<T>(aux->get_data()));
    aux = aux->get_next();  // Adelantar aux
  }
}

template <class T>
void dll_t<T>::erase_odds() {
  dll_node_t<T>* aux = get_head();
  while (aux != NULL)  // Recorrer toda la lista
  {
    dll_node_t<T>* next = aux->get_next();
    delete erase(aux);  // Borrar el aux y liberarlo
    aux = next != NULL ? next->get_next() : NULL;
    // aux avanza saltándose next. Si next es NULL, termina
  }
}

template <class T>
dll_t<T> dll_t<T>::move_evens() {
  dll_t<T> even_list;
  dll_node_t<T>* aux = get_head();
  while (aux != NULL && aux->get_next() != NULL)
  { // Recorrer toda la lista
    aux = aux->get_next();  // aux en posición par
    dll_node_t<T>* next = aux->get_next();  // next en impar
    even_list.push_back(erase(aux));  // Mover el aux
    aux = next;  // Posicionar aux en siguiente impar
  }
  return even_list;  // Retornar lista de impares
}


#endif  // DLLT_H_