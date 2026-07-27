#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Doubly Node
 * @brief Doubly Linked List Node
 *
 * A node which stores data and two pointer for next and previous node.
 */
typedef struct Node
{
  /**
   * @brief Data of the node.
   */
  int data;

  /**
   * @brief Pointer for next node.
   */
  struct Node *next;

  /**
   * @brief Pointer for previous node.
   */
  struct Node *prev;
} Node;

/**
 * @struct Linked List
 * @brief Linked list struct.
 *
 * Linked list struct stores linked list related data.
 */
typedef struct LinkedList
{
  /**
   * @brief Head node.
   *
   * This node stores the head node of the linked list.
   */
  struct Node *head;

  /**
   * @brief Size
   *
   * This value stores the size of the linked list.
   */
  int size;

  /**
   * @brief Type of Linked List
   *
   * The value stores the type linked list.
   * Linked list can be 4 types.
   * 1 - Singly Linked List.
   * 2 - Doubly Linked List.
   * 3 - Circular Singly Linked List.
   * 4 - Circular Doubly Linked List.
   */
  int type;
} LinkedList;

/**
 * @brief Create Linked List.
 *
 * This function creates a linked list.
 *
 * @param type Type of linked list.
 * @return `LinkedList` if successful, `NULL` otherwise
 */
LinkedList *createList(int type)
{
  if (type >= 1 && type <= 4)
  {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;
    list->type = type;

    return list;
  }
  else
  {
    printf("%d number is not a valid linked list type.\n", type);
    printf("Use number 1 to 4.\n");

    return NULL;
  }
}

/**
 * @brief Create a node.
 *
 * This function takes an integer value and creates a node and retures the newly created node.
 *
 * @param value Node data.
 * @return node if successful.
 */
Node *createNode(int value)
{
  Node *node = (Node *)malloc(sizeof(Node));

  if (!node)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  node->data = value;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

/**
 * @brief Insert an self referential node.
 *
 * This function insert a node with the next and previous pointer points to itself.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param value Node data.
 */
void insertInEmpty(Node **headRef, int value)
{
  Node *newNode = createNode(value);

  newNode->next = newNode;
  newNode->prev = newNode;
  *headRef = newNode;
}

/**
 * @brief Inserts node at the beginning.
 *
 * This function inserts a node at the beginning of linked list.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param value Node data.
 */
void insertAtHead(Node **headRef, int value)
{
  if (*headRef == NULL)
  {
    insertInEmpty(headRef, value);
    return;
  }

  Node *head = *headRef;
  Node *last = head->prev;
  Node *newNode = createNode(value);

  newNode->next = head;
  newNode->prev = last;
  last->next = newNode;
  head->prev = newNode;

  // Update head pointer
  *headRef = newNode;
}

/**
 * @brief Inserts node at the end.
 *
 * This function inserts a node at the end of linked list.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param value Node data.
 */
void insertAtTail(Node **headRef, int value)
{
  if (*headRef == NULL)
  {
    insertInEmpty(headRef, value);
    return;
  }

  Node *head = *headRef;
  Node *last = head->prev;
  Node *newNode = createNode(value);

  newNode->next = head;
  newNode->prev = last;
  last->next = newNode;
  head->prev = newNode;
  // head stays the same, newNode becomes the new 'last'
}

// Delete the first node matching 'key'
/**
 * @brief Delete a key data.
 *
 * This function delete the first matching key data from linked list.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param key Key to delete.
 */
void deleteValue(Node **headRef, int key)
{
  if (*headRef == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *curr = *headRef;

  // Search for the node containing key
  do
  {
    if (curr->data == key)
      break;
    curr = curr->next;
  } while (curr != *headRef);

  // Key was not found
  if (curr->data != key)
  {
    printf("Value %d not found in list.\n", key);
    return;
  }

  // Case 1: Only one node in the list
  if (curr->next == curr)
  {
    free(curr);
    *headRef = NULL;
    return;
  }

  // Case 2: Deleting the head node
  if (curr == *headRef)
  {
    *headRef = curr->next;
  }

  // Unlink the node from both neighbors
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;

  free(curr);
}

/**
 * @brief Print linked list from the head node to the last node.
 *
 * @param head Pointer of the head node.
 */
void printForward(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *curr = head;

  printf("Forward: ");
  do
  {
    printf("%d <-> ", curr->data);
    curr = curr->next;
  } while (curr != head);
  printf("(head)\n");
}

/**
 * @brief Print linked list from the last node to the head node.
 *
 * @param head Pointer of the head node.
 */
void printBackward(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *last = head->prev;
  Node *curr = last;
  printf("Backward: ");
  do
  {
    printf("%d <-> ", curr->data);
    curr = curr->prev;
  } while (curr != last);
  printf("(tail)\n");
}

// Free memory for all nodes
/**
 * @brief Free all the nodes of linked list from memeory.
 *
 * @param headRef Pointer reference of the linked list head.
 */
void freeList(Node **headRef)
{
  if (*headRef == NULL)
    return;

  Node *curr = *headRef;
  Node *nextNode;

  // Break the circular link first to treat it as a linear list for freeing
  curr->prev->next = NULL;

  while (curr != NULL)
  {
    nextNode = curr->next;
    free(curr);
    curr = nextNode;
  }

  *headRef = NULL;
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
  int operation;
  int value;

  LinkedList *list = NULL;

  int linkedListType;

  while (running)
  {
    if (!list)
    {
      clearScreen();
      printf("=== C Linked List ===\n");

      printf("Create A Linked List (y/n): ");
      scanf(" %c", &choice);

      if (choice == 'y' || choice == 'Y')
      {
        printf("Add the first node (head) value: ");
        scanf(" %d", &value);

        insertInEmpty(&list->head, value);
      }
      else if (choice == 'n' || choice == 'N')
      {
        freeList(&list->head);
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
      printf("\n");
      printf("Menus");
      printf("1. Insert new value at the head\n");
      printf("2. Insert new value at the tail\n");
      printf("3. Delete a node by key data\n");
      printf("4. Print linked list from tail\n");
      printf("5. Free Linked List\n");
      printf("Enter your choice (1-6): ");
      if (scanf("%d", &operation) != 1)
      {
        printf("Invalid input! Please enter a number.\n");

        // Clear the input buffer to prevent an infinite loop of errors
        while (getchar() != '\n')
          ;
        continue;
      }

      switch (operation)
      {
      case 6:
        freeList(&list->head);
        running = false;
        break;

      default:
        break;
      }
    }
  }

  return 0;
}