# Laboratorio 04: Visualización usando pantalla LCD 16x2

Índice:

- [Laboratorio 04: Visualización usando pantalla LCD 16x2](#laboratorio-04-visualización-usando-pantalla-lcd-16x2)
  - [Objetivos de aprendizaje](#objetivos-de-aprendizaje)
  - [Introducción](#introducción)
  - [Procedimiento](#procedimiento)
    - [Parte 1](#parte-1)
    - [Parte 2](#parte-2)
  - [Entregables](#entregables)
  - [Documentación de apoyo necesaria](#documentación-de-apoyo-necesaria)

*******


## Objetivos de aprendizaje

* Introducir el concepto de máquina de estado en el diseño de hardware utilizando Verilog, enfocado en el control y funcionamiento de una pantalla LCD.


## Introducción

En sistemas embebidos y arquitecturas digitales, la interacción con dispositivos de visualización es esencial para la presentación de información en tiempo real. Entre estos dispositivos, las pantallas LCD alfanuméricas de 16x2 son ampliamente utilizadas debido a su simplicidad y bajo consumo de recursos.

Sin embargo, el control de una LCD 16x2 implica una secuencia precisa de comandos que deben ejecutarse en el orden correcto para inicializar la pantalla, escribir caracteres y actualizar su contenido. En este contexto, el uso de una Máquina de Estados Finitos (FSM) en *hardware* permite gestionar de manera estructurada el flujo de datos y señales de control necesarias para escribir en la pantalla.

LCD significa "Pantalla de Cristal Líquido" (Liquid Crystal Display). El nombre LCD 16×2 se debe a que tiene 16 columnas y 2 filas. Existen varias configuraciones como 8×1, 8×2, 10×2, 16×1, entre otras, pero la más utilizada es la 16×2. Esto significa que puede mostrar 32 caracteres en total, donde cada carácter está compuesto por una matriz de 5×8 píxeles, como se muesta en la siguiente figura:

<p align="center">
 <img src="/laboratorios/figs/lab02/LCD16x2_diag.png" alt="alt text" width=500 >
</p>

**Características del Módulo LCD 16×2:**

* Voltaje de operación: 4.7V a 5.3V
* Consumo de corriente: 1mA sin retroiluminación
* Pantalla alfanumérica, permite mostrar letras y números
* Dos filas, cada una con capacidad para 16 caracteres
* Cada carácter se construye en una matriz de 5×8 píxeles
* Puede operar en modo de 8 bits o 4 bits (se usará en modo de 4 bits)
* Permite mostrar caracteres personalizados
* Disponible con retroiluminación en color verde o azul


La pantalla LCD 16x2 cuenta con múltiples pines para alimentación, control y transferencia de datos. La siguiente lista describe sus funciones principales:

<p align="center">
 <img src="/laboratorios/figs/lab02/LCD16x2.png" alt="alt text" width=500 >
</p>

* **Vss** = GND (Tierra)
* **Vdd** = (+3.3V a +5V) – Alimentación de la pantalla
* **Vo** = Ajuste de contraste 
* **RS** = Selección de tipo de registro – RS=0: Comando, RS=1: Dato
* **R/W** = Lectura/Escritura – R/W=0: Escritura, R/W=1: Lectura
* **E** = Clock (Enable) – Activado en el flanco de bajada
* **D0** = Bit 0 – Línea de datos
* **D1** = Bit 1 – Línea de datos
* **D2** = Bit 2 – Línea de datos
* **D3** = Bit 3 – Línea de datos
* **D4** = Bit 4 – Línea de datos
* **D5** = Bit 5 – Línea de datos
* **D6** = Bit 6 – Línea de datos
* **D7** = Bit 7 – Línea de datos
* **A** = Ánodo de retroiluminación (+)
* **K** = Cátodo de retroiluminación (-)


**Se recomienda revisar en detalle el [*datasheet*](/laboratorios/lab02/lcd016n002bcfhet.pdf) de la LCD 16x2**.




## Entregables

Realice las partes [1](#parte-1) y [2](#parte-2) mencionadas en el procedimiento y presente
en clase las implementaciones de cada una al docente de laboratorio.
