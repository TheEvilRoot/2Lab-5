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
  struct dll_node *first;
  struct dll_node *last;
};

struct dll_minmax_holder {
  struct dll_node *minValueNode;
  struct dll_node *maxValueNode;
};

typedef struct dll_node DoublyLinkedListNode;
typedef struct dll DoublyLinkedList;
typedef struct dll_minmax_holder DoublyLinkedListMinMaxHolder;


DoublyLinkedListNode * newDoublyLinkedListNode(payload data);
DoublyLinkedList * emptyDoublyLinkedList();
DoublyLinkedList * doublyLinkedListOf(payload *items, int count);
DoublyLinkedListMinMaxHolder * newMinMaxHolder(DoublyLinkedListNode *min, DoublyLinkedListNode *max);

void dllAddAfter(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data);
void dllAddBefore(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data);
void dllPush(DoublyLinkedList *list, payload data);
void dllAppend(DoublyLinkedList *list, payload data);

void dllNodePrint(DoublyLinkedListNode *node);
void dllPrint(DoublyLinkedList *list);

void dllNodeRemove(DoublyLinkedListNode *node);
void dllRemoveAll(DoublyLinkedList *list);
void dllRemoveWith(DoublyLinkedList *list, payload value);
void dllRemoveAllWith(DoublyLinkedList *list, payload value);

void dllReplace(DoublyLinkedList *list, payload value, payload newValue);
void dllReplaceAll(DoublyLinkedList *list, payload value, payload newValue);

payload dllPop(DoublyLinkedList *list);
payload dllEndPop(DoublyLinkedList *list);

DoublyLinkedListNode * dllFind(DoublyLinkedList *list, payload value);
DoublyLinkedListMinMaxHolder * dllFindMinMax(DoublyLinkedList *list);

unsigned int dllSize(DoublyLinkedList *list);
int dllIsEmpty(DoublyLinkedList *list);
int dllIsSymmetric(DoublyLinkedList *list);

#endif
























