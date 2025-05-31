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
        system(("rmdir /s /q" + foldername).c_str());
    }

    void createFolder(std::string foldername) {
        system(("mkdir " + foldername).c_str());
    }

    void changeDir(std::string foldername) {
        _chdir(foldername.c_str());
    }

    void cmdCommand(std::string command) {
        if (command.substr(0, 2) == "cd")
            _chdir(command.substr(3, command.length()).c_str());
        else
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

int getcharcode() {
    return _getch();
}

void help() {
    std::cout << "structure file" << std::endl;
    std::cout << "|-   text file.fileGetContents(text file_path)" << std::endl;
    std::cout << "|-   void file.filePutContents(text file_path, text file_contents)" << std::endl;
    std::cout << "|-   void file.fileAddContents(text file_path, text append_contents)" << std::endl;
    std::cout << "structure convert" << std::endl;
    std::cout << "|-   text convert.number_to_text(number num)" << std::endl;
    std::cout << "|-   number convert.text_to_number(text text)" << std::endl;
    std::cout << "|-   symbol convert.number_to_symbol(number num)" << std::endl;
    std::cout << "|-   number convert.symbol_to_number(symbol sym)" << std::endl;
    std::cout << "|-   text convert.symbol_to_text(symbol sym)" << std::endl;
    std::cout << "structure os" << std::endl;
    std::cout << "|-   text os.getPath()" << std::endl;
    std::cout << "|-   list<text> os.listDir()" << std::endl;
    std::cout << "|-   void os.deleteFile(text filename)" << std::endl;
    std::cout << "|-   void os.deleteFolder(text foldername)" << std::endl;
    std::cout << "|-   void os.createFolder(text foldername)" << std::endl;
    std::cout << "|-   void os.changeDir(text foldername)" << std::endl;
    std::cout << "|-   void os.cmdCommand(text command)" << std::endl;
    std::cout << "structure ConsoleColor" << std::endl;
    std::cout << "|-   number BLACK = 0" << std::endl;
    std::cout << "|-   number BLUE = 1" << std::endl;
    std::cout << "|-   number GREEN = 2" << std::endl;
    std::cout << "|-   number CYAN = 3" << std::endl;
    std::cout << "|-   number RED = 4" << std::endl;
    std::cout << "|-   number MAGENTA = 5" << std::endl;
    std::cout << "|-   number BROWN = 6" << std::endl;
    std::cout << "|-   number LIGHTGRAY = 7" << std::endl;
    std::cout << "|-   number DARKGRAY = 8" << std::endl;
    std::cout << "|-   number LIGHTBLUE = 9" << std::endl;
    std::cout << "|-   number LIGHTGREEN = 10" << std::endl;
    std::cout << "|-   number LIGHTCYAN = 11" << std::endl;
    std::cout << "|-   number LIGHTRED = 12" << std::endl;
    std::cout << "|-   number LIGHTMAGENTA = 13" << std::endl;
    std::cout << "|-   number YELLOW = 14" << std::endl;
    std::cout << "|-   number WHITE = 15" << std::endl;
    std::cout << "text ask()" << std::endl;
    std::cout << "text explode(symbol separator, text text)" << std::endl;
    std::cout << "text explode(symbol separator, text text)" << std::endl;
    std::cout << "void setConsoleColor(number textColor, number backgroundColor = ConsoleColor.BLACK)" << std::endl;
    std::cout << "number getcharcode()" << std::endl;
    std::cout << "void help()" << std::endl;
    std::cout << std::endl << "-- 21 methods --" << std::endl << std::endl;
}

#define display std::cout << 
#define number int
#define text std::string
#define symbol char
#define list std::vector
#define begin { 
#define end }

// and here number main() begin
