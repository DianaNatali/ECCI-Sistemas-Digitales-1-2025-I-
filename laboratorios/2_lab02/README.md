
# Lab02:  Blinker en HAL vs Bare-Metal vs Mbed OS con STM32CubeIDE"


## 1. Objetivos de aprendizaje


1. Aprender a usar STM32CubeIDE para configurar y programar el microcontrolador.

2. Comparar tres enfoques para programar un STM32: 
HAL, Bare-Metal y Mbed OS.

3. Entender las ventajas y desventajas de cada enfoque.

## 2. Materiales y herramientas

1. STM32F103C8T6 (**"Blue Pill"**).
2.  ST-Link V2 (para programar y depurar el STM32).
3. STM32CubeIDE instalado.
4. LED (o usar el LED en **PC13** de la placa)
5. Resistencia 220Ω (si se usa un LED externo).

## 3. Procedimiento

1. Paso 1: Configuración del Entorno

    1. Instalar y configurar el IDE correspondiente según el método de desarrollo.

    2. Verificar la conexión de la placa y los drivers necesarios.

    3. Crear proyectos independientes para cada enfoque (Bare Metal, HAL, Mbed OS).

2. Paso 2: Configuración del LED

    1. Identificar el pin del LED en la placa de desarrollo.

    2. Configurar el modo del pin como salida digital.

    3. Asegurar que la frecuencia del reloj del sistema sea la adecuada.

3. Paso 3: Implementación del Blinker

    * Enfoque Bare Metal

        * Configurar los registros directamente.

        * Controlar el GPIO sin librerías externas.

        * Implementar retardos de forma manual o usando temporizadores.

    * Enfoque HAL

        * Utilizar las funciones HAL para configurar y controlar el GPIO.

        * Usar funciones HAL para los retardos.

    *  Enfoque Mbed OS

        * Usar las API de Mbed OS para definir el comportamiento del LED.

        * Implementar retardos mediante temporizadores de alto nivel.

4. Paso 4: Pruebas y Comparación

    * Verificar que el LED parpadee correctamente en cada caso.

    * Comparación:

        * Código requerido: Líneas de código y complejidad.

        * Facilidad de mantenimiento y escalabilidad.

        * Portabilidad entre diferentes microcontroladores.

        * Consumo de memoria (flash/RAM utilizada).

        * Flexibilidad en configuraciones de temporización.

## Entregables

* Documentación en **GitHub Classroom** siguiendo los lineamientos de la plantilla.

