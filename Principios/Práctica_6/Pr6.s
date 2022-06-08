# ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
# =====================================================================================
#    █          • Nombre Archivo:    Práctica_6.s                                 █
#    █          • Autores:           Samuel Pérez López - Valeria Bosch Pérez     █
#    █          • Fecha:             13/05/2022                                   █
#    █          • Asignatura:        Principios de Computadores                   █
#    █          • Lenguaje:          MIPS                                         █
# =====================================================================================
# ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

# PRACTICA 6. PRINCIPIO DE COMPUTADORES.

# ╔═══════════════╗
# ║ CÓDIGO EN C++ ║
# ╚═══════════════╝
# #include <iostream>
# #include <string>

# using namespace std;

# const int maxElementos = 400;

# int matriz[] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
#                 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
#                 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
#                 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
#                 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
#                 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
#                 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
#                 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
#                 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
#                 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
#                 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
#                 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
#                 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
#                 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
#                 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
#                 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
#                 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
#                 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
#                 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
#                 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499 };

# // FUNCIONES

# // --- SWAP ---

# void Swap(int* elemento_1, int* elemento_2) {
#    int valor_1 = *elemento_1;
#    int valor_2 = *elemento_2;
#    *elemento_2 = valor_1;
#    *elemento_1 = valor_2;
# }

# // --- INVERTIR RECURSIVA ---

# void Invertir(int* primero, int separacion, int sz)  {
#    if (sz < 1) {
#        return;
#    }
#    Swap(primero, primero + sz * separacion - separacion);
#    primero += separacion;
#    sz -= 2;
#    Invertir(primero, separacion, sz);
# }

# // --- TRASPUESTA ---

# void Traspuesta(int* m, int num_fil) {
#    for (int i = 0; i < num_fil; ++i) {
#        for (int j = i; j < num_fil; ++j) {
#            Swap(&m[i * num_fil + j], &m[j * num_fil + i]);
#        }
#    }
# }


# // --- IMPRIME MATRIZ ---

# void PrintMatriz (const int* m, const int num_filas, const int num_columnas) {
#    for (int i = 0; i < num_filas; ++i) {
#        for (int j = 0; j < num_columnas; ++j) {
#            cout << *(m + num_columnas * i + j) << " ";
#        }
#        cout << endl;
#    }
# }


# // PROGRAMA PRINCIPAL 
#             
# int main() {
#  int filas = 20;
#  int columnas = 20;
#  int opcion;
#  cout << "Practica 6 de Principios de Computadores. Matrices con funciones.\n";
#  while(true) {
#    cout << "Matriz de " << filas << " x " << columnas << endl;
#    // FUNCION IMPRIME MATRIZ
#    PrintMatriz(matriz, filas, columnas);
#    // MENU
#    cout << "(1) Cambiar dimensiones\n";
#    cout << "(2) Obtener elemento [i,j]\n";
#    cout << "(3) Invertir fila\n";
#    cout << "(4) Invertir columna\n";
#    cout << "(5) Traspuesta\n";
#    cout << "(0) Salir\n";
#    cout << "Introduzca opción: ";
#    cin >> opcion;
#    int filas_aux, columnas_aux;
#    switch (opcion) {
#        case 0:
#            system("clear");
#            cout << "-- Cerrando programa --" << endl;
#            return 0;
#        case 1:  // REDIMENSIONAR
#            system("clear");
#            cout << "--- REDIMENSIONAR ---\n";
#            int filas_nuevas, columnas_nuevas;
#            cout << "Introduzca el número de filas: ";
#            cin >> filas_nuevas;
#            cout << "Introduzca el número de columnas: ";
#            cin >> columnas_nuevas;
#            if (filas_nuevas * columnas_nuevas > maxElementos) {
#                cout << "Error: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
#                exit(EXIT_FAILURE);
#            }
#            filas = filas_nuevas;
#            columnas = columnas_nuevas;
#            break;
#        case 2:  // OBTENER ELEMENTO (i,j)
#            system("clear");
#            cout << "--- OBTENER ELEMENTO (i, j) ---\n";
#            cout << "Introduzca la fila del elemento: ";
#            cin >> filas_aux;
#            if (filas_aux < 0) {
#               cout << "Error. Posicion i incorrecta";
#               return 0;
#            }
#            cout << "Introduzca la columna del elemento: ";
#            cin >> columnas_aux;
#            if (columnas_aux < 0) {
#               cout << "Error. Posicion j incorrecta";
#               return 0;
#            }
#            cout << "El elemento escogido es: " << matriz[filas_aux * columnas + columnas_aux] << endl;
#            break;
#        case 3:  // INVERTIR FILA
#            system("clear");
#            cout << "--- INVERTIR FILA ---\n";
#            cout << "Introduzca la fila que quiera invertir: ";
#            cin >> filas_aux;
#            if (filas_aux < 0) {
#                cout << "Error: dimension incorrecta. Numero de filas incorrecto.\n";
#                return 0;
#            }
#            Invertir(matriz + filas_aux * columnas, 1, columnas);
#            break;
#        case 4:  // INVERTIR COLUMNA
#            system("clear");
#            cout << "--- INVERTIR COLUMNA ---\n";
#            cout << "Introduzca la columna que quiera invertir: ";
#            cin >> columnas_aux;
#            if (columnas_aux < 0) {
#                cout << "Error: dimension incorrecta. Numero de columnas incorrecto.\n";
#                return 0;
#            }
#            Invertir(matriz + columnas_aux, columnas, filas);
#            break;
#        case 5:  // TRASPUESTA
#            system("clear");
#            if (filas == columnas) {
#                cout << "--- TRASPUESTA ---\n";
#                Traspuesta(matriz, filas);
#            } else {
#                cout << "Error: No se puede calcular la traspuesta en matrices no cuadradas.\n";
#            }
#            break;
#        default:
#            cout << "Error. Opcion incorrecta\n";
#            return 0;
#    }
#  }
# }


