#include <avr/io.h>

int main(void) {
    // Configura el puerto B como salida
    DDRB = 0xFF;
    int numero = 5; // Cambia este valor para probar

    // Si el número es par, enciende el pin PB0, si es impar, apaga PB0
    if (numero % 2 == 0) {
        PORTB |= (1 << PB0); // Enciende PB0
    } else {
        PORTB &= ~(1 << PB0); // Apaga PB0
    }

    while (1) {
        // Bucle infinito, típico en sistemas embebidos
    }
    return 0;
}
