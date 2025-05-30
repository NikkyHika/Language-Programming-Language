# Language
Simple programming language
# Download
[Windows](https://github.com/NikkyHika/Programming-Language-Language/releases/tag/v1.0.3)

# help();
structure file  
|-   text file.fileGetContents(text file_path)  
|-   void file.filePutContents(text file_path, text file_contents)  
|-   void file.fileAddContents(text file_path, text append_contents)  
structure convert  
|-   text convert.number_to_text(number num)  
|-   number convert.text_to_number(text text)  
|-   symbol convert.number_to_symbol(number num)  
|-   number convert.symbol_to_number(symbol sym)  
|-   text convert.symbol_to_text(symbol sym)  
structure os  
|-   text os.getPath()  
|-   list<text> os.listDir()  
|-   void os.deleteFile(text filename)  
|-   void os.deleteFolder(text foldername)  
|-   void os.createFolder(text foldername)  
|-   void os.changeDir(text foldername)  
|-   void os.cmdCommand(text command)  
structure ConsoleColor  
|-   number BLACK = 0  
|-   number BLUE = 1  
|-   number GREEN = 2  
|-   number CYAN = 3  
|-   number RED = 4  
|-   number MAGENTA = 5  
|-   number BROWN = 6  
|-   number LIGHTGRAY = 7  
|-   number DARKGRAY = 8  
|-   number LIGHTBLUE = 9  
|-   number LIGHTGREEN = 10  
|-   number LIGHTCYAN = 11  
|-   number LIGHTRED = 12  
|-   number LIGHTMAGENTA = 13  
|-   number YELLOW = 14  
|-   number WHITE = 15  
text ask()  
text explode(symbol separator, text text)  
text explode(symbol separator, text text)  
void setConsoleColor(number textColor, number backgroundColor = ConsoleColor.BLACK)  
number getcharcode()  
void help()  
  
-----------------------------------------------------------------------------------  
  
display ???  
list<???>  
text  
number  
symbol  
begin  
end  
  
-----------------------------------------------------------------------------------  
  
```cpp
number main() begin
	display "Hello, world!"
end
```

-----------------------------------------------------------------------------------

usage: Language.exe \<file\>
