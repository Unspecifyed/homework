#include <cs50.h>
#include <stdio.h>
#include <string.h>
bool valid(int count, string key);
bool caps(char c);
void cyper(string key, string ptext);
char lowerChar(char c);
char upperChar(char c);
bool isSpace(char c);
int main(int argc, string argv[])
{
  const int ARGUMENTCOUNT = argc;
  const string KEY = argv[1];
  const bool VALIDKEY = valid(ARGUMENTCOUNT, KEY);

  if (!VALIDKEY)
  {
    return 1;
  }
  const string PLAINTEXT = get_string("plaintext: ");
  printf("ciphertext: ");
  cyper(KEY, PLAINTEXT);

  return 0;
}

bool valid(int count, string key)
{
  bool isValid = true;
  if (key == NULL)
  {
    printf("Usage: ./substitution key");
    return false;
  }
  int length = strlen(key);
  if (count != 2)
  {
    printf("Usage: ./substitution key");
    isValid = false;
  }

  if (length != 26)
  {
    printf("Key must contain 26 characters.");
    isValid = false;
  }

  return isValid;
}

bool caps(char c)
{
  bool isCaps = false;
  if (c > 64 && c < 91)
  {
    isCaps = true;
  }
  return isCaps;
}

void cyper(string key, string ptext)
{
  int i = 0;
  int cAmount = 65;
  int lAmount = 97;
  char out = '0';
  while (i <= strlen(ptext))
  {
    char plainChar = ptext[i];
    bool plainCharCaps = caps(plainChar);
    int plainCharValue = 0;
    bool spaceChar = false;
    if (plainChar == ' ')
    {
      plainCharValue = 0;
      spaceChar = true;
    }
    else if (plainCharCaps)
    {
      plainCharValue = plainChar - cAmount;
    }
    else
    {
      plainCharValue = plainChar - lAmount;
    }
    char cLetter = key[plainCharValue];
    if (caps(cLetter) && !caps(plainChar))
    {
      out = lowerChar(cLetter);
    }
    else if (!caps(cLetter) && caps(plainChar))
    {
      out = upperChar(cLetter);
    }
    else
    {
      out = cLetter;
    }

    if (spaceChar)
    {
      printf(" ");
    }
    else
    {
      printf("%c", out);
    }

    i++;
  }
  printf("\n");
}
char lowerChar(char c)
{
  c = c + 32;
  return c;
}
char upperChar(char c)
{
  c = c - 32;
  return c;
}
bool isSpace(char c)
{
  if (c == ' ')
  {
    return true;
  }
  else
  {
    return false;
  }
}