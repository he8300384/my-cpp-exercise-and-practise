#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void saveInfoAtLine(const std::string& filename, int lineNum, const std::string& info) {
    std::ifstream fileIn(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(fileIn, line)) {
        lines.push_back(line);
    }

    fileIn.close();

    if (lineNum > 0 && lineNum <= lines.size()) {
        lines[lineNum - 1] = info;
    } else {
        std::cout << "Invalid line number\n";
        return;
    }

    std::ofstream fileOut(filename);
    for (const std::string& updatedLine : lines) {
        fileOut << updatedLine << "\n";
    }

    fileOut.close();
}

int main() {
    saveInfoAtLine("data.txt", 3, "New information to save");

    return 0;
}