# ╔════════════════╗
# ║ CÓDIGO EN MIPS ║
# ╚════════════════╝

maximoElementos=400 # numero de enteros maximo reservado para la matriz 1600 bytes
size=4 # bytes que ocupa un entero

    .data
mat:   .word   100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119
       .word   120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139
       .word   140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159
       .word   160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179
       .word   180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199
       .word   200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219
       .word   220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239
       .word   240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259
       .word   260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279
       .word   280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299
       .word   300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319
       .word   320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339
       .word   340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359
       .word   360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379
       .word   380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399
       .word   400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419
       .word   420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439
       .word   440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459
       .word   460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479
       .word   480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499
       

nfil:   .word   20 # nuemro de filas de la matriz
ncol:   .word   10 # numero de columnas de la matriz
separador:  .asciiz "  " # separador entre numeros
newline:    .asciiz "\n"
menu:       .ascii  "\n(1) Cambiar dimensiones\n(2) Obtener elemento [i,j]\n"
            .asciiz "(3) Invertir fila\n(4) Invertir columna\n(5) Traspuesta\n(0) Salir\nElija opcion: "
error_op:   .asciiz "\nError: opcion incorrecta.\n"
msg_nfilas: .asciiz "\nIntroduzca numero de filas: "
msg_ncols:  .asciiz "\nIntroduzca numero de columnas: "
error_nfilas:   .asciiz "\nError: dimension incorrecta. Numero de fila incorrecto.\n"
error_ncols:    .asciiz "\nError: dimension incorrecta. Numero de columna incorrecto.\n"
error_dime:     .asciiz "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n"
msg_i:      .asciiz "\nObtener el elemento [i,j]. Introduzca indice i (primera fila indice 0): "
msg_j:      .asciiz "\nObtener el elemento [i,j]. Introduzca indice j (primera columna indice 0): "
msg_f:      .asciiz "\nInvertir la fila [i,*]. Introduzca indice i (primera fila indice 0): "
msg_c:      .asciiz "\nInvertir la columna [*,j]. Introduzca indice j (primera columna indice 0): "
msg_elemento:   .asciiz "\nElemento obtenido en la posicion indicada: "
titulo:     .asciiz "\nPractica 6 de Principios de Computadores. Matrices con funciones.\n"
header:     .asciiz "Matriz con dimension "
x:          .asciiz " x "
msg_fin:    .asciiz "\nFin del programa.\n"
error_no_cuadrada:  .asciiz "\nError: No se puede calcular la traspuesta en matrices no cuadradas.\n"

    .text

