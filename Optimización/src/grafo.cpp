/**
 *  grafo.cpp - Plantilla para la implementación de la clase GRAFOS
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos  : 2012-2021
 * 
 * @ASIGNATURA: Optimización
 * @ALUMNO: Samuel Pérez López
 * @CORREO: alu0101481524@ull.edu.es
 * @FECHA: 27/04/2022 
**/

#include "grafo.h"


void GRAFO::destroy() {
  for (unsigned i = 0; i < n; i++) {
    LS[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    }
  }
  LS.clear();
  LP.clear();
}


void GRAFO :: build (char nombrefichero[85], int &errorapertura) {
  ElementoLista     dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile.is_open()) {
    unsigned i, j, k;
    textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
    LS.resize(n);
    for (k = 0; k < m; k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      if (dirigido == true) {
        LP.resize(n);
        dummy.j = j - 1;  //damos los valores a dummy.j y dummy.c
        LS[i - 1].push_back(dummy);  //situamos en la posici�n del nodo i a dummy mediante push_back
        dummy.j = i - 1;
        LP[j - 1].push_back(dummy);
      }
      if (dirigido == false) {
        dummy.j = i - 1;
        LS[j - 1].push_back(dummy);
        if (i != j) {
          dummy.j = j - 1;
          LS[i - 1].push_back(dummy);
        }
      }
    }
  } else {
    errorapertura = 1;
  }
}


GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
  build (nombrefichero, errorapertura);
}


void GRAFO::actualizar (char nombrefichero[85], int &errorapertura) {
  //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
  destroy();
  //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}


unsigned GRAFO::Es_dirigido() {
  return dirigido;
}


void GRAFO::Info_Grafo() {
  cout << "El grafo es: ";
  dirigido == 1 ? cout << "Dirigido" : cout << "No dirigido";
  cout << '\n';
  cout << "El nº de nodos del grafo es: " << n << endl;
  dirigido == 1 ? cout << "El nº de arcos del grafo es: " << m << endl : cout << "El nº de aristas del grafo es: " << m << endl;
}

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) {
  if (i != s)
  {
    MostrarCamino(s,pred[i],pred);
    cout << pred[i]+1 << " - ";
  }
}

void Mostrar_Lista(vector<LA_nodo> L) {
  for(int i=0; i<L.size(); i++){
    cout<<"["<<i+1<<"]: ";
    for(int k=0; k<L[i].size(); k++){
      if(k>0){
	cout<<" - ";
      }
      cout<< L[i][k].j+1;
    }
    if(L[i].size()==0){
      cout<<"Vacío";
    }
    cout<<endl;
  }
}

void GRAFO::Mostrar_Listas (int l) {
  if (dirigido == 1) {
    if (l == -1) {        
      Mostrar_Lista(LP);
    }
    if (l == 1) {       
      Mostrar_Lista(LS);
    }
  } else {                
    if (l == 0) {
      Mostrar_Lista(LS);
    }
  }
}


void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {
	visitado[i] = true;
  prenum[prenum_ind++] = i;
    for (unsigned j = 0; j < L[i].size(); j++) { 
      if (!visitado[L[i][j].j]) {
        dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
      }
    }
    postnum[postnum_ind++] = i;
}

