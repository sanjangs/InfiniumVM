/**
 * InfiniumVM
 * A Simple Bytecode Interpreter/Virtual Machine in C++.
 * 
 * Author: Sanjan Geet Singh <sanjangs976@gmail.com>
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "vm.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {    // Incorrect number of arguments passed.
        std::cout << "InfiniumVM - A Simple Bytecode Interpreter/Virtual Machine in C++.\n"
                  << "Made By Sanjangeet Singh <sanjangs976@gmail.com>\n\n"
                  << "Usage: ivm.exe [file]\n";
        return 0;   // exit
    }

    std::ifstream f;    // to read the file.
    f.open(argv[1]);    // opens the binary file.

    if (!f.is_open()) { // file is not open.
        std::cout << "Error: Failed to read the file.\n";
        return 1;   // exit
    }

    // Get File Lenght.
    f.seekg(0, f.end);
    int len = f.tellg();
    f.seekg(0, f.beg);

    char* code = new char(len); // creates an array of unsigned char (byte)
    // with a lenght equal to the lenght of the file.

    f.read(code, sizeof(code)); // reads the file as a binary file
    // and stores its contents in 'code' variable.
    f.close();  // closes file.

    execute(code, len);
    // This function is located in file 'vm.hpp'.
    // The first argument 'code' carries the executable/binary code.
    // The sencond argument 'len' is the lenght of the code.

    return 0;
}
