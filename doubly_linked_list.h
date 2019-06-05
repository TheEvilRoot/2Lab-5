#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include <stdio.h>
#include <stdlib.h>

struct dll_node {
  int data;
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


DoublyLinkedListNode * newDoublyLinkedListNode(int data);
DoublyLinkedList * emptyDoublyLinkedList();
DoublyLinkedListMinMaxHolder * newMinMaxHolder(DoublyLinkedListNode *min, DoublyLinkedListNode *max);

void dllAddAfter(DoublyLinkedList *list, DoublyLinkedListNode *node, int data);
void dllAddBefore(DoublyLinkedList *list, DoublyLinkedListNode *node, int data);
void dllPush(DoublyLinkedList *list, int data);
void dllAppend(DoublyLinkedList *list, int data);

void dllNodePrint(DoublyLinkedListNode *node);
void dllPrint(DoublyLinkedList *list);

void dllNodeRemove(DoublyLinkedListNode *node);
void dllRemoveAll(DoublyLinkedList *list);
void dllRemoveWith(DoublyLinkedList *list, int value);
void dllRemoveAllWith(DoublyLinkedList *list, int value);

void dllReplaceAll(DoublyLinkedList *list, int value, int newValue);

int dllPop(DoublyLinkedList *list);
int dllEndPop(DoublyLinkedList *list);

DoublyLinkedListNode * dllFind(DoublyLinkedList *list, int value);
DoublyLinkedListMinMaxHolder * dllFindMinMax(DoublyLinkedList *list);

unsigned int dllSize(DoublyLinkedList *list);
int dllIsEmpty(DoublyLinkedList *list);
int dllIsSymmetric(DoublyLinkedList *list);

#endif
