# ╔═════════════╗
# ║  VARIABLES  ║
# ╚═════════════╝
# -- IMPORTANTE --
# $s0 = Direccion Matriz
# $s6 = num_fil
# $s7 = num_col
# $s5 = max_elementos
# -- OPCIONES --
# $s1 = todos valores

#  
# ╔══════════════╗
# ║     MAIN     ║
# ╚══════════════╝

main:
# ║ IMPRIME EL TITULO ║
# cout << "Práctica 6 de Principio de Computadores. Matrices en C++\n";
  la $a0,titulo
	li $v0,4    
	syscall
  la $a0,newline
	li $v0,4    
	syscall

# ║ DECLARACIÓN DE VARIABLES ║
# - MAXIMO ELEMENTOS
  li $s5,400
# - NUMERO DE FILAS Y COLUMNAS
  lw $s6,nfil
  lw $s7,ncol
# - OPCIONES DEL MENU
  li $s1,0    # opcion(0) -> Salir del programa
  li $t0,1    # opcion(1) -> Redimensionar
  li $s2,2    # opcion(2) -> Obtener elemento
  li $s3,3    # opcion(3) -> Invertir fila
  li $s4,4    # opcion(4) -> Invertir columna
  li $t1,5    # opcion(5) -> Traspuesta
  la $s0,mat      # Dirección de la matriz guardada en $s0

  move $a0,$s0
  move $a1,$s6
  move $a2,$s7

imprime:
# ║ IMPRESIÓN DE LA MATRIZ ║
  jal ImprimirMatriz

# ╔══════════╗
# ║   MENÚ   ║
# ╚══════════╝
Menu:
  la $a0,newline
	li $v0,4
	syscall
# ║ IMPRESIÓN DE LAS OPCIONES DEL MENÚ ║
# cout << menu << endl << "> ";
  la $a0,menu
	li $v0,4
	syscall

# ║ LEEMOS LA OPCION ESCOGIDA POR EL USUARIO ║
# cin >> opcion;
  li $v0,5
  syscall
  move $s1,$v0

# ║ SEGÚN LA OPCION ESCOGIDA SALTAR A LA ETIQUETA ║
# switch (opcion) {
#     case 0: SALIR DEL PROGRAMA ...
#     case 1: REDIMENSIONAR ... 
#     case 2: OBTENER ELEMENTO ...
#     case 3: INVERTIR FILA ...
#     case 4: INVERTIR COLUMNA ...
  beq $s1,$zero,FinPrograma       # (0) SALIR DEL PROGRAMA
  beq $s1,1,Redimensionar     # (1) REDIMENSIONAR
  beq $s1,2,ObtenerElemento   # (2) OBTENER ELEMENTO
  beq $s1,3,InvertirFilas     # (3) INVERTIR FILA
  beq $s1,4,InvertirColumna  # (4) INVERTIR COLUMNA
  beq $s1,5,MatrizTraspuesta        # (5) TRASPUESTA
# ║ SI NO SE DA NINGUNA DE ESTAS OPCIONES DARÁ UN ERROR ║
# default:
#     cout << "Error. Opcion incorrecta\n";
#     return 0;
  b ErrorOpcion   

# ╔════════════════════════════════╗
# ║ FUNCIÓN IMPRESIÓN DE LA MATRIZ ║
# ╚════════════════════════════════╝
# PASAR ARGUMENTOS:
#   - Direccion matriz ($s0) = $a0
#   - num_fil ($s6) = $a1
#   - num_col ($s7) = $a2

ImprimirMatriz:
# ║ GUARDAMOS LOS VALORES DE LOS PARÁMETROS EN SALVADOS ║
  move $s0,$a0
  move $s6,$a1
  move $s7,$a2
# ║ HACEMOS PUSH A LA PILA DE LOS ELEMENTOS GUARDADOS ║
  sub $sp,$sp,12
  sw $s0,0($sp) 
  sw $s6,4($sp)
  sw $s7,8($sp)
# ║ IMPRIMIMOS EL VECTOR DE TAL FORMA COMO MATRIZ ║
# cout << "Matriz de " << num_fil << " x " << num_col << endl;
  la $a0,header
  li $v0,4    
	syscall
# Aquí imprime el entero en pantalla (num_fil)
  move $a0,$s6 
	li $v0,1    
	syscall
