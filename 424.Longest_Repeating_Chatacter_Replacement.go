//go:build ignore

package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func findMaxInArr(arr [26]int) int {
	max := 0
	for _, element := range arr {
		if element > max {
			max = element
		}
	}
	return max
}

func characterReplacement(s string, k int) int {

	left, right := 0, 0
	freqArr := [26]int{}
	ans := 0

	for right < len(s) {

		freqArr[int(s[right]-'A')]++

		if ((right - left + 1) - findMaxInArr(freqArr)) <= k {
			ans = max(ans, right-left+1)
		} else {
			freqArr[int(s[left]-'A')]--
			left++
		}

		right++

	}

	return ans

}