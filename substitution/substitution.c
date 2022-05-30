#include <cs50.h>
#include <stdio.h>
#include <string.h>
bool valid(int count, string key);
bool caps(char c);
void cyper(string key, string ptext);
int main(int argc, string argv[]) {
  const int ARGUMENTCOUNT = argc;
  const string KEY = argv[1];
  const bool VALIDKEY = valid(ARGUMENTCOUNT, KEY);

  if (!VALIDKEY) {
    return 1;
  }

  const string PLAINTEXT = get_string("plaintext: ");
  cyper(KEY, PLAINTEXT);

  return 0;
}

bool valid(int count, string key) {
  bool isValid = true;
  if (key == NULL) {
    printf("Usage: ./substitution key");
    return false;
  }
  int length = strlen(key);
  if (count != 2) {
    printf("Usage: ./substitution key");
    isValid = false;
  }

  if (length != 26) {
    printf("Key must contain 26 characters.");
    isValid = false;
  }
  if (isValid) {
    int n = 0;
    int nSub = 0;
    while (n < 26) {
      char a = key[n];
      if (a == ' ') {
      } else {
        while (nSub < 26) {
          char b = key[nSub];
          if (a == b) {
            return false;
          }
          nSub++;
        }
      }
      n++;
    }
  }
  return isValid;
}

bool caps(char c) {
  bool isCaps = false;
  if (c > 64 && c < 91) {
    isCaps = true;
  }
  return isCaps;
}

void cyper(string key, string ptext) {
  int i = 0;
  int cAmount = 65;
  int lAmount = 97;
  int pValue = 0;
  char out = 'a';
  while (ptext[i] != '\0') {
    if (caps(ptext[i])) {
      pValue = ptext[i] - cAmount;
    } else {
      pValue = ptext[i] - lAmount;
    }
    out = key[pValue];
    printf("%c", out);
    i++;
  }
}