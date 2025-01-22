//go:build ignore

package main

// ==================
// beats 7.21%

func checkFunc(firstMap* map[rune]int, s2 string, i, s1Length int) bool{

    secondMap := make(map[rune]int)

    for _,element:=range(s2[i : i+s1Length]){
        secondMap[element]++
    }

    if len(secondMap)!=len(*firstMap){
        return false
    }

    for key,val := range *firstMap{
        if(secondMap[key]!=val){
            return false
        }
    }

    return true

}

func checkInclusion(s1 string, s2 string) bool {

    firstMap := make(map[rune]int);

    for _,element:=range(s1){
        firstMap[element]++
    }

    s1Length , s2Length := len(s1), len(s2)

    for i:=0;i+s1Length<=s2Length;i++{
        if(checkFunc(&firstMap,s2,i,s1Length)){
            return true
        }
    }

    return false
    
}