#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Stack
 * @brief Array based dynamic stack implementation for integers.
 * This structure implements a standard Last-In, First-Out (LIFO) stack. It manages an array dynamically allocated on the heap, allowing the stack to grow or shrink in capacity as needed.
 */
typedef struct
{
  int *data;    // Array to store stack elements
  int topIndex; // Index of the top element (-1 when empty)
  int capacity; // Maximum elements the stack can currently hold
} Stack;

/**
 * @brief Creates a new stack.
 *
 * `createStack()` function creates a stack with 1 capacity. It allocate memory of `Stack` size.
 *
 * @return `Stack` if successful, `NULL` if memory allocation failed.
 */
Stack *createStack()
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));

  if (!stack)
    return NULL;

  stack->capacity = 1;
  stack->topIndex = -1; // -1 means the stack is empty
  stack->data = (int *)malloc(stack->capacity * sizeof(int));

  if (!stack->data)
  {
    free(stack);
    return NULL;
  }

  return stack;
}

/**
 * @brief Checks if stack is empty or not.
 * @param stack Pointer of targeted stack.
 * @return `true` if empty, `false` if not empty.
 */
bool isEmpty(Stack *stack)
{
  return stack->topIndex == -1;
}

/**
 * @brief Size of stack.
 * @param stack Pointer of targeted stack.
 * @return 0 if stack is empty, greater then 0 if stack is not empty.
 */
int size(Stack *stack)
{
  return stack->topIndex + 1;
}

/**
 * @brief Inserts a new element into a stack.
 *
 * `push` function inserts a new element at the end of the stack. if stack is overflowed, it resizes the stack by reallocating memory.
 *
 * @param stack Pointer of targeted stack.
 * @param value Value to push into the targeted stack.
 */
void push(Stack *stack, int value)
{
  // If the array is full, double its capacity dynamically
  if (stack->topIndex == stack->capacity - 1)
  {
    stack->capacity *= 2;

    int *temp = (int *)realloc(stack->data, stack->capacity * sizeof(int));

    // check if memory reallocation is successful.
    if (temp == NULL)
    {
      fprintf(stderr, "Memory allocation failed!\n");
      free(stack->data);
      exit(1);
    }
    stack->data = temp;
  }

  // Increment top index and insert the value
  stack->data[++stack->topIndex] = value;
  printf("Push %d into the stack.\n", value);
}

/**
 * @brief Removes an element.
 *
 * `pop` function removes the last inserted element from the stack.
 *
 * @param stack Pointer of targeted stack.
 * @return Removed element, -1 if stack is empty.
 */
int pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty (underflow)!\n");
    return -1;
  }

  // return the element and decrement the topIndex
  return stack->data[stack->topIndex--];
}

/**
 * @brief Top element of the stack.
 * @param stack Pointer of targeted stack.
 * @return Top element, -1 if stack is empty.
 */
int top(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty (underflow)! No top element.\n");
    return -1;
  }

  return stack->data[stack->topIndex];
}

/**
 * @brief Free stack from memory.
 *
 * Clean up memory to prevent memory leaks
 *
 * @param stack Pointer of targeted stack.
 */
void freeStack(Stack *stack)
{
  if (stack)
  {
    free(stack->data);
    free(stack);
  }
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
  char choice;
  int operation;
  bool running = true;
  int value;

  Stack *s = NULL;

  printf("=== C Stack ===\n");

  // This loop keeps the app running indefinitely
  while (running)
  {
    if (!s)
    {
      clearScreen();
      printf("Create Stack (y/n): ");
      scanf(" %c", &choice);

      if (choice == 'y' || choice == 'Y')
      {
        s = createStack();
      }
      else if (choice == 'n' || choice == 'N')
      {
        freeStack(s);
        printf("\nExiting the application. Goodbye!\n");
        running = false; // This breaks the while loop
      }
      else
      {
        while (getchar() != '\n')
          ;
        clearScreen();
        printf("Invalid input.\n\n");
        continue;
      }
    }
    else
    {
      printf("\n");
      printf("1. Push new value\n");
      printf("2. Pop value\n");
      printf("3. Top element\n");
      printf("4. Size of stack\n");
      printf("5. Free stack\n");
      printf("6. Exit\n");
      printf("Enter your choice (1-5): ");

      // Read user input
      if (scanf("%d", &operation) != 1)
      {
        printf("Invalid input! Please enter a number.\n");

        // Clear the input buffer to prevent an infinite loop of errors
        while (getchar() != '\n')
          ;
        continue;
      }

      printf("\n");

      // Process the input
      switch (operation)
      {
      case 1:
        printf("Value (int): ");
        scanf("%d", &value);
        push(s, value);
        break;
      case 2:
        value = pop(s);
        if (value != -1)
        {
          printf("Poped %d\n", value);
        }
        break;
      case 3:
        value = top(s);
        if (value != -1)
        {
          printf("Top element: %d\n", value);
        }
        break;
      case 4:
        value = size(s);
        if (value != -1)
        {
          printf("Stack size: %d\n", value);
        }
        break;
      case 5:
        freeStack(s);
        s = NULL;
        break;
      case 6:
        freeStack(s);
        printf("\nExiting the application. Goodbye!\n");
        running = false; // This breaks the while loop
        break;
      default:
        printf("\n[!] Invalid option. Please choose 1, 2, or 3.\n");
        break;
      }
    }
  }

  return 0;
}