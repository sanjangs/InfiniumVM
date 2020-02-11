#include <iostream>
#include <fstream>
#include "vm.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "InfiniumVM - A Simple Bytecode Interpreter/Virtual Machine in C++.\n"
                  << "Made By Sanjangeet Singh <sanjangs976@gmail.com>\n\n"
                  << "Usage: ivm.exe [file]\n";
        return 0;
    }

    std::ifstream f;
    f.open(argv[1]);

    if (!f.is_open()) {
        std::cout << "Error: Failed to read the file.\n";
        return 1;
    }

    f.seekg(0, f.end);
    int len = f.tellg();
    f.seekg(0, f.beg);

    char* code = new char(len);

    f.read(code, sizeof(code));
    f.close();

    return 0;
}
