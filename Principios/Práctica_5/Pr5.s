# =========================================================================
# =========================================================================
#    =            Nombre Archivo:    Practica5.s                       =
#    =            Autor:         Samuel Pérez López                    =
#    =            Fecha:         04/05/2022                            =
#    =            Asignatura:    Principios de Computadores            =
#    =            Lenguaje:      MIPS                                  = 
# =========================================================================          
# =========================================================================

# PRACTICA 6. PRINCIPIO DE COMPUTADORES.

# PSEUDOCÓDIGO EN C++

# #include <iostream>

#  int main() { 
#    int maximo_elemento = 400;
#    int primer_elemento;
#    int ultimo_elemento;
#    int mitad_elementos;
#    int n_filas = 20;
#    int num_aux_filas;
#    int n_columnas = 20;
#    int num_aux_columnas;
#    int menu;
#    int size;
#    int M[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
#               120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
#               140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
#               160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
#               180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
#               200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
#               220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
#               240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
#               260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
#               280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
#               300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
#               320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
#               340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
#               360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
#               380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
#               400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
#               420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
#               440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
#               460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
#               480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499 };
#
#    std::cout << "Práctica 5 de Principio de Computadores. Matrices en C++" << std::endl;
#    while(menu != 0) {
#      std::cout << "Matriz con dimensión " << n_filas << " x " << n_columnas << std::endl;
#      for (int i{0}; i < n_filas; ++i) {
#        for (int j{0}; j < n_columnas; ++j) {
#          std::cout << M[i * n_filas + j] << " ";
#        }
#        std::cout << std::endl;
#      }
#      std::cout << "(1) Cambiar dimensiones\n";
#      std::cout << "(2) Obtener elemento [i,j]\n";
#      std::cout << "(3) Invertir fila\n";
#      std::cout << "(4) Invertir columna\n";
#      std::cout << "(0) Salir\n";
#      std::cout << "Introduzca opción: ";
#      std::cin >> menu;
#      switch (menu) {
#        case 1:
#          std::cout << "Introduzca numero de filas: ";
#          std::cin >> num_aux_filas;
#          if (num_aux_filas == 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#          }
#          std::cout << "Introduzca numero de columnas: ";
#          std::cin >> num_aux_columnas;
#          if (num_aux_columnas == 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#          }
#          system("clear");
#          size = num_aux_filas * num_aux_columnas;
#          if (size > maximo_elemento) {
#            std::cerr << "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
#          }
#          n_filas = num_aux_filas;
#          n_columnas = num_aux_columnas;
#          break;
#        case 2:
#          std::cout << "\nObtener el elemento [i,j]. Introduzca indice i (primera fila indice 0): ";
#          std::cin >> num_aux_filas;
#          if (num_aux_filas < 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#          }
#          if (num_aux_filas >= n_filas) {
#            std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#          }
#          system("clear");
#          n_filas = num_aux_filas;
#          std::cout << "\nObtener el elemento [i,j]. Introduzca indice j (primera columna indice 0): ";
#          std::cin >> num_aux_columnas;
#          if (num_aux_columnas < 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#          }
#          if (num_aux_columnas >= n_columnas) {
#            std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#          }
#          n_columnas = num_aux_columnas;
#          std::cout << "\nElemento obtenido en la posicion indicada: " <<  M[num_aux_filas * n_columnas + num_aux_columnas] << std::endl;
#          break;
#        case 3:
#          int fila;
#          std::cout << "Introduce la fila que quiera invertir: ";
#          std::cin >> fila;
#          if (fila < 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#            exit(EXIT_FAILURE);
#          }
#          system("clear");
#          primer_elemento = fila * n_columnas;
#          ultimo_elemento = fila * n_columnas + n_columnas - 1;
#          mitad_elementos = n_columnas / 2;
#          for (int i = 0, j = 0; i < mitad_elementos; ++i) {
#            int aux = M[primer_elemento + i];
#            M[primer_elemento + i] = M[ultimo_elemento - i];
#            M[ultimo_elemento - i] = aux;
#          }
#          break;
#        case 4:
#          int columna; 
#          std::cout << "Introduce la columna que quiera invertir: ";
#          std::cin >> columna;
#          if (columna < 0) {
#            std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#            exit(EXIT_FAILURE);
#          }
#          system("clear");
#          primer_elemento = columna;
#          ultimo_elemento = columna + n_columnas * (n_filas - 1);
#          mitad_elementos = n_filas / 2;
#          for (int i = 0, j = 0; i < mitad_elementos; ++i, ++j) {
#            int aux = M[primer_elemento + i * num_fila];
#            M[primer_elemento + i * num_fila] = M[ultimo_elemento - i * num_fila];
#            M[ultimo_elemento - i * num_fila] = aux;
#          }
#          break;
#      }
#    }
#    std::cout << "\nFin del programa.\n" << std::endl;
#    return 0;
#  }


