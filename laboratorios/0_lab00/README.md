# Lab 00: Instalación de herramientas 

En este laboratorio nos enfocaremos en la instalación y configuración de las herramientas esenciales para el desarrollo de este curso.

Índice:

1. [STM32CubeIDE](#1-stm32cubeide)
2. [Visual Studio Code](#2-visual-studio-code)
3. [Git/Githuv](#3-git-y-github)

## 1. ```STM32CubeIDE```

STM32CubeIDE es un entorno de desarrollo integrado (IDE) diseñado para programar y depurar microcontroladores STM32. Ofrece herramientas completas para escribir código, compilar proyectos y gestionar periféricos, todo en una sola plataforma. Es ideal para trabajar con familias de microcontroladores como la STM32 Blue Pill (```STM32F1```), permitiendo desarrollar proyectos embebidos de manera eficiente y profesional.

### Partes de STM32CubeIDE

```STM32CubeIDE``` combina varias herramientas en un solo entorno. Las partes principales son:

1. ```STM32CubeMX``` (Configuración de Hardware): Permite configurar periféricos, asignar pines y generar código de inicialización.

    * Características:

        1. Interfaz gráfica para configurar GPIO, UART, ADC, PWM, I2C, SPI, etc.

        2. Generación automática de código en C para inicializar el hardware.

        3. Configuración del sistema de relojes (Clock Tree).

    * Integración: En versiones como ```1.12.1```, ```STM32CubeMX``` está completamente integrado en la IDE. En versiones más recientes (1.15.1 o superior), debe instalarse por separado.

2. Editor de código: Permite escribir y editar código en C/C++.


3. Compilador y enlazador: Convierte el código fuente en un archivo binario (firmware) que puede cargarse en el microcontrolador. Integra el compilador GCC para ARM.

4. Depurador: Permite depurar el código para encontrar y corregir errores.

5. Programador: Carga el firmware en el microcontrolador. Compatible con programadores como ST-Link y J-Link.



###  Descargar ```STM32CubeIDE```:

1. Versión ```1.12.1```: Incluye ```STM32CubeMX``` integrado, lo que permite configurar periféricos y generar código sin necesidad de herramientas adicionales.

    Pasos a seguir:

    1. Ir al sitio oficial de STMicroelectronics: [STM32CubeIDE Download](https://www.st.com/en/development-tools/stm32cubeide.html).

    2. Hacer clic en el botón ```Get Software```.

        ![get_sw](/laboratorios/figs/lab00/get_sw.png)

    3. Descargar la versión ```1.12.1``` de acuerdo a su sistema operativo.

        ![get_sw](/laboratorios/figs/lab00/version_12.png)

    4. Aceptar el *License Agreement*.

    5. Crear una cuenta o continuar como invitado *Download as a guest* si no desea crear la cuenta. 

        ![get_sw](/laboratorios/figs/lab00/guest.png)


    5. Se descargará el ```.zip``` que contiene el instalador.

    4. Seguir las instrucciones de instalación:

        * Ejecutar el instalador.

        * Seleccionar la carpeta de instalación.

        * Configurar el workspace al abrir ```STM32CubeIDE``` por primera vez.

2. Versiones Posteriores (```1.15.1``` o Superior): STM32CubeMX no está integrado y debe instalarse por separado.

    Pasos a seguir:

    1. Para ```STM32CubeIDE``` se siguen los mismos pasos enlistados en la versión ```1.12.1``` pero seleccionando la versión superior deseada.

    2. Ir al sitio oficial de ```STM32CubeMX```: [STM32CubeMX Download](https://www.st.com/en/development-tools/stm32cubemx.html).

    3. Hacer clic en el botón ```Get Software```.

    4. Descargar la versión deseada.

    5. Integrar ```STM32CubeMX``` con STM32CubeIDE:

        1. Abrir ```STM32CubeIDE```.

        2. Ir a ```Window > Preferences > STM32Cube > STM32CubeMX```.

        3. Seleccionar la ruta donde se instaló ```STM32CubeMX```.

        4. Guardar los cambios.





## 2. Visual Studio Code 

```Visual Studio Code``` (```VS Code```) es un editor de código ligero pero potente, desarrollado por Microsoft. Es altamente personalizable y cuenta con una amplia gama de extensiones que lo hacen ideal para el desarrollo de software y hardware.

1. Descargar Visual Studio Code: [VS Code download](https://code.visualstudio.com/).

2. Seguir las instrucciones del instalador para completar la instalación.

3. Una vez instalado, abrir ```VS Code``` y explora las extensiones disponibles en el marketplace.


## 3. ```Git``` y GitHub

Git es un sistema de control de versiones ampliamente utilizado para gestionar proyectos de software y hardware. GitHub es una plataforma basada en Git que permite alojar repositorios y colaborar en proyectos.

1. Crear cuenta en [GitHub](https://github.com/).

2. Descargar Git en el computador a través del sitio oficial: [Git download](https://git-scm.com/downloads).

3. Seguir las instrucciones del instalador.

4. Configura ```Git``` de acuerdo al nombre de usuario y correo electrónico usados al crear la cuenta en Github:

    En una terminal del sistema operativo ejecutar:

    ```
    git config --global user.name "cuenta de usario"
    git config --global user.email correo@email.com
    ```

5. Aprender los comandos básicos de Git:

    * ```git init```: Inicializa un repositorio.
    * ```git clone <url>```: Clona un repositorio remoto.
    * ```git add <archivo>```: Añade archivos al área de preparación.
    * ```git commit -m "mensaje"```: Guarda los cambios en el repositorio.
    * ```git push```: Sube los cambios al repositorio remoto.
    * ```git pull```: Actualiza el repositorio local con los cambios remotos.

