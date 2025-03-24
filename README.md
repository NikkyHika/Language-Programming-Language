# Language
Simple programming language
# Download
Windows(https://github.com/NikkyHika/Programming-Language-Language/releases/tag/v1.0.2)

# Cheat sheets
## Variable types
`number` - int from C/C++.<br>
`text` - string from C++.<br>
`symbol` - char from C/C++.<br>
`list<vartype>` - list from C/C++.<br>
`point_number` - float from C/C++.

## Functions
`display text/number/symbol/point_number;` - displays text on the screen.<br>
`ask();` - get response from user, returns `text`.<br>
`fileGetContents(text filename);` - get content from file, returns `text`.<br>
`filePutContents(text filename, text content);` - put content to file.<br>
`explode(symbol separator, text text);` - splits a string into a list of texts, returns `list<text>`.<br>
`getPath();` - gets the directory path it is currently in, returns `text`.<br>
`listDir();` - gets a list of files and folders from the current directory, returns `list<text>`.<br>
`deleteFile(text filename);` - deletes a file.<br>
`deleteFolder(text foldername);` - deletes a folder (dir)(only if it's empty).<br>
`createFolder(text foldername);` - creates a folder.<br>
`changeDir(text foldername);` - move to another directory.<br>
`cmdCommand(text command);` - execute command line command.<br>
`textToNum(text);` - converts `text` to `number`.

## The rest that is not here
`loop` - this creates a `while` loop.<br>
`begin` - opens a code block for a function/class/loop like `{`.<br>
`end` - closes a code block for a function/class/loop like `}`.<br>

# Hello world

```cpp
number main()
begin
  display "Hello world!";
end
```
