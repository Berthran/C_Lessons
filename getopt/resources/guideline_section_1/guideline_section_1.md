### **Section 1: Compilation and Build Process**  
**Guidelines**: 1, 2, 3, 32  
**Theme**: Setting up a robust and clean build environment while avoiding unnecessary resource waste.  

---

#### **Introduction**  
Every project must have a well-organized compilation and build system to ensure consistent and efficient development. These guidelines emphasize compiling without errors, creating a `Makefile` for automation, making targets idempotent, and avoiding unnecessary resource consumption by keeping headers focused and clean.  

---

### Guideline 1: Compilation Without Errors
`All source files of your program(s) should compile with`
Command:  
```bash  
gcc -std=c99 -pedantic -Wall -D_DEFAULT_SOURCE-D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809L -g -c file.c 

   ```  
   **Explanation**:  
   - The flags ensure compliance with C99, detect warnings, and include necessary feature macros.
        * `std=c99`: Use the C99 standard for compiling.
        * `-pedantic`: Warns about non-standard practices.
        * `-Wall`: Enables all warnings.
        * `-D_<SOURCE>`: Defines macros that control compatibility with certain system APIs.
        * `-g`: Generates debug information for tools like gdb.

### Guideline 2&3. A Basic Makefile

*There should be a Makefile implementing the targets: `all` to build the program(s) (i.e. generate executables) from the sources (this must be the first target in the Makefile); `clean` to delete all files that can be built from your sources with the Makefile.`*

*Make all targets of your `Makefile` idempotent. I.e. execution of `make clean;` `make clean` should yield the same result as `make clean`, and should not fail with an error*

**Illustrative Example:**

   ```makefile  
   all: program  

   program: main.o utils.o  
       gcc -o program main.o utils.o  

   main.o: main.c  
       gcc -std=c99 -c main.c  

   utils.o: utils.c  
       gcc -std=c99 -c utils.c  

   clean:  
       rm -f *.o program  
   ```  
   **Explanation**:  
   - `all`: Builds the program.  
   - `clean`: Deletes generated files for a clean slate.  


### Guidline 32: Avoiding Redundant Implementation in Headers
`Don’t waste resources due to inconvenient programming. Header files shall not include implementation parts (exception: macros).`

**Illustration**

   ```c  
   // Header file (math_utils.h)  
   #ifndef MATH_UTILS_H  
   #define MATH_UTILS_H  
   int add(int a, int b);  
   #endif  

   // Implementation file (math_utils.c)  
   #include "math_utils.h"  
   int add(int a, int b) { return a + b; }  
   ```  
   **Explanation**: Keep implementation in `.c` files to prevent resource waste.  

---

