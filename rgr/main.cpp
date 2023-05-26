#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

std::vector<std::string> readLinesFromFile(const std::string& filename);
void printTextWithLineNumbers(const std::vector<std::string>& lines);
std::string connectLines(const std::vector<std::string>& lines);
std::vector<std::string> extractWords(const std::string& text);
void generateCrossReferences(const std::vector<std::string>& lines);

int main() {
    try {
        const std::string filename = "test.txt";
        std::vector<std::string> lines = readLinesFromFile(filename);

        std::cout << "Text with line numbers:\n";
        printTextWithLineNumbers(lines);

        std::cout << "\nCross-references table:\n";
        generateCrossReferences(lines);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open the file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

void printTextWithLineNumbers(const std::vector<std::string>& lines) {
    for (int i = 0; i < lines.size(); ++i) {
        std::cout << i + 1 << ": " << lines[i] << std::endl;
    }
}

void generateCrossReferences(const std::vector<std::string>& lines) {
    std::map<std::string, std::vector<int>> wordTable;
    std::vector<std::string> words = extractWords(connectLines(lines));

    for (int i = 0; i < lines.size(); ++i) {
        const std::string& line = lines[i];

        for (const std::string& word : words) {
            std::string lowerWord = word;
            std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            std::string lowerLine = line;
            std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

            if (lowerLine.find(lowerWord) != std::string::npos) {
                wordTable[word].push_back(i + 1);
            }
        }
    }

    std::cout << std::setw(15) << std::left << "Words:" << "Lines:\n";

    for (const std::string& word : words) {
        std::cout << std::setw(15) << std::left << word;
        const std::vector<int>& lineNumbers = wordTable[word];
        std::vector<int> uniqueLineNumbers(lineNumbers.begin(), lineNumbers.end());
        std::sort(uniqueLineNumbers.begin(), uniqueLineNumbers.end());

        for (int lineNumber : uniqueLineNumbers) {
            std::cout << lineNumber << " ";
        }

        std::cout << '\n';
    }
}

std::string connectLines(const std::vector<std::string>& lines) {
    std::string text;
    for (const std::string& line : lines) {
        text += line + " ";
    }
    return text;
}

std::vector<std::string> extractWords(const std::string& text) {
    
    std::vector<std::string> words;
    std::istringstream iss(text);

    std::string word;
    while (iss >> word) {
        std::string cleanedWord;
        for (char c : word) {
            if (std::isalpha(static_cast<unsigned char>(c))) {
                cleanedWord += std::tolower(c);
            }
        }

        if (!cleanedWord.empty()) {
            words.push_back(cleanedWord);
        }
    }

    std::sort(words.begin(), words.end());
    words.erase(std::unique(words.begin(), words.end()), words.end());

    return words;
}