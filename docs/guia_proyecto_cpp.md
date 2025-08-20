# Guía paso a paso para crear un proyecto en C++

## 1. Estructura de carpetas

- **src/**: Contiene el código fuente principal (.cpp).
- **include/**: Archivos de cabecera (.h/.hpp) para declarar funciones y clases.
- **build/**: Carpeta para archivos generados durante la compilación.
- **build/Debug/**: Ejecutables y archivos de depuración.
- **bin/**: Ejecutables finales listos para distribución.
- **docs/**: Documentación del proyecto (manuales, tutoriales, especificaciones).

## 2. Creación de carpetas

```bash
mkdir -p src include build/Debug bin docs
```
- `mkdir`: Comando para crear carpetas.
- `-p`: Crea carpetas intermedias si no existen.

## 3. Compilación del código fuente

```bash
g++ src/par_impar.cpp -o build/Debug/outDebug
```
- `g++`: Compilador de C++.
- `src/par_impar.cpp`: Archivo fuente a compilar.
- `-o build/Debug/outDebug`: Ruta y nombre del ejecutable generado.

## 4. Ejecución del programa

```bash
./build/Debug/outDebug
```
- Ejecuta el programa compilado.

## 5. Configuración de depuración

En VS Code, configura el archivo `launch.json` para depurar el ejecutable:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug C++",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/Debug/outDebug",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        { "description": "Enable pretty-printing", "text": "-enable-pretty-printing", "ignoreFailures": true }
      ]
    }
  ]
}
```

## 6. Compilación para otra arquitectura (cross-compiling)

### Para ARM:

```bash
sudo apt-get install g++-arm-linux-gnueabihf
arm-linux-gnueabihf-g++ src/par_impar.cpp -o build/Debug/outDebug_arm
```
- `arm-linux-gnueabihf-g++`: Compilador para ARM.
- El ejecutable generado solo funcionará en sistemas ARM.

### Para RISC-V:

```bash
sudo apt-get install gcc-riscv64-linux-gnu
riscv64-linux-gnu-g++ src/par_impar.cpp -o build/Debug/outDebug_riscv
```
- `riscv64-linux-gnu-g++`: Compilador para RISC-V.

## 7. Simulación en otra arquitectura

### ARM:

```bash
sudo apt-get install qemu-user
qemu-arm build/Debug/outDebug_arm
```
- `qemu-arm`: Emulador para ejecutables ARM.

### RISC-V:

```bash
sudo apt-get install qemu-user
qemu-riscv64 build/Debug/outDebug_riscv
```
- `qemu-riscv64`: Emulador para ejecutables RISC-V.




Esta guía te permite crear, compilar, depurar y simular proyectos en diferentes arquitecturas. Si necesitas ejemplos más detallados o ayuda con algún paso, ¡avísame!

### Compilar con símbolos de depuración
```bash
riscv64-linux-gnu-gcc -static -g src/par_impar.c -o build/Debug/outDebug_riscv_static
```
- `-g`: Incluye información de depuración.
- `-static`: Genera un ejecutable estático (sin dependencias externas).

### Iniciar QEMU en modo GDB server
```bash
qemu-riscv64 -g 1234 build/Debug/outDebug_riscv_static
```
- `-g 1234`: QEMU espera conexiones de GDB en el puerto 1234.

### Instalar y usar GDB multi-arquitectura
```bash
sudo apt-get install gdb-multiarch
gdb-multiarch build/Debug/outDebug_riscv_static
```
En GDB, conecta al servidor QEMU:
```
target remote :1234
```
Ahora puedes usar comandos como `break`, `step`, `next`, `continue`, `print`.

### Configuración de depuración en VS Code
Agrega esta configuración en `.vscode/launch.json`:
```json
{
  "name": "Debug RISC-V (QEMU + GDB)",
  "type": "cppdbg",
  "request": "launch",
  "program": "${workspaceFolder}/build/Debug/outDebug_riscv_static",
  "miDebuggerServerAddress": "localhost:1234",
  "miDebuggerPath": "/usr/bin/gdb-multiarch",
  "cwd": "${workspaceFolder}",
  "stopAtEntry": true,
  "MIMode": "gdb",
  "setupCommands": [
    { "description": "Enable pretty-printing", "text": "-enable-pretty-printing", "ignoreFailures": true }
  ]
}
```

### Solución de problemas comunes
- Si VS Code muestra "Unable to start debugging. The value of miDebuggerPath is invalid":
  - Instala `gdb-multiarch` y verifica la ruta con `which gdb-multiarch`.
- Si VS Code muestra "could not connect: Connection timed out":
  - Asegúrate de que QEMU esté corriendo en modo GDB server antes de iniciar la depuración.
- Si QEMU muestra errores de bibliotecas faltantes, compila el ejecutable como estático (`-static`).
