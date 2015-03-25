#include <stdio.h>

void reverse(char *str, int count) {
  char temp;
  int i;
  for (i = 0; i < count / 2; i++) {
    temp = str[i];
    str[i] = str[count - (i + 1)];
    str[count - (i + 1)] = temp;
  }
}

void caesar_cipher(char str[], int shift, int count) {
  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  int i;
  int j;
  int letter_pos;
  for (i = 0; i < count; i++) {
    for (j = 0; j < 26; j++) {
      if (letters[j] == str[i]) {
        letter_pos = j;
      }
    }
    letter_pos += shift;
    if (letter_pos > 25) {
      letter_pos -= 26;
    }
    str[i] = letters[letter_pos];
  }
}

int main(int argc, char *argv[]) {
  char string[] = "helloworld";

  caesar_cipher(string, 20, 10);
  printf("%s\n", string);
  return 0;
}
