//go:build ignore

package main

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {

    var prev *ListNode = nil
    curr := head
    var next *ListNode = nil

    for curr!=nil{

        next = curr.Next

        curr.Next = prev

        prev = curr

        curr = next

    }

    return prev

}