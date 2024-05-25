// Se declara una variable de tipo "boolean volatile" llamada "flag". 
// "volatile" > se usa para indicar que la variable puede ser modificada en cualquier momento (incluso dentro de una ISR)
volatile boolean flag; 

// Interrupt Service Routine (ISR) > Rutina de Servicio de Interrupciones
void isr () {
  flag = true; // se establece la variable flag en true para indicar que ha ocurrido una interrupción.
} // fin de la interrupcion

void setup () {
  // configuracion de una interrupcion en el PIN digital 2 >
  // "attachInterrupt()" toma tres argumentos...
  // 1 > especifica el número del pin en el que se producirá la interrupción
  // 2 > es el nombre de la función que se ejecutará cuando se produzca la interrupción (en este caso, "isr")
  // 3 > indica cuándo se activará la interrupción (en este caso se activa con CHANGE)...
  // ... esto quiere decir que la interrupción se activará cuando haya un cambio de estado en el pin (ya sea de bajo a alto o de alto a bajo)
  attachInterrupt (digitalPinToInterrupt (2), isr, CHANGE); // Se adjunta el manejador de interrupción (ISR) a la interrupción del pin digital 2 (INT0) que se activa en cualquier cambio (CHANGE).
} // fin del setup

void loop() { //inicio del loop
  if (flag) { // Si "flag" es "true" (es decir, si se ha producido una interrupción)...
    // Sección donde se maneja la interrupción
    // ...la acción específica se ha omitido, pero se indica que ha ocurrido una interrupción
  }
} // fin del loop 