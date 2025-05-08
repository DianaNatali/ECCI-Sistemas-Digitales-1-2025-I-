# Lab05: Generación de Señal PWM con STM32 Blue Pill o ESP32

* Comprender y aplicar los principios del modulador por ancho de pulso (PWM) mediante la configuración y programación de periféricos en microcontroladores para el control de dispositivos electrónicos.

* Identificar los conceptos fundamentales del PWM y su aplicación en sistemas embebidos.

* Configurar un periférico generador de señales PWM en un microcontrolador (STM32, ESP32 u otro) usando herramientas de desarrollo adecuadas.

* Variar parámetros como frecuencia y ciclo de trabajo (duty cycle) para observar sus efectos sobre la señal generada.

* Visualizar y analizar la señal PWM generada mediante instrumentos de medición (como osciloscopios o analizadores lógicos).

* Aplicar señales PWM en tareas de control básicas como regulación de brillo en LEDs o velocidad en motores DC.

## Materiales 

* Placa de desarrollo STM32 Blue Pill (```STM32F103C8T6```) o ESP32.

* Pantalla LCD $16\times2$. 

* Módulo I2C (basado en ```PCF8574```).

* Potenciómetro de $10$ kΩ.

* Protoboard y cables de conexión.

* Entorno de desarrollo.

* LED y resistencias


## Fundamento teórico 

### PWM

PWM (Pulse Width Modulation) o Modulación por Ancho de Pulsos es una técnica ampliamente utilizada para controlar la potencia entregada a dispositivos eléctricos mediante la variación del ancho de los pulsos en una señal digital de alta frecuencia. Esta modulación se utiliza para controlar la cantidad de energía que se suministra a una carga, como un motor, un LED o incluso en sistemas de regulación de voltaje.

<div align="center">
 <img src="/laboratorios/figs/lab05/PWM.png" alt="pwm" width="600" />
</div>

**Características clave de la señal PWM**:

1. **Frecuencia**:
Es la cantidad de ciclos completos de la señal por segundo. La frecuencia de la señal PWM determina cuántos pulsos por segundo se envían al dispositivo. La frecuencia es importante porque debe ser alta lo suficiente como para que el ojo humano no perciba el parpadeo o el zumbido de los dispositivos, como un LED o un motor. Sin embargo, debe ser lo suficientemente baja como para no generar interferencia o ruido eléctrico.

$$ f = \dfrac{1}{\text{período}(T)} = \dfrac{1}{f}$$

2. **Ciclo de trabajo (Duty Cycle)**:
 El ciclo de trabajo es el porcentaje del tiempo durante el cual la señal permanece en un nivel alto (encendida) durante un ciclo. Se calcula como la fracción del tiempo en que la señal está en estado alto con respecto al tiempo total del ciclo.


 $$ \text{Ciclo de trabajo} = \dfrac{\text{Tiempo en alto}}{\text{Período} (T)} \times 100 $$  


3. **Frecuencia y ciclo de trabajo**: La frecuencia y el ciclo de trabajo están relacionados, pero son independientes en cuanto al control. Mientras que la frecuencia controla cuántos ciclos se repiten por segundo, el ciclo de trabajo controla la cantidad de tiempo que la señal permanece "encendida" dentro de cada ciclo.


<div align="center">
 <img src="/laboratorios/figs/lab05/PWM02.gif" alt="pwm" width="550" />
 </div>
 
 Tomado de **[1]**


 ## Explicación de la implementación de PWM en ESP32 y STM32

La generación de señales PWM (Modulación por Ancho de Pulso) es un proceso fundamental en muchos sistemas embebidos, especialmente cuando se requiere controlar la velocidad de un motor, la intensidad de un LED o la posición de un servomotor. A continuación, se explica cómo se implementa el control de PWM en dos plataformas seleccionadas para trabajar en este curso: ESP32 y STM32.

### 1. ESP32

Se utiliza el controlador de LEDs (```ledc```) que es capaz de generar señales PWM en varios pines GPIO. El temporizador de alta velocidad (```ledc_timer```) controla la frecuencia de la señal PWM, y cada canal de salida (```ledc_channel```) puede ajustar el ciclo de trabajo. En este labroatorio, se configurará un temporizador de $500$ Hz y resoluciones de $11$ bits para el ciclo de trabajo.

El controlador LED_PWM (```ledc```) está diseñado principalmente para controlar la intensidad de los LED, aunque también puede utilizarse para generar señales PWM con otros fines. Cuenta con 16 canales que generan formas de onda independientes que pueden utilizarse para controlar dispositivos LED RGB.

* **Configuración del temporizador**: Se utiliza la función ```ledc_timer_config``` para definir la frecuencia y la resolución del temporizador que generará la señal PWM.

* **Configuración del Canal de PWM**: La señal PWM se asocia a un pin GPIO mediante ```ledc_channel_config```, donde se define el canal, el modo de salida y el ciclo de trabajo inicial.

* **Control de Duty Cycle**: La variable ```duty``` se ajusta de manera incremental en el ciclo principal del programa. La función ```ledc_set_duty``` se usa para actualizar el ciclo de trabajo del PWM, y ```ledc_update_duty``` aplica el cambio.

* **Generación de señal PWM**: El ciclo de trabajo se incrementa en pasos de $20$% cada $500$ ms, produciendo un cambio continuo en la intensidad de la señal.

<div align="center">
 <img src="/laboratorios/figs/lab05/pwmesp32.png" alt="pwm" width="550" />
 </div>

Tomado de **[2]**


En la imagen se evidencia:

* **Timer (Temporizador)**: Se configura con la frecuencia de PWM y la resolución del ciclo de trabajo.

* **Channel (Canal)**: Controla el ciclo de trabajo del PWM, que a su vez regula la intensidad de la señal enviada a los pines GPIO.

* **GPIO (Pin de salida)**: El pin que genera la señal PWM.

El diagrama también menciona el *Fade Control* y la posibilidad de usar interrupciones, lo cual es útil para controlar transiciones suaves (desvanecimiento) y realizar acciones específicas cuando cambiar los valores de ciclo útil PWM, pero en el paqute de trabajo de Github Classroom no se emplean.


**Se recomienda consultar: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/ledc.html**


 #### Conexiones

 <div align="center">
 <img src="/laboratorios/figs/lab05/esp32.png" alt="pwm" width="450" />
 </div>




### 2. STM32

El sistema de generación de PWM se basa en el uso de temporizadores de propósito general, como el ```TIM2```. Al igual que en el ESP32, el temporizador se configura para que su frecuencia de operación y el ciclo de trabajo sean controlados.


* **Configuración del reloj**: Se habilitan los relojes de los módulos ```GPIOA``` y ```TIM2``` para habilitar el uso del pin y el temporizador, respectivamente.

* **Configuración del pin**: El pin ```PA0``` se configura como salida alternada en modo push-pull para generar la señal PWM.

* **Configuración del temporizador**: Se configura el ```TIM2``` con un prescaler para generar una frecuencia de $500$ Hz. La resolución del ciclo de trabajo se ajusta en el registro ```CCR1```.

* **Control del Duty Cycle**: El ciclo de trabajo se ajusta incrementando el valor de ```CCR1``` en pasos de $20$%. El programa utiliza una función de retardo para espaciar los cambios de ciclo de trabajo.

* **Generación de señal PWM**: Al igual que en el ESP32, se incrementa el ciclo de trabajo en pasos de $20$% para observar cambios en la señal.


 #### Conexiones

 <div align="center">
 <img src="/laboratorios/figs/lab05/stm32.png" alt="pwm" width="450" />
 </div>


