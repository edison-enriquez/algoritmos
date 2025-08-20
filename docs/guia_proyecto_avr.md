## 6. Limitaciones y alternativas en la depuración AVR

La depuración remota con GDB y simavr puede presentar problemas de compatibilidad, como errores de registros truncados o falta de soporte completo para algunos microcontroladores.

- simavr no soporta completamente la depuración remota con GDB en todas las versiones y chips.
- gdb-multiarch puede no reconocer correctamente los registros simulados.

### Alternativas recomendadas
- Usa simuladores gráficos como `simulide` para pruebas visuales y depuración básica.
- Para depuración avanzada, utiliza hardware real con programadores/debuggers como AVR Dragon o Atmel ICE.
- Para simulación funcional, simavr sigue siendo útil para probar lógica y periféricos, aunque la depuración con GDB puede estar limitada.

Si tienes dudas sobre cómo usar estas herramientas o necesitas ejemplos, ¡consúltame!
# Guía para compilar, simular y depurar proyectos AVR en Linux y VS Code

## 1. Instalación de herramientas

```bash
sudo apt-get install gcc-avr avr-libc simavr simulide
```
- `gcc-avr`: Compilador para AVR.
- `avr-libc`: Librerías estándar para AVR.
- `simavr`: Simulador funcional para microcontroladores AVR.
- `simulide`: Simulador gráfico para circuitos y microcontroladores.

## 2. Compilación y generación de archivo HEX

El código debe ser compatible con AVR (evita funciones como `printf`). Ejemplo de compilación:

```bash
avr-gcc -mmcu=atmega328p -Os -o build/Debug/outDebug_avr src/par_impar_avr.c
avr-objcopy -O ihex build/Debug/outDebug_avr build/Debug/outDebug_avr.hex
```

## 3. Simulación funcional con simavr

```bash
simavr -m atmega328p build/Debug/outDebug_avr
```

## 4. Simulación gráfica con SimulIDE

1. Ejecuta SimulIDE: `simulide`
2. Arrastra un ATmega328P al área de trabajo.
3. Haz doble clic en el microcontrolador y carga el archivo `.hex` generado.
4. Conecta componentes virtuales (LEDs, UART, etc.) y haz clic en “Play”.

## 5. Depuración por impresión
- Usa UART, LEDs o displays para mostrar valores de variables o estados internos durante la ejecución.

## 6. Consideraciones
- La depuración remota con GDB y simavr tiene limitaciones y puede no funcionar correctamente.
- Para depuración avanzada, utiliza hardware real con programadores/debuggers como Atmel ICE o AVR Dragon.
- SimulIDE es ideal para depuración visual y pruebas de lógica embebida.

---

¿Necesitas ejemplos de código para AVR, ayuda con simulación gráfica o debug por impresión?
