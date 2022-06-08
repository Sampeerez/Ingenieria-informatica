# Samuel Pérez López
# practica 4. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.

#include <iostream>
#include <iomanip> // para set precision

#int main() {
#    
#   float numero, suma, media;
#	int n;
#   std::cout << "P4 Principios de computadores.\n";    
#    n=0;
#	suma=0;
#	do {
#       // Introducir el numero        
#        std::cout << "Introduzca el valor del numero (0 para salir):\n ";
#        std::cin >> numero;
#               if ( numero== 0 ) break;
#         // hace la suma acumulada e incrementa n 
#        suma+=numero;
#		n++;
#       		} while (true);
#		// calculo de la media
#		media=suma/n;
#    std: :cout << "La media de " << n << " terminos = " << std::setprecision(15) << media << std::endl;
#    std::cout<<"\n Fin del programa\n";
#    return 0;
#}

	.data		# directiva que indica la zona de datos
titulo: 	.asciiz	"P4 Principios de computadores.\n" 
msgpregunta:    .asciiz "Introduzca el valor del numero (0 para salir):\n"
msg1:           .asciiz "La media de "
msg2:           .asciiz " terminos= "
msgfin:			.asciiz "\nFIN DEL PROGRAMA."


	.text		# directiva que indica la zona de código
main:

#   float numero, suma, media;
#	int n;
#   std::cout << "P4 Principios de computadores.\n";    
#   n=0;
#	suma=0;

	la 		$a0,titulo
	li 		$v0,4
	syscall

	li.s	$f0,$zero		# numero
	li.s	$f1,$zero		# suma
	li.s	$f2,$zero		# media
	li		$t0,$zero		# n

#	do {

do:

#   std::cout << "Introduzca el valor del numero (0 para salir):\n ";
#   std::cin >> numero;

	la 		$a0,msgpregunta
	li 		$v0,4
	syscall

	li       $v0,6
   	syscall

	mov.s	 $f4,$v0

#	if ( numero== 0 ) break;

   	c.eq.s	$f4,$zero
	bclt 	fin

#	suma+=numero;

	add.s	$f1,$f1,$f0

#	n++;

	li      $t2,1
	add		$t0,$t0,$t2

#       		} while (true);

	j do
fin:

#	media=suma/n;

	mtcl	$t0,$f5
	cvt.s.w $f6,$f5

	div.s 	$f2,$f1,$f6

#   std: :cout << "La media de " << n << " terminos = " << std::setprecision(15) << media << std::endl;
#   std::cout<<"\n Fin del programa\n";
	
	la 		$a4,msg1
	li 		$v0,4
	syscall

	mov.s 	$f6,f7
	li.s 	$v0,2

	la 		$a4,msg2
	li 		$v0,4
	syscall

	mov.s 	$f2,f8
	li.s 	$v0,2

	la 		$a4,msgfin
	li 		$v0,4
	syscall

	li $v0,10
	syscall