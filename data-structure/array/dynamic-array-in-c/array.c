#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Dynamic Array
 * @brief A dynamic array.
 *
 * This structure implments a simple dynamic array.
 */
typedef struct DynamicArray
{
  /**
   * @brief Array to store elements.
   */
  int *data;

  /**
   * @brief Length or size of the array.
   */
  int length;

  /**
   * @brief capacity of the array.
   */
  int capacity;
} DynamicArray;

/**
 * @brief Create a dynamic array.
 *
 * This function creates a simple dynamic array.
 *
 * @param initailCapacity Initial capacity of the array.
 * @return Dynamic array if successfull, `NULL` otherwise.
 */
DynamicArray *createDynamicArray(int initailCapacity)
{
  initailCapacity = initailCapacity > 0 ? initailCapacity : 8;

  DynamicArray *d = (DynamicArray *)malloc(sizeof(DynamicArray));
  if (!d)
  {
    return NULL;
  }

  d->data = (int *)malloc(initailCapacity * sizeof(int));
  if (!d->data)
  {
    free(d);
    return NULL;
  }

  d->length = 0;
  d->capacity = initailCapacity;

  return d;
}

/**
 * @brief Resize the array capacity.
 *
 * This function resizes the capacity of the array so that it does not overflow.
 *
 * @param d Pointer to the dynamic array.
 * @param newCapacity New capacity to increase the array size. New capacity must be greater than current capacity.
 * @return true if resize is successful, false otherwise.
 */
bool resize(DynamicArray *d, int newCapacity)
{
  if (newCapacity <= d->length)
  {
    printf("New capacity must be greater than the array length.\n");
    return false;
  }

  int *temp = d->data;
  int *newData = (int *)realloc(temp, newCapacity * sizeof(int));
  if (!newData)
  {
    printf("Memory allocation failed.\n");
    return false;
  }

  d->data = newData;
  d->capacity = newCapacity;
  return true;
}

/**
 * @brief Insert new element.
 *
 * This function insert a new element at the end of the array.
 *
 * @param d Pointer to the dynamic array.
 * @param value The value to insert into the array.
 */
void push(DynamicArray *d, int value)
{
  if (!d)
  {
    printf("Array does not exits.\n");
    return;
  }

  if (d->length == d->capacity)
  {
    if (!resize(d, d->capacity * 2))
    {
      return;
    }
  }

  d->data[d->length] = value;
  d->length++;
}

/**
 * @brief Delete an element.
 *
 * This function deletes an element from the end of the array.
 *
 * @param d Pointer the to dynamic array.
 * @return Value if successfull, `NULL` otherwise.
 */
int pop(DynamicArray *d)
{
  if (!d || d->length == 0)
  {
    printf("Array does not exits.\n");
    return -1;
  }

  int value = d->data[d->length - 1];
  d->length--;

  // Resize the array if the length becomes smaller or equal to one-forth of the current capacity.
  if (d->length > 0 && d->length <= d->capacity / 4 && d->capacity > 8)
  {
    resize(d, d->capacity / 2);
  }

  return value;
}

/**
 * @brief Delete array from memory
 *
 * This function removes all array data and the array struct from memory.
 *
 * @param d Pointer the to dynamic array.
 */
void freeArray(DynamicArray *d)
{
  if (d)
  {
    free(d->data);
    free(d);
  }
}

/**
 * @brief Print array.
 *
 * This function prints the array with its length and current capacity.
 *
 * @param d Pointer the to dynamic array.
 */
void printArray(DynamicArray *d)
{
  if (!d)
  {
    printf("Array does not exits.\n");
    return;
  }

  printf("[");
  for (int i = 0; i < d->length; i++)
  {
    printf("%d%s", d->data[i], i != d->length - 1 ? ", " : "");
  }
  printf("]\n");
  printf("Array lenght: %d\n", d->length);
  printf("Array capacity: %d\n", d->capacity);
}

/**
 * @brief Clear the terminal.
 */
void clearScreen()
{
  // \e[1J clears the screen, \e[H moves cursor to the top-left corner
  printf("\e[1J\e[H");
}

/**
 * @brief Interrupts the program.
 *
 * This function interrupts the program to print some warning or error before clearing the screen.
 */
void pressEnterToContinue()
{
  // clear input buffer.
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Press ENTER to continue...");
  getchar();
}

int main()
{
  bool running = true;
  char choice;
  int operation;
  int inputValue;

  DynamicArray *d = NULL;

  while (running)
  {
    if (!d)
    {
      clearScreen();
      printf("=== C Dynamic Array ===\n");

      printf("Create a dynamic array (y/n): ");
      scanf(" %c", &choice);
      if (choice == 'y' || choice == 'Y')
      {
        d = createDynamicArray(0);
      }
      else if (choice == 'n' || choice == 'N')
      {
        running = false;
        printf("Exiting application, bye!\n");
      }
      else
      {
        printf("Invalid input!\n");
        pressEnterToContinue();
      }
    }
    else
    {
      printf("\n");
      printArray(d);
      printf("Menus\n");
      printf("1. Push a value.\n");
      printf("2. Pop a value.\n");
      printf("3. Free array.\n");
      printf("4. Exit application\n");
      printf("Enter your choice (1 - 4): ");
      scanf("%d", &operation);

      switch (operation)
      {
      case 1:
        printf("Value: ");
        scanf("%d", &inputValue);
        push(d, inputValue);
        break;
      case 2:
        pop(d);
        break;
      case 3:
        free(d->data);
        free(d);
        break;
      case 4:
        running = false;
        printf("Exiting application, bye!\n");
        break;
      default:
        printf("%d is not a valid operation.\n", operation);
        break;
      }
    }
  }

  return 0;
}