# Imprime " x "
  la $a0,x
	li $v0,4    
	syscall  
# Aquí imprime el entero en pantalla (num_col)
  move $a0,$s7 
	li $v0,1    
	syscall
# ║ Inicializamos contador, cargamos dirección de matriz y operamos ║
  move $t1,$zero    # $t1 = contador_elementos
  la $s0,mat        # Carga de dirección de la matriz
  mul $t2,$s6,$s7   # Operamos num_fil * num_col ($s6 * $s7) y lo guardamos en $t2

  ForImpresion:
# ║ DARLE LA FORMA A LA MATRIZ ║
# Si el número de elementos == contador de elementos -> acaba
    beq $t2,$t1,ImprimirMatrizFinal
# ║ Dividimos el contador entre el numero de columnas ║
    div $t1,$s7     # $t1 % $t7 = $t3
    mfhi $t3 
# Si el resto es 0, imprimimos un espacio
    beq $t3,$zero,PrintEspacio

  continua:
    lw $t4,0($s0)
    move $a0,$t4 # Se asigna a a0 el valor de t4
	  li $v0,1    
	  syscall
    la $a0,separador
    li $v0,4    
	  syscall

    addi $t1,1 # Se le suma el valor inmediato 1 a $t1 
    addi $s0,4 # Se le suma el valor inmediato 4 a $s0

    j ForImpresion

  ImprimirMatrizFinal:
# ║ FINAL DE LA IMPRESIÓN ║
    lw  $s7,8($sp)
    lw  $s6,4($sp)
    lw  $s0,0($sp)
    addi $sp,$sp,12
# ║ VOLVEMOS A LA LLAMADA DE LA FUNCIÓN ║
    jr $ra       
   

# ╔═══════════════════╗
# ║   REDIMENSIONAR   ║
# ╚═══════════════════╝
Redimensionar:
# ║ PEDIMOS EL NÚMERO DE FILAS ║
# cout << "Introduzca el número de filas: ";
# cin >> filas;
  la $a0,msg_nfilas
  li $v0,4    
  syscall
  li $v0,5 # Se lee un entero
  syscall
  blez $v0,ErrorFilas # Se imprime un mensaje de error de filas
  move $t1,$v0 # Se asigna a t8 el valor de v0

# ║ PEDIMOS EL NÚMERO DE COLUMNAS ║
# cout << "Introduzca el número de columnas: ";
# cin >> columnas;
  la $a0,msg_ncols
  li $v0,4    
  syscall
  li $v0,5 # Se lee un entero
  syscall
 # ║ COMPROBAMOS QUE EL USUARIO NO HAYA PUESTO UN NUMERO NEGATIVO ║
  blez $v0,ErrorColumnas # Se imprime un mensaje de error de columnas
  move $t2,$v0 # Se asigna a $t2 el valor de v0

# ║ COMPROBAMOS SI SU PRODUCTO NO EXCEDE DEL MAXIMO ELEMENTOS (400) ║
# if (filas * columnas > 400) {
#    cout << "Error: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
#    exit(EXIT_FAILURE);
# }
  mul $t3,$t1,$t2
  bgt $t3,$s5,ErrorDimension

# ║ SI CONCUERDA GUARDAMOS LOS VALORES INTRODUCIDOS Y VAMOS A IMPRIMIR MATRIZ CON ESOS VALORES ║
  move $s6,$t1
  move $s7,$t2
# ║ GUARDAMOS LOS VALORES SALVADOS PARA PASARLOS COMO PARÁMETRO A LA FUNCIÓN ║
  move $a0,$s0
  move $a1,$s6
  move $a2,$s7

  jal ImprimirMatriz
  j Menu

# ╔════════════════════╗
# ║  OBTENER ELEMENTO  ║
# ╚════════════════════╝

ObtenerElemento:
# ║ PEDIMOS EL ELEMENTO i QUE QUIERA EL USUARIO ║
#      cout << "Introduzca la fila del elemento: ";
#      cin >> elemento_f;
  la $a0,msg_i
  li $v0,4    
  syscall
  li $v0,5 # Se lee un entero
  syscall
# ║ COMPROBAR SI ES VÁLIDO ║
# if (elemento_f < 0) {
#    cout << "Error. Posicion i incorrecta\n";
#    return 0;
# }     
  bge $v0,$s6,ErrorFilas # Se imprime un mensaje de error de filas
  bltz $v0,ErrorFilas # Se imprime un mensaje de error de filas
  move $t1,$v0 # Se asigna a t8 el valor de v0

