# Language
Simple programming language
# Download
Windows(https://github.com/NikkyHika/Programming-Language-Language/releases/tag/v1.0.2)

# Cheat sheets
##Variable types
`number` - int from C/C++.
`text` - string from C++.
`symbol` - char from C/C++.
`list<vartype>` - list from C/C++.
`point_number` - float from C/C++.

##Functions
`display text/number/symbol/point_number;` - displays text on the screen.
`ask();` - get response from user, returns `text`.
`fileGetContents(text filename);` - get content from file, returns `text`.
`filePutContents(text filename, text content);` - put content to file.
`explode(symbol separator, text text);` - splits a string into a list of texts, returns `list<text>`.
`getPath();` - gets the directory path it is currently in, returns `text`.
`listDir();` - gets a list of files and folders from the current directory, returns `list<text>`.
`deleteFile(text filename);` - deletes a file.
`deleteFolder(text foldername);` - deletes a folder (dir)(only if it's empty).
`createFolder(text foldername);` - creates a folder.
`changeDir(text foldername);` - move to another directory.
`cmdCommand(text command);` - execute command line command.
`textToNum(text);` - converts `text` to `number`.

##The rest that is not here
`loop` - this creates a `while` loop.
`begin` - opens a code block for a function/class/loop like `{`.
`end` - closes a code block for a function/class/loop like `}`.

# Hello world

```cpp
number main()
begin
  display "Hello world!";
end
```
