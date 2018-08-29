# AbstractVm
The purpose of this project is to create a simple virtual machine that can interpret programs written in a basic assembly language.

A virtual machine is nothing more than a program that simulates a physical machine, or another virtual machine.
Nevertheless, it is clear that a virtual machine that emulates a physical machine such as a desktop computer
is a very advanced program that requires an important programming experience as well as a very in-depth architectural knowledge.

For this project, requirements will be limited to a very simple virtual machine: it will run some basic arithmetic programs coded in
a very basic assembly language.

## Description
The language of AbstractVM is composed of a series of instructions, with one instruction per line. However, AbstractVM’s assembly language
has a limited type system, which is a major difference from other real world assembly languages.

* Comments: Comments start with a ’;’ and finish with a newline. A comment can be either at the start of a line, or after an instruction.
* push v: Pushes the value v at the top of the stack. The value v must have one of the following form:
	* int8(n) : Creates an 8-bit integer with value n.
	* int16(n) : Creates a 16-bit integer with value n.
	* int32(n) : Creates a 32-bit integer with value n.
	* float(z) : Creates a float with value z.
	* double(z) : Creates a double with value z.
* pop: Unstacks the value from the top of the stack. If the stack is empty, the program execution must stop with an error.
* dump: Displays each value of the stack.
* assert v: Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction.
* add: Unstacks the first two values on the stack, adds them together and stacks the result.
* sub: Unstacks the first two values on the stack, subtracts them, then stacks the result.
* mul: Unstacks the first two values on the stack, multiplies them, then stacks the result.
* div: Unstacks the first two values on the stack, divides them, then stacks the result. If the divisor is equal to 0, the program stops with an error.
* mod: Unstacks the first two values on the stack, calculates the modulus, then stacks the result.
* print: Asserts that the value on the stack is an 8-bit integer then interprets it as an ASCII value and displays the character on the standard output.
* exit: Terminate the execution of the current program.

## Running and compiling
Run `make` and an executable will compile. This is currently only tested on OS X
Run the program with `./avm tests/[test***.avm]`. There are some tests provided in the [tests] directory.
