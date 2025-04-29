# Lab04: Lectura de ADC y Visualización en LCD I2C con STM32 Blue Pill y ESP32

## Objetivos de aprendizaje

* **Comprender el funcionamiento del ADC (Convertidor Analógico a Digital)**.

* **Configurar y utilizar la comunicación I2C para controlar una pantalla LCD $16\times2$**.

* Integrar la lectura de valores analógicos y su visualización en tiempo real en la LCD.

* Comprender cómo utilizar CubeMonitor para visualizar variables en tiempo real desde un microcontrolador STM32.

* Integrar CubeMonitor con el STM32 y mostrar los valores leídos desde el ADC en un gráfico en tiempo real.

* Desarrollar habilidades en programación embebida utilizando **STM32CubeIDE** y lenguaje ```C```.


## Materiales 

* Placa de desarrollo STM32 Blue Pill (```STM32F103C8T6```).

* Pantalla LCD $16\times2$. 

* Módulo I2C (basado en ```PCF8574```).

* Potenciómetro de $10$ kΩ.

* Protoboard y cables de conexión.

* Entorno de desarrollo STM32CubeIDE.

* CubeMonitor instalado.

## Fundamento teórico

1. Convertidor Analógico a Digital (ADC) en STM32

    El ADC del STM32F103C8T6 es de $12$ bits, lo que permite representar señales analógicas en un rango de $0$ a $4095$. En este laboratorio, se utilizará el canal $0$ (```PA0```) para leer el voltaje proporcionado por un potenciómetro. La conversión se realiza en modo continuo, permitiendo lecturas constantes sin intervención adicional.

    ![adc](/laboratorios/figs/lab04/adc.png)

2. Comunicación I2C y Control de LCD $16\times2$:

    ![i2c](/laboratorios/figs/lab04/i2c.png)

    La pantalla LCD $16\times2$ se controlará en este laboratorio mediante el protocolo I2C utilizando un expansor de puertos ```PCF8574```. Este enfoque reduce la cantidad de pines necesarios para la conexión, ya que utiliza únicamente dos líneas: ```SDA``` (datos) y ```SCL``` (reloj). El módulo suele tener una dirección base de $7$ bits igual a $0\times27$. Sin embargo, en el protocolo I2C, la dirección que se transmite al bus debe tener $8$ bits, donde el último bit indica si se va a leer ($1$) o escribir ($0$). Como en este caso solo se realiza escritura hacia el LCD, la dirección efectiva enviada es $0\times4E$, que resulta de desplazar $0\times27$ una posición a la izquierda ($0\times27 << 1 $). Esta dirección ya se encuentra definida en el código como:

    ```
    #define LCD_ADDR 0x4E
    ```

## Procedimiento

### Parte 1: Configuración del hardware

#### Para STM32: 

1. Conexión del potenciómetro:

    * Conectar los extremos del potenciómetro a VCC ($3.3$ V) y GND.

    * Conectar el terminal central del potenciómetro al pin ```PA0``` del STM32.

2. Conexión de la LCD 16x2 a través del módulo I2C:

    * SDA del módulo I2C a ```PB7``` del STM32.

    * SCL del módulo I2C a ```PB6``` del STM32.
    
### Parte 2: Configuración del proyecto

#### Para STM32: 

1. Crear un nuevo proyecto.

2. El microcontrolador funcionará con el HSI a $8$ MHz (por defecto).

3.  Inicialización del ```ADC1``` (```PA0``` - Canal 0)

    * Se activa el reloj del puerto ```A``` y del ```ADC1```.

    * Se configura PA0 como entrada analógica.

    * Se habilita el ADC en modo continuo.

    * Se inicia la calibración y conversión automática.

4. Inicialización de I2C1 (```PB6=SCL```, ```PB7=SDA```)

    * Se activan los relojes de ```GPIOB```, ```AFIO``` e ```I2C1```.

    * Se configuran ```PB6``` y ```PB7``` como salidas alternativas open-drain.

    * Se configura ```I2C1``` para ```100``` kHz (modo estándar, con PCLK1=36 MHz).

    * Se activa el periférico I2C.

### Parte 3: Instalación de CubeMonitor

**STM32CubeMonitor** es una herramienta de STMicroelectronics que permite monitorear en tiempo real variables del microcontrolador STM32 sin necesidad de implementar un protocolo de comunicación como UART o USB

* ¿Qué hace CubeMonitor?

    * Se conecta al microcontrolador vía ST-LINK (usando SWD).

    * Lee directamente variables desde la memoria RAM.

    * Permite visualizar datos en gráficas, indicadores, tablas, etc.

    * Usa una interfaz de tipo ```Node-RED``` (es decir, basada en flujos con nodos conectados).

Para configurar **CubeMonitor** y visualizar los datos:

1. Instalar CubeMonitor:

    * Descargue e instalue **CubeMonitor** desde el [sitio oficial de STM32CubeMonitor](https://www.st.com/en/development-tools/stm32cubemonitor.html).

2. Conectar el ```STM32``` al **CubeMonitor**:

    * Conectar el STM32 al PC a través del ST-Link.

    * Agregar a su proyecto las líneas que considere de este archivo base [main.c](). Tenga en cuenta que ya cuenta con las librerías ```adc.h``` y ```i2c_lcd.h```.

3. Configurar el flujo para **CubeMonitor**:

    * Descargue el archivo [flows.json](/laboratorios/4_lab04/flows.json)





## Entregables

1. Realice la implementación del código en *github classroom* y presentela
en clase al docente.

2. Modifique el código para convertir la lectura del ADC a tensión.

3. Realice la respectiva documentación de la implementación llevada a cabo.







