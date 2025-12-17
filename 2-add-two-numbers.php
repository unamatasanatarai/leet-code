<?php

/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */

class ListNode
{
    public $data;
    public $next;

    public function __construct($data)
    {
        $this->data = $data;
        $this->next = null;
    }
}
class Solution
{
    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    public function addTwoNumbers($l1, $l2)
    {
        $now = new ListNode(0);
        $wip = $now;
        $carry = 0;

        while ($l1 || $l2) {
            $x = ($l1 != null) ? $l1->val : 0;
            $y = ($l2 != null) ? $l2->val : 0;
            $sum = $carry + $x + $y;
            $carry = intdiv($sum, 10);
            $wip->next = new ListNode($sum % 10);
            $wip = $wip->next;
            if ($l1 != null) {
                $l1 = $l1->next;
            }
            if ($l2 != null) {
                $l2 = $l2->next;
            }

        }
        if ($carry) {
            $wip->next = new ListNode($carry);
        }
        return $now->next;
    }
}

$sol = new Solution();
$sol->addTwoNumbers([2,4,3], [5,6,4]);
//#[7,0,8]
