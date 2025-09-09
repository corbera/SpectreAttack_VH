/**
 * CacheTime.c
 * En esta práctica vamos a medir el tiempo de acceso a diferentes posiciones de un array
 * en función de si están en caché o no.
 */
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define CHUNK_SIZE 4096

// array es un array de 10 elementos, cada uno de tamaño CHUNK_SIZE (4096 bytes).
uint8_t array[10 * CHUNK_SIZE];

int main(int argc, const char **argv)
{
  int junk = 0;
  register uint64_t time1, time2;
  volatile uint8_t *addr;
  int i;
  // Inicializamos los elementos del array a 1
  for (i = 0; i < 10; i++)
    array[i * CHUNK_SIZE] = 1;

  // 1.- FLUSH: Limpia los elementos del array de la caché para asegurarnos de que no
  //     están en caché (utiliza la instrucción _mm_clflush)
  //     Documentación _mm_clflush: https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_mm_clflush&ig_expand=750
  /** TODO 1 */

  // Accedemos a un par de elementos del array para que estén en caché
  array[3 * CHUNK_SIZE] = 100;
  array[7 * CHUNK_SIZE] = 200;

  // 2.- RELOAD: Mide el tiempo de acceso a cada uno de los 10 trozos e imprime 
  //     un mensaje como "Tiempo de acceso para array[i*CHUNK_SIZE]: X CPU cycles"
  //     donde X es el tiempo de acceso medido.
  //     Documentación __rdtscp: https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=__rdtscp&ig_expand=5274
  /** TODO 2 */

  return 0;
}
