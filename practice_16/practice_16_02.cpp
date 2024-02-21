#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring> 

int main(int argc, char* argv[]) {
    if (argc <   2) {
        std::cerr << "Usage: " << argv[0] << " [FILE]...\n";
        return   1;
    }

    for (int i =   1; i < argc; ++i) {
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
        while (std::getline(*input, line)) {
            std::cout << line;
            if (!input->eof()) {
                std::cout << '\n';
            }
        }

        if (input != &std::cin) {
            delete input;
        }
    }

    return 0;
}