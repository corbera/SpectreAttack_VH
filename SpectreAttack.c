/**
 * SpectreAttack.c
 * En esta práctica vamos a implementar un ataque Spectre V1
 */
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define CHUNK_SIZE 4096

// buffer que se le pasa a la función restrictedAccess() y que vamos a usar para la filtración
uint8_t array[256 * CHUNK_SIZE];

#define CACHE_HIT_THRESHOLD (80)

/*****************************************************************************/
/* SANDBOX                                                                   */
// buffer_size: tamaño del buffer al que se accede de forma restringida
unsigned int buffer_size = 10;
uint8_t buffer[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char *secret = "Some Secret Value";
uint8_t temp = 0;

void restrictedAccess(size_t x, uint8_t a[])
{
  if (x < buffer_size)
  {
    uint8_t s = buffer[x];
    temp = a[s * CHUNK_SIZE];
  }
}
/*****************************************************************************/

// Función que inicializa el array para tenerlo en RAM y lo limpia de la caché,
// creada en FlushReload.c
void flushSideChannel()
{
  // Copiar de FlushReload.c
  /** TODO 1 */
}

// Función que accede a todos los elementos del array y mide el tiempo de acceso
// creada en FlushReload.c
void reloadSideChannel()
{
  // Copiar de FlushReload.c
  /** TODO 2 */
}

// Función que implementa el ataque Spectre V1
void spectreAttack(size_t larger_x)
{
  // Implmenta el ataque: entrena la CPU repetidamente para que tome la rama verdadera dentro de restrictedAccess()
  // y posteriormente llámala con el valor valor larger_x (que no está en el rango de buffer_size).
  /** TODO 3 */
}

int main()
{
  // FLUSH: Inicializamos el array y lo limpiamos de la caché
  flushSideChannel();
  // Calculamos la posición del "secreto" con respecto al comienzo de buffer
  size_t larger_x = (size_t)(secret - (char *)buffer);
  // Lanzamos el ataque con ese valor larger_x
  spectreAttack(larger_x);
  // RELOAD: Accedemos a todos los elementos del array y medimos el tiempo de acceso
  reloadSideChannel();
  return (0);
}
