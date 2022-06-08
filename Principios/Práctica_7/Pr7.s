# practica 7. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.

# include <iostream>
# include <stdio.h>
# define nrows 4
# define ncols 3
# /* EN MIPS es multiplicar(dirección del elemento (i,j) de la matriz m1, dirección del elemento (i,j) de la matriz m2)*/
# ·int multiplicar(int m1[nrows][ncols], int m2[nrows][ncols],int i,int j){
#	int s;
#	s=m1[i][j]*m2[i][j];
#	return(s);
# }
#
# /* EN MIPS es multiplicar_matrix( dirección base m1, direccion base m2, direccion base m3, número de filas, número de columnas)*/
#
# void multiplicar_matrix(int m1[nrows][ncols],int m2[nrows][ncols],int m3[nrows][ncols],int f, int c){
#	int i,j;
#	for (i = 0; i < f ; i++) {
#			for (j = 0; j < c ; j++)
#				m3[i][j]=multiplicar(m1,m2,i,j);
#			std::cout << std::endl;
#		}
#	}
#
# /* EN MIPS quiero que el cálculo de los desplazamientos estén optimizados.*/
# 
# void print_matrix(int ma[nrows][ncols],int f, int c){
#	int i,j;
#		for (i = 0; i< f ; i++) {
#			for (j = 0; j < c ; j++)
#				std::cout << ma[i][j] << " ";

#		}
# }
# int main(void) {
#	
#	int matrix1[nrows][ncols] = {{1,2,3},{2,2,2},{3,3,3},{4,4,4}};
#	int matrix2[nrows][ncols] = {{1,0,0},{0,1,0},{0,0,1},{0,0,1}};
#	int matrix3[nrows][ncols] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
#	int selection;
#	std::cout << "P7 Principios de computadores.\n ";
#	do {
#		
#		do {
#			std::cout << "Elija opcion <0> Salir, <1> Multiplicar matrices:\n";
#			std::cin >> selection;
#		} while (selection < 0 || selection > 1);
#		std::cout << "Primera Matriz\n";
#		print_matrix(matrix1,nrows,ncols);
#		std::cout << "Segunda Matriz\n";
#		print_matrix(matrix2,nrows,ncols);
#		if (selection == 1) {
#			multiplicar_matrix(matrix1,matrix2,matrix3,nrows,ncols);
#			std::cout << "El resultado de la multiplicacion es:\n";	
#			print_matrix(matrix3,nrows,ncols);
#		}
#    } while (selection != 0);
#   std::cout << "\nFIN DEL PROGRAMA.";
#	return(0);
# }

nrows=4
ncols=3

	.data		# directiva que indica la zona de datos
titulo: 			.asciiz	"P7 Principios de computadores.\n" 
msgpregunta:  .asciiz "Elija opcion <0> Salir, <1> Multiplicar matrices:\n"
separador:  	.asciiz "  "
newline:    	.asciiz "\n"
msg1:         .asciiz "Primera Matriz\n"
msg2:         .asciiz "Segunda Matriz\n"
msg3:					.asciiz "El resultado de la multiplicacion es:\n"
msgfin:				.asciiz "\nFIN DEL PROGRAMA."

matrix1:	.word	1, 2, 3
					.word	2, 2, 2
					.word	3, 3, 3
					.word	4, 4, 4

matrix2:	.word	1, 0, 0
					.word	0, 1, 0
					.word	0, 0, 1
					.word	0, 0, 1			

matrix3:	.word	0, 0, 0
					.word	0, 0, 0
					.word	0, 0, 0
					.word	0, 0, 0
	.text		# directiva que indica la zona de código

main:
	
	la $a0,titulo
	li $v0,4    
	syscall

	li $s5,400

  lw $s3,nrows
  lw $s4,ncols	

Menu:

  la $a0,msgpregunta
	li $v0,4
	syscall

  li $v0,5
  syscall
  move $s5,$v0

  beq $s5,$zero,FinPrograma      
  beq $s5,1,Programa  

	j Menu

