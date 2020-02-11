/**
 * InfiniumVM
 * A Simple Bytecode Interpreter/Virtual Machine in C++.
 * 
 * Author: Sanjan Geet Singh <sanjangs976@gmail.com>
**/

#ifndef __INFINIUMVM_VM_HPP__
#define __INFINIUMVM_VM_HPP__

enum Opcodes {  // List of Instructions
    EXIT,   // Normally terminates the program.
    EXITR   // Exits the program with a specific return code.
};

void execute(char* code, int lenght) {
    int pos = 0;    // Current position in code.

    while (pos < lenght) {  // Check if we have reached the end or not.
        switch(code[pos]) {

            case EXIT:
                exit(0);

            case EXITR:
                int r_code = int(code[pos]);
                exit(r_code);

        }

        pos++;  // Increment position in code.
    }
}

#endif /* __INFINIUMVM_VM_HPP__ */