# ║ PEDIMOS EL ELEMENTO j QUE QUIERA EL USUARIO ║
#      cout << "Introduzca la columna del elemento: ";
#      cin >> elemento_c;
  la $a0,msg_j
  li $v0,4    
  syscall
  li $v0,5 # Se lee un entero
  syscall
# ║ COMPROBAR SI ES VÁLIDO ║    
  bge $v0,$s7,ErrorColumnas # Se imprime un mensaje de error de filas
  bltz $v0,ErrorColumnas # Se imprime un mensaje de error de filas
  move $t2,$v0 # Se asigna a t8 el valor de v0

# ║ DIRECCIÓN DE MATRIZ GUARDADA ║
  la $s0,mat

# ║ NOS DESPLAZAMOS POR LA MATRIZ PARA ENCONTRAR EL ELEMENTO REQUERIDO ║
# matriz[elemento_f * num_col + elemento_c]
  mul $t3,$t1,$s7 
  add $t3,$t3,$t2 
  mul $t3,$t3,$s4
  add $s0,$s0,$t3
# ║ IMPRIMIR EL ELEMENTO ║
# cout << "El elemento escogido es: " << matriz[elemento_f * num_col + elemento_c] << endl;
  la $a0,msg_elemento
  li $v0,4
  syscall
  lw $t4,0($s0) 
  move $a0,$t4
  li $v0,1 
  syscall
  la $a0,newline
	li $v0,4
	syscall

# ║ IMPRIMIMOS MATRIZ INICIAL Y VOLVEMOS AL MENU ║
  jal ImprimirMatriz
  j Menu

# ╔════════╗
# ║  SWAP  ║
# ╚════════╝
# void Swap(int* elemento_1, int* elemento_2) {
#    int valor_1 = *elemento_1;
#    int valor_2 = *elemento_2;
#    *elemento_2 = valor_1;
#    *elemento_1 = valor_2;
# }
Swap:
  lw $t0, 0($a0)  # int valor_1 = *elemento_1;
  lw $t1, 0($a3)  # int valor_2 = *elemento_2;
  sw $t0, 0($a3)  # *elemento_2 = valor_1;
  sw $t1, 0($a0)  # *elemento_1 = valor_2;
# ║ VOLVEMOS A LA LLAMADA DE LA FUNCIÓN ║
  jr $ra

# ╔══════════════════════╗
# ║  INVERTIR RECURSIVA  ║
# ╚══════════════════════╝
# void Invertir(int* primero, int separacion, int sz)  {
#    if (sz < 1) {
#        return;
#    }
#    Swap(primero, primero + sz * separacion - separacion);
#    primero += separacion;
#    sz -= 2;
#    Invertir(primero, separacion, sz);
# }
Invertir:
# ║ GUARDAMOS VALORES DE LOS PARAMETROS EN REGISTROS TEMPORALES ║
  li $t0, 2
  move $t1,$a0    # $t1 = $a0 (primero)
  move $t2,$a1    # $t2 = $a1 (sz)
  move $t3,$a2    # $t3 = $a2 (separación)
# ║ COMPROBAMOS QUE ║
  bge $a1, $t0, operacion
  move $a0,$s0
  move $a1,$s6
  move $a2,$s7
# ║ VOLVEMOS A LA LLAMADA DE LA FUNCIÓN ║
  jr $ra
  operacion:
    addi $sp,$sp,-4
    sw $ra,0($sp)
# primero + sz * separacion - separacion
    mul $t4,$a1,$t3     # sz * separacion
    sub $t4,$t4,$t3     # (sz * separacion) - separacion
    addu $t4,$t4,$a0    # Se suma la primera dirección del vector
    move $a3,$t4# 
# ║ HACEMOS PUSHA A LA PILA DE LOS VALORES ║
    sub $sp,$sp,12
    sw $t0,0($sp) 
    sw $t1,4($sp)
    sw $t4,8($sp)
# ║ LLAMAMOS LA FUNCIÓN SWAP PARA CAMBIAR LOS ELEMENTOS ║
    jal Swap
