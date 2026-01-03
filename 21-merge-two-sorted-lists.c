#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

// Helper function to print a linked list
void print_list(struct ListNode *list) {
  while (list) {
    printf("%d ", list->val);
    list = list->next;
  }
  printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  if (!list1)
    return list2;
  if (!list2)
    return list1;

  size_t list_node_size = sizeof(struct ListNode);
  struct ListNode *result = malloc(list_node_size);
  struct ListNode *result_ptr = result;

  while (list1 && list2) {
    struct ListNode *head = malloc(list_node_size);

    if (list1->val < list2->val) {
      head->val = list1->val;
      list1 = list1->next;
    } else {
      head->val = list2->val;
      list2 = list2->next;
    }

    result_ptr->next = head;
    result_ptr = result_ptr->next;
  }

  if (list1) {
    result_ptr->next = list1;
  } else {
    result_ptr->next = list2;
  }

  struct ListNode *real_result = result->next;
  free(result);
  return real_result;
}

// Function to create a linked list from an array
struct ListNode *list_from_array(int *arr, int len) {
  struct ListNode *head = NULL, *tail = NULL;
  for (int i = 0; i < len; i++) {
    struct ListNode *newNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = arr[i];
    newNode->next = NULL;
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}

// Function to check if two linked lists are equal
int compare_lists(struct ListNode *list1, struct ListNode *list2) {
  while (list1 && list2) {
    if (list1->val != list2->val) {
      return 0; // Lists are not equal
    }
    list1 = list1->next;
    list2 = list2->next;
  }
  return (list1 == NULL && list2 == NULL); // Check if both lists are finished
}

// Test Case structure
struct TestCase {
  struct ListNode *list1;
  struct ListNode *list2;
  struct ListNode *expected;
  int checkContent; // 1 to check content, 0 to check size only
};

int main(void) {
  struct TestCase tests[] = {
      // Test Case 1: Both lists are empty
      {NULL, NULL, NULL, 1},

      // Test Case 2: One list is empty
      {NULL, list_from_array((int[]){1, 2, 3}, 3),
       list_from_array((int[]){1, 2, 3}, 3), 1},
      {list_from_array((int[]){4, 5, 6}, 3), NULL,
       list_from_array((int[]){4, 5, 6}, 3), 1},

      // Test Case 3: Both lists have the same length
      {list_from_array((int[]){1, 3, 5}, 3),
       list_from_array((int[]){2, 4, 6}, 3),
       list_from_array((int[]){1, 2, 3, 4, 5, 6}, 6), 1},

      // Test Case 4: Lists of different lengths
      {list_from_array((int[]){1, 4, 7}, 3),
       list_from_array((int[]){2, 3, 5, 6, 8}, 5),
       list_from_array((int[]){1, 2, 3, 4, 5, 6, 7, 8}, 8), 1},

      // Test Case 5: List1 has all elements smaller than List2
      {list_from_array((int[]){1, 2, 3}, 3),
       list_from_array((int[]){4, 5, 6}, 3),
       list_from_array((int[]){1, 2, 3, 4, 5, 6}, 6), 1},

      // Test Case 6: List2 has all elements smaller than List1
      {list_from_array((int[]){4, 5, 6}, 3),
       list_from_array((int[]){1, 2, 3}, 3),
       list_from_array((int[]){1, 2, 3, 4, 5, 6}, 6), 1},

      // Test Case 7: Lists with duplicate elements
      {list_from_array((int[]){1, 2, 2, 3}, 4),
       list_from_array((int[]){2, 2, 3, 4}, 4),
       list_from_array((int[]){1, 2, 2, 2, 2, 3, 3, 4}, 8), 1},

      // Test Case 8: List1 has all elements larger than List2
      {list_from_array((int[]){10, 20, 30}, 3),
       list_from_array((int[]){1, 2, 3}, 3),
       list_from_array((int[]){1, 2, 3, 10, 20, 30}, 6), 1},

      // Test Case 9: Both lists contain identical elements
      {list_from_array((int[]){5, 5, 5}, 3),
       list_from_array((int[]){5, 5, 5}, 3),
       list_from_array((int[]){5, 5, 5, 5, 5, 5}, 6), 1},

      // Test Case 10: One element in each list
      {list_from_array((int[]){1}, 1), list_from_array((int[]){2}, 1),
       list_from_array((int[]){1, 2}, 2), 1},
  };

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    struct ListNode *result = mergeTwoLists(tests[i].list1, tests[i].list2);
    int ok = 1;

    // Check if the result matches the expected output
    if (tests[i].checkContent) {
      ok = compare_lists(result, tests[i].expected);
    }

    printf("Test %d :: %s\n", i + 1, ok ? "PASSED" : "FAILED");

    if (!ok) {
      printf("Expected: ");
      print_list(tests[i].expected);
      printf("Got: ");
      print_list(result);
      exit(1);
    }

    passed++;

    // Free the allocated memory
    free(result); // Make sure to free the result list if necessary
  }

  printf("\nSummary: %d / %d tests passed\n", passed, total);
  return passed == total;
}