# CÓDIGO EN MIPS

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
       

nfil:   .word   20 # Número de filas de la matriz
ncol:   .word   10 # Número de columnas de la matriz

separador:  .asciiz "  " 
newline:    .asciiz "\n"
menu:       .ascii  "\n(1) Cambiar dimensiones\n(2) Obtener elemento [i,j]\n"
            .asciiz "(3) Invertir fila\n(4) Invertir columna\n(0) Salir\nElija opcion: "
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
titulo:     .asciiz "\nPractica 5 de Principios de Computadores. Matrices.\n"
header:     .asciiz "Matriz con dimension "
x:          .asciiz " x "
msg_fin:    .asciiz "\nFin del programa.\n"

    .text

# std::cerr << "\nError: opcion incorrecta.\n";

  error_opcion:  
    la $a0,error_op # Se imprime el título por pantalla
	  li $v0,4    
	  syscall 
    b menu_principal

# std::cerr << "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n";

  error_dimension:
    la $a0,error_dime # Se imprime un mensje de error de dimensión por pantalla
	  li $v0,4    
	  syscall
    b matriz_impresa

# std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";

  error_filas:
    la $a0,error_nfilas # Se imprime un mensaje de error de filas por pantalla
	  li $v0,4    
	  syscall
    b matriz_impresa

# std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";

  error_columnas:
    la $a0,error_ncols # Se imprime un mensaje de error de columnas por pantalla
	  li $v0,4    
	  syscall
    b matriz_impresa

# std::cout << "\n";

  espacio:
    la $a0,newline # Se imprime un espacio por pantalla
	  li $v0,4    
	  syscall
    b for_continua

# while(menu != 0) {
#   std::cout << "(1) Cambiar dimensiones\n";
#   std::cout << "(2) Obtener elemento [i,j]\n";
#   std::cout << "(3) Invertir fila\n";
#   std::cout << "(4) Invertir columna\n";
#   std::cout << "(0) Salir\n";
#   std::cout << "Introduzca opción: ";
#   std::cin >> menu;
#   switch (menu) {
#     case 1:
#     -
#     -
#     -
#     case 2:
#     -
#     -
#     -
#     case 3:
#     -
#     -
#     -
#     case 4:
#     -
#     -
#     -
# }

menu_principal:
    la $a0,newline # Se imprimime un espacio
	  li $v0,4    
	  syscall
    la $a0,menu # Se imprime el menú
	  li $v0,4    
	  syscall
    li $v0,5 # Se lee la opción que ha introducido el usuario
    syscall
    beq $v0,$s4,invertir_columna # Si se elige la opción 4, salta a la etiqueta de invertir columna
    beq $v0,$s3,invertir_fila # Si se elige la opción 3, salta a la etiqueta de invertir fila
    beq $v0,$s2,elemento # Si se elige la opción 2, salta a la etiqueta de mostrar elemento
    beq $v0,$s1,redimension # Si se elige la opción 1, salta a la etiqueta de redimensionar
    beq $v0,$s0,fin # Si se elige la opción 0, salta a la etiqueta de fin de programa   
    
    b error_op
 
# std::cout << "Práctica 5 de Principio de Computadores. Matrices en C++" << std::endl;

  main:
    # s0 = 0
    # s1 = 1
    # s2 = 2
    # s3 = 3
    # s4 = 4

    la $a0,titulo # Se imprime el título por pantalla
	  li $v0,4    
	  syscall
    la $a0,newline # Se imprimime un espacio
	  li $v0,4    
	  syscall

    li $s4,4
    li $s3,3
    li $s2,2
    li $s1,1
    li $s0,0 # Asignamos las opciones del 0 al 4 en registros salvados
    lw $t0,nfil # Se guardan el número de filas predeterminadas
    lw $t2,ncol # Se guardan el número de columnas predeterminadas
    li $s5,400 # Se guarda el tamaño máximo


