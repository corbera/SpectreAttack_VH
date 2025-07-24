/**
 * SpectreExperiment.c
 * En esta práctica vamos a ver la base del ataque Spectre, como utilizar la
 * ejecución especulativa para filtrar información de la caché.
 */
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define CHUNK_SIZE 4096

// size: tamaño máximo permitido de acceso al array
int size = 10;
// array: array de 256 elementos, cada uno de tamaño CHUNK_SIZE (CHUNK_SIZE)
uint8_t array[256 * CHUNK_SIZE];

// Límite del número de ciclos de CPU que consideramos para un acierto de caché
// Deberás ajustar este valor
#define CACHE_HIT_THRESHOLD (80)

/*****************************************************************************/
/* SANDBOX                                                                   */
uint8_t temp = 0;

// Función que accede al array comprobando no exceder el tamaño máximo permitido
void victim(size_t x)
{
  if (x < size)
  {
    temp = array[x * CHUNK_SIZE];
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

int main()
{
  // Pasos del experimento:
  // 1.- Inicializar el array y limpiarlo de la caché (flushSideChannel)
  // 2.- Entrenar la CPU repetidamente para que tome la rama verdadera dentro de victim()
  //     LLamar a victim() con cada uno de los valores de 0 a 9 (previamente a la llamada
  //     limpiar de cache la variable size (_mm_clflush(&size) para que se tarde en computar
  //     la condición del if y se tenga que especular).
  // 3.- Explota la ejecución especulativa:
  //     - Limpia de caché el array (_mm_clflush para cada elemento)
  //     - Limpiar de caché la variable size (_mm_clflush(&size))
  //     - Llamar a victim() con un valor que no está en el rango
  // 4.- Acceder a todos (256) los elementos del array y medir el tiempo de acceso (reloadSideChannel)
  /** TODO 3 */

  return (0);
}
