#include "doubly_linked_list.h"

DoublyLinkedListNode * newDoublyLinkedListNode(int data) {
  DoublyLinkedListNode *node = (DoublyLinkedListNode*) calloc(1, sizeof(DoublyLinkedListNode));
  node->data = 0;
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  
  return node;
}

DoublyLinkedList * emptyDoublyLinkedList() {
  DoublyLinkedList *list = (DoublyLinkedList*) calloc(1, sizeof(DoublyLinkedList));
  list->first = NULL;
  list->last = NULL;
  return list;
}

DoublyLinkedListMinMaxHolder * newMinMaxHolder(DoublyLinkedListNode *min, DoublyLinkedListNode *max) {
  DoublyLinkedListMinMaxHolder *holder = (DoublyLinkedListMinMaxHolder* ) calloc(1, sizeof(DoublyLinkedListMinMaxHolder));
  holder->maxValueNode = max;
  holder->minValueNode = min;

  return holder;
}

void dllAddAfter(DoublyLinkedList *list, DoublyLinkedListNode *node, int data) {
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

void dllAddBefore(DoublyLinkedList *list, DoublyLinkedListNode *node, int data) {
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
void dllPush(DoublyLinkedList *list, int data) {

  if (list->first == NULL) {
    DoublyLinkedListNode *newNode = newDoublyLinkedListNode(data);

    list->first = newNode;
    list->last = newNode;
  } else {
    dllAddBefore(list, list->first, data);
  }
}

// Add to end
void dllAppend(DoublyLinkedList *list, int data) {
  if (list->last == NULL) {
    dllPush(list, data);
  } else {
    dllAddAfter(list, list->last, data);
  }
}

void dllNodePrint(DoublyLinkedListNode *node) {
  printf("%d\n", node->data);
  if (node->next != NULL) {
    dllNodePrint(node->next);
  }
}

void dllPrint(DoublyLinkedList *list) {
  if (list->first != NULL) {
    dllNodePrint(list->first);
  }
}


void dllNodeRemove(DoublyLinkedListNode *node) {
    if (node->next != NULL) {
        dllNodeRemove(node->next);
    }
    free(node);
}

void dllRemoveAll(DoublyLinkedList *list) {
    if (list->first != NULL) {
        dllNodeRemove(list->first);
    }

    list->first = NULL;
    list->last = NULL;
}


unsigned int dllSize(DoublyLinkedList *list) {

  unsigned int size = 0;

  for (DoublyLinkedListNode *node = list->first; node != NULL; size++, node = node->next);

  return size;
}

int dllIsEmpty(DoublyLinkedList *list) {
  return list->first == NULL && list->last == NULL;
}

int dllPop(DoublyLinkedList *list) {
  if (list->first == NULL) {
    return -1;
  }

  int popped = list->first->data;

  list->first = list->first->next;
  list->first->prev = NULL;

  return popped;
}

int dllEndPop(DoublyLinkedList *list) {
  if (list->last == NULL) {
    return -1;
  }

  int popped = list->last->data;

  list->last = list->last->prev;
  list->last->next = NULL;

  return popped;
}

DoublyLinkedListNode * dllFind(DoublyLinkedList *list, int value) {

  if (list->first == NULL) {
    return NULL;
  }

  DoublyLinkedListNode *node = list->first;

  while (node != NULL) {
    if (node->data == value) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

DoublyLinkedListMinMaxHolder * dllFindMinMax(DoublyLinkedList *list) {
  if (list->first == NULL) {
    return NULL;
  }
  DoublyLinkedListNode *min = list->first;
  DoublyLinkedListNode *max = list->first;

  DoublyLinkedListNode *node = list->first;

  while (node != NULL) {
    if (node->data > max->data) {
      max = node;
    }
    if (node->data < min->data) {
      min = node;
    }
    node = node->next;
  }

  return newMinMaxHolder(min, max);
}

void dllRemoveWith(DoublyLinkedList *list, int value) {
  DoublyLinkedListNode *node = list->first;

  while (node != NULL) {
    if (node->data == value) {
      if (node == list->last && node == list->first) {
        list->last = list->first = NULL;
        return;
      }
      if (node->prev != NULL) {
        node->prev->next = node->next;
        if (node == list->last)
          list->last = node->prev;
      }
      if (node->next != NULL) {
        node->next->prev = node->prev;
        if (node == list->first)
          list->first = node->next;
      }
      return;
    }
    node = node->next;
  }
}

void dllRemoveAllWith(DoublyLinkedList *list, int value) {
  DoublyLinkedListNode *node = list->first;

  while (node != NULL) {
    if (node->data == value) {
      if (node == list->last && node == list->first) {
        list->last = list->first = NULL;
        return;
      }
      if (node->prev != NULL) {
        node->prev->next = node->next;
        if (node == list->last)
          list->last = node->prev;
      }
      if (node->next != NULL) {
        node->next->prev = node->prev;
        if (node == list->first)
          list->first = node->next;
      }
    }
    node = node->next;
  }
}

void dllReplaceAll(DoublyLinkedList *list, int value, int newValue) {
  DoublyLinkedListNode *node = list->first;

  while (node != NULL) {
    if (node->data == value) {
      node->data = newValue;
    }
    node = node->next;
  }
}

int dllIsSymmetric(DoublyLinkedList *list) {
  if(dllIsEmpty(list))
    return 0;

  DoublyLinkedListNode *first = list->first;
  DoublyLinkedListNode *second = list->last;

  if (first->data != second->data)
    return 0;

  while (first != NULL && second != NULL && first != second && first->next != second) {
    if (first->data != second->data)
      return 0;

    first = first->next;
    second = second->prev;
  }

  return 1;
}