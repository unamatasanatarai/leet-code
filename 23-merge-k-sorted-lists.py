from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def merge2lists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        ptr = dummy
        while list1 and list2:
            if list1.val < list2.val:
                ptr.next = list1
                list1 = list1.next
            else:
                ptr.next = list2
                list2 = list2.next

            ptr = ptr.next

        ptr.next = list1 or list2

        return dummy.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None

        if len(lists) == 1:
            return lists[0]

        interval = 1
        while interval < len(lists):
            for i in range(0, len(lists) - interval, interval * 2):
                print(i, interval)
                lists[i] = self.merge2lists(lists[i], lists[i + interval])
            interval *= 2

        return lists[0]


# Helper: create linked list from list of values (or None if empty list)
def create_list(vals):
    if not vals:  # Handles both [] and None (though we use [] in test cases)
        return None
    dummy = ListNode(0)
    curr = dummy
    for v in vals:
        curr.next = ListNode(v)
        curr = curr.next
    return dummy.next


# Helper: convert linked list to Python list (handles None head)
def list_to_vals(head: Optional[ListNode]) -> List[int]:
    vals = []
    while head:
        vals.append(head.val)
        head = head.next
    return vals


# Test cases: input is list of lists (empty sublist means None node)
test_cases = [
    ([[1, 4, 5], [1, 3, 4], [2, 6]], [1, 1, 2, 3, 4, 4, 5, 6]),
    ([], []),  # k=0 lists → empty result
    ([[]], []),  # one empty list → None → []
    ([[], []], []),  # two empty lists
    ([[1]], [1]),
    ([[-1, 1], [-3, 1, 3], [-1, 2, 4]], [-3, -1, -1, 1, 1, 2, 3, 4]),
    ([[1, 2, 3]], [1, 2, 3]),
    ([[1, 3, 5], [2, 4, 6], [0, 7, 8]], [0, 1, 2, 3, 4, 5, 6, 7, 8]),
    ([[], [1, 2], [], [3]], [1, 2, 3]),  # mixed empty and non-empty
    ([[10], [5, 15], [1, 20, 25]], [1, 5, 10, 15, 20, 25]),
    # Removed the invalid descending list case — LeetCode assumes sorted ascending
]

solution = Solution()
passed = 0

for i, (input_lists_vals, expected_vals) in enumerate(test_cases, 1):
    # Convert each sublist into a ListNode chain (empty sublist → None)
    input_lists = [create_list(sublist) for sublist in input_lists_vals]

    result_head: Optional[ListNode] = solution.mergeKLists(input_lists)
    result_vals = list_to_vals(result_head)

    ok = result_vals == expected_vals

    print(
        f"Test {i:2d}: in: {input_lists_vals} → exp: {expected_vals} | res: {result_vals} :: "
        f"{'PASSED' if ok else 'FAILED'}"
    )

    if ok:
        passed += 1
    else:
        print("First failure — stopping.")
        break  # or use exit() if you want hard stop

print(f"\nSummary: {passed} / {len(test_cases)} tests passed")
