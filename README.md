# SpectreAttack
Descubierto en el 2017 y publicado en Enero del 2018, el ataque Spectre explota una serie de vulnerabilidades críticas que existen en muchos procesadores modernos, incluyendo procesadores Intel, AMD y ARM. Estas vulnerabilidades le permiten a un programa romper el aislamiento inter e intra proceso, por lo que un programa malicioso puede leer datos de un área de memoria que no le pertenece. En un escenario normal tal acceso no es permitido debido a las protecciones hardware (para el aislamiento inter-proceso, con soporte del SO) o protecciones de software (para el intra-proceso), pero esta vulnerabilidad existente a nivel de diseño de las CPUs permite saltarse este tipo de protecciones. 


El objetivo de esta práctica es experimentar con el Ataque Spectre. El ataque por sí mismo es bastante sofisticado, por ese motivo, para una mejor comprensión del mismo, se ha fragmentado en una serie de pasos. Una vez realizados cada uno de los pasos, no debería ser muy complicado reunir todos los elementos y proceder a realizar el ataque. La práctica consistirá en usar el ataque Spectre para obtener e imprimir un dato secreto.


En esta práctica se cubren los siguientes aspectos:
- Ataque Spectre
- Ataque de canal encubierto (Side channel)
- CPU caching
- Ejecución fuera de orden y Branch Prediction dentro de la microarquitectura de la CPU
