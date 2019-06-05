#include "doubly_linked_list.h"

char * enterString(const char *message) {

	char *string = (char*)calloc(1, sizeof(char));

	if (string == NULL) {
		return NULL;
	}

	int i = 0;
	char c;

	printf("%s", message);

	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
	while ((c = (char)getchar()) != -1) {
		if (c == '\n') {
			string[i] = '\0';
			break;
		} else {
      string[i++] = c;
		}

		if (!(string = (char*)realloc(string, sizeof(char) * (i + 1)))) {
			break;
		}
	}

	return string;
}

int enterInt(char *message) {
  int ret = 0;
  do {
    rewind(stdin);
    fseek(stdin, 0, SEEK_END);
    printf("%s", message);
  } while (!scanf("%d", &ret));
  return ret;
}

int enterIntWithBoundary(char *message, int bBoundary, int uBoundary) {
	int ret = bBoundary;
	do {
		rewind(stdin);
		fseek(stdin, 0, SEEK_END);
		printf("%s", message);
	} while (!scanf("%d", &ret) || ret <= bBoundary || ret > uBoundary);
	return ret;
}

int main(int argc, const char * argv[]) {
	DoublyLinkedList *list = emptyDoublyLinkedList();

	while (1) {
		printf("Menu: \n");
		printf("[1] Add to start\n");
		printf("[2] Add to end\n");
		printf("[3] Print all elements\n");
		printf("[4] Remove all elements\n");
		printf("[5] List size\n");
		printf("[6] Is list empty?\n");
		printf("[7] Remove first\n");
		printf("[8] Remove last\n");
		printf("[9] Find\n");
		printf("[a] Find max and min values\n");
		printf("[b] Remove by value\n");
		printf("[c] Remove all by value\n");
		printf("[d] Edit\n");
		printf("[e] Is list symmetric\n");
		printf("[f] Exit the program\n");

		int option = enterIntWithBoundary("[1-F]# ", 0, 0xF);

		switch (option) {
      case 1: {
        int value = enterInt("Enter new value: ");
        dllPush(list, value);
        break;
      }
      case 2: {
        int value = enterInt("Enter new value: ");
        dllAppend(list, value);
        break;
      }
      case 3: {
        dllPrint(list);
        break;
      }
      case 4: {
        dllRemoveAll(list);
        break;
      }
      case 5: {
        printf("List size: %d\n", dllSize(list));
        break;
      }
      case 6: {
        if (dllIsEmpty(list)) {
          printf("List is empty\n");
        }
        else {
          printf("Is is not empty\n");
        }
        break;
      }
      case 7: {
        printf("Value from the head of the list: %d", dllPop(list));
        break;
      }
      case 8: {
        printf("Value from the end of the list: %d", dllEndPop(list));
        break;
      }
      case 9:  {
        int value = enterInt("Enter search value: ");
        DoublyLinkedListNode *node = dllFind(list, value);
        if (node == NULL) {
          printf("Search unsuccessful\n");
        }
        else {
          printf("Value found: %d", node->data);
        }
        break;
      }
      case 0xA: {
        DoublyLinkedListMinMaxHolder *holder = dllFindMinMax(list);
        if (holder == NULL) {
          printf("Search has failed. Please, check list...\n");
          break;
        }
        if (holder->maxValueNode == NULL || holder->minValueNode == NULL) {
          printf("There's some errors. Min/Max value not found. Check list consistent...\n");
          break;
        }
        printf("Max: %d\nMin: %d\n", holder->maxValueNode->data, holder->minValueNode->data);
        break;
      }
      case 0xB: {
        int value = enterInt("Enter new value: ");
        dllRemoveWith(list, value);
      }
      case 0xC: {
        int value = enterInt("Enter new value: ");
        dllRemoveAllWith(list, value);
      }
      case 0xD: {
        int value = enterInt("Enter value: ");
        int newValue = enterInt("Replace with: ");
        dllReplaceAll(list, value, newValue);
        break;
      }
      case 0xE: {
        if (dllIsSymmetric(list)) {
          printf("List is symmetric\n");
        }
        else {
          printf("List is asymmetric\n");
        }
        break;
      }
      case 0xF: {
        printf("Goodbye!\n");
        return 0;
      }

      default:
        continue; // It's cannot be done, but need to be checked {
		}

		enterString("Enter any symbol to get back to the menu...");
	}
}
