#include <stdio.h>
#include <stdlib.h>

int isWon(int stack[]) {
  if (stack[0] == 3 && stack[1] == 2 && stack[2] == 1) {
    return 1;  
  }
  return 0;
}

int isValid(int from_disc, int to_disc) {
  if (from_disc > 0 && (to_disc == 0 || from_disc < to_disc)) {
    return 1;
  } 
  return 0;
}

void play() {
  int stacks[3][3] = {{3, 2, 1}, {}, {}};
  int from_choice;
  int to_choice;
  char from_str[3];
  char to_str[3];
  int stack_tops[3] = {2, -1, -1};
  while (isWon(stacks[1]) == 0 && isWon(stacks[2]) == 0) {
    printf("%d %d %d\n", stacks[0][0], stacks[0][1], stacks[0][2]);
    printf("%d %d %d\n", stacks[1][0], stacks[1][1], stacks[1][2]);
    printf("%d %d %d\n", stacks[2][0], stacks[2][1], stacks[2][2]);

    printf("From which stack would you like to move?\n");
    fgets(from_str, 3, stdin);
    from_choice = atoi(from_str);
    int from_pos = stack_tops[from_choice] < 0 ? 0 : stack_tops[from_choice];
    int from_disc = stacks[from_choice][from_pos];

    printf("To which stack would you like to move?\n");
    fgets(to_str, 3, stdin);
    to_choice = atoi(to_str);
    int to_pos = stack_tops[to_choice] < 0 ? 0 : stack_tops[to_choice];
    int to_disc = stacks[to_choice][to_pos];

    if (isValid(from_disc, to_disc) == 1) {
      stacks[from_choice][from_pos] = 0;
      stacks[to_choice][stack_tops[to_choice] + 1] = from_disc;
      stack_tops[from_choice] -= 1;
      stack_tops[to_choice] += 1;
    }
  }
  printf("You win!");
}

int main(int argc, char *argv[]) {
  play();
  return 0;
}
