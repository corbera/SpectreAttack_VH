/**
 * Flush+Reload.c
 * En esta práctica vamos a implementar un ataque Flush+Reload para filtrar
 * 1 byte de información.
 */
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define CHUNK_SIZE 4096

// array es un array de 256 elementos, cada uno de tamaño CHUNK_SIZE (4096 bytes).
// Tiene 256 elementos para poder filtrar un byte de información (0-255).
uint8_t array[256 * 4096];

// Límite del número de ciclos de CPU que consideramos para un acierto de caché
// Deberás ajustar este valor
#define CACHE_HIT_THRESHOLD (100)

/*****************************************************************************/
/* SANDBOX                                                                   */
// Variable que contiene el byte secreto que queremos filtrar
char secret = 94;
int temp;

// Función que accede al elemento "secreto" del array que queremos filtrar
void victim()
{
  temp = array[secret * CHUNK_SIZE];
}
/*****************************************************************************/

// Función que inicializa el array para tenerlo en RAM y lo limpia de la caché
void flushSideChannel()
{
  // 1. Iniciliaza las 256 posiciones del array a 1 (array[pos * CHUNK_SIZE] = 1)
  /** TODO 1 */

  // 2. Limpia los elementos del array de la caché para asegurarnos de que no están en caché
  //    Utiliza la instrucción _mm_clflush
  /** TODO 2 */
}

// Función que accede a todos los elementos del array y mide el tiempo de acceso
// Si el tiempo de acceso de una posición "pos" es menor que CACHE_HIT_THRESHOLD,
// significa que el elemento está en caché y debes imprmir un mensaje como:
// "array[pos*CHUNK_SIZE] está en caché, el secreto es: p."
// Si el filtrado de información ha tenido éxito, el valor de "pos" debería coincidir
// con el valor de la variable "secret".
void reloadSideChannel()
{
  // 3. Calcula tiempo de acceso de los 256 elementos del array 
  //    y si es menor que CACHE_HIT_THRESHOLD imprime mensaje.
  //     Documentación _mm_clflush: https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_mm_clflush&ig_expand=750.   
  //     Documentación __rdtscp: https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=__rdtscp&ig_expand=5274
  /** TODO 3 */
}

int main(int argc, const char **argv)
{
  flushSideChannel();
  victim();
  reloadSideChannel();
  return (0);
}
