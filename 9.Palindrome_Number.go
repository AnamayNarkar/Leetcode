//go:build ignore

package main

func lengthOfNumberAndMore(num int) (int,[]rune){
    ans := 0

    var arr []rune;

    for num!=0 {
        ans++
        arr=append(arr,rune(num%10)+'0')
        num/=10
    }
    return ans,arr
}

func isPalindrome(x int) bool {

    if(x<0){
        return false
    }

    end, arr := lengthOfNumberAndMore(x)
    start:=0
    end-=1

    for start<end {
        if arr[start]!=arr[end]{
            return false
        }
        start++
        end--
    }

    return true
    
}