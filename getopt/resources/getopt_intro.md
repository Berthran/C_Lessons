
**INTRODUCTION**
`getopt` is a useful function in C for parsing (interpreting, extracting and managing, or reading and decoding) command-line options and arguments in a program.
It is useful in applications that rely heavily on CLI interactions, such as scripts, tools and utilities
 

________________________
**ANALOGY**
Using `getopt` is like being a chef following a recipe. Before you start cooking, you check off ingredients and tools from a list to ensure everything is ready. If the list says '2 cups of flour' or '1 teaspoon of salt,' you gather those items.
Similarly, `getopt` acts like a checklist for your program, gathering and organizing the 'ingredients'—the command-line options and arguments—so your program knows exactly what to do before it starts executing its main task.
________________________
**WHY USE `getopt`?**
To make it easier to parse and validate command-line arguments.
 
**HOW TO USE `getopt`?**
- Include the `<unistd.h>` header file
- Define option flags and their expected behaviour. Examples of expected behaviours are:
    * requiring arguments
    * being standalone (not requiring arguments)
- Use a loop to process arguments
- Use a loop to handle non-option arguments
________________________

**WHEN TO USE `getopt`?**
Whenever your program requires dynamic user input through command-line flags (e.g., `-h`, `-o fileoutput`)
________________________
**IN WHAT WAYS CAN `getopt` BE USED?**
- To parse simple options (e.g., `-h` for help)
- To  parse options with arguments (e.g., `-o output.txt`)
- To parse long-form options (e.g., `--help`)