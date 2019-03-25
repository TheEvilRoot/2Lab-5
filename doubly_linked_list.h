#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#define payload int

#include <stdio.h>
#include <stdlib.h>

struct dll_node {
  payload data;
  struct dll_node *next;
  struct dll_node *prev;
};

struct dll {
  unsigned int size;
  struct dll_node *first;
  struct dll_node *last;
};

struct minmax_holder {
  payload minValud;
  payload maxValue;
};

typedef struct dll_node DoublyLinkedListNode;
typedef struct dll DoublyLinkedList;
typedef struct minmax_holder MinMaxHolder;


DoublyLinkedListNode * newDoublyLinkedListNode(payload data);
DoublyLinkedList * emptyDoublyLinkedList();
DoublyLinkedList * doublyLinkedListOf(payload *items, int count);
MinMaxHolder newMinMaxHolder(payload min, payload max);

void dllAddAfter(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data);
void dllAddBefore(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data);
void dllPush(DoublyLinkedList *list, payload data);
void dllAppend(DoublyLinkedList *list, payload data);

void dllTraverse(DoublyLinkedList *list);

void dllRemoveAll(DoublyLinkedList *list);
void dllRemoveWith(DoublyLinkedList *list, payload value);
void dllRemoveAllWith(DoublyLinkedList *list, payload value);

void dllRepace(DoublyLinkedList *list, payload value, payload newValue);
void dllRepaceAll(DoublyLinkedList *list, payload value, payload newValue);

payload dllPop(DoublyLinkedList *list);
payload dllEndPop(DoublyLinkedList *list);

DoublyLinkedListNode * dllFind(DoublyLinkedList *list, payload value);
MinMaxHolder dllFindMinMax(DoublyLinkedList *list);

unsigned int dllSize(DoublyLinkedList *list);
int dllIsEmpty(DoublyLinkedList *list);
int dllIsSymmetric(DoublyLinkedList *list);

#endif
























