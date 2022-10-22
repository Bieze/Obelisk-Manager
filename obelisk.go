package main

import (
	"flag"
	"fmt"
	"runtime"
)

var AppVersion string
var GitHash string

func main() {
	version := flag.Bool("version", false, "Print version number")	
	flag.Parse()

	if *version {
		fmt.Println("Compiled with " + runtime.Version() + "\nObelisk-Manager",AppVersion,"\nCommit:", GitHash)
	} else {
		flag.PrintDefaults()
	}
}
