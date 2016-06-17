package main

import (
	"fmt"
)

//variable out of function body muset use "var"
//var x int = 1
var x = 1
var a, b, c = 1, 2, 3
var slice []int

///golang struct
type books struct {
	xx string
}

func main() {
	var scanf = 1
	fmt.Scanf("%d", scanf)
	d, e, f := 1, 2, 3
	//var ss = [2]int{1, 2}

	ss := [2]int{1, 2}
	print(ss[0])
	println(x, a, b, c, d, e, f)

	//point
	ip := &d
	println(ip)

	var ip2 = &d
	println(ip2)

	slice = []int{1, 2, 3}
	println(slice[0])

}
