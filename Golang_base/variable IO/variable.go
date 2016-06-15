package main

//variable out of function body muset use "var"
//var x int = 1
var x = 1

//other :=1
//var a , b , c int
var a, b, c = 1, 2, 3

//d,e,f := 1,2,3

func main() {
	d, e, f := 1, 2, 3
	println(x, a, b, c, d, e, f)
}
