package main

import "fmt"
import "strconv"

type Palindrome struct {
	Num          int
	IsPalindrome bool
}

func isPalindrome1(x int) bool {
	if x < 0 {
		return false
	}
	s := strconv.Itoa(x)
	l := len(s)
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-i-1] {
			return false
		}
	}
	return true
}

func isPalindrome2(x int) bool {
	if x < 0 {
		return false
	}
	if x < 10 {
		return true
	}
	nums := []int{}
	for x != 0 {
		nums = append(nums, x%10)
		x /= 10
	}
	left := 0
	right := len(nums) - 1
	for left < right {
		if nums[left] != nums[right] {
			return false
		}
		left++
		right--
	}
	return true
}

func isPalindrome3(x int) bool {
	if x < 0 {
		return false
	}

	if x < 10 {
		return true
	}
	rx := 0
	tmp := x
	for tmp > 0 {
		rx *= 10
		rx += tmp % 10
		tmp /= 10
	}
	return rx == x
}

func isPalindromeFastest(x int) bool {
	if x < 0 || (x%10 == 0 && x != 0) {
		return false
	}

	if x < 10 {
		return true
	}

	rx := 0
	for x > rx {
		rx = rx*10 + x%10
		x /= 10
	}
	return rx == x || rx/10 == x
}

func main() {
	palindromes := []Palindrome{
		{Num: 123321, IsPalindrome: true},
		{Num: 121, IsPalindrome: true},
		{Num: -121, IsPalindrome: false},
		{Num: 19, IsPalindrome: false},
		{Num: 87687678678, IsPalindrome: true},
		{Num: 0, IsPalindrome: true},
	}

	for i := 0; i < len(palindromes); i++ {
		fmt.Println(palindromes[i].Num, isPalindromeFastest(palindromes[i].Num), palindromes[i].IsPalindrome)
	}
}
