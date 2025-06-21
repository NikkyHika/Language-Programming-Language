#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <direct.h>

namespace file
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

namespace convert
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
namespace os {
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
        DeleteFileA(filename.c_str());
    }

    void deleteFolder(std::string foldername) {
        RemoveDirectoryA(foldername.c_str());
    }

    void createFolder(std::string foldername) {
        CreateDirectoryA(foldername.c_str(), NULL);
    }

    void changeDir(std::string foldername) {
        _chdir(foldername.c_str());
    }

    void cmdCommand(std::string command) {
        system(command.c_str());
    }

    void sleep(int milliseconds) {
        Sleep(milliseconds);
    }

    void shutdown() {
        system("shutdown /s /t 0");
    }

    void reboot() {
        system("shutdown /r /t 0");
    }
};

namespace ConsoleColor {
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

void setConsoleColor(int textColor, int backgroundColor = ConsoleColor::BLACK) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

int getCharCode() {
    return _getch();
}

void help() {
    std::cout << "The LPL is just a simplified C++." << std::endl;
    std::cout << "namespace file" << std::endl;
    std::cout << "|-   `text file::fileGetContents(text file_path)` = reads text from a file." << std::endl;
    std::cout << "|-   `void file::filePutContents(text file_path, text file_contents)` = writes text from a file." << std::endl;
    std::cout << "|-   `void file::fileAddContents(text file_path, text append_contents)` = appends text to a file." << std::endl;
    std::cout << "namespace convert" << std::endl;
    std::cout << "|-   `text convert::number_to_text(number num)` = converts a number to text (123 -> \"123\")." << std::endl;
    std::cout << "|-   `number convert::text_to_number(text text)` = converts a text to number (\"123\" -> 123)." << std::endl;
    std::cout << "|-   `symbol convert::number_to_symbol(number num)` = converts a number to symbol by number code (97 -> 'a')." << std::endl;
    std::cout << "|-   `number convert::symbol_to_number(symbol sym)` = converts a symbol to number by symbol code ('a' -> 97)." << std::endl;
    std::cout << "|-   `text convert::symbol_to_text(symbol sym)` = converts a symbol to text ('a' -> \"a\")." << std::endl;
    std::cout << "namespace os" << std::endl;
    std::cout << "|-   `text os::getPath()` = get current directory." << std::endl;
    std::cout << "|-   `list<text> os::listDir()` = get list of directiores and files." << std::endl;
    std::cout << "|-   `void os::deleteFile(text filename)` = deletes file." << std::endl;
    std::cout << "|-   `void os::deleteFolder(text foldername)` = deletes directory." << std::endl;
    std::cout << "|-   `void os::createFolder(text foldername)` = creates directory." << std::endl;
    std::cout << "|-   `void os::changeDir(text foldername)` = creates directory." << std::endl;
    std::cout << "|-   `void os::cmdCommand(text command)` = runs a command line command (IMPORTANT! The \"cd\" command does not work, use os.changeDir)." << std::endl;
    std::cout << "|-   `void os::sleep(number milliseconds)` = pauses the program for the specified number of milliseconds." << std::endl;
    std::cout << "|-   `void os::shutdown()` = shutdowns the computer." << std::endl;
    std::cout << "|-   `void os::reboot()` = reboots the computer." << std::endl;
    std::cout << "namespace ConsoleColor" << std::endl;
    std::cout << "|-   `ConsoleColor::BLACK` = 0" << std::endl;
    std::cout << "|-   `ConsoleColor::BLUE` = 1" << std::endl;
    std::cout << "|-   `ConsoleColor::GREEN` = 2" << std::endl;
    std::cout << "|-   `ConsoleColor::CYAN` = 3" << std::endl;
    std::cout << "|-   `ConsoleColor::RED` = 4" << std::endl;
    std::cout << "|-   `ConsoleColor::MAGENTA` = 5" << std::endl;
    std::cout << "|-   `ConsoleColor::BROWN` = 6" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTGRAY` = 7" << std::endl;
    std::cout << "|-   `ConsoleColor::DARKGRAY` = 8" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTBLUE` = 9" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTGREEN` = 10" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTCYAN` = 11" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTRED` = 12" << std::endl;
    std::cout << "|-   `ConsoleColor::LIGHTMAGENTA` = 13" << std::endl;
    std::cout << "|-   `ConsoleColor::YELLOW` = 14" << std::endl;
    std::cout << "|-   `ConsoleColor::WHITE` = 15" << std::endl;
    std::cout << "`text ask()` = accepts text entered by the user." << std::endl;
    std::cout << "`list<text> explode(symbol separator, text text)` = splits the text into list<text>." << std::endl;
    std::cout << "`void setConsoleColor(number textColor, number backgroundColor` = ConsoleColor.BLACK)` = changes the color of the console." << std::endl;
    std::cout << "`number getCharCode()` = waits for a key to be pressed and returns its code, just like _getch() does." << std::endl;
    std::cout << "`void help()` = prints a list of methods and keywords to the console." << std::endl;
    std::cout << "`number getElementIndex(list<typename> l, typename e)` = returns the index of an element in a list." << std::endl;
    std::cout << "`typename::iterator _Begin(typename& l)` = returns a list or text and etc. iterator, like typename.begin()." << std::endl;
    std::cout << "`typename::iterator _End(typename& l)` = returns a list or text and etc. iterator, like typename.end()." << std::endl;
    std::cout << std::endl << "-- 21 methods --" << std::endl << std::endl;
    std::cout << "`display ?` = prints text to the console." << std::endl;
    std::cout << "`number` = a variable type that stores in 32-bit a number from -2147483644 to 2147483648 if you add unsigned in front of it, it will also be from 0 to 4294967295." << std::endl;
    std::cout << "`text` = a variable type that stores text, the text must be in double quotes (\"Hello, world!\")." << std::endl;
    std::cout << "`symbol` = a variable type that contains a single character is protected by apostrophes ('a')." << std::endl;
    std::cout << "`list<typename>` = a list of objects (variables), you can learn more about them as vector in C++: https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170 (IMPORTANT: do not use list<typename>.find(), list<typename>.begin() and list<typename>.end(), we recommend using a `number getElementIndex(list<typename> l, typename e)`, `typename::iterator _Begin(typename& l)` and `typename::iterator _End(typename& l)`)." << std::endl;
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
auto _Begin(LT& l) {
    return l.begin();
}

template<typename LT>
auto _End(LT& l) {
    return l.end();
}

#define display std::cout << 
#define number int
#define text std::string
#define symbol char
#define list std::vector
#define begin { 
#define end }