void GRAFO::RecorridoProfundidad() {
  unsigned nodo;
  cout << "Elija el nodo de partida [1-" << n << "]: ";
  cin >> nodo;
  vector<bool> visitado;
  vector<unsigned> prenum, postnum;
  visitado.resize(n, false);
  prenum.resize(n);
  postnum.resize(n);
  unsigned prenum_ind{0}, postnum_ind{0};
  dfs_num(nodo - 1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
  cout << "Nodos en preorden\n";
  cout << "[" << prenum[0] + 1 << "]";
  if (prenum.size() != 0) {
    for (int j = 1; j < prenum_ind; j++) {
      if (prenum[j] != prenum[0]) {
        cout << " -> " << "[" << prenum[j] + 1 << "]";
      }
    }
  }

  cout << "\nNodos en postorden\n";
  cout << "[" << postnum[0] + 1 << "]";
  for (int j = 1; postnum[j] != prenum[0]; j++) {
    cout << " -> [" << postnum[j] + 1 << "]";
  }
  cout << " -> [" << prenum[0] + 1 << "]";
  cout << endl;
}



void GRAFO::bfs_num(unsigned i, vector<LA_nodo>  L, vector<unsigned>& pred, vector<unsigned>& d) {
  vector<bool> visitado; //creamos e iniciamos el vector visitado
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0); 
  d.resize(n, 0);
  pred[i] = i + 1;
  d[i] = 0;

  queue<unsigned> cola; //creamos e inicializamos la cola
  cola.push(i);//iniciamos el recorrido desde el nodo i+1

  //al menos entra una vez al visitar el nodo i+1 y continua hasta que la cola se vacie
  while (!cola.empty()) {   
    unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
    cola.pop(); //lo sacamos de la cola
    //Hacemos el recorrido sobre L desde el nodo k+1 
    for (int counter = 0; counter < L.at(k).size(); ++counter) {
      // Si no está visitado, hacemos lo siguiente
      if (!visitado[L[k][counter].j]) {   
        visitado[L[k][counter].j] = true;         // Lo visitamos
        cola.push(L[k][counter].j);               // Lo metemos en la cola
        pred[L[k][counter].j] = k + 1;            // Le asignamos el predecesor
        d[L[k][counter].j] = d[k] + 1;            // Le calculamos su etiqueta distancia
      }
    }
  }
}


void GRAFO::RecorridoAmplitud() {
  vector<LA_nodo> L{LS};
  vector<unsigned> pred;
  vector<unsigned> d;
  int nodo_inicial;
  cout << "Introduzca el nodo en el que quiere iniciar el recorrido [1 - " << n << "]: ";
  cin >> nodo_inicial;
  cout << "Nodo inicial: " << nodo_inicial << endl << endl;
  // Hacemos el bfs con los datos obtenidos
  bfs_num(nodo_inicial - 1, L, pred, d);
  cout << "Nodos según distancia al nodo inicial en número de aristas:" << endl;
  // Inicializamos un vector con el número de aristas
  vector<vector<unsigned>> distancia(d.size());

  for (size_t i{0}; i < d.size(); i++) {
    // Añadimos la distancia del nodo dentro del vector
    distancia[d[i]].push_back(i);
  }

  for (size_t i{0}; i < distancia.size(); i++) {
    if (distancia[i].empty()) {
      // Si el vector está vacío rompemos el bucle
      break;
    }
    // Imprimimos las distancias de las aristas
    cout << "Distancia " << i << " aristas : ";
    // Recorremos el vector entero y vamos imprimiendo dependiendo de la distancia
    for (size_t j{0}; j < distancia[i].size(); j++) {
      if (i == 0) {
        cout << nodo_inicial;
        break;
      } else {
        cout << distancia[i][j] + 1;
        // Mientras que no sea el último elemento imprimimos : entre medias
          if (j < distancia[i].size() - 1) {
          cout << " : ";
        }
      } 
    }
    cout << '\n';
  }


  cout << "\nLista de predecesores:\n";
  for (int i = 0; i < n; ++i) {
    if (pred[i] == 0) {
      cout << "Predecesor del nodo " << i + 1 << " -> x" << endl;  
    } else {
      cout << "Predecesor del nodo " << i + 1 << " -> " << pred.at(i) << endl;
    }
  }
}


