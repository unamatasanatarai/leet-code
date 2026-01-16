package main

import "fmt"
import "slices"
import "os"

func findNonMinOrMax(nums []int) int {
	if len(nums) < 3 {
		return -1
	}

	if nums[0] > nums[1] {
		nums[0], nums[1] = nums[1], nums[0]
	}
	if nums[1] > nums[2] {
		nums[1], nums[2] = nums[2], nums[1]
	}
	if nums[0] > nums[1] {
		nums[0], nums[1] = nums[1], nums[0]
	}
	return nums[1]
}

func findNonMinOrMaxSlow(nums []int) int {

	r := len(nums)
	if r < 3 {
		return -1
	}
	first, second, third := 0, 0, 0

	for _, n := range nums {
		if n == first || n == second || n == third {
			continue
		}
		if n > first {
			first, second, third = n, first, second
		} else if n > second {
			second, third = n, second
		} else if n > third {
			third = n
		}
	}
	return second
}

func main() {
	testCases := []struct {
		input    []int
		expected []int
	}{
		{[]int{}, []int{-1}},
		{[]int{91}, []int{-1}},
		{[]int{8, 7}, []int{-1}},
		{[]int{8, 7, 6}, []int{7}},
		{[]int{1, 8, 7, 6}, []int{7}},
		{[]int{1, -1, 7, 6}, []int{1, 6}},
	}

	allPassed := true

	for i, tc := range testCases {
		result := findNonMinOrMax(tc.input)

		if !slices.Contains(tc.expected, result) {
			allPassed = false
			fmt.Printf(
				"❌ Test %d FAILED: input=%v expected one of=%d got=%d\n",
				i, tc.input, tc.expected, result,
			)
			os.Exit(1)
		}
	}

	if allPassed {
		fmt.Println("🎉 All tests passed!")
	}
}
