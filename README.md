# Language
Simple programming language
# Download
[Windows](https://github.com/NikkyHika/Programming-Language-Language/releases/tag/v1.0.3)

# help();
The LPL is just a simplified C++.
structure file
|-   `text file.fileGetContents(text file_path)` = reads text from a file.
|-   `void file.filePutContents(text file_path, text file_contents)` = writes text from a file.
|-   `void file.fileAddContents(text file_path, text append_contents)` = appends text to a file.
structure convert
|-   `text convert.number_to_text(number num)` = converts a number to text (123 -> "123").
|-   `number convert.text_to_number(text text)` = converts a text to number ("123" -> 123).
|-   `symbol convert.number_to_symbol(number num)` = converts a number to symbol by number code (97 -> 'a').
|-   `number convert.symbol_to_number(symbol sym)` = converts a symbol to number by symbol code ('a' -> 97).
|-   `text convert.symbol_to_text(symbol sym)` = converts a symbol to text ('a' -> "a").
structure os
|-   `text os.getPath()` = get current directory.
|-   `list<text> os.listDir()` = get list of directiores and files.
|-   `void os.deleteFile(text filename)` = deletes file.
|-   `void os.deleteFolder(text foldername)` = deletes directory.
|-   `void os.createFolder(text foldername)` = creates directory.
|-   `void os.changeDir(text foldername)` = creates directory.
|-   `void os.cmdCommand(text command)` = runs a command line command (IMPORTANT! The "cd" command does not work, use os.changeDir).
structure ConsoleColor
|-   `number BLACK = 0`
|-   `number BLUE = 1`
|-   `number GREEN = 2`
|-   `number CYAN = 3`
|-   `number RED = 4`
|-   `number MAGENTA = 5`
|-   `number BROWN = 6`
|-   `number LIGHTGRAY = 7`
|-   `number DARKGRAY = 8`
|-   `number LIGHTBLUE = 9`
|-   `number LIGHTGREEN = 10`
|-   `number LIGHTCYAN = 11`
|-   `number LIGHTRED = 12`
|-   `number LIGHTMAGENTA = 13`
|-   `number YELLOW = 14`
|-   `number WHITE = 15`
`text ask()` = accepts text entered by the user.
`list<text> explode(symbol separator, text text)` = splits the text into list<text>.
`void setConsoleColor(number textColor, number backgroundColor` = ConsoleColor.BLACK)` = changes the color of the console.
`number getCharCode()` = waits for a key to be pressed and returns its code, just like _getch() does.
`void help()` = prints a list of methods and keywords to the console.
`number getElementIndex(list<typename> l, typename e)` = returns the index of an element in a list.
`list<typename>::iterator listBegin(list<typename>& l)` = returns a list iterator, like list<typename>.begin().
`list<typename>::iterator listEnd(list<typename>& l)` = returns a list iterator, like list<typename>.end().

-- 21 methods --

`display ?` = prints text to the console.
`number` = a variable type that stores in 32-bit a number from -2147483644 to 2147483648 if you add unsigned in front of it, it will also be from 0 to 4294967295.
`text` = a variable type that stores text, the text must be in double quotes ("Hello, world!").
`symbol` = a variable type that contains a single character is protected by apostrophes ('a').
`list<typename>` = a list of objects (variables), you can learn more about them as vector in C++: https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170 (IMPORTANT: do not use list<typename>.find(), list<typename>.begin() and list<typename>.end(), we recommend using a `number getElementIndex(list<typename> l, typename e)`, `list<typename>::iterator listBegin(list<typename>& l)` and `list<typename>::iterator listEnd(list<typename>& l)`).
`begin` = opens a block of code.
`end` = closes a block of code.

-- 7 keywords --
```cpp
number main() begin
	display "Hello, world!"
end
```

-----------------------------------------------------------------------------------

usage: Language.exe \<file\>
