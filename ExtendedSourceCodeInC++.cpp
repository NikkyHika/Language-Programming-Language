#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <direct.h>

struct file_functions
{
    std::string fileGetContents(std::string file_path) {
        std::ifstream content(file_path);
        std::string contentLINE;
        std::string contentRETURN;
        while (std::getline(content, contentLINE)) {
            contentRETURN += contentLINE + "\n";
        }
        content.close();
        return contentRETURN;
    }

    void filePutContents(std::string file_path, std::string file_contents) {
        std::ofstream fileaddc(file_path);
        fileaddc << file_contents;
        fileaddc.close();
    }

    void fileAddContents(std::string file_path, std::string append_contents) {
        filePutContents(file_path, fileGetContents(file_path) + append_contents);
    }
};

struct convert_functions
{
    std::string number_to_text(int num) {
        return std::to_string(num);
    }

    int text_to_number(std::string text) {
        return std::stoi(text);
    }

    char number_to_symbol(int num) {
        return static_cast<char>(num);
    }

    int symbol_to_number(char sym) {
        return static_cast<int>(sym);
    }

    std::string symbol_to_text(char sym) {
        return std::string({sym});
    }
};

file_functions file;
convert_functions convert;

std::string ask() {
    std::string stirngask;
    std::getline(std::cin, stirngask);
    return stirngask;
}

std::vector<std::string> explode(char separator, std::string text) {
    int i = 0;
    std::vector<std::string> result;
    std::string element = "";
    while (i < text.length()) {
        if (text[i] == separator) {
            result.push_back(element);
            element = "";
        }
        else if (i == (text.length() - 1)) {
            element += text[i];
            result.push_back(element);
            element = "";
        }
        else {
            element += text[i];
        }
        i++;
    }
    return result;
}
struct os_functions {
    std::string getPath() {
        char buffer[MAX_PATH];
        DWORD len = GetCurrentDirectoryA(MAX_PATH, buffer);
        if (len == 0) return "";
        return std::string(buffer, len);
    }

    std::vector<std::string> listDir() {
        std::vector<std::string> files;
        WIN32_FIND_DATAA fd;
        HANDLE hFind = FindFirstFileA("*", &fd);

        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                std::string name = fd.cFileName;
                if (name != "." && name != "..") {
                    files.push_back(name);
                }
            } while (FindNextFileA(hFind, &fd));
            FindClose(hFind);
        }

        return files;
    }

    void deleteFile(std::string filename) {
        system(("del " + filename).c_str());
    }

    void deleteFolder(std::string foldername) {
        system(("rmdir /s /q " + foldername).c_str());
    }

    void createFolder(std::string foldername) {
        //CreateDirectoryA(foldername.c_str());
        system(("mkdir " + foldername).c_str());
    }

    void changeDir(std::string foldername) {
        _chdir(foldername.c_str());
    }

    void cmdCommand(std::string command) {
        system(command.c_str());
    }
};

struct ConsoleColor_lllist {
    int BLACK = 0;
    int BLUE = 1;
    int GREEN = 2;
    int CYAN = 3;
    int RED = 4;
    int MAGENTA = 5;
    int BROWN = 6;
    int LIGHTGRAY = 7;
    int DARKGRAY = 8;
    int LIGHTBLUE = 9;
    int LIGHTGREEN = 10;
    int LIGHTCYAN = 11;
    int LIGHTRED = 12;
    int LIGHTMAGENTA = 13;
    int YELLOW = 14;
    int WHITE = 15;
};

ConsoleColor_lllist ConsoleColor;
os_functions os;

void setConsoleColor(int textColor, int backgroundColor = ConsoleColor.BLACK) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

int getCharCode() {
    return _getch();
}

