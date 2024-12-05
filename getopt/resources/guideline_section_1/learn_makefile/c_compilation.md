### **Tree Representation of the C Compilation Process**

```
C Compilation Process
├── Preprocessing
│   ├── Input Files: .c file, .h files
│   ├── Processes: Macro expansion, header inclusion, conditional compilation
│   ├── Command: gcc -E file.c -o file.i
│   ├── Output File: Preprocessed file (.i)
│
├── Compilation
│   ├── Input Files: Preprocessed file (.i)
│   ├── Processes: Convert C code to assembly language
│   ├── Command: gcc -S file.i -o file.s
│   ├── Output File: Assembly file (.s)
│
├── Assembly
│   ├── Input Files: Assembly file (.s)
│   ├── Processes: Convert assembly to machine code
│   ├── Command: gcc -c file.s -o file.o
│   ├── Output File: Object file (.o)
│
├── Linking
│   ├── Input Files: Object files (.o), libraries (.a, .so)
│   ├── Processes: Resolve symbols, combine object files and libraries
│   ├── Command: gcc file.o -o program
│   ├── Output File: Executable file (e.g., program or program.exe)
```

---

### **Table Representation**

| **Stage**          | **Input Files**                | **Processes**                              | **Command**                       | **Output File**         |
|---------------------|--------------------------------|--------------------------------------------|------------------------------------|-------------------------|
| **Preprocessing**   | `.c` files, `.h` files        | Macro expansion, header inclusion, conditional compilation | `gcc -E file.c -o file.i`         | Preprocessed file `.i`  |
| **Compilation**     | Preprocessed file `.i`        | Convert C code to assembly language        | `gcc -S file.i -o file.s`         | Assembly file `.s`      |
| **Assembly**        | Assembly file `.s`            | Convert assembly to machine code           | `gcc -c file.s -o file.o`         | Object file `.o`        |
| **Linking**         | Object files `.o`, libraries  | Resolve symbols, combine object files and libraries | `gcc file.o -o program`           | Executable file         |

---

### **Highlights**
- **Commands**: Each stage's command explicitly generates the output.
- **Outputs**: Each stage creates an intermediate or final output file for the next stage.
- **Processes**: Captures the key actions at each step in the pipeline.