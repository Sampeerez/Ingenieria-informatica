# Samuel Pérez López
# Fecha: 30/03/2022
# practica 4. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.
# #include <iostream>
# #include <cmath>

# int main() {  

#  std::cout << "PR3 aproximación por serie geométrica" << std::endl;
#  double x{0};
#  double resultado_real{0};
#  const double kEpsilon = 1e-10; 
#  double error_objetivo{0};
#  double error_cometido{0};
#  int terminos{0};

#  while (true) {
#    do{
#      std::cout << "Introduzca el valor de x (|x|<1): " << std::endl;
#      std::cin >> x;
#    } while (fabs(x) >= 1);

#    if (x == 0) break;

#    resultado_real = 1 / (1 + x);
#    std::cout << "Resultado real = " << resultado_real << std::endl;
    
#    do {
#      std::cout << "Introduzca el error objetivo: " << std::endl;
#      std::cin >> error_objetivo;
#    } while (kEpsilon >= error_objetivo || error_objetivo >= resultado_real);

#    while (fabs(error_objetivo - error_cometido) > kEpsilon) {
#      ++terminos;
#      double sumatorio{1};
#      double potencia_1{1};
#      double potencia_2{1};
#      for (int i = 1; i < terminos; i++) {
#        potencia_1 = potencia_1 * (-1);
#        potencia_2 = potencia_2 * x;
#        sumatorio += potencia_1 * potencia_2;
#      }
#      error_cometido = fabs(resultado_real - sumatorio);
#    }
#    std::cout << "Error cometido para " << terminos << " terminos = " << error_cometido << std::endl;
#  }
#  std::cout << "FIN DEL PROGRAMA." << std::endl;
# }


.data
  titulo: .asciiz "PR3 aproximación por serie geométrica\n"
  finmsg: .asciiz "\nFIN DEL PROGRAMA.\n"
  calmsg: .asciiz "\nResultado real = "
  pidex:  .asciiz "\nIntroduzca el valor de x (|x|<1): "
  piderr: .asciiz "\nIntroduzca el error objetivo: "
  resmsg: .asciiz "\nResultado calculado para "
  termsg: .asciiz " terminos = "
  errmsg: .asciiz "\nError cometido para "

.text

# int main() {  

#  std::cout << "PR3 aproximación por serie geométrica" << std::endl;
#  double x{0};
#  double resultado_real{0};
#  const double kEpsilon = 1e-10; 
#  double error_objetivo{0};
#  double error_cometido{0};
#  int terminos{0};

  main:
    la        $a0,titulo
    li        $v0,4
    syscall

    li.s      $f1,0.0 # x
    li.s      $f2,0.0 # resultado_real
    li.s      $f3,0.0 # error_objetivo
    li.s      $f4,0.0 # error_cometido
    li.s      $f6,0.0 # 0 flotante
    li.s      $f7,1.0 # 1 flotante
    li.s      $f5,0.0 # terminos

# do{
#      std::cout << "Introduzca el valor de x (|x|<1): " << std::endl;
#      std::cin >> x;
#    } while (fabs(x) >= 1);

    while:
      la        $a0,pidex
      li        $v0,4
      syscall
      li        $v0,6
      syscall
      mov.s     $f1,$f0  
      abs.s     $f8,$f1
      c.le.s    $f7,$f8
      bc1t      while

#    if (x == 0) break;

    c.eq.s    $f1,$f6
    bc1t      fin

#    resultado_real = 1 / (1 + x);
#    std::cout << "Resultado real = " << resultado_real << std::endl;

    add.s     $f9,$f1,$f7
    div.s     $f2,$f7,$f9
    la        $a0,calmsg
    li        $v0,4
    syscall
    mov.s     $f12,$f2
    li        $v0,2
    syscall

#    do {
#      std::cout << "Introduzca el error objetivo: " << std::endl;
#      std::cin >> error_objetivo;
#      } while (kEpsilon >= error_objetivo || error_objetivo >= resultado_real);

    while_2:
      la        $a0,piderr
      li        $v0,4
      syscall
      li        $v0,6
      syscall
      mov.s     $f3,$f0 
      c.le.s    $f3,$f6
      bc1t      while_2
      c.le.s    $f2,$f3
      bc1t      while_2

