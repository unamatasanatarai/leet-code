package main

import "fmt"
import "os"

func thirdMax(nums []int) int {
	if 0 == len(nums) {
		return 0
	}
	if 1 == len(nums) {
		return nums[0]
	}

	first, second, third := -1<<63, -1<<63, -1<<63

	for _, num := range nums {
		if first == num || second == num || third == num {
			continue
		}

		if num > first {
			first, second, third = num, first, second
		} else if num > second {
			second, third = num, second
		} else if num > third {
			third = num
		}

	}
	if third == -1<<63 {
		return first
	}
	return third
}

func main() {
	testCases := []struct {
		input    []int
		expected int
	}{
		{[]int{-1, -1, -1}, -1},
		{[]int{-1, -2, -3}, -3},
		{[]int{-10, -20, -5, -30}, -20},
		{[]int{-5, -5, 0, 3, 1}, 0},
		{[]int{0, 0, 0}, 0},
		{[]int{1, 0, -1}, -1},
		{[]int{1, 1, 1, 2, 2, 3, 3}, 1},
		{[]int{1, 1, 1}, 1},
		{[]int{1, 2, 3, 4, 5, 6, 7}, 5},
		{[]int{1, 2, 3, 4, 5}, 3},
		{[]int{1, 2}, 2},
		{[]int{10, 8, 6, 4, 2}, 6},
		{[]int{10, 9, 9, 8, 8, 7, 7}, 8},
		{[]int{100, -100, 50, -50, 0}, 0},
		{[]int{2, 2, 2, 1, 5, 5, 3}, 2},
		{[]int{2, 2, 3, 1}, 1},
		{[]int{3, 2, 1}, 1},
		{[]int{3, 3, 3, 1, 1, 1}, 3},
		{[]int{4, 4, 4, 4}, 4},
		{[]int{42, 42, 42, 10, 5}, 5},
		{[]int{5, 4, 3, 2, 1}, 3},
		{[]int{5}, 5},
		{[]int{7, 7, 7, 7, 7}, 7},
		{[]int{999999999, 999999998, 999999997}, 999999997},
		{[]int{}, 0},
	}

	allPassed := true

	for i, tc := range testCases {
		result := thirdMax(tc.input)

		if result != tc.expected {
			allPassed = false
			fmt.Printf(
				"❌ Test %d FAILED: input=%v expected=%d got=%d\n",
				i, tc.input, tc.expected, result,
			)
			os.Exit(1)
		}
	}

	if allPassed {
		fmt.Println("🎉 All tests passed!")
	}
}
