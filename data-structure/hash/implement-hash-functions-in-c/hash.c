#include <stdio.h>
#include <math.h>

/**
 * @brief Division Hash
 *
 * This hash function performs division hash method.
 *
 * The mathematical expression of division hash: `h(k) = k mod m`, m > h(k)
 *
 * @param k Key to hash.
 * @param m Size of hash table.
 * @return Hash of the key `k`.
 */
int divisionHash(int k, int m)
{
  return k % m;
}

/**
 * @brief Multiplication Hash
 *
 * This hash function performs multiplication hash method.
 *
 * The mathematical expression: `h(k) = ⌊m(Ak mod 1)⌋`, where `1 < A < 1`.
 *
 * `Ak mod 1 = Ak - ⌊Ak⌋`
 *
 * @param k Key to hash.
 * @param m Size of hash table.
 * @return Hash of the key `k`.
 */
int multiplicationHash(int k, int m)
{
  float Ak = 0.3 * k;

  return floor(m * (Ak - floor(Ak)));
}

int multiplyShiftHash(int k, int m)
{
  int l = 14;
  int d = 32 - l;

  return 0;
}

/**
 * @brief Clear the terminal.
 */
void clearScreen()
{
  // \e[1J clears the screen, \e[H moves cursor to the top-left corner
  printf("\e[1J\e[H");
}

int main()
{
  int inputValue;

  int tableSize = 12;
  int keys[10] = {0, 9, 23, 29, 12, 78, 1001, 129019, 64, 100};

  clearScreen();
  printf("Hash Functions\n");
  printf("=================\n");
  printf("1. Division hash\n");
  printf("2. Multiplication hash\n");
  printf("2. Multiply-shift hash\n");
  printf("Enter option: ");
  scanf("%d", &inputValue);

  clearScreen();
  switch (inputValue)
  {
  case 1:
    printf("Division Hash Function\n");
    printf("======================\n");
    printf("| %-8s | %-7s |\n", "key", "hash");
    printf("======================\n");
    for (int i = 0; i < 10; i++)
    {
      printf("| %8d | %7d |\n", keys[i], divisionHash(keys[i], tableSize));
    }
    printf("======================\n");
    break;
  case 2:
    printf("Multiplication Hash Function\n");
    printf("============================\n");
    printf("| %-11s | %-10s |\n", "key", "hash");
    printf("============================\n");
    for (int i = 0; i < 10; i++)
    {
      printf("| %11d | %10d |\n", keys[i], multiplicationHash(keys[i], tableSize));
    }
    printf("============================\n");
    break;
  case 3:
    printf("Multiply-shift Hash Function\n");
    printf("============================\n");
    printf("| %-11s | %-10s |\n", "key", "hash");
    printf("============================\n");
    for (int i = 0; i < 10; i++)
    {
      printf("| %11d | %10d |\n", keys[i], multiplyShiftHash(keys[i], tableSize));
    }
    printf("============================\n");
    break;

  default:
    break;
  }
  return 0;
}