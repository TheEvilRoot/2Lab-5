#include "doubly_linked_list.h"

DoublyLinkedListNode * newDoublyLinkedListNode(payload data) {
  DoublyLinkedListNode *node = (DoublyLinkedListNode*) calloc(1, sizeof(DoublyLinkedListNode));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  
  return node;
}

DoublyLinkedList * emptyDoublyLinkedList() {
  DoublyLinkedList *list = (DoublyLinkedList*) calloc(1, sizeof(DoublyLinkedList*));
  list->size = 0;
  return list;
}

DoublyLinkedList * doubleLinkedListOf(payload *items, int count) {
  DoublyLinkedList *list = emptyDoublyLinkedList();
  for (int i = 0; i < count; i++) {
    dllAppend(list, items[i]);
  }
  return list;
}

void dllAddAfter(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data) {
  DoublyLinkedListNode *newNode = newDoublyLinkedListNode(data);
  newNode->prev = node;
  if (node->next == NULL) {
    list->last = newNode;
  } else {
    newNode->next = node->next;
    node->next->prev = newNode;
  }
  node->next = newNode;
}

void dllAddBefore(DoublyLinkedList *list, DoublyLinkedListNode *node, payload data) {
  DoublyLinkedListNode *newNode = newDoublyLinkedListNode(data);

  newNode->next = node;
  if (node->prev == NULL) {
    list->first = newNode;
  }  else {
    newNode->prev = node->prev;
    node->prev->next = newNode;
  }
  
  node->prev = newNode;
}

// Add to start
void dllPush(DoublyLinkedList *list, payload data) {

  if (list->first == NULL) {
    DoublyLinkedListNode *newNode = newDoublyLinkedListNode(data);

    list->first = newNode;
    list->last = newNode;
  } else {
    dllAddBefore(list, list->first, data);
  }
}

// Add to end
void dllAppend(DoublyLinkedList *list, payload data) {
  if (list->last == NULL) {
    dllPush(list, data);
  } else {
    dllAddAfter(list, list->last, data);
  }
}