#    while (fabs(error_objetivo - error_cometido) > kEpsilon) {
#      ++terminos;
#      double sumatorio{1};
#      double potencia_1{1};
#      double potencia_2{1};

    while_3:
      c.lt.s  $f3,$f4     # if(error_objetivo < error_cometido)
      bc1f    while_3_fin    # Si se cumple la condicion anterior va a resultados.
      add.s   $f5,$f7,$f5 # ++elementos
      # creamos las variables, sumatorio, potencia_1 y potencia_2
      li.s    $f20,1.0    # sumatorio
      li.s    $f21,1.0    # potencia_1
      li.s    $f22,1.0    # potencia_2
      li.s    $f23,1.0    # Declaramos el iterador

#      for (int i = 1; i < terminos; i++) {
#        potencia_1 = potencia_1 * (-1);
#        potencia_2 = potencia_2 * x;
#        sumatorio += potencia_1 * potencia_2;
#      }
#      error_cometido = fabs(resultado_real - sumatorio);
#    }

      for:
        c.lt.s  $f23,$f5
        bc1t  while_3
        neg.s  $f24,$f7 # Guardamos valor -1 en $f24
        mul.s  $f21,$f21,$f24   # potencia_1 = potencia_1 * (-1)
        mul.s  $f22,$f22,$f1    # potencia_2 = potencia_2 * x
        mul.s  $f25,$f21,$f22   # potencia_1 * potencia_2
        add.s  $f20,$f20,$f25   # sumatorio += potencia_1 * potencia_2
        add.s  $f23,$f8,$f23
        b  for                  
        sub.s  $f4,$f2,$f20
        abs.s  $f4,$f4
        j  while_3

#    std::cout << "Error cometido para " << terminos << " terminos = " << error_cometido << std::endl;
#  }
#  std::cout << "FIN DEL PROGRAMA." << std::endl;
# }
    
    while_3_fin:
      # IMPRIME LOS RESULTADOS
      li  $v0,4           # std::cout << "Resultado calculado para " <<
      la  $a0,resmsg
      syscall

      # NUMERO DE ELEMENTOS
      mfc1    $t1,$f5     # Pasamos el número flotante a entero
      li  $v0,1           # std::cout << i << (i es el numero de terminos)
      move  $a0,$t1
      syscall

      li  $v0,4           # std::cout << " terminos =" <<
      la  $a0,termsg
      syscall

      # VALOR DEL SUMATORIO FINAL
      li  $v0,2
      mov.s  $f12,$f20        # std::cout << sumatorio << std::endl;

      li  $v0,4           # std:.cout << "Error cometido para " <<
      la  $a0,errmsg
      syscall

      # NUMERO DE ELEMENTOS
      li  $v0,1           # std::cout << i << (i es el numero de elementos)
      move  $a0,$t1
      syscall

      li  $v0,4           # std::cout << " terminos = "
      la  $a0,termsg
      syscall
      # ERROR COMETIDO FINAL
      li  $v0,2
      mov.s  $f12,$f4        # std::cout << error_cometido << std::endl;

      j  while        # Vuelve a empezar el programa
        
    fin:
        # Las siguientes instrucciones imprimen la cadena de fin y finalizan el programa
        li  $v0,4
        la  $a0,finmsg      # C++ → std::cout << "FIN DEL PROGRAMA" << std::endl;
        syscall             
        li  $v0,10
        syscall



# Preguntas
# 1) El programa se ha mejorado utilizando diferentes bucles, como por ejemplo el primer while(true) y los otros dos do{}while. 
# Este cambio minimizaba gran parte del código inicial y las operaciones que se efectuaban.
# 2) Los registros usados fueron $f0-$f2 para valores de retorno en punto flotante a subprogramas, $f4-$f10 para registros temporales, 
# $f16-$f30 para registros salvados y temporales, $v0-$v1 para valores resultantes de funciones, $a0-$a3 para argumentos pra subrutinas, 
# y $t0-$t7 para enteros temporales.
# 3) Para cambiar a doble precisión habrían que cambiar los registros flotantes ya que los de simple precisión solo ocupan 1 como $f1, porque es de 32 bits
# pero los de doble precisión ocupan 2 como $f0-$f1, porque son de 64 bits. Como su propio nombre indica, si afecta al programa ya que la precisión
# de los resultados es mayor.