void help() {
    std::cout << "The LPL is just a simplified C++." << std::endl;
    std::cout << "structure file" << std::endl;
    std::cout << "|-   `text file.fileGetContents(text file_path)` = reads text from a file." << std::endl;
    std::cout << "|-   `void file.filePutContents(text file_path, text file_contents)` = writes text from a file." << std::endl;
    std::cout << "|-   `void file.fileAddContents(text file_path, text append_contents)` = appends text to a file." << std::endl;
    std::cout << "structure convert" << std::endl;
    std::cout << "|-   `text convert.number_to_text(number num)` = converts a number to text (123 -> \"123\")." << std::endl;
    std::cout << "|-   `number convert.text_to_number(text text)` = converts a text to number (\"123\" -> 123)." << std::endl;
    std::cout << "|-   `symbol convert.number_to_symbol(number num)` = converts a number to symbol by number code (97 -> 'a')." << std::endl;
    std::cout << "|-   `number convert.symbol_to_number(symbol sym)` = converts a symbol to number by symbol code ('a' -> 97)." << std::endl;
    std::cout << "|-   `text convert.symbol_to_text(symbol sym)` = converts a symbol to text ('a' -> \"a\")." << std::endl;
    std::cout << "structure os" << std::endl;
    std::cout << "|-   `text os.getPath()` = get current directory." << std::endl;
    std::cout << "|-   `list<text> os.listDir()` = get list of directiores and files." << std::endl;
    std::cout << "|-   `void os.deleteFile(text filename)` = deletes file." << std::endl;
    std::cout << "|-   `void os.deleteFolder(text foldername)` = deletes directory." << std::endl;
    std::cout << "|-   `void os.createFolder(text foldername)` = creates directory." << std::endl;
    std::cout << "|-   `void os.changeDir(text foldername)` = creates directory." << std::endl;
    std::cout << "|-   `void os.cmdCommand(text command)` = runs a command line command (IMPORTANT! The \"cd\" command does not work, use os.changeDir)." << std::endl;
    std::cout << "structure ConsoleColor" << std::endl;
    std::cout << "|-   `number BLACK = 0`" << std::endl;
    std::cout << "|-   `number BLUE = 1`" << std::endl;
    std::cout << "|-   `number GREEN = 2`" << std::endl;
    std::cout << "|-   `number CYAN = 3`" << std::endl;
    std::cout << "|-   `number RED = 4`" << std::endl;
    std::cout << "|-   `number MAGENTA = 5`" << std::endl;
    std::cout << "|-   `number BROWN = 6`" << std::endl;
    std::cout << "|-   `number LIGHTGRAY = 7`" << std::endl;
    std::cout << "|-   `number DARKGRAY = 8`" << std::endl;
    std::cout << "|-   `number LIGHTBLUE = 9`" << std::endl;
    std::cout << "|-   `number LIGHTGREEN = 10`" << std::endl;
    std::cout << "|-   `number LIGHTCYAN = 11`" << std::endl;
    std::cout << "|-   `number LIGHTRED = 12`" << std::endl;
    std::cout << "|-   `number LIGHTMAGENTA = 13`" << std::endl;
    std::cout << "|-   `number YELLOW = 14`" << std::endl;
    std::cout << "|-   `number WHITE = 15`" << std::endl;
    std::cout << "`text ask()` = accepts text entered by the user." << std::endl;
    std::cout << "`list<text> explode(symbol separator, text text)` = splits the text into list<text>." << std::endl;
    std::cout << "`void setConsoleColor(number textColor, number backgroundColor = ConsoleColor.BLACK)` = changes the color of the console." << std::endl;
    std::cout << "`number getCharCode()` = waits for a key to be pressed and returns its code, just like _getch() does." << std::endl;
    std::cout << "`void help()` = prints a list of methods and keywords to the console." << std::endl;
    std::cout << "`number getElementIndex(list<typename> l, typename e)` = returns the index of an element in a list." << std::endl;
    std::cout << "`list<typename>::iterator listBegin(list<typename>& l)` = returns a list iterator, like list<typename>.begin()." << std::endl;
    std::cout << "`list<typename>::iterator listEnd(list<typename>& l)` = returns a list iterator, like list<typename>.end()." << std::endl;
    std::cout << std::endl << "-- 21 methods --" << std::endl << std::endl;
    std::cout << "`display ?` = prints text to the console." << std::endl;
    std::cout << "`number` = a variable type that stores in 32-bit a number from -2147483644 to 2147483648 if you add unsigned in front of it, it will also be from 0 to 4294967295." << std::endl;
    std::cout << "`text` = a variable type that stores text, the text must be in double quotes (\"Hello, world!\")." << std::endl;
    std::cout << "`symbol` = a variable type that contains a single character is protected by apostrophes ('a')." << std::endl;
    std::cout << "`list<typename>` = a list of objects (variables), you can learn more about them as vector in C++: https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170 (IMPORTANT: do not use list<typename>.find(), list<typename>.begin() and list<typename>.end(), we recommend using a `number getElementIndex(list<typename> l, typename e)`, `list<typename>::iterator listBegin(list<typename>& l)` and `list<typename>::iterator listEnd(list<typename>& l)`)." << std::endl;
    std::cout << "`begin` = opens a block of code." << std::endl;
    std::cout << "`end` = closes a block of code." << std::endl;
    std::cout << std::endl << "-- 7 keywords --" << std::endl << std::endl;
}

template<typename LT>
int getElementIndex(std::vector<LT> l, LT e) {
    int i = 0; 
    while (l[i] != e) {
        i++; 
        if (i >= l.size())
            return -1;
    }
    return i;
}

template<typename LT>
auto listBegin(std::vector<LT>& l) {
    return l.begin();
}

template<typename LT>
auto listEnd(std::vector<LT>& l) {
    return l.end();
}

#define display std::cout << 
#define number int
#define text std::string
#define symbol char
#define list std::vector
#define begin { 
#define end }

