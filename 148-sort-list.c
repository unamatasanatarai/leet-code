#include <stddef.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

static struct ListNode *split(struct ListNode *head, int size) {
  while (--size && head) {
    head = head->next;
  }
  if (!head)
    return NULL;
  struct ListNode *second = head->next;
  head->next = NULL;
  return second;
}

static struct ListNode *mergeTwoLists(struct ListNode *a, struct ListNode *b,
                                      struct ListNode **tail_out) {
  struct ListNode dummy;
  struct ListNode *tail = &dummy;
  dummy.next = NULL;

  while (a && b) {
    if (a->val <= b->val) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }
  tail->next = a ? a : b;

  while (tail->next) {
    tail = tail->next;
  }
  *tail_out = tail;
  return dummy.next;
}

struct ListNode *sortList(struct ListNode *head) {
  if (!head || !head->next)
    return head;
  int n = 0;
  for (struct ListNode *p = head; p; p = p->next)
    n++;
  struct ListNode dummy;
  dummy.next = head;
  for (int size = 1; size < n; size <<= 1) {
    struct ListNode *prev = &dummy;
    struct ListNode *curr = dummy.next;
    while (curr) {
      struct ListNode *left = curr;
      struct ListNode *right = split(left, size);
      curr = split(right, size);
      struct ListNode *new_tail;
      prev->next = mergeTwoLists(left, right, &new_tail);
      prev = new_tail;
    }
  }
  return dummy.next;
}

/*
 * recursive
 */

struct ListNode *mergeTwoSortedLists(struct ListNode *list1,
                                     struct ListNode *list2) {
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

struct ListNode *sortListRecursive(struct ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  struct ListNode *mid = findMiddle(head);
  struct ListNode *right = mid->next;
  mid->next = NULL;

  struct ListNode *left = head;

  left = sortListRecursive(left);
  right = sortListRecursive(right);

  return mergeTwoSortedLists(left, right);
}
