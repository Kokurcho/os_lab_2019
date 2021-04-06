#include "find_min_max.h"
#include "stdio.h"
#include <limits.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end) {
  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;

int i;


printf("\n");
 for ( i = begin; i < end; i++)
 {
    if(min_max.min > array[i])
        min_max.min = array[i];
    else 
        continue;
    
 }

 for ( i = begin; i < end; i++)
 {
    if(min_max.max < array[i])
        min_max.max = array[i];
    else 
        continue;
    
 }
  return min_max;
}