package main

import (
	"fmt"
)

func romanToInt(s string) int {
	total := 0
	prev := 0
	for i := len(s) - 1; i >= 0; i-- {
		curr := 0
		switch s[i] {
		case 'I':
			curr = 1
		case 'V':
			curr = 5
		case 'X':
			curr = 10
		case 'L':
			curr = 50
		case 'C':
			curr = 100
		case 'D':
			curr = 500
		case 'M':
			curr = 1000
		}
		if curr < prev {
			total -= curr
		} else {
			total += curr
		}
		prev = curr
	}
	return total
}

func main() {
	testCases := []struct {
		input    string
		expected int
	}{
		{"I", 1},
		{"II", 2},
		{"III", 3},
		{"IV", 4},
		{"V", 5},
		{"VI", 6},
		{"IX", 9},
		{"X", 10},
		{"XL", 40},
		{"XLIX", 49},
		{"L", 50},
		{"LVIII", 58},
		{"XC", 90},
		{"XCIX", 99},
		{"C", 100},
		{"CD", 400},
		{"D", 500},
		{"CM", 900},
		{"M", 1000},
		{"MCMXCIV", 1994},
		{"MMMCMXCIX", 3999}, // Maximum valid Roman numeral
		{"MDCCLXXVI", 1776},
		{"MCMLIV", 1954},
		{"MMXXV", 2025},
		{"XIV", 14},
		{"XIX", 19},
		{"XLII", 42},
		{"CDXLIV", 444},
		{"CMXCIX", 999},
		{"MMM", 3000},
		{"MMMDCCCLXXXVIII", 3888}, // A longer valid one
	}

	passed := 0
	failed := 0

	for _, tc := range testCases {
		result := romanToInt(tc.input)

		if result == tc.expected {
			passed++
		} else {
			failed++
			fmt.Println("\nFAILED: \"%s\"\n  Expected: %d\n  Got:      %d", tc.input, tc.expected, result)
			panic("F")
		}
	}

	fmt.Printf("SUMMARY: %d passed, %d failed\n", passed, failed)
	if failed == 0 {
		fmt.Printf("🎉 All tests passed!\n")
	}
}
