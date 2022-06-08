/**
 *  grafo.h - Plantilla para los alumnos y alumnas de definicion de la clase GRAFO
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos  : 2012-2021
 * 
 * @ASIGNATURA: Optimización
 * @ALUMNO: Samuel Pérez López
 * @CORREO: alu0101481524@ull.edu.es
 * @FECHA: 27/04/2022 
**/

/// GUARDS
#ifndef _GRAPH_H
#define _GRAPH_H

/// Librerías adjuntas
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <unistd.h>

using namespace std;

/// Constantes
const unsigned UERROR = 65000; /// Constante del ERROR 
const int maxint = 1000000; /// El entero máximo. 

/// Definicion de un elemento de la lista de adyacencia
typedef struct {
	unsigned j; /// Nodo
	int      c; /// Atributo para expresar los costes, pesos, las longitudes, las inversiones, etc...
} ElementoLista;

/// definicion del tipo de una lista de adyacencia de un nodo
/// LA_nodo = vector<ElementoLista> 
typedef vector<ElementoLista> LA_nodo;

typedef struct {
        unsigned extremo1, extremo2;
        int peso;
    } AristaPesada;


class GRAFO {
 public:
  /// Constructores
  GRAFO(char nombrefichero[], int &errorapertura);
  /// Destructores
  
  /// /// Operaciones - Métodos 
  void actualizar (char nombrefichero[], int &errorapertura);
  unsigned Es_dirigido(); // devuelve 0 si el grafo es no dirigido y 1 si es dirigido
  void Info_Grafo(); // devuelve información básica del grafo
  void Mostrar_Listas (int l);
  void MostrarCamino(unsigned k, unsigned i, vector<unsigned> pred);
  void RecorridoProfundidad(); //Construye un recorrido en profundidad desde un nodo inicial
  void RecorridoAmplitud(); //Construye un recorrido en amplitud desde un nodo inicial
  void Kruskal(); //Construye un recorrido en amplitud desde un nodo inicial
  void Dijkstra();
	void destroy(); // Destructor del LS, A, y LP, en su caso
  void build (char nombrefichero[85], int &errorapertura); //Crea LS, A y LP en su caso, desde la lectura del fichero
  void dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind); //Recorrido en profundidad recursivo con recorridos enum y postnum
  void bfs_num(unsigned i, vector<LA_nodo>  L, vector<unsigned> &pred, vector<unsigned> &d); //Recorrido en amplitud con c�lculo de pred y d
  /// Variables
  unsigned            dirigido;  // 0 si el grafo es no dirigido y 1 si es dirigido
  unsigned            n;         // Número de NODOS
  unsigned            m;         // Número de ARCOS
  vector<LA_nodo>     LS;        // Lista de adyacencia de los sucesores: es una matriz dónde cada fila es posiblemente de distinto tamaño
  vector<LA_nodo>     LP;        // Lista de adyacencia de los predecesores: es una matriz dónde cada fila es posiblemente de distinto tamaño
};

#endif