//go:build ignore

package main

import (
	"fmt"
)

func convertArrayToNumber(arr []rune,sign bool) (int64,bool){
    var ans int64=0
    for _,element:=range(arr){
        ans = ans*10 + int64(element-'0')
       fmt.Println(string(element) + " " + fmt.Sprint(ans))
        if(!sign && ans > 2147483648){
            fmt.Println("running nef 2")
            return -2147483648,true
        }else if (sign && ans > 2147483647){
            fmt.Println("running pos 2")
            return 2147483647,true
        }
    }
    return ans,false
}

func returnSizeSignAndIndexToStart(s string) (int,bool,int,bool){
    size:=0
    sign:=true;
    indexToStart:=0
    numberStarted:=false

    for index,element := range(s){
        if (element < '0' || element > '9')&&numberStarted {
			break
		}
        if(element==' ' && !numberStarted){
            indexToStart++
            continue
        }
        if(element=='-' && !numberStarted){
            if index+1 < len(s) && (s[index+1] < '0' || s[index+1] > '9') {
                return 0,false,0,true
            }
            sign=false
            indexToStart++
            continue
        }

        if(element=='+'){
            if index+1 < len(s) && (s[index+1] < '0' || s[index+1] > '9') {
                return 0,false,0,true
            }
            indexToStart++
            continue
        }
        size++
        numberStarted=true
    }
    return size,sign,indexToStart,false
}

func myAtoi(s string) int {

    size,sign,indexToStart,invalid := returnSizeSignAndIndexToStart(s)
    fmt.Println(invalid)
    if(invalid){
        return 0
    }
    var arr []rune
    if size > len(s)-indexToStart {
        size = len(s) - indexToStart
    }
    
  if indexToStart > 1 {
  if s[indexToStart-1] == '+' && s[indexToStart-2] == '-' || s[indexToStart-1] == '-' && s[indexToStart-2] == '+' {
        return 0
  }
}
    for _,element := range(s[indexToStart:indexToStart+size]){
        if element < '0' || element > '9' {
			break
		}
        arr = append(arr,element)
    }
    if len(arr) == 0 {
        return 0
    }

    finalAns,overflowOrNot := convertArrayToNumber(arr,sign)    
	if !sign && !overflowOrNot {
		finalAns = -finalAns
	}
    return int(finalAns)
}