void GRAFO::Kruskal() {
vector <AristaPesada> Aristas; //vector de "AristaPesada", estructura con "unsigned extremo1,extremo2" y "int peso"

    /*Usaremos la busqueda del menor en cada momento, pues es el mejor para Kruskal que no exige tener todas las aristas ordenadas*/
    /*Cargamos todas las aristas de la lista de adyacencia*/

    Aristas.resize(m);

    unsigned k = 0;
    for (unsigned i = 0; i<n; i++){
        for (unsigned j=0; j<LS[i].size();j++){
            if (i < LS[i][j].j) {
                Aristas[k].extremo1 = i;
                Aristas[k].extremo2 = LS[i][j].j;
                Aristas[k++].peso = LS[i][j].c;
                }
        }
    };
    /*Inicializamos el indice a la cabeza del vector*/
    unsigned head = 0;
    AristaPesada AristaDummy; //Para los intercambios en la ordenacion parcial

    /*Inicializamos el contador de aristas en la solución*/
    unsigned a = 0;

    /*Inicializamos el peso de la solucion*/
    unsigned pesoMST = 0;

    /*Inicializamos el registro de componentes conexas: cada nodo está en su compomente conexa*/
    vector <unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0;q < n; q++){
        Raiz[q]=q;
    };

 if(Aristas.size() != 0){ //debemos asegurarnos que el grafo contiene aristas
    /*Comenzamos Kruskal*/
    do {
        /* Implementamos el algoritmo de Kruskal */
        
        int mincoste = Aristas[head].peso;
        for(int i = head; i<m; i++)
         if(Aristas[i].peso <= mincoste){ //cambiamos la arista en la posición head por la de menor coste entre las sobrantes (sobrantes = desde head... hasta n-1)
          mincoste = Aristas[i].peso;
          AristaDummy = Aristas[head];
          Aristas[head] = Aristas[i];
          Aristas[i] = AristaDummy;        
         } //tenemos la arista i-esima de menor coste en la posición "head"
        
        if(Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2]){ //si sus extremos tienen distitas raíces (diferentes componentes conexas):
         int kill = Raiz[Aristas[head].extremo1]; 
          for (unsigned q = 0;q < n; q++)
           if(Raiz[q] == kill)
            Raiz[q] = Raiz[Aristas[head].extremo2]; //todo nodo con "raiz = raiz del extremo1" será cambiada por la "raiz del extremo2"      

        cout << "Arista numero " << a+1 << " incorporada ("<< Aristas[head].extremo1+1 << ", " << Aristas[head].extremo2+1 << "), con peso " << Aristas[head].peso;
        cout << endl; //mostramos la arista incorporada de la forma: "extremo1-extremo2-coste"

        pesoMST += Aristas[head].peso; //actualizamos el peso, añadiéndole la nueva arista incoporada               

        a++; //actualizamos "a" cada vez que se incluya/muestre una arista
        }
        head++; //actualizamos siempre "head" al final del do-while
        } while ((a < (n-1)) && (head < m));

        if (a == (n - 1)){
            cout << "El peso del arbol generador de minimo coste es " << pesoMST << endl;
        }
        else {
            cout << "El grafo no es conexo, y el bosque generador de minimo coste tiene peso " << pesoMST << endl;
        };

  } else //Si el grafo no contiene aristas:
    cout << "El grafo es NO conexo y ademas no posee aristas, por lo que no podemos crear ni siquiera un solo arbol a partir de el mismo." << endl;
}


void GRAFO::Dijkstra() {
  vector<bool> nodoEtiquetado;
  vector<int> d;
  vector<unsigned> pred;
  unsigned s, nodoElegido;
  unsigned predNull = maxint;
  int min; 

  nodoEtiquetado.resize(n, false);
  d.resize(n, maxint);
  pred.resize(n, predNull);

  cout << "Nodo de partida [1 - "<< n << "]: ";
  cin >> s;

  d[--s] = 0; pred[s] = s;

  do {
    min = maxint;

    for (unsigned i = 0; i < n; ++i) { 
      if ((nodoEtiquetado[i] == false) && (d[i] < min)) {
        nodoElegido = i;
        min = d[i];
      }
    }

    if (nodoElegido != predNull) {
      nodoEtiquetado[nodoElegido] = true;
      for (unsigned k = 0; k < LS[nodoElegido].size(); ++k) { 
        if ((nodoEtiquetado[LS[nodoElegido][k].j] == false) && ((d[LS[nodoElegido][k].j]) > (d[nodoElegido] + LS[nodoElegido][k].c))) { 
          d[LS[nodoElegido][k].j] = (d[nodoElegido] + LS[nodoElegido][k].c);
          pred[LS[nodoElegido][k].j] = nodoElegido;
        }
      }
    }
  } while (min < maxint);
  cout << endl;
  
  for (unsigned i = 0; i < n; ++i) { 
    if ((i != s) && (nodoEtiquetado[i] == true)) {
      if (nodoEtiquetado[i] == true) {
        cout << "El camino desde " << s + 1 << " al nodo " << i + 1 << " es : ";
        MostrarCamino(s,i,pred);
        cout << i + 1 << " de longitud " << d[i] << endl;
      } else 
        cout << "No hay camino desde " << s + 1 <<" al nodo " << i + 1 << endl;
  }
}