Programa:

  la $a0,msg1
	li $v0,4    
	syscall

	la $s0,matrix1

	sub $sp,$sp,12
  sw $s0,0($sp) 
  sw $s3,4($sp)
  sw $s4,8($sp)

	move $a0,$s0
  move $a1,$s3
  move $a2,$s4

	jal Print_Matrix

	lw  $s4,8($sp)
 	lw  $s3,4($sp)
 	lw  $s0,0($sp)
 	addi $sp,$sp,12

	la $a0,msg2
	li $v0,4    
	syscall

	la $s1,matrix1

	sub $sp,$sp,12
  sw $s1,0($sp) 
  sw $s3,4($sp)
  sw $s4,8($sp)

	move $a0,$s1
  move $a1,$s3
  move $a2,$s4

	jal Print_Matrix

	lw  $s4,8($sp)
 	lw  $s3,4($sp)
 	lw  $s1,0($sp)
 	addi $sp,$sp,12

	sub $sp,$sp,12
  sw $a0,0($sp) 
  sw $a1,4($sp)
  sw $a2,8($sp)

	la $t0,matrix1
	la $t1,matrix2
	la $t2,matrix3

	move $a0,$t0
	move $a1,$t1
	move $a2,$t2

	jal Multiplicar_Matrix

	lw  $a2,8($sp)
 	lw  $a1,4($sp)
 	lw  $a0,0($sp)
 	addi $sp,$sp,12

	la $a0,msg3
	li $v0,4    
	syscall

	sub $sp,$sp,12
  sw $s0,0($sp) 
  sw $s3,4($sp)
  sw $s4,8($sp)

	move $a0,$s1
  move $a1,$s3
  move $a2,$s4

	jal Print_Matrix

	lw  $s4,8($sp)
 	lw  $s3,4($sp)
 	lw  $s1,0($sp)
 	addi $sp,$sp,12

	j FinPrograma

Print_Matrix:

	sub $sp,$sp,4
  sw $ra,0($sp)

  move $s0,$a0
  move $s6,$a1
  move $s7,$a2

  move $t1,$zero   
  la $s0,matrix1     
  mul $t2,$s3,$s4   

  ForImpresion:

    beq $t2,$t1,Print_MatrixFin

    div $t1,$s7    
    mfhi $t3 

    beq $t3,$zero,PrintEspacio

  Continua:

    lw $t4,0($s0)
    move $a0,$t4 
	  li $v0,1    
	  syscall
    la $a0,separador
    li $v0,4    
	  syscall

    addi $t1,1
    addi $s0,4 

    j ForImpresion

Print_MatrixFin:

	lw  $ra,0($sp)
  addi  $sp,$sp,4

  jr $ra       

   
PrintEspacio:
  la $a0,newline
	li $v0,4    
	syscall
  b continua


Multiplicar:


Multiplicar_Matrix:

	move $t0,$s0
	move $t1,$s1
	move $t2,$s2

  sub $sp,$sp,4
  sw $ra,0($sp)

  li $t1,0 
for_filas:
  beq $t1,$s6,fin_for_filas  

  li $t2,0  
for_columnas:
  beq $t2,$t1,fin_for_columnas  

	sub $sp,$sp,12
  sw $s0,0($sp) 
  sw $s3,4($sp)
  sw $s4,8($sp)

	move $s0,$a0
  move $s6,$a1
  move $s7,$a2

	jal Multiplicar

	lw  $s4,8($sp)
 	lw  $s3,4($sp)
 	lw  $s1,0($sp)
 	addi $sp,$sp,12

	la $a0,$s0
	li $v0,4    
	syscall
	la $a0,separador
	li $v0,4    
	syscall


  addi $t2,1

  j for_columnas

fin_for_columnas:

  addi $t1,1

  j for_filas

fin_for_filas:

  lw  $ra,0($sp)
  addi  $sp,$sp,4

  jr $ra

FinPrograma:

  la $a0,msg_fin
  li $v0,4    
  syscall
	li $v0,10   
	syscall