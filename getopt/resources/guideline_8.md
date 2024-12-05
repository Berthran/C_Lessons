### **Section 8: Resource Management and Efficiency**  
**Guidelines**: 31, 22, 23, 32  
**Theme**: Proper allocation, use, and release of resources in programming to avoid inefficiencies, memory leaks, and unnecessary overhead.  

---

#### **Introduction**  
Resource management is crucial in programming. Efficient handling ensures programs use memory and other resources judiciously, avoid waste, and prevent bugs like memory leaks. This section focuses on closing files, freeing dynamically allocated memory, avoiding global variables, and managing boundaries properly.  

---

#### **Examples and Explanation**  

1. **Closing Files and Freeing Resources**  
   Proper resource cleanup prevents memory leaks and dangling resources.  
   ```c  
   FILE *file = fopen("example.txt", "r");  
   if (file == NULL) {  
       perror("Error opening file");  
       return EXIT_FAILURE;  
   }  
   // File operations...  
   fclose(file);  // Always close files when done.  

   char *data = malloc(100 * sizeof(char));  
   if (data == NULL) {  
       fprintf(stderr, "Memory allocation failed\n");  
       return EXIT_FAILURE;  
   }  
   // Use allocated memory...  
   free(data);  // Free memory after use.  
   ```  

2. **Avoiding Global Variables**  
   Global variables increase coupling and reduce modularity. Instead, use local variables or pass parameters to functions.  
   ```c  
   // Avoid global variable  
   int global_count = 0;  

   void increment() {  
       global_count++;  
   }  

   // Use parameters instead  
   void increment_count(int *count) {  
       (*count)++;  
   }  

   int main() {  
       int count = 0;  
       increment_count(&count);  
       printf("Count: %d\n", count);  
       return 0;  
   }  
   ```  

3. **Defining and Handling Boundaries**  
   Use constants to define boundaries for better readability and maintainability. Handle crossing boundaries explicitly.  
   ```c  
   #define MAX_LENGTH 100  

   void process_input(const char *input) {  
       if (strlen(input) >= MAX_LENGTH) {  
           fprintf(stderr, "Input too long\n");  
           return;  
       }  
       // Process input...  
   }  
   ```  

4. **Avoiding Resource Wastage**  
   Only include necessary components in headers and avoid redundant operations.  
   ```c  
   // Avoid including implementation in headers  
   #ifndef HEADER_H  
   #define HEADER_H  

   void function1();  
   void function2();  

   #endif  
   ```  

---

#### **Practical Problems and Solutions**  

1. **Problem Statement**:  
   Write a program that:  
   - Opens a file and reads its content.  
   - Allocates memory dynamically to store a line of text from the file.  
   - Frees the allocated memory and closes the file properly after use.  

2. **Solution**:  
   ```c  
   #include <stdio.h>  
   #include <stdlib.h>  

   int main() {  
       FILE *file = fopen("example.txt", "r");  
       if (file == NULL) {  
           perror("Error opening file");  
           return EXIT_FAILURE;  
       }  

       char *line = malloc(100 * sizeof(char));  
       if (line == NULL) {  
           fprintf(stderr, "Memory allocation failed\n");  
           fclose(file);  
           return EXIT_FAILURE;  
       }  

       while (fgets(line, 100, file) != NULL) {  
           printf("%s", line);  
       }  

       free(line);  
       fclose(file);  
       return EXIT_SUCCESS;  
   }  
   ```  

3. **Problem Statement**:  
   Refactor the following code to remove global variables and use boundary constants:  
   ```c  
   #include <stdio.h>  

   int buffer[256];  

   void process() {  
       for (int i = 0; i < 256; i++) {  
           buffer[i] = i;  
       }  
   }  

   int main() {  
       process();  
       return 0;  
   }  
   ```  

4. **Solution**:  
   ```c  
   #include <stdio.h>  

   #define BUFFER_SIZE 256  

   void process(int *buffer, int size) {  
       for (int i = 0; i < size; i++) {  
           buffer[i] = i;  
       }  
   }  

   int main() {  
       int buffer[BUFFER_SIZE];  
       process(buffer, BUFFER_SIZE);  
       return 0;  
   }  
   ```  

---

This section ties together resource allocation and cleanup, the use of boundaries, and modular coding practices for robust and efficient programming. Let me know if you'd like me to continue!