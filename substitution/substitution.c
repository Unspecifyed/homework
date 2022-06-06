#include <cs50.h>
#include <stdio.h>
#include <string.h>
bool valid(int count, string key);
bool caps(char c);
void cyper(string key, string ptext);
char lowerChar(char c);
char upperChar(char c);
bool isSpace(char c);
bool isDuplicate(string s);
bool isValidChars(string s);
int main(int argc, string argv[])
{
  const int ARGUMENTCOUNT = argc;
  const string KEY = argv[1];

  if (!valid(ARGUMENTCOUNT, KEY))
    return 1;
  if(!isValidChars(KEY))
    return 1;
  const string PLAINTEXT = get_string("plaintext: ");
  printf("ciphertext: ");
  cyper(KEY, PLAINTEXT);

  return 0;
}

bool valid(int count, string key)
{
  if (key == NULL)
  {
    printf("Usage: ./substitution key");
    return false;
  }
  int length = strlen(key);
  if (count != 2)
  {
    printf("Usage: ./substitution key");
    return false;
  }

  if (length != 26)
  {
    printf("Key must contain 26 characters.");
    return false;
  }
  if (isDuplicate(key))
    return false;

  return true;
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
  char plainChar = ptext[i];
  while (plainChar != '\0')
  {
    plainChar = ptext[i];
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
bool isDuplicate(string s)
{
  int outer = 0;
  char outerC = '!';
  int inner = 0;
  char innerC = '!';
  while (s[outer] != '\0')
  {
    if (inner == outer)
    {
      inner++;
    }
    outerC = s[outer];

    while (s[inner] != '\0')
    {
      innerC = s[inner];
      if (outerC == innerC)
      {
        return true;
      }
      inner++;
    }
    outer++;
  }

  return false;
}
bool isValidChars(string s)
{
  int i = 0;
  char iChar = '!';
  bool statment =true;
  while (iChar != '\0')
  {
    iChar = s[i];
    if (upperChar(s[i])) i++;
    else if( lowerChar(s[i])) i++;
    else {
      statment = false;
      i++;
      break;
    }
  }
  return statment;
}