<?php

class ListNode
{
    public $val;
    public $next;

    public function __construct($val)
    {
        $this->val = $val;
        $this->next = null;
    }
}

class Solution
{
    public function addTwoNumbers($l1, $l2)
    {
        $root = new ListNode(0);
        $tmp = $root;
        $carry = 0;

        while ($l1 || $l2) {
            $r = ($l1->val ?? 0) + ($l2->val ?? 0) + $carry;

            $carry = (int)($r / 10);
            $tmp->next = new ListNode($r % 10);
            $tmp = $tmp->next;

            $l1 = $l1->next ?? null;
            $l2 = $l2->next ?? null;
        }

        if ($carry) {
            $tmp->next = new ListNode($carry);
        }

        return $root->next;
    }
}

$test_cases = [
    [
        [9,9,9,9,9,9,9],
        [9,9,9,9],
        [8,9,9,9,0,0,0,1],
    ],
    [
        [2,4,3],
        [5,6,4],
        [7,0,8],
    ],
];

function makeNodes($arr)
{
    $current = new ListNode(array_shift($arr));
    $tmp = $current;
    while ($arr) {
        $tmp->next = new ListNode(array_shift($arr));
        $tmp = $tmp->next;
    }
    return $current;
}

$sol = new Solution();
foreach ($test_cases as $test_case) {
    $lft = makeNodes($test_case[0]);
    $rgt = makeNodes($test_case[1]);
    $exp = makeNodes($test_case[2]);
    $res = $sol->addTwoNumbers($lft, $rgt);
    while ($exp) {
        $a = $res->val;
        $b = $exp->val;
        if ($a != $b) {
            echo "FAILED";
            print_r($test_case);
            break;
        }
        $res = $res->next;
        $exp = $exp->next;
    }
}
