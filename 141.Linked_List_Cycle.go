//go:build ignore

package main

type ListNode struct {
	Val int
	Next *ListNode
}

// ===============
// beats 7.60%

func check(hashMap *map[*ListNode]bool,node *ListNode)bool{
    if _, exists := (*hashMap)[node]; exists {
        return true
    }

    (*hashMap)[node] = true
    return false;
}

func hasCycle(head *ListNode) bool {

    if(head==nil || head.Next==nil ){
        return false
    }
    
    hashMap := make(map[*ListNode]bool)

    hashMap[head]=true

    for head.Next!=nil {
        if(check(&hashMap,head.Next)){
            return true;
        }
        head = head.Next
    }
    return false
}

// ===============
// beats 79.68%
// changed function name from hasCycle to hasCycle2

func hasCycle2(head *ListNode) bool {

    if head==nil || head.Next==nil{
        return false
    }
    
    slow,fast := head,head

    for fast!=nil && fast.Next!=nil {

        slow=slow.Next
        fast=fast.Next.Next

        if fast==slow {
            return true
        }

    }

    return false

}