# std::cout << "Matriz con dimensión " << n_filas << " x " << n_columnas << std::endl;
# for (int i{0}; i < n_filas; ++i) {
#   for (int j{0}; j < n_columnas; ++j) {
#     std::cout << M[i * n_filas + j] << " ";
#   }
#   std::cout << std::endl;
# }

  matriz_impresa:
    # t0 = número de filas inicial
    # t1 = 0 / contador
    # t2 = número de columnas inicial
    # t3 = dirección de la matriz
    # t6 = cociente

    la $a0,header
	  li $v0,4    
	  syscall
    move $a0,$t0 # Se asigna a a0 el valor de t0
	  li $v0,1    
	  syscall
    la $a0,x
	  li $v0,4    
	  syscall  
    move $a0,$t2 # Se asigna a a0 el valor de t2
	  li $v0,1    
	  syscall

    move $t1,$zero # Se asigna a t1 el valor 0
    la $t3,mat # Se asigna a t3 la dirección del primer elemento de la matriz
    mul $t4,$t0,$t2 # Se obtiene la dimensión de la matriz en t4

    for_impresion:
      beq $t4,$t1,fin_matriz_impresa
      div $t1,$t2
      mfhi $t6 
      beq $t6,$zero,espacio

      for_continua:
        lw $t5,0($t3)
        move $a0,$t5 # Se asigna a a0 el valor de t5
	      li $v0,1    
	      syscall
        la $a0,separador
        li $v0,4    
	      syscall

        addi $t1,1 # Se le suma el valor inmediato 1 a t1 
        addi $t3,4 # Se le suma el valor inmediato 4 a t3 

        j for_impresion

  fin_matriz_impresa:
    b menu_principal


# std::cout << "Introduzca numero de filas: ";
# std::cin >> num_aux_filas;
# if (num_aux_filas == 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
# }
# std::cout << "Introduzca numero de columnas: ";
# std::cin >> num_aux_columnas;
# if (num_aux_columnas == 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
# }
# system("clear");
# size = num_aux_filas * num_aux_columnas;
# if (size > maximo_elemento) {
#   std::cerr << "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
# }
# n_filas = num_aux_filas;
# n_columnas = num_aux_columnas;

  redimension:
    # t0 = número de filas inicial
    # t2 = número de columnas inicial
    # t3 = dirección de la matriz
    # t7 = dimensión de la matriz
    # t8 = número de fila
    # t9 = número de columna

    la $a0,msg_nfilas
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall
    blez $v0,error_filas # Se imprime un mensaje de error de filas
    move $t8,$v0 # Se asigna a t8 el valor de v0

    la $a0,msg_ncols
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall
    blez $v0,error_columnas # Se imprime un mensaje de error de columnas
    move $t9,$v0 # Se asigna a t9 el valor de v0

    mul $t7,$t8,$t9
    bgt $t7,$s5,error_dimension

    move $t0,$t8 # Se asigna a t0 el valor de t8
    move $t2,$t9 # Se asigna a t2 el valor de t9

    b matriz_impresa


# int fila;
# std::cout << "Introduce la fila que quiera invertir: ";
# std::cin >> fila;
# if (fila < 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#   exit(EXIT_FAILURE);
# }
# system("clear");
# primer_elemento = fila * n_columnas;
# ultimo_elemento = fila * n_columnas + n_columnas - 1;
# mitad_elementos = n_columnas / 2;
# for (int i = 0, j = 0; i < mitad_elementos; ++i) {
#   int aux = M[primer_elemento + i];
#   M[primer_elemento + i] = M[ultimo_elemento - i];
#   M[ultimo_elemento - i] = aux;
# } 

  invertir_fila:
    # t0 = número de filas inicial
    # t1 = resto
    # t2 = número de columnas inicial
    # t3 = dirección de la matriz
    # t4 = 0 / contador
    # t8 = número de fila

    la $a0,msg_f
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall

    la $t3,mat # Se asigna a t3 la dirección del primer elemento de la matriz
    bge $v0,$t0,error_filas # Se imprime un mensaje de error de filas
    bltz $v0,error_filas # Se imprime un mensaje de error de filas
    move $t8,$v0 # Se asigna a t8 el valor de v0
    
    mul $t7,$t8,$s4
    mul $t7,$t7,$t2
    add $t3,$t3,$t7
    mul $t7,$s4,$t2
    add $t5,$t3,$t7
    addi $t5,-4 # Se le suma el valor inmediato -4 a t5

    div $t2,$s2
    mflo $t1
    move $t4,$s0 # Se asigna a t4 el valor de s0

    for_fila:
      beq $t4,$t1,matriz_impresa  
      lw $t6,0($t3) 
      lw $a0,0($t5) 
      sw $a0,0($t3) 
      sw $t6,0($t5) 
      
      addi $t3,4 # Se le suma el valor inmediato 4 a t3 
      addi $t5,-4 # Se le suma el valor inmediato -4 a t5 
      addi $t4,1 # Se le suma el valor inmediato 1 a t4
      
      b for_fila


