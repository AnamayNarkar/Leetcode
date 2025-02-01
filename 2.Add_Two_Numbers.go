//go:build ignore

package main



type ListNode struct {
      Val int
      Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{}
    head.Val=0
    carry:=0
    sum:=0
    current:=head

    for l1!=nil || l2!=nil || carry!=0 {
        sum+=carry
        if(l1!=nil){
            sum+=l1.Val
            l1=l1.Next
        }

        if(l2!=nil){
            sum+=l2.Val
            l2=l2.Next
        }

        carry=sum/10

        current.Val=sum%10

        if l1!=nil || l2!=nil || carry!=0 {
            newNode:=&ListNode{}
            current.Next=newNode
            current=current.Next
            sum=0
        }

    }   

    return head
    
}