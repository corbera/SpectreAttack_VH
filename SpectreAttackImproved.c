/**
 * SpectreAttackImproved.c
 * En esta práctica vamos a implementar un ataque Spectre V1 mejorado
 */
#include <emmintrin.h>
#include <x86intrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define CHUNK_SIZE 4096

// buffer que se le pasa a la función restrictedAccess() y que vamos a usar para la filtración
uint8_t array[256 * 4096];

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

// scores: array para almacenar el número de aciertos de caché por cada valor
static int scores[256];

// Función que accede a todos los elementos del array y mide el tiempo de acceso
// modificación de la creada en FlushReload.c
void reloadSideChannelImproved()
{
  // Igual que reloadSideChannel(), pero si un valor (de los 256) tiene tiempo < CACHE_HIT_THRESHOLD
  // en lugar de imprimir el valor, incrementa el contador de scores para ese valor (scores[i]++)
  /** TODO 2 */
}

// Función que implementa el ataque Spectre V1 mejorado
// Ligera modificación de la función spectreAttack() de SpectreAttack.c añadiendo
// un paso inicial (0) para limpiar el array de la caché en cada llamada
void spectreAttack(size_t larger_x)
{
  // Pasos del ataque:
  // 0.- Puesto que este ataque se va a llamar repedidamente, primero limpiamos el array de la caché
  //    (llamando a _mm_clflush para cada elemento de los 256)
  // 1.- Entrenar la CPU repetidamente para que tome la rama verdadera dentro de restrictedAccess()
  //     LLamar a restrictedAccess() con cada uno de los valores de 0 a 9 y el array (previamente a la llamada
  //     limpiar de cache la variable buffer_size (_mm_clflush(&buffer_size) para que se tarde en computar
  //     la condición del if y se tenga que especular).
  // 2.- Limpia de caché el array (_mm_clflush para cada elemento de los 256) y buffer_size (_mm_clflush(&buffer_size))
  // 3.- Llamar a restrictedAccess() con el valor larger_x (que no está en el rango de buffer_size)
  /** TODO 3 */
}

int main()
{
  // Calculamos la posición del "secreto" con respecto al comienzo de buffer
  size_t larger_x = (size_t)(secret - (char *)buffer);
  // FLUSH: Inicializamos el array y lo limpiamos de la caché
  flushSideChannel();

  int i;
  // Inicializamos el array de scores a 0
  for (i = 0; i < 256; i++)
    scores[i] = 0;
  // Llamamos repetidamente al ataque para que se acumulen los aciertos en scores
  for (i = 0; i < 1000; i++)
  {
    spectreAttack(larger_x);
    reloadSideChannelImproved();
  }

  int max = 0;
  // Buscamos el valor con más aciertos en scores
  for (i = 0; i < 256; i++)
  {
    if (scores[max] < scores[i])
      max = i;
  }

  // Imprimimos el valor secreto y el número de aciertos
  printf("Reading secret value at %p = ", (void *)larger_x);
  printf("The  secret value is %d\n", max);
  printf("The number of hits is %d\n", scores[max]);
  return (0);
}