# int columna; 
# std::cout << "Introduce la columna que quiera invertir: ";
# std::cin >> columna;
# if (columna < 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#   exit(EXIT_FAILURE);
# }
# system("clear");
# primer_elemento = columna;
# ultimo_elemento = columna + n_columnas * (n_filas - 1);
# mitad_elementos = n_filas / 2;
# for (int i = 0, j = 0; i < mitad_elementos; ++i, ++j) {
#   int aux = M[primer_elemento + i * num_fila];
#   M[primer_elemento + i * num_fila] = M[ultimo_elemento - i * num_fila];
#   M[ultimo_elemento - i * num_fila] = aux;
# }

  invertir_columna:
    # t0 = número de filas inicial
    # t1 = resto
    # t2 = número de columnas inicial
    # t3 = dirección de la matriz
    # t4 = 0 / contador
    # t9 = número de columna

    la $a0,msg_c
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall

    la $t3,mat # Se asigna a t3 la dirección del primer elemento de la matriz
    bge $v0,$t2,error_columnas # Se imprime un mensaje de error de columnas
    bltz $v0,error_columnas # Se imprime un mensaje de error de columnas
    move $t9,$v0 # Se asigna a t9 el valor de v0

    mul $t7,$t9,$s4
    add $t3,$t3,$t7
    mul $t7,$s4,$t0
    mul $t7,$t7,$t2
    add $t5,$t3,$t7
    mul $t7,$t2,$s4
    sub $t5,$t5,$t7

    div $t0,$s2
    mflo $t1
    move $t4,$s0 # Se asigna a t4 el valor de s0

    for_columna:
      beq $t4,$t1,matriz_impresa
      lw $a0,0($t5) 
      lw $t6,0($t3)
      sw $t6,0($t5) 
      sw $a0,0($t3) 
      
      add $t3,$t3,$t7 
      sub $t5,$t5,$t7
      addi $t4,1 # Se le suma el valor inmediato 1 a t4
      
      b for_columna


# std::cout << "\nObtener el elemento [i,j]. Introduzca indice i (primera fila indice 0): ";
# std::cin >> num_aux_filas;
# if (num_aux_filas < 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
# }
# if (num_aux_filas >= n_filas) {
#   std::cerr << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
# }
# system("clear");
# n_filas = num_aux_filas;
# std::cout << "\nObtener el elemento [i,j]. Introduzca indice j (primera columna indice 0): ";
# std::cin >> num_aux_columnas;
# if (num_aux_columnas < 0) {
#   std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
# }
# if (num_aux_columnas >= n_columnas) {
#   std::cerr << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
# }
# n_columnas = num_aux_columnas;
# std::cout << "\nElemento obtenido en la posicion indicada: " <<  M[num_aux_filas * n_columnas + num_aux_columnas] << std::endl;

  elemento:
    # t0 = número de filas inicial
    # t2 = número de columnas inicial
    # t3 = dirección de la matriz
    # t8 = número de fila
    # t9 = número de columna
    
    la $a0,msg_i
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall
    
    bge $v0,$t0,error_filas # Se imprime un mensaje de error de filas
    bltz $v0,error_filas # Se imprime un mensaje de error de filas
    move $t8,$v0 # Se asigna a t8 el valor de v0

    la $a0,msg_j
    li $v0,4    
    syscall
    li $v0,5 # Se lee un entero
    syscall

    la $t3,mat # Se asigna a t3 la dirección del primer elemento de la matriz
    bge $v0,$t2,error_columnas # Se imprime un mensaje de error de columnas
    bltz $v0,error_columnas # Se imprime un mensaje de error de columnas
    move $t9,$v0 # Se asigna a t9 el valor de v0

    mul $t7,$t8,$t2 
    add $t7,$t7,$t9 
    mul $t7,$t7,$s4 
    add $t3,$t3,$t7

    la $a0,msg_elemento
    li $v0,4    
    syscall
    lw $t5,0($t3)
    move $a0,$t5 # Se asigna a a0 el valor de t5
    li $v0,1    
    syscall
    la $a0,newline # Se imprimime un espacio
	  li $v0,4    
	  syscall

    b matriz_impresa

  
# std::cout << "\nFin del programa.\n" << std::endl;
# return 0;
  fin:
    la $a0,msg_fin
    li $v0,4    
    syscall
	  li $v0,10   
	  syscall