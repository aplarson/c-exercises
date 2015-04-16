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

int max_diff(int *numbers, int count) {
  int diff = 0;
  int left = 0;
  int right = 0;
  int i;
  for (i = 0; i < count; i++) {
    if (numbers[i] < numbers[left]) {
      left = i;
      if (left > right) {
        right = left;
      }
    }
    if (numbers[i] >= numbers[right]) {
      right = i;
    }
    if (numbers[right] - numbers[left] > diff) {
      diff = numbers[right] - numbers[left];
    }
  }
  return diff;
}

int *merge_sort(int *numbers, int count) {
  int list_size = 1;
  int t_idx;
  int i;
  int l_idx;
  int l_max;
  int r_max;
  int r_idx;
  int *target = malloc(count * sizeof(int));
  while(list_size < count) {
    t_idx = 0;
    for(i = 0; i < count; i += (2 * list_size)) {
      l_idx = i;
      r_idx = i + list_size;
      l_max = r_idx;
      r_max = r_idx + list_size < count ? r_idx + list_size : count;
      while(l_idx < l_max && r_idx < r_max) {
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

  int diff = max_diff(numbers, count);
  printf("%d\n", diff);
  free(numbers);

  return 0;
}
