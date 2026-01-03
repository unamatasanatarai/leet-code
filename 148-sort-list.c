#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
void print_list(struct ListNode *list);

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode dummy;
  struct ListNode *tail = &dummy;
  dummy.next = NULL;

  while (list1 && list2) {

    if (list1->val <= list2->val) {
      tail->next = list1;
      list1 = list1->next;
    } else {
      tail->next = list2;
      list2 = list2->next;
    }

    tail = tail->next;
  }

  tail->next = list1 ? list1 : list2;

  return dummy.next;
}

struct ListNode *findMiddle(struct ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  struct ListNode *slow = head;
  struct ListNode *fast = head->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

struct ListNode *sortList(struct ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  struct ListNode *mid = findMiddle(head);
  struct ListNode *right = mid->next;
  mid->next = NULL;

  struct ListNode *left = head;

  left = sortList(left);
  right = sortList(right);

  return mergeTwoLists(left, right);
}

/* ---------- Helper functions ---------- */

void print_list(struct ListNode *list) {
  while (list) {
    printf("%d ", list->val);
    list = list->next;
  }
  printf("\n");
}

struct ListNode *list_from_array(int *arr, int len) {
  struct ListNode *head = NULL, *tail = NULL;
  for (int i = 0; i < len; i++) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = NULL;
    if (!head) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

int compare_lists(struct ListNode *a, struct ListNode *b) {
  while (a && b) {
    if (a->val != b->val)
      return 0;
    a = a->next;
    b = b->next;
  }
  return a == NULL && b == NULL;
}

/* ---------- Test case structure ---------- */

struct TestCase {
  struct ListNode *input;
  struct ListNode *expected;
};

/* ---------- Tests ---------- */

int main(void) {
  struct TestCase tests[] = {
      // Test 1: Empty list
      {NULL, NULL},

      // Test 2: Single element
      {list_from_array((int[]){5}, 1), list_from_array((int[]){5}, 1)},

      // Test 3: Already sorted
      {list_from_array((int[]){1, 2, 3, 4}, 4),
       list_from_array((int[]){1, 2, 3, 4}, 4)},

      // Test 4: Reverse sorted
      {list_from_array((int[]){4, 3, 2, 1}, 4),
       list_from_array((int[]){1, 2, 3, 4}, 4)},

      // Test 5: Random order
      {list_from_array((int[]){4, 2, 1, 3}, 4),
       list_from_array((int[]){1, 2, 3, 4}, 4)},

      // Test 6: With duplicates
      {list_from_array((int[]){3, 1, 2, 3, 2}, 5),
       list_from_array((int[]){1, 2, 2, 3, 3}, 5)},

      // Test 7: Negative numbers
      {list_from_array((int[]){-1, 5, 3, 0, -2}, 5),
       list_from_array((int[]){-2, -1, 0, 3, 5}, 5)},

      // Test 8: All same values
      {list_from_array((int[]){7, 7, 7, 7}, 4),
       list_from_array((int[]){7, 7, 7, 7}, 4)},

      // Test 9: Large range
      {list_from_array((int[]){100, 1, 50, -50, 0}, 5),
       list_from_array((int[]){-50, 0, 1, 50, 100}, 5)},

      // Test 10: Alternating high/low
      {list_from_array((int[]){10, 1, 9, 2, 8, 3}, 6),
       list_from_array((int[]){1, 2, 3, 8, 9, 10}, 6)},
  };

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    struct ListNode *result = sortList(tests[i].input);

    int ok = compare_lists(result, tests[i].expected);
    printf("Test %d :: %s\n", i + 1, ok ? "PASSED" : "FAILED");

    if (!ok) {
      printf("In: ");
      print_list(tests[i].input);
      printf("Expected: ");
      print_list(tests[i].expected);
      printf("Got: ");
      print_list(result);
      return 1;
    }

    passed++;
  }

  printf("\nSummary: %d / %d tests passed\n", passed, total);
  return 0;
}
