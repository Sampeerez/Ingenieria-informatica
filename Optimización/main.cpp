/**
 *  main.cpp - Programa principal
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso.
 *  Cursos  : 2012-2021
 * 
 * @ASIGNATURA: Optimización
 * @ALUMNO: Samuel Pérez López
 * @CORREO: alu0101481524@ull.edu.es
 * @FECHA: 27/04/2022 
**/

#include "grafo.h"

//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
void menu (unsigned dirigido, char &opcion) {
  cout << "Optimización en Grafos - 2021-2022 - Samuel Pérez López" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  if (dirigido == 0) { //Grafo no dirigido
    cout << "i. Mostrar [i]nformacion básica del grafo" << endl;
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
    cout << "k. Realizar un árbol generador de mínimo coste con el algoritmo de [k]ruskal" << endl;
  } else { //Grafo dirigido
    cout << "i. Mostrar [i]nformacion básica del grafo" << endl;
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "d. Buscar el camino mínimo con [d]ijkstra" << endl;
  }
  cout << "q. Finalizar el programa" << endl;
  cout << "\nIntroduce la letra de la acción a ejecutar > ";
  cin >> opcion;
}


/// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un menú inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
  int error_apertura;
  char nombrefichero[85], opcion;
  /// Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
		system("clear");
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
		system("clear");
    cout << "Introduce el nombre completo del fichero de datos" << endl;
		cout << "> ";
    cin >> nombrefichero;
  }

  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
		while (error_apertura == 1) { 
    	cout << "Error en la apertura del fichero: revisa nombre y formato, puedes volver a intentarlo" << endl;
			sleep(2);
			system("clear");
			cout << "Introduce el nombre completo del fichero de datos" << endl; 
			cout << "> ";
    	cin >> nombrefichero;
			GRAFO G(nombrefichero, error_apertura);
		}		
  } 
	if (error_apertura != 1) {
    cout << "Grafo cargado desde el fichero " << nombrefichero << endl;
		sleep(1);
		system("clear");
    do {
      menu(G.Es_dirigido(), opcion);
      switch (opcion) {        
        case 'c' :
					system("clear");
          cout << "Introduce el nombre completo del fichero de datos" << endl;
					cout << "> ";
          cin >> nombrefichero;
					cout << "Grafo cargado desde el fichero " << nombrefichero << endl;
					G.actualizar(nombrefichero, error_apertura);
					sleep(1);
					system("clear");
            if (error_apertura == 1) {
              cout << "Error en la apertura del fichero: revisa nombre y formato, puedes volver a intentarlo" << endl;
            } else {
              cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
            }
					system("clear");
          break;

        case 'i' :
					system("clear");
          G.Info_Grafo();
				  cout << "\n";
          break;
      
        case 'a' :
					system("clear");
          G.Mostrar_Listas(0);
					cout << "\n";
          break;
        
        case 's' :
					system("clear");
          G.Mostrar_Listas(1);
          cout << "\n";
        break;

        case 'p' :
        	system("clear");
          G.Mostrar_Listas(-1);
          cout << "\n";
        break;

        case 'r' :
					system("clear");
          G.RecorridoProfundidad();
          cout << "\n";
        break;

        case 'm' :
					system("clear");
          G.RecorridoAmplitud();
          cout << "\n";
        break;

        case 'k' :
					system("clear");
          G.Kruskal();
          cout << "\n";
        break;

        case 'd' :
					system("clear");
          G.Dijkstra();
          cout << "\n";
        break;
			}
    }
    while (opcion != 'q');
  }
	system("clear");
  cout << "Fin del programa" << endl;
	sleep(1);
	system("clear");
  return(0);
}