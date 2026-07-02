#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Queue
 * @brief Queue type definition.
 *
 * Array based fixed sized queue implementation for integers.
 */
typedef struct Queue
{
  /**
   * @brief Array buffer.
   *
   *  Internal array buffer holding the queue elements. Pointer to the dynamic array buffer.
   */
  int *data;

  /**
   * @brief Capacity of queue.
   *
   * This member stores queue capacity while initializing queue.
   */
  int capacity;

  /**
   * @brief Index of the head (front) element.
   *
   * This points to the location from which the next element will be dequeued (removed).
   */
  int head;

  /**
   * @brief Index of the tail (rear) element.
   *
   * This points to the location where the most recent element was enqueued (inserted).
   */
  int tail;

  /**
   * @brief The exact number of elements currently residing in the queue.
   *
   * Used to manage boundaries, distinguish between "empty" and "full" states,
   * and fetch the queue size in O(1) time.
   */
  int current_size;
} Queue;

/**
 * @brief Creates a queue with initail capacity.
 *
 * This function creates and returns a queue if successfull.
 *
 * @param initial_capacity Capacity of queue.
 * @return queue if successfull, NULL if its failed.
 */
Queue *createQueue(int initial_capacity)
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  if (!queue)
  {
    fprintf(stderr, "Failed to allocate memeory for queue!\n");
    return NULL;
  }

  queue->capacity = initial_capacity;
  queue->head = 0;
  queue->tail = -1;
  queue->current_size = 0;
  queue->data = (int *)malloc(queue->capacity * sizeof(int));

  if (!queue->data)
  {
    fprintf(stderr, "Failed to allocate memeory for queue data!\n");
    free(queue);
    return NULL;
  }

  return queue;
}

/**
 * @brief Check if queue is empty.
 *
 * This function checks if the queue is empty.
 *
 * @param q Pointer of targeted queue.
 * @return True if queue is empty, false if not.
 */
bool isEmpty(Queue *q)
{
  if (!q)
    return true;

  return q->current_size == 0;
}

/**
 * @brief Check if queue is full.
 *
 * This function checks if the queue is full.
 *
 * @param q Pointer of targeted queue.
 * @return True if queue is full, false if not.
 */
bool isFull(Queue *q)
{
  if (!q)
    return false;

  return q->current_size == q->capacity;
}

/**
 * @brief Queue size.
 *
 * This function gets the size of the queue.
 *
 * @param q Pointer of targeted queue.
 * @return 0 if queue is empty or no queue found, otherwise grater than 0.
 */
int size(Queue *q)
{
  if (!q)
    return 0;

  return q->current_size;
}

/**
 * @brief Enqueue element.
 *
 * This function enqueues (insert) a new element into the queue. The element is enqueued at the tail end of the queue.
 *
 * @param q Pointer of targeted queue.
 * @param value Value to insert into the targeted queue.
 */
void enqueue(Queue *q, int value)
{
  if (!q || isFull(q))
  {
    printf("Queue overflow! Enqueue failed!\n");
    return;
  }

  q->tail = (q->tail + 1) % q->capacity;
  q->data[q->tail] = value;
  q->current_size++;
}

/**
 * @brief Dequeue element.
 *
 * This function duqueues (removes) an element from the queue. The element dequeued from the head (front) of the queue.
 *
 * @param q Pointer of targeted queue.
 * @return -1 if queue is empty, otherwise some number.
 */
int dequeue(Queue *q)
{
  if (!q || isEmpty(q))
  {
    printf("Queue Underflow! Dequeue failed!\n");
    return -1;
  }

  int dequeuedValue = q->data[q->head];

  q->head = (q->head + 1) % q->capacity;
  q->current_size--;
}

/**
 * @brief Get the head element.
 * @param q Pointer of targeted queue.
 */
int getHead(Queue *q)
{
  if (!q || isEmpty(q))
  {
    printf("Queue is empty! No head element!\n");
    return -1;
  }

  return q->data[q->head];
}

/**
 * @brief Get the tail element.
 * @param q Pointer of targeted queue.
 */
int getTail(Queue *q)
{
  if (!q || isEmpty(q))
  {
    printf("Queue is empty! No tail element!\n");
    return -1;
  }

  return q->data[q->tail];
}

/**
 * @brief Free queue from memory.
 *
 * Clean up memory to prevent memory leaks.
 *
 * @param q Pointer of targeted queue.
 */
void freeQueue(Queue *q)
{
  if (q)
  {
    free(q->data);
    free(q);
  }
}

void printQueue(Queue *q)
{
  if (!q || isEmpty(q))
  {
    printf("Queue: []\n");
    return;
  }

  printf("Queue: [");
  int index = q->head;

  for (int i = 0; i < q->current_size; i++)
  {
    printf("%d", q->data[index]);

    if (i < q->current_size - 1)
    {
      printf(", ");
    }

    index = (index + 1) % q->capacity;
  }

  printf("]\n");
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
  bool running = true;
  char choice;
  int initial_capacity;
  int operation;
  int value;

  Queue *q = NULL;

  printf("=== C Queue ==\n");

  while (running)
  {
    // if q is null show prompt to create queue with initial capacity
    if (!q)
    {
      clearScreen();
      printf("Create A Queue (y/n): ");
      scanf(" %c", &choice);

      if (choice == 'y' || choice == 'Y')
      {
        printf("Queue Capacity: ");
        scanf(" %d", &initial_capacity);

        q = createQueue(initial_capacity);
      }
      else if (choice == 'n' || choice == 'N')
      {
        freeQueue(q);
        printf("\nExiting the application. Bye!\n");
        running = false;
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
      clearScreen();
      printf("=== C Queue ==\n");
      printf("Queue Capacity: %d\n", initial_capacity);
      printQueue(q);

      printf("\n");
      printf("1. Enqueue new value\n");
      printf("2. Dequeue value\n");
      printf("3. Free Queue\n");
      printf("4. Exit\n");
      printf("Enter your choice (1-4): ");

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

      switch (operation)
      {
      case 1:
        printf("Enqueue value(int): ");
        scanf("%d", &value);
        enqueue(q, value);
        break;
      case 4:
        freeQueue(q);
        printf("\nExiting the application. Goodbye!\n");
        running = false; // This breaks the while loop
        break;
      default:
        break;
      }
    }
  }

  return 0;
}