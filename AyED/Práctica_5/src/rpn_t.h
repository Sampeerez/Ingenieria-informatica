// AUTOR: Samuel Pérez López
// FECHA: 13/05/2022
// EMAIL: alu0101481524@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl << "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');

  int operando_1, operando_2;
  operando_1 = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << operando_1 << std::endl;
  
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') { //solo sacamos un segundo operando para operaciones de aridad 2
    operando_2 = stack_.top(); 
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << operando_2 << std::endl;
  } 
  
   switch (c) {
      case '+':
        stack_.push(operando_2 + operando_1);
        break;
      case '-':
        stack_.push(operando_2 - operando_1);
        break;
      case '*':
        stack_.push(operando_2 * operando_1);
        break;
      case '/':
        stack_.push(operando_2 / operando_1);
        break;
      case '^':
        stack_.push(std::pow(operando_2, operando_1));
        break;
      case 'r':
        stack_.push(std::sqrt(operando_1));
        break;
      case 'l':
        stack_.push(std::log2(operando_1));
        break;
      case 'c':
        stack_.push(operando_1 * operando_1);
        break;
    }
  std::cout << "   Metemos en la pila el resultado: " << stack_.top() << std::endl;
}
 
#endif  // RPNT_H_