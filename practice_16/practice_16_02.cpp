#include <iostream>
#include <fstream>
#include <string>

void readAndOutputFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc <  2) {
        std::cerr << "Usage: " << argv[0] << " [file1] ..." << std::endl;
        return  1;
    }

    for (int i =  1; i < argc; ++i) {
        readAndOutputFile(argv[i]);
    }

    return  0;
}