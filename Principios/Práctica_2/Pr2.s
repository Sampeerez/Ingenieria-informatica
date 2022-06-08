# practica 2. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.
 
##include <iostream>
# int main()
# {
#     std::cout << "Suma las cifras de un número entero." << std::endl;
#     std::cout << "Introduzca un 0 para salir del programa." << std::endl;
 
 
#     int numero,cifra,suma;
#     do {
#         std::cout << "Introduzca un entero para calcular la suma de sus cifras (0 para salir): ";
#         std::cin >> numero;
#         if (numero == 0) break;
#         if (numero < 0 ) numero = 0 - numero;
#         suma = 0;
#         while ( numero != 0 ){
#             cifra = numero % 10;
#             suma += cifra;
#             numero /= 10;
#         }
#         std::cout << "La suma de las cifras es " << suma << std::endl;
#     } while (true);
#     std::cout << "FIN DEL PROGRAMA. " << std::endl;
#     return 0;
# }
#
# En esta zona de .data es donde se almacenan los datos que serán usados después en el programa, que en este caso son todo
# cadenas de texto, y en .text comienza el código del programa con un main.
 
   .data       # directiva que indica la zona de datos
titulo:        .asciiz "\nSuma las cifras de un número entero. Introduzca un 0 para salir del programa.\n "
msgnumero:     .asciiz "\n\nIntroduzca un entero para calcular la suma de sus cifras (0 para salir): "
 
msgresultado1:    .asciiz "\nLa suma de las cifras es  "
msgfin:           .asciiz "\nFIN DEL PROGRAMA."
 
 
   .text       # directiva que indica la zona de código
main:

   # IMPRIME EL TITULO POR CONSOLA
   # std::cout << "Suma las cifras de un número entero." << std::endl;
   # std::cout << "Introduzca un 0 para salir del programa." << std::endl;
   #
   # En este primer trozo de código lo que se hace es almacenar en $a0 el título y después con $v0,4 imprimirlo en pantalla.

   la       $a0,titulo
   li       $v0,4
   syscall
 
   # EL MAYOR PORCENTAJE DEL CÓDIGO C++ SE ENCUENTRA DENTRO DE UNA ESTRUCTURA do { ...  } while (true).
   # IMPLEMENTA EN MIPS ESE BUCLE INFINITO, Y A CONTINUACIÓN DESARROLLA CADA UNA DE LAS SECCIONES QUE
   # SE ENCUENTRAN EN SU INTERIOR.
 
   do:
   # INTRODUCE EN ESTA SECCION EL CÓDIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
   # TEN EN CUENTA QUE break NO ES SINO UN SALTO A LA SIGUIENTE INSTRUCCION QUE ESTE FUERA DEL BUCLE
   # do { ...  } while (true).
   #         std::cout << "Introduzca un entero para calcular la suma de sus cifras (0 para salir): ";
   #         std::cin >> numero; 
   #         if (numero == 0) break;        
   #
   # Aquí se ha impreso en pantalla el mensaje de texto a través de una llamada al sistema y con el registro $v0,4, 
   # posteriormente se ha recibido un número entero proporcionado por el usuario con li $v0,5 y finalmente se guarda y asegura que el número
   # en el registro $t0 no sea igual a cero, en caso contrario irá a la eetiqueta de fin del programa.

   la       $a0,msgnumero
   li       $v0,4
   syscall
   li       $v0,5
   syscall
   move     $t0,$v0
   beqz     $t0,fin
 
   # INTRODUCE EN ESTA SECCION EL CODIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
   #         if (numero < 0 ) numero = 0 - numero;
   #
   # En esta sección se comprueba si el número es mayor que 0 con bgtz, en cuyo caso saltará a la etiqueta ifFin y seguirá con el código,
   # pero si no es mayor se le restará 0 a ese mismo número para hacerle un cambio de signo.
 
   bgtz     $t0,ifFin
   sub      $t0,$zero,$t0
   b        ifFin
   ifFin:
 
   # INTRODUCE EN ESTA SECCION EL CODIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
   #         suma = 0;
   #         while ( numero != 0 ){
   #             cifra = numero % 10;
   #             suma = suma + cifra;
   #             numero = numero / 10;
   #         }
   #
   # En este trozo de código se inicializa suma = $s0 = 0, $t2 = 10 y cifra = $t1. Se entra en la etiqueta de bucle while y mientras
   # el número sea distinto de 0 con beqz, se harán las siguientes operaciones: se almacena el resto de el número entre 10 en cifra, 
   # se suma ese resto a nuestra variable suma, y al resultado se le divide entre 10. Despúes vuelve a saltar al inicio del bucle y se vuelve a comprobar 
   # que el número es distinto de 0.

   move     $s0,$zero
   while:
   li       $t2,10
   beqz     $t0,whileFin
   move     $t1,$zero
   rem      $t1,$t0,$t2
   add      $s0,$t1,$s0
   div      $t0,$t0,$t2
   b        while
   whileFin:
      
   # INTRODUCE EN ESTA SECCION EL CODIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
   #         std::cout << "La suma de las cifras es " << suma << std::endl;
   #
   # Por último se imprime en pantalla una cadena de texto, despúes el resultado de la suma que estaba almacenado en $s0, y se vuelve a saltar
   # a la etiqueta do.
   
   la       $a0,msgresultado1
   li       $v0,4
   syscall
   li       $v0,1
   move     $a0,$s0
   li       $s0,5
   syscall

   j do
   fin:

   # Las siguientes instrucciones imprimen la cadena de fin y finalizan el programa

   li       $v0,4
   la       $a0,msgfin
   syscall
   li       $v0,10
   syscall