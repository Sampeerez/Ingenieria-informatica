// AUTOR: Samuel Pérez López
// FECHA: 13/05/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;
  int count_odd_(void);

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> 
  std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> 
  std::ostream& operator<<(std::ostream& os, const queue_l_t<T>& q) {
  q.write(os);
  return os;
}

// Invertir el orden de los elementos de una cola, usando si es necesario una estructura auxiliar de otro tipo
template <class T>
void reverse(queue_l_t<T> &src)
{
  stack_t<T> aux;  // Se usa una pila auxiliar para invertir el orden
  while (!src.empty())
  {
    aux.push(src.front());  // Se vuelca todo el contenido a la pila
    src.pop();
  }
  while (!aux.empty())
  {
    src.push(aux.top());  // Se devuelven todos los elementos a la cola
    aux.pop();
  }
}

// Separar una cola en dos instancias, tales que una contenga los elementos originalmente en posiciones pares y la otra, 
// aquellos originalmente en posiciones impares. La cola original puede ser una de las instancias o puede quedar vacía
template <class T>
T split(T &src) { // Devuelve una cola nueva y se actualiza la original
  T dst;  // Cola nueva
  int n = src.size();  // Recordamos el tamaño inicial
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) src.push(src.front());  // Los elementos pares se vuelcan en la cola original
    else dst.push(src.front());  // Los elementos impares se vuelcan en la cola nueva
    src.pop();
  }
  return dst;
}

// Fusionar dos colas en una tercera, tomando elementos alternativamente de una y de otra. 
// Si tienen distintos tamaños, los elementos sobrantes se introducen igualmente. Las colas originales quedan vacías
template <class T>
T fuse(T &a, T &b) {
  T ab;
  while (!a.empty() || !b.empty()) {
    if (!a.empty()) {
      ab.push(a.front());
      a.pop();
    }
    if (!b.empty()) {
      ab.push(b.front());
      b.pop();
    }
  }
  return ab;
}

// Eliminar los elementos repetidos de una cola, usando si es necesario una estructura auxiliar de otro tipo.
template <class T>  
void remove_repeated(T &src) {         
  int size = src.size();  // Tamaño original de la cola
  int n = 0;  // Número de elementos no repetidos encontrados hasta el momento
  T *aux = new T[size];  // Estructura auxiliar
  for (int i = 0; i < size; i++) {  // Para cada elemento de la cola
    bool found = false;  // Comprobamos si ya aparece en la estructura auxiliar
    for (int j = 0; j < n && !found; j++)
      if (aux[j] == src.front()) found = true;
    if (!found) {  // Si no está repetido, lo añadimos tanto a la cola como a aux
      aux[n++] = src.front();
      src.push(src.front());
    }
    src.pop();
  }
  delete [] aux;
}


template<class T> 
int queue_l_t<T>::count_odd_(void) {
  int contador = 0;
  dll_node_t<T>* aux = l_.get_head();

  while (aux != NULL){
    if (aux->get_data() % 2 != 0) {
      ++contador;
      std::cout << aux->get_data() << ": " << contador << std::endl;
    } 
    aux = aux->get_next();
  }
  return contador;
}

#endif  // QUEUE_H_
