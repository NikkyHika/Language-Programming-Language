# Language
Simple programming language
# Download
Windows(https://github.com/NikkyHika/Language/releases/tag/v1.0.1)
# Language Programming Language Tutorial
In this tutorial, we will introduce the basics of the Language programming language, its syntax, and the available functions. The language is designed to be simple and concise, allowing for easy and readable code. It is built using C++ as the base language and utilizes macros to streamline common operations.

# 1. Basic Concepts
Language offers a set of simplified data types and macros to make the code easier to write. Here's an overview of the key components:

Data Types:

`number`: Represents integers.

`text`: Represents strings of characters.

`symbol`: Represents individual characters.

`point_number`: Represents floating-point numbers.

`list`: Represents dynamic arrays (vectors).

These data types are used to declare variables that store different types of values.

# 2. Using Macros for Simplicity
The Language language uses macros to simplify common tasks. Here are some of the key macros:

`display`: Used as a shorthand for `cout <<`, which allows you to print messages to the screen.

`number`, `text`, `symbol`, `point_number`: These are simply aliases for C++ data types (like `int`, `string`, `char`, and `float`).

`list`: Represents a dynamic array (vector), which is used to store collections of items.

`begin` and `end`: Used to define the beginning and end of blocks of code (similar to curly braces { and } in C++).

`loop`: This is an alias for the while loop in C++, making it easier to read.

These macros are designed to make the code shorter and more readable.

# 3. Functions in Language
Language supports functions, just like C++. Functions are used to group related code together and perform specific tasks. Here are some basic functions in Language:

File Handling: Functions like `file_get_contents(filename);` and `file_put_contents(filename, filecontent);` allow you to read from and write to files. This is essential for interacting with external data.

User Input: The `ask();` function allows you to prompt the user for input. It reads a line of text from the user and returns it as a string.

These functions are easy to use and designed to reduce the complexity of file operations and user interaction.

# Hello world

`number main()
begin
  display "Hello world!";
end
`
