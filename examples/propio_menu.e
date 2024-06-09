<<
  Asignatura:    Procesadores de Lenguajes

  Titulación:    Ingeniería Inparamática
  Especialidad:  Computación
  Curso:         Tercero
  Cuatrimestre:  Segundo

  Departamento:  Inparamática y Análisis Numérico
  Centro:        Escuela Politécnica Superior de Córdoba
  Universidad de Córdoba

  Autor:         Jesús Núñez de Arenas Llamas
 
  Curso académico: 2023 - 2024

  Fichero de ejemplo para interpreter.exe
>>

!! Bienvenida

borrar_pantalla;
lugar(10,10);
escribir('Introduce tu nombre --> ');
leer_cadena(nombre);

borrar_pantalla;
lugar(10,10);
escribir('  Intérprete de pseudocódigo: \'interpreter.exe\'.');
escribir('\n Bienvenido/a \t ');
escribir nombre;

lugar(40,10);
escribir('Pulsa una tecla para continuar');
leer_cadena(pausa);

repetir

 !! Opciones disponibles

 borrar_pantalla;
 lugar(10,10);
 escribir(' Secuencia de Fibonacci ----> 1 ');

 lugar(11,10);
 escribir(' Comprobar número primo ----> 2 ');

 lugar(12,10);
 escribir(' Cálculo del número áureo --> 3 ');

 lugar(13,10);
 escribir(' Finalizar -----------------> 0 ');

 lugar(15,10);
 escribir(' Elige una opcion ');

 leer(opc);

 borrar_pantalla;

 casos(opc)
    valor 0:
        lugar(10,10);
        escribir nombre;
        lugar(11,10);
        escribir('Gracias por usar el intérprete interpreter.exe ');


    valor 1:

        lugar(10,10);
        escribir(' Secuencia de Fibonacci  ');

        lugar(11,10);
        escribir(' Introduce un número entero hasta el que calcular Fibonacci ');
        leer(n);

        a := 0;
        b := 1;

        para i desde 2 hasta n paso 1 hacer
            temp := a + b;
            a := b;
            b := temp;
        fin_para

        !! Resultado
        lugar(15,10);
        escribir(' El número de Fibonacci en ');
        escribir n;
        lugar(16,10);
        escribir(' es ');
        escribir(b);

    valor 2:

        lugar(10,10);
        escribir(' Comprobar si un número es primo  ');

        lugar(11,10);
        escribir(' Introduce un número entero ');
        leer(n);

        es_primo := verdadero;

        si (n <= 1) 
            entonces
                es_primo := falso;
        fin_si

        para i desde 2 hasta n-1 paso 1 hacer
            aux := n % i;
            si (aux = 0) entonces
                es_primo := falso;
            fin_si
        fin_para

        !! Resultado
        si (es_primo = verdadero) entonces
            lugar(15,10);
            escribir(' El número es primo ');
        si_no
            lugar(15,10); 
            escribir(' El número no es primo ');
        fin_si

    valor 3:

        lugar(10,10);
        escribir(' Calcular el número áureo  ');

        lugar(11,10);
        escribir(' Introduce un número entero de iteraciones ');
        leer(n);

        a := 0;
        b := 1;

        para i desde 2 hasta n paso 1 hacer
            temp := a + b;
            a := b;
            b := temp;
        fin_para

        numero_aureo := b / a;

        !! Resultado
        lugar(15,10);
        escribir(' El número Áureo en la iteración ');
        escribir n;
        lugar(16,10);
        escribir(' es ');
        escribir numero_aureo;

    defecto:

        lugar(15, 10);
        escribir(' La opción elegida no existe, vuelve a introducir una opción ');

 fin_casos

 lugar(40,10); 
 escribir('\n Pulse una tecla para continuar --> ');
 leer_cadena(pausa);

hasta (opc = 0)

!! Despedida
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');