# ║ HACEMOS POP A LA PILA DE LOS VALORES ║
    lw $t4,8($sp)
    lw $t1,4($sp)
    lw $t0,0($sp)
    addi $sp,$sp,12
# ║ CONTINUAMOS HACIENDO CALCULOS ║
    addi $a1,-2       # sz -= 2;
    add $a0,$t1,$t3   # primero += separacion;
    sub $a3,$t4,$t3   # $a3 = primero + (sz * separacion - separacion) 
# ║ VOLVEMOS A LLAMAR A LA FUNCIÓN INVERTIR ║
    jal Invertir
# ║ RECUPERAMOS EL VALOR DE $ra ANTERIOR ║
    lw $ra, 0($sp)
    addi $sp, $sp, 4
# ║ VOLVEMOS A LA LLAMADA DE LA FUNCIÓN ║
    jr $ra

# ╔══════════════╗
# ║  TRASPUESTA  ║
# ╚══════════════╝
# void Traspuesta(int* m, int* num_fil) {
#    for (int i = 0; i < *num_fil; ++i) {
#        for (int j = 0; j < i; ++j) {
#            Swap(m + i * *num_fil + j, m + j * *num_fil + i);
#        }
#    }
# }
Traspuesta:
  move $s0,$a0
  move $s6,$a1
  sub $sp,$sp,4
  sw $ra,0($sp)
#    for (int i = 0; i < *num_fil; ++i) {
  li $t1,0  # int i = 0
for_Traspuesta_filas:
  beq $t1,$s6,fin_for_Traspuesta_filas  # if (i == num_fil) termina for filas
#        for (int j = 0; j < i; ++j) {
  li $t2,0  # int j = 0
for_Traspuesta_columnas:
  beq $t2,$t1,fin_for_Traspuesta_columnas   # if (j < i) termina for columnas

# m + i * *num_fil + j
  mul $t5,$t1,$s6 
  add $t5,$t5,$t2
  mul $t5,$t5,size
  add $a0,$t5,$s0

# m + j * *num_fil + i
  mul $t6,$t2,$s6 
  add $t6,$t6,$t1
  mul $t6,$t6,size
  add $a3,$t6,$s0
# ║ HACEMOS PUSH A LA PILA DE LOS VALORES ║
  sub $sp,$sp,20
  sw $t0,0($sp) 
  sw $t5,4($sp)
  sw $t1,8($sp)
  sw $t2,12($sp)
  sw $t6,16($sp)
# ║ LLAMAMOS A LA FUNCIÓN SWAP PARA CAMBIAR LOS ELEMENTOS ║
  jal Swap
# ║ HACEMOS POP A LA PILA DE LOS VALORES ║
  lw $t6,16($sp)
  lw $t2,12($sp)
  lw $t1,8($sp)
  lw $t5,4($sp)
  lw $t0,0($sp)
  addi $sp,$sp,20

# ║ AUMENTAMOS EL ITERADOR j++ ║
  addi $t2,1

# ║ VUELVE AL BUCLE ║
  j for_Traspuesta_columnas

fin_for_Traspuesta_columnas:
# ║ AUMENTAMOS EL ITERADOR i++ ║
  addi $t1,1

# ║ VUELVE AL BUCLE ║
  j for_Traspuesta_filas

fin_for_Traspuesta_filas:

# ║ HACEMOS POP DEL $ra Y LO RECUPERAMOS ║
  lw  $ra,0($sp)
  addi  $sp,$sp,4

  move $a0,$s0
  move $a1,$s6
  move $a2,$s7
# ║ VOLVEMOS A LA LLAMADA DE LA FUNCIÓN ║
  jr $ra


# ╔═══════════════════════╗
# ║ MENSAJES DE IMPRESIÓN ║
# ╚═══════════════════════╝
# cout << "Error: dimension incorrecta. Numero de fila incorrecto.\n";
ErrorFilas:
  la $a0,error_nfilas
  li $v0,4    
  syscall
  b ImprimirMatriz

# cout << "Error: dimension incorrecta. Numero de columna incorrecto.\n;
ErrorColumnas:
  la $a0,error_ncols
	li $v0,4    
	syscall
  b ImprimirMatriz

# cout << "Error: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
ErrorDimension:
  la $a0,error_dime
	li $v0,4    
	syscall
  b ImprimirMatriz

