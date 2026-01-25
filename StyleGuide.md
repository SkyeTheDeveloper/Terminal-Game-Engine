# Style Guide
If you would like to contribute to this repo, there are a few stylistic things that must be taken care of

## Formatting and Layout
### Indentation Style
- Indentations must be consistent for the entire file (e.g. having a single if statement use K&R when the rest of the file is Allman)
- 1TBS/OTBS/Java, K&R, or Allman is preferred

### Whitespace
- Always add a space between operators (e.g. x += y or x || y; only exception is "!x")
- Always add a space after commas
- When using K&R indentations, add a space before the curly brace
- Always add a blank line between sections of code that are not related but physically close to each other

### Line Length
- Try and stay below 100 characters per line, but its not enforced unless its incredibly long

## Naming Conventions
### Cases
- Variables and Functions should use snake_case
- Filenames, Structs, and Enums should use PascalCase
- Constants and Macros should use SCREAMING_SNAKE_CASE
- Global Variables should use snake_case, but theey should be denoted with "g_" at the start (avoid Globals if possible)

### Descriptiveness
- Use descriptive names for everything (e.g. "car_count" as opposed to "var2" or "MainMenu.c" instead of "file1.c")

## Commenting
### Explanations
- Add a comment directly above methods that do something that is not instantly obvious
- Add comments to "magic numbers" if they are needed (see Programming Practices requirement 3)

### File Headers
- When you create a new file, make a header saying the file name, your name, and a brief description of what it does
- Header should look like this
<pre>/* (file name).(extension)        
 * Author(s): (authors names here)
 * Description: (description here)
 * Indentation Style: (brace style)
 */</pre>
- If you contribute to a file, add your name to the list of authors for that file

## Programming Practices
- Use constants when possible
- Minimize the scope of a variable and declare it as close to its first use as possible
- Avoid random numbers and instead declare them as variables or explain why that number is what it is
- Reduce functions to one use if possible to increase modularity
- Reduce files to do one section of code (e.g. one file for the main menu, another for the game logic, etc.) to increase modularity
- Create a new header file for each file and #include stuff only required for that one source file
- Do not prototype all functions in the header file, but instead prototype only the ones needed outside of the source file in the header and prototype the others above the first function of the source file
- Reduce the use of external libraries and headers if possible, if not, include their license in a licenses folder
- If a method does not have any arguments, always put void in the definition and the prototype, but it is never required when calling the function

## Compiler and Portability
- add `-Wall -Wextra -Wpedantic` to your compilation args to see all warnings, and treat every one as an error
- Do not commit and push until the program fully works
- Use the newest standard of C possible unless there is a catastrophic issue with it