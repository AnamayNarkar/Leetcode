//go:build ignore

package main 

func areAlmostEqual(s1 string, s2 string) bool {

    s1Len := len(s1)
    s2Len := len(s2)

    if s1Len!=s2Len {
        return false
    }

    map1 := make(map[rune]int)
    map2 := make(map[rune]int)

    twoDone := 0

    for index := range s1 {
        map1[rune(s1[index])]++
        map2[rune(s2[index])]++

        if rune(s1[index])!=rune(s2[index]) {
            if twoDone!=2{
                twoDone++
            }else{
                return false
            }
        }

    }

    for key := range map1{
        if map1[key] != map2[key]{
            return false
        }
    }

    return true

}