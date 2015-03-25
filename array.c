#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

int *merge_sort(int *numbers, int count) {
  int list_size = 1;
  int t_idx;
  int i;
  int l_idx;
  int r_idx;
  int *target = malloc(count * sizeof(int));
  while(list_size < count) {
    t_idx = 0;
    for(i = 0; i < count; i += (2 * list_size)) {
      l_idx = i;
      r_idx = i + list_size;
      while(l_idx < i + list_size && r_idx < i + (2 * list_size) && r_idx < count) {
        if(numbers[l_idx] < numbers[r_idx]) {
          target[t_idx] = numbers[l_idx];
          l_idx++;
        } else {
          target[t_idx] = numbers[r_idx];
          r_idx++;
        }
        t_idx++;
      }
      while(l_idx < i + list_size && l_idx < count) {
        target[t_idx] = numbers[l_idx];
        l_idx++;
        t_idx++;
      }
      while(r_idx < i + (2 * list_size) && r_idx < count) {
        target[t_idx] = numbers[r_idx];
        r_idx++;
        t_idx++;
      }
    }

    list_size *= 2;
    memcpy(numbers, target, count * sizeof(int));
  }
  free(target);

  return numbers;
}

void test_sorting(int *numbers, int count)
{
    int i = 0;
    int *sorted = merge_sort(numbers, count);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("USAGE: array 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if(!numbers) die("Memory error.");

  for(i = 0; i < count; i++) {
     numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count);

  free(numbers);

  return 0;
}
