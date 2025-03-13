# Lab02: Creación de caracteres especiales en una LCD de 16x2 

## Objetivo:

Aprender a crear y mostrar caracteres especiales personalizados en una pantalla LCD de 16x2 utilizando la placa STM32 Blue Pill, programando en C con STM32CubeIDE y manejando la LCD en modo de 4 bits. Además, comprender el uso de la CGRAM para almacenar y visualizar caracteres personalizados.

# Materiales necesarios:

* Pantalla LCD de 16x2 (modo de 4 bits).

* Placa STM32 Blue Pill.

* Protoboard y cables de conexión.

* Potenciómetro de 10kΩ (para ajustar el contraste de la LCD).

* Resistencias de 220Ω (para la retroiluminación de la LCD).

* Entorno de programación STM32CubeIDE.

# Fundamento teórico:

En sistemas embebidos y arquitecturas digitales, la interacción con dispositivos de visualización es esencial para la presentación de información en tiempo real. Entre estos dispositivos, las pantallas LCD alfanuméricas de 16x2 son ampliamente utilizadas debido a su simplicidad y bajo consumo de recursos.

LCD significa "Pantalla de Cristal Líquido" (Liquid Crystal Display). El nombre LCD 16×2 se debe a que tiene 16 columnas y 2 filas. Existen varias configuraciones como 8×1, 8×2, 10×2, 16×1, entre otras, pero la más utilizada es la 16×2. Esto significa que puede mostrar 32 caracteres en total, donde cada carácter está compuesto por una matriz de 5×8 píxeles, como se muesta en la siguiente figura:

<p align="center">
 <img src="/pics/lab04/LCD16x2_diag.png" alt="alt text" width=500 >
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
 <img src="/figs/lab02/LCD16x2.png" alt="alt text" width=500 >
</p>


Una pantalla LCD de 16x2 permite mostrar caracteres alfanuméricos y algunos símbolos predefinidos. Además, es posible crear caracteres personalizados utilizando la memoria CGRAM (Character Generator RAM) de la LCD. Cada carácter personalizado se define como una matriz de 5x8 píxeles y se almacena en la CGRAM, que tiene espacio para hasta 8 caracteres personalizados.

La placa STM32 Blue Pill, basada en el microcontrolador STM32F103C8T6, permite controlar periféricos como una LCD de 16x2 mediante programación en C utilizando STM32CubeIDE.
Procedimiento:
