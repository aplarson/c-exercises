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

void remove_dups(char str[], int count) {
  char seen[26];
  int cur_seen;
  int seen_idx = 0;
  int i;
  int j;
  int k;
  for (i = 0; i < count; i++) {
    if (str[i] == '\0') {
      break;
    }
    cur_seen = 0; 
    for (j = 0; j < 26; j++) {
      if (seen[j] == str[i]) {
        cur_seen = 1; 
      }
    }
    if (cur_seen == 0) {
      seen[seen_idx] = str[i];
      seen_idx += 1;
    } else {
      for (k = i; k < count; k++) {
        str[k] = str[k + 1];
      }
      i -= 1;
    }
  }
}

int main(int argc, char *argv[]) {
  char string[] = "hello world";

  remove_dups(string, 11);
  printf("%s\n", string);
  return 0;
}