# cout << "Error: opcion incorrecta.\n";
ErrorOpcion:  
  la $a0,error_op
	li $v0,4    
	syscall 
  b Menu

# cout << endl;
PrintEspacio:
  la $a0,newline
	li $v0,4    
	syscall
  b continua


# ╔═══════════════════════════╗
# ║  COMPROBACIÓN TRASPUESTA  ║
# ╚═══════════════════════════╝
MatrizTraspuesta:
# ║ COMPROBAMOS QUE LA MATRIZ ES CUADRADA ║
  bne $s6,$s7,ErrorCuadrada   # Imprimirá un mensaje de error en caso contrario.
  move  $a0,$s0               # GUARDA matriz PARA ARGUMENTO
  move  $a1,$s6               # GUARDA num_fil PARA ARGUMENTO

# ║ LLAMA A LA FUNCIÓN TRSPUESTA ║
  jal  Traspuesta

# ║ VUELVE AL MENÚ PRINCIPAL ║
  j  imprime

ErrorCuadrada:
  la $a0,error_no_cuadrada
  li $v0,4
  syscall
  j imprime

# ╔═══════════════════╗
# ║   INVERTIR FILA   ║
# ╚═══════════════════╝
# cout << "Introduzca la fila que quiera invertir: ";
# cin >> filas_aux;
# if (filas_aux < 0) {
#   cout << "Error: dimension incorrecta. Numero de filas incorrecto.\n";
#   return 0;
# }
# Invertir(matriz + filas_aux * columnas, 1, columnas);
InvertirFilas:
# ║ IMPRIME MENSAJE PARA PEDIR AL USUARIO LA FILA ║
  la $a0,msg_f
  li $v0,4    
  syscall
  li $v0,5 # Se lee un entero
  syscall

# ║ COMPROBAMOS QUE LA FILA INTRODUCIDA ES ADECUADA ║
  bltz $v0,ErrorFilas
  bge $v0,$s6,ErrorFilas
  move $t1,$v0

# ║ CALCULOS ║
  mul $t1,$t1,$s7
  mul $t1,$t1,size
  la $s0, mat
  addu $t1,$t1,$s0

# ║ GUARDAMOS LOS VALORES PARA PASAR COMO PARÁMETROS ║
  move $a0,$t1
  move $a1,$s7
  move $a2,$zero
  addi $a2,size

# ║ LLAMAMOS A LA FUNCIÓN INVERTIR ║
  jal Invertir

# ║ VUELVE AL MENÚ PRINCIPAL ║
  j imprime


# ╔══════════════════════╗
# ║   INVERTIR COLUMNA   ║
# ╚══════════════════════╝
# cout << "Introduzca la columna que quiera invertir: ";
# cin >> columnas_aux;
# if (columnas_aux < 0) {
#   cout << "Error: dimension incorrecta. Numero de columnas incorrecto.\n";
#   return 0;
# }
# Invertir(matriz + columnas_aux, columnas, filas);
InvertirColumna:
# ║ IMPRIME MENSAJE PARA PEDIR AL USUARIO LA COLUMNA ║
  la $a0,msg_c
  li $v0,4
  syscall
  li $v0,5
  syscall

# ║ COMPROBAMOS QUE LA COLUMNA INTRODUCIDA ES ADECUADA ║
  bltz $v0,ErrorColumnas
  bge $v0,$s7,ErrorColumnas
  move $t1,$v0

# ║ CALCULOS ║
  mul $t1,$t1,size
  la $s0,mat
  addu $t1,$t1,$s0
  mul $t2,$s7,size

# ║ GUARDAMOS LOS VALORES PARA PASAR COMO PARÁMETROS ║
  move $a0,$t1
  move $a1,$s6
  move $a2,$t2

# ║ LLAMAMOS A LA FUNCIÓN INVERTIR ║
  jal Invertir

# ║ VUELVE AL MENÚ PRINCIPAL ║
  j imprime

# ╔═════════════════════╗
# ║    FINAL PROGRAMA   ║
# ╚═════════════════════╝
FinPrograma:
# cout << "-- Cerrando programa --" << endl;
# return 0;
# ║ FINALIZA EL PROGRAMA ║
  la $a0,msg_fin
  li $v0,4    
  syscall
	li $v0,10   
	syscall