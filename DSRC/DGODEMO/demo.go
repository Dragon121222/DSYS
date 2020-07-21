package main

import (
	"fmt"
	"math"
)

func helloWorld() { 
    fmt.Println("hello world")
}

func stringCat() { 
	fmt.Println("go" + "lang")
}

func mathAndLogic() { 

	fmt.Println("1 + 2 =",1 + 2)
	fmt.Println("7.5/3.1 =" , 7.5/3.1)
 	
    fmt.Println("true && false =", true && false)
    fmt.Println("true || false =", true || false)
    fmt.Println("!true =", !true)
}

func variables() { 

	var a = "init"
	fmt.Println("a:",a)

	var b = 54
	fmt.Println("b:",b)

// Throws truncation error
//	var c int = 3.14159
	var c = 3.14159 
	fmt.Println("c:",c)

	var d int = 5
// Throws typecast error
//	d = c
	fmt.Println("d:",d)

	var bool = true
	fmt.Println("bool:",bool)

	var e int 
	fmt.Println("No Init:", e)

	f := "apple"
	fmt.Println("Implicit definition:",f)

}

func constants() { 

	const s string = "constant"

	fmt.Println("constant s:",s)

    const n = 500000000

    const d = 3e20 / n
    fmt.Println(d)
    fmt.Println(int64(d))
    fmt.Println(math.Sin(n))
}

func loops() { 
//  Let: 
	i := 1

	fmt.Println("Count to 3: ")
	for i <= 3 { 
		fmt.Println(i)
		i++
	}

// Further let: 
	M := 666
// Then we will index M things: 
	for i := 0; i < M; i++ { 
		fmt.Println(i)
	}




}

func main() {	

/*
	fmt.Println("Running helloWorld Demo: ")	
	helloWorld()

	fmt.Println("Running stringCat Demo: ")	
	stringCat()

	fmt.Println("Running math and logic Demo: ")
	mathAndLogic()

	fmt.Println("Running variables Demo: ")
	variables()

	fmt.Println("Running constants Demo: ")
	constants()

	fmt.Println("Running loops demo: ")
	loops()
*/

}
