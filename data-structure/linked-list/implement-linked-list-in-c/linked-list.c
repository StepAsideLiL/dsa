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
   * This node is the head node of the linked list.
   */
  struct Node *head;

  /**
   * @brief Last Node.
   *
   * This node is the last node of the linked list.
   */
  struct Node *last;

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
LinkedList *create_list(int type)
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
Node *create_node(int value)
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
void insert_in_empty(LinkedList *list, int value)
{
  Node *node = create_node(value);

  switch (list->type)
  {
  case 1:
    node->next = NULL;
    node->prev = NULL;
    break;
  case 2:
    node->next = NULL;
    node->prev = NULL;
    break;
  case 3:
    node->next = node;
    node->prev = NULL;
    break;
  case 4:
    node->next = node;
    node->prev = node;
    break;
  default:
    printf("\nType %d does not exists.\n\n", list->type);
    break;
  }

  list->head = node;
  list->last = node;
  list->size++;
}

/**
 * @brief Inserts node at the beginning.
 *
 * This function inserts a node at the beginning of linked list.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param value Node data.
 */
void insert_at_head(LinkedList *list, int value)
{
  if (list->head == NULL)
  {
    insert_in_empty(list, value);
    return;
  }

  Node *head = list->head;
  Node *last = list->last;
  Node *newNode = create_node(value);

  switch (list->type)
  {
  case 1:
    newNode->next = head;
    break;
  case 2:
    newNode->next = head;
    head->prev = newNode;
    break;
  case 3:
    newNode->next = head;
    last->next = newNode;
    break;
  case 4:
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    break;
  default:
    printf("\nType %d does not exists.\n\n", list->type);
    break;
  }

  // newNode->next = head;
  // newNode->prev = last;
  // last->next = newNode;
  // head->prev = newNode;

  // Update head pointer
  list->head = newNode;
  list->size++;
}

/**
 * @brief Inserts node at the end.
 *
 * This function inserts a node at the end of linked list.
 *
 * @param headRef Pointer reference of the linked list head.
 * @param value Node data.
 */
void insert_at_tail(LinkedList *list, int value)
{
  if (list->head == NULL)
  {
    insert_in_empty(list, value);
    return;
  }

  Node *head = list->head;
  Node *last = list->last;
  Node *newNode = create_node(value);

  switch (list->type)
  {
  case 1:
    last->next = newNode;
    break;
  case 2:
    last->next = newNode;
    newNode->prev = last;
    break;
  case 3:
    last->next = newNode;
    newNode->next = head;
    break;
  case 4:
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    break;
  default:
    printf("\nType %d does not exists.\n\n", list->type);
    break;
  }

  // newNode->next = head;
  // newNode->prev = last;
  // last->next = newNode;
  // head->prev = newNode;

  // head stays the same, newNode becomes the new 'last'
  list->last = newNode;
  list->size++;
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
void deleteValue(LinkedList *list, int key)
{
  if (list->head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *curr = list->head;

  // Search for the node containing key
  do
  {
    if (curr->data == key)
      break;
    curr = curr->next;
  } while (curr != list->head);

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
    list->head = NULL;
    return;
  }

  // Case 2: Deleting the head node
  if (curr == list->head)
  {
    list->head = curr->next;
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
void clear_screen()
{
  // \e[1J clears the screen, \e[H moves cursor to the top-left corner
  printf("\e[1J\e[H");
}

/**
 * @brief Interrupts the program.
 *
 * This function interrupts the program to print some warning or error before clearing the screen.
 */
void press_enter_to_continue()
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
  bool running = false;
  char choice;
  int operation;
  int inputValue;

  LinkedList *list = NULL;
  int linkedListType;

  while (running)
  {
    if (!list)
    {
      clear_screen();
      printf("=== C Linked List ===\n");

      printf("Create A Linked List (y/n): ");
      scanf(" %c", &choice);

      if (choice == 'y' || choice == 'Y')
      {
        printf("Types of Linked List.\n");
        printf("1 - Singly Linked List.\n");
        printf("2 - Doubly Linked List.\n");
        printf("3 - Circular Singly Linked List.\n");
        printf("4 - Circular Doubly Linked List.\n");
        printf("Enter the type of linked list (1 - 4): ");
        scanf(" %d", &inputValue);

        list = create_list(inputValue);

        if (!list)
        {
          press_enter_to_continue();
        }
      }
      else if (choice == 'n' || choice == 'N')
      {
        freeList(&list->head);
        printf("\nExiting the application. Bye!\n");
        running = false;
      }
      else
      {
        clear_screen();
        printf("Invalid input.\n\n");
        press_enter_to_continue();
        continue;
      }
    }
    else
    {
      printf("\n");
      printf("Menus\n");
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
      case 1:
        printf("Value: ");
        scanf("%d", &inputValue);
        insert_at_head(list, inputValue);
        break;
      case 2:
        printf("Value: ");
        scanf("%d", &inputValue);
        insert_at_tail(list, inputValue);
        break;
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