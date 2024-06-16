# Protocolo I2C
Repositório com alguns código criados para testar a implementação do protocolo I2C com o intuito de aplicar em validação de I2C no microcontrolador PIC.

O protocolo I2C é utilizado para conectar vários dispositivos (microcontroladores, sensores, circuitos integrados etc) por meio de poucos fios, precisamente 2 ficos **SDA** e **SCL**. O pino SCL é utilizado para sincronizar os dispositivos conectados ao barramento I2C. O pino SDA é utilizado para transmitir dados entre dispisitivos controladores e periféricos. Os dispositivos controladores são o que controlam a comunicação, ou seja, realizam as solicitações de escrita ou leitura para os dispositivos periféricos, geralmente são microntroladores como (Arduino, ESP32, PIC, AVR, Raspberry etc). Os dispositivos periféricos são responsáveis por respondar as solicitações enviadas pelos controladores, geralmente são sensores.

Para validar a implementação do I2C em um microcontrolar PIC (atuando como periférico) foi utilizado uma ESP32 para se comunicar com o microcontrolador.
