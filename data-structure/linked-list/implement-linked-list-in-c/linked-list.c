#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Doubly Node (Element)
 * @brief Doubly Linked List Node
 *
 * A node which stores data and two pointer for next and previous node.
 */
typedef struct Node
{
  /**
   * @brief Key of the node.
   */
  int key;

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
   * This node is the head (first) node of the linked list.
   */
  struct Node *head;

  /**
   * @brief Tail Node.
   *
   * This node is the tail (last) node of the linked list.
   */
  struct Node *tail;

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
   * 5 - Circular Doubly Linked List with Sentinel.
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
  if (type >= 1 && type <= 5)
  {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    if (!list)
    {
      printf("[createList]: Memory allocation failed!\n");
      return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->type = type;

    return list;
  }
  else
  {
    printf("[createList]: %d number is not a valid linked list type.\n", type);
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
Node *createNode(int key)
{
  Node *node = (Node *)malloc(sizeof(Node));

  if (!node)
  {
    printf("[createNode]: Memory allocation failed!\n");
    return NULL;
  }

  node->key = key;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

/**
 * @brief Checks if the list is empty.
 *
 * This function checks if the given list is empty.
 *
 * @param list Pointer of the list.
 * @return `true` if list is empty, `false` otherwise.
 */
bool isEmpty(LinkedList *list)
{
  if (!list || list->head == NULL)
  {
    return true;
  }

  return list->size == 0;
}

/**
 * @brief Insert a node in empty list.
 *
 * This function inserts the first node in an empty list. Depending of the type the node may or may not self referential.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void insertInEmpty(LinkedList *list, int key)
{
  Node *node = createNode(key);

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
  case 5:
    node->next = node;
    node->prev = node;
    break;
  default:
    printf("[insertInEmpty]: Type %d does not exists.\n\n", list->type);
    break;
  }

  list->head = node;
  list->tail = node;
  list->size++;
}

/**
 * @brief Inserts node at the beginning.
 *
 * This function inserts a node at the beginning of linked list.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void insertAtHead(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    insertInEmpty(list, key);
    return;
  }

  Node *head = list->head;
  Node *tail = list->tail;
  Node *node = createNode(key);

  switch (list->type)
  {
  case 1:
    node->next = head;
    break;
  case 2:
    node->next = head;
    head->prev = node;
    break;
  case 3:
    node->next = head;
    tail->next = node;
    break;
  case 4:
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
    break;
  case 5:
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
    break;
  default:
    printf("[insertAtHead]: Type %d does not exists.\n\n", list->type);
    break;
  }

  // Update the head pointer.
  list->head = node;
  list->size++;
}

/**
 * @brief Inserts node at the end.
 *
 * This function inserts a node at the end of linked list.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void insertAtTail(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    insertInEmpty(list, key);
    return;
  }

  Node *head = list->head;
  Node *tail = list->tail;
  Node *node = createNode(key);

  switch (list->type)
  {
  case 1:
    tail->next = node;
    break;
  case 2:
    tail->next = node;
    node->prev = tail;
    break;
  case 3:
    tail->next = node;
    node->next = head;
    break;
  case 4:
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
    break;
  case 5:
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
    break;
  default:
    printf("[insertAtTail]: Type %d does not exists.\n\n", list->type);
    break;
  }

  // Update the tail pointer.
  list->tail = node;
  list->size++;
}

Node *searchListByKey(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    printf("[searchListByKey]: List is empty!\n");
    return NULL;
  }

  Node *curr = list->head;

  switch (list->type)
  {
  case 1:
    while (curr != NULL && curr->key != key)
    {
      curr = curr->next;
    }
    break;
  case 2:
    while (curr != NULL && curr->key != key)
    {
      curr = curr->next;
    }
    break;
  default:
    break;
  }

  return curr;
}

/**
 * @brief Delete node.
 *
 * This function deletes a node by key from singly linked list.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void deleteSinglyListedListNodeByKey(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    printf("[deleteSinglyListedListNodeByKey]: List is empty!\n");
    return;
  }

  Node *curr = list->head;
  Node *prev = NULL;

  while (curr != NULL && curr->key != key)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL || curr->key != key)
  {
    printf("[deleteSinglyListedListNodeByKey]: Linked list does not contain %d!\n", key);
    return;
  }

  // Case 1: List contains only head node.
  if (list->head->next == NULL && curr->key == key)
  {
    printf("[deleteSinglyListedListNodeByKey]: Case 1 applyed\n");
    list->head = NULL;
    list->tail = NULL;
    free(curr);
    list->size--;
    return;
  }

  // Case 2: Key is in the head node.
  if (list->head == curr && curr->key == key)
  {
    printf("[deleteSinglyListedListNodeByKey]: Case 2 applyed\n");
    list->head = curr->next;
    curr->next = NULL;
    free(curr);
    list->size--;
    return;
  }

  // Case 3: Key is in the tail node.
  if (list->tail == curr && curr->key == key)
  {
    printf("[deleteSinglyListedListNodeByKey]: Case 3 applyed\n");
    prev->next = NULL;
    list->tail = prev;
    free(curr);
    list->size--;
    return;
  }

  // Case 4: Key is somewhere in the middle.
  printf("[deleteSinglyListedListNodeByKey]: Case 4 applyed\n");
  prev->next = curr->next;
  free(curr);
  list->size--;
}

/**
 * @brief Delete node.
 *
 * This function deletes a node by targeting a key from doubly linked list.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void deleteDoublyLinkedListNodeByKey(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    printf("[deleteDoublyLinkedListNodeByKey]: List is empty!\n");
    return;
  }

  Node *curr = list->head;

  while (curr != NULL && curr->key != key)
  {
    curr = curr->next;
  }

  if (curr == NULL || curr->key != key)
  {
    printf("[deleteDoublyLinkedListNodeByKey]: Linked list does not contain %d!\n", key);
    return;
  }

  // Case 1: For only head node.
  if (list->head->next == NULL && curr->key == key)
  {
    printf("[deleteDoublyLinkedListNodeByKey]: Case 1 applyed\n");
    list->head = NULL;
    list->tail = NULL;
    free(curr);
    list->size--;
    return;
  }

  // Case 2: key in head node.
  if (list->head == curr && curr->key == key)
  {
    printf("[deleteDoublyLinkedListNodeByKey]: Case 2 applyed\n");
    curr->next->prev = curr->prev;
    list->head = curr->next;
    free(curr);
    list->size--;
    return;
  }

  // Case 3: key in tail node.
  if (list->tail == curr && curr->key == key)
  {
    printf("[deleteDoublyLinkedListNodeByKey]: Case 3 applyed\n");
    curr->prev->next = curr->next;
    list->tail = curr->prev;
    free(curr);
    list->size--;
    return;
  }

  // Case 4: key in middle node.
  printf("[deleteDoublyLinkedListNodeByKey]: Case 4 applyed\n");
  curr->next->prev = curr->prev;
  curr->prev->next = curr->next;
  free(curr);
  list->size--;
  return;
}

/**
 * @brief Delete node by key.
 *
 * This function delete the first matching key from linked list.
 *
 * @param list Pointer of the list.
 * @param key Node key.
 */
void deleteNodeByKey(LinkedList *list, int key)
{
  if (isEmpty(list))
  {
    printf("List is empty.\n");
    return;
  }

  Node *curr = list->head;

  // Search for the node containing key
  switch (list->type)
  {
  case 1:
    deleteSinglyListedListNodeByKey(list, key);
    break;
  case 2:
    deleteDoublyLinkedListNodeByKey(list, key);
    break;
  case 3:
    //
    break;
  case 4:
    do
    {
      if (curr->key == key)
        break;
      curr = curr->next;
    } while (curr != list->head);
    break;
  default:
    printf("[deleteValue]: Type %d does not exists.\n\n", list->type);
    break;
  }

  // // Key was not found
  // if (curr->data != key)
  // {
  //   printf("Value %d not found in list.\n", key);
  //   return;
  // }

  // // Case 1: Only one node in the list
  // if (curr->next == curr)
  // {
  //   free(curr);
  //   list->head = NULL;
  //   return;
  // }

  // // Case 2: Deleting the head node
  // if (curr == list->head)
  // {
  //   list->head = curr->next;
  // }

  // // Unlink the node from both neighbors
  // curr->prev->next = curr->next;
  // curr->next->prev = curr->prev;

  // free(curr);
}

/**
 * @brief Print linked list.
 *
 * This function prints the linked list key and what it points to.
 *
 * @param list Pointer of the list.
 * @param direction Print direction. `1` for head to tail, `2` for tail to head.
 */
void printLinkedList(LinkedList *list, int direction)
{
  if (isEmpty(list))
  {
    printf("[printLinkedList]: List is empty!\n");
    return;
  }

  switch (list->type)
  {
  case 1:
    printf("(head)");
    for (Node *curr = list->head; curr != NULL; curr = curr->next)
    {
      printf("%d%s", curr->key, curr->next == NULL ? "(tail)\n" : "->");
    }
    break;
  case 2:
    printf("(head)");
    for (Node *curr = list->head; curr != NULL; curr = curr->next)
    {
      printf("%d%s", curr->key, curr->next == NULL ? "(tail)\n" : "<->");
    }
    break;

  default:
    break;
  }
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
    printf("%d <-> ", curr->key);
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
    printf("%d <-> ", curr->key);
    curr = curr->prev;
  } while (curr != last);
  printf("(tail)\n");
}

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
  // bool running = false;
  // char choice;
  // int operation;
  // int inputValue;

  LinkedList *list = createList(2);
  // int linkedListType;

  clearScreen();

  for (int i = 1; i <= 32; i++)
  {
    insertAtTail(list, i);
    printLinkedList(list, 1);
  }

  for (int j = 33; j <= 50; j++)
  {
    insertAtHead(list, j);
    printLinkedList(list, 1);
  }

  printf("\n=== Search ===\n\n");

  int num1 = 32;
  int num2 = 100;
  printf("Search result: %d %s", num1, !searchListByKey(list, num1) ? "Not Found\n" : "Found\n");
  printf("Search result: %d %s", num2, !searchListByKey(list, num2) ? "Not Found\n" : "Found\n");

  printf("\n=== Delete ===\n\n");

  deleteNodeByKey(list, 50);
  printLinkedList(list, 1);
  deleteNodeByKey(list, 32);
  printLinkedList(list, 1);

  for (int k = 1; k <= 50; k++)
  {
    deleteNodeByKey(list, k);
    printLinkedList(list, 1);
  }

  // printf("Test List size: %d\n", test_list->size);
  // printf("Test List head data: %d\n", test_list->head->data);
  // printf("Test List last data: %d\n", test_list->last->data);

  // if (test_list->last->prev == NULL)
  // {
  //   printf("Tail does not point to previous node.\n");
  // }
  // else
  // {
  //   printf("Tail points to previous node.\n");
  //   printf("test_list->last->prev->data = %d\n", test_list->last->prev->data);
  // }

  // if (test_list->last->next == NULL)
  // {
  //   printf("Tail does not points to head node.\n");
  // }
  // else
  // {
  //   printf("Tail points to the head node.\n");
  //   printf("test_list->last->next->data = %d\n", test_list->last->next->data);
  //   printf("test_list->head->data = %d\n", test_list->head->data);
  // }

  // if (test_list->head->prev == NULL)
  // {
  //   printf("Head does not points to last node.\n");
  // }
  // else
  // {
  //   printf("Head points to the last node.\n");
  //   printf("test_list->head->prev->data = %d\n", test_list->head->prev->data);
  //   printf("test_list->last->data = %d\n", test_list->last->data);
  // }

  // Node *curr = test_list->head;

  // printf("Print all node key\n");

  // while (curr != NULL)
  // {
  //   printf("%d\n", curr->data);
  //   curr = curr->next;
  // }

  // while (running)
  // {
  //   if (!list)
  //   {
  //     clearScreen();
  //     printf("=== C Linked List ===\n");

  //     printf("Create A Linked List (y/n): ");
  //     scanf(" %c", &choice);

  //     if (choice == 'y' || choice == 'Y')
  //     {
  //       printf("Types of Linked List.\n");
  //       printf("1 - Singly Linked List.\n");
  //       printf("2 - Doubly Linked List.\n");
  //       printf("3 - Circular Singly Linked List.\n");
  //       printf("4 - Circular Doubly Linked List.\n");
  //       printf("Enter the type of linked list (1 - 4): ");
  //       scanf(" %d", &inputValue);

  //       list = createList(inputValue);

  //       if (!list)
  //       {
  //         pressEnterToContinue();
  //       }
  //     }
  //     else if (choice == 'n' || choice == 'N')
  //     {
  //       freeList(&list->head);
  //       printf("\nExiting the application. Bye!\n");
  //       running = false;
  //     }
  //     else
  //     {
  //       clearScreen();
  //       printf("Invalid input.\n\n");
  //       pressEnterToContinue();
  //       continue;
  //     }
  //   }
  //   else
  //   {
  //     printf("\n");
  //     printf("Menus\n");
  //     printf("1. Insert new value at the head\n");
  //     printf("2. Insert new value at the tail\n");
  //     printf("3. Delete a node by key data\n");
  //     printf("4. Print linked list from tail\n");
  //     printf("5. Free Linked List\n");
  //     printf("Enter your choice (1-6): ");
  //     if (scanf("%d", &operation) != 1)
  //     {
  //       printf("Invalid input! Please enter a number.\n");

  //       // Clear the input buffer to prevent an infinite loop of errors
  //       while (getchar() != '\n')
  //         ;
  //       continue;
  //     }

  //     switch (operation)
  //     {
  //     case 1:
  //       printf("Value: ");
  //       scanf("%d", &inputValue);
  //       insertAtHead(list, inputValue);
  //       break;
  //     case 2:
  //       printf("Value: ");
  //       scanf("%d", &inputValue);
  //       insertAtTail(list, inputValue);
  //       break;
  //     case 6:
  //       freeList(&list->head);
  //       running = false;
  //       break;

  //     default:
  //       break;
  //     }
  //   }
  // }

  return 0;
}