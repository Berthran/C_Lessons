### **Section 3: Documentation and Maintainability**  
**Guidelines**: 13, 14, 15, 16, 17  
**Theme**: Writing clear documentation and maintainable code through proper commenting, structure, and standards.  

---

#### **Introduction**  
Proper documentation and meaningful comments make programs easier to understand, maintain, and extend. These guidelines emphasize documenting code with Doxygen, using descriptive comments, and adhering to a clear structure for documenting modules, functions, variables, and constants.  

---

#### **Examples**  

1. **Doxygen-Style Documentation for a Function**  
   ```c  
   /**  
    * @brief Adds two integers.  
    * @param a The first integer.  
    * @param b The second integer.  
    * @return The sum of the integers.  
    */  
   int add(int a, int b) {  
       return a + b;  
   }  
   ```  

2. **Module Header Documentation**  
   ```c  
   /**  
    * @file math_utils.c  
    * @author John Doe (1234567)  
    * @date 2024-11-30  
    * @brief Provides mathematical utility functions.  
    */  
   ```  

3. **Meaningful Comments**  
   ```c  
   // Correct: Explains the algorithm  
   // Use binary search for faster lookups in a sorted array  
   int binary_search(int *arr, int size, int target) {  
       int left = 0, right = size - 1;  
       while (left <= right) {  
           int mid = left + (right - left) / 2;  
           if (arr[mid] == target)  
               return mid;  
           if (arr[mid] < target)  
               left = mid + 1;  
           else  
               right = mid - 1;  
       }  
       return -1;  
   }  

   // Incorrect: Redundant comment  
   // Increment x by 1  
   x = x + 1;  
   ```  

---

#### **Practical Problem**  

1. **Problem Statement**:  
   Write Doxygen documentation for the following module:  
   ```c  
   // math_utils.c  
   int add(int a, int b) {  
       return a + b;  
   }  

   int multiply(int a, int b) {  
       return a * b;  
   }  
   ```  

2. **Solution**:  
   ```c  
   /**  
    * @file math_utils.c  
    * @author John Doe (1234567)  
    * @date 2024-11-30  
    * @brief Mathematical utility functions.  
    */  

   /**  
    * @brief Adds two integers.  
    * @param a The first integer.  
    * @param b The second integer.  
    * @return The sum of the integers.  
    */  
   int add(int a, int b) {  
       return a + b;  
   }  

   /**  
    * @brief Multiplies two integers.  
    * @param a The first integer.  
    * @param b The second integer.  
    * @return The product of the integers.  
    */  
   int multiply(int a, int b) {  
       return a * b;  
   }  
   ```  

---

### **Section 4: Resource Management**  
**Guidelines**: 31, 9, 22, 23  
**Theme**: Efficient and responsible handling of memory, files, and other resources.  

---

#### **Introduction**  
Proper resource management ensures your program runs efficiently and avoids issues like memory leaks, dangling pointers, or file descriptor exhaustion. These guidelines focus on dynamically allocated memory, avoiding global variables, and using constants for boundaries.  

---

#### **Examples**  

1. **Freeing Dynamically Allocated Memory**  
   ```c  
   #include <stdlib.h>  

   int main() {  
       int *arr = malloc(10 * sizeof(int));  
       if (!arr) {  
           perror("malloc failed");  
           return EXIT_FAILURE;  
       }  

       // Use the array...  
       arr[0] = 42;  

       // Free the memory  
       free(arr);  
       return EXIT_SUCCESS;  
   }  
   ```  

2. **Defining Boundaries as Constants**  
   ```c  
   #define MAX_SIZE 100  

   void process_data(int data[MAX_SIZE]) {  
       for (int i = 0; i < MAX_SIZE; i++) {  
           // Process each element  
       }  
   }  
   ```  

---

#### **Practical Problem**  

1. **Problem Statement**:  
   Write a program that reads integers from a file into a dynamically allocated array. Ensure the following:  
   - Free the allocated memory after use.  
   - Handle errors (e.g., file not found).  
   - Use a constant to define the maximum size of the array.  

2. **Solution**:  
   ```c  
   #include <stdio.h>  
   #include <stdlib.h>  

   #define MAX_SIZE 100  

   int main() {  
       FILE *file = fopen("numbers.txt", "r");  
       if (!file) {  
           perror("File opening failed");  
           return EXIT_FAILURE;  
       }  

       int *arr = malloc(MAX_SIZE * sizeof(int));  
       if (!arr) {  
           perror("Memory allocation failed");  
           fclose(file);  
           return EXIT_FAILURE;  
       }  

       int count = 0;  
       while (count < MAX_SIZE && fscanf(file, "%d", &arr[count]) == 1) {  
           count++;  
       }  

       printf("Read %d numbers.\n", count);  

       // Clean up  
       free(arr);  
       fclose(file);  
       return EXIT_SUCCESS;  
   }  
   ```  

---

Let me know if I should continue with Sections 5 and beyond!