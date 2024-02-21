#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip> 

int main(int argc, char* argv[]) {
    bool numberLines = false;
    int fileIndex =   1;

    if (argc >   1 && std::strcmp(argv[1], "-n") ==   0) {
        numberLines = true;
        fileIndex++;
    }

    if (argc < fileIndex +   1) {
        std::cerr << "Usage: " << argv[0] << " [-n] [FILE]...\n";
        return   1;
    }

    for (int i = fileIndex; i < argc; ++i) {
        std::istream* input = nullptr;
        if (std::strcmp(argv[i], "-") ==   0) {
            input = &std::cin;
        } else {
            input = new std::ifstream(argv[i]);
            if (!*input) {
                std::cerr << "Error: Cannot open file " << argv[i] << '\n';
                delete input;
                return   1;
            }
        }

        std::string line;
        int lineNumber =   1;
        while (std::getline(*input, line)) {
            if (numberLines) {
                std::cout << std::setw(4) << std::setfill(' ') << lineNumber++ << ": ";
            }
            std::cout << line;
            if (!input->eof()) {
                std::cout << '\n';
            }
        }

        if (input != &std::cin) {
            delete input;
        }
    }

    return   0;
}