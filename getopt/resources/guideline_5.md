### **Section 5: Code Quality and Readability**  
**Guidelines**: 10, 18, 20, 21, 27, 28  
**Theme**: Writing clean, consistent, and understandable code for better collaboration and maintenance.  

---

#### **Introduction**  
Readable and maintainable code is critical in software engineering. These guidelines emphasize consistent formatting, meaningful names, clear indentation, and avoiding complex arithmetic expressions that compromise clarity.  

---

#### **Examples**  

1. **Meaningful Variable and Constant Names**  
   ```c  
   // Good naming  
   #define MAX_CONNECTIONS 10  
   int current_connections = 0;  

   // Poor naming  
   #define M 10  
   int cc = 0;  
   ```  

2. **Consistent Indentation**  
   ```c  
   // Consistent  
   void display() {  
       if (1) {  
           printf("Hello\n");  
       } else {  
           printf("World\n");  
       }  
   }  

   // Inconsistent  
   void display() {  
       if (1) {  
           printf("Hello\n");  
           } else {  
       printf("World\n");  
       }  
   }  
   ```  

3. **Avoiding Tricky Arithmetic**  
   ```c  
   // Clear and readable  
   total_cost = price_per_item * quantity;  

   // Tricky and unclear  
   total_cost = price_per_item + --quantity * price_per_item / 2;  
   ```  

---

#### **Practical Problem**  

1. **Problem Statement**:  
   Refactor the following code to improve readability, naming, and indentation:  
   ```c  
   int fn(int a, int b) {return a+b*2;}  
   int main(){int x=fn(2,3);printf("%d",x);return 0;}  
   ```  

2. **Solution**:  
   ```c  
   #include <stdio.h>  

   int calculate_total(int base, int multiplier) {  
       return base + multiplier * 2;  
   }  

   int main() {  
       int result = calculate_total(2, 3);  
       printf("%d\n", result);  
       return 0;  
   }  
   ```  

---

### **Section 6: Defensive and Logical Programming**  
**Guidelines**: 24, 25, 26, 8  
**Theme**: Writing programs that anticipate edge cases, handle logical operations appropriately, and ensure code safety.  

---

#### **Introduction**  
Defensive and logical programming practices ensure programs behave predictably, even in unexpected situations. This section focuses on avoiding side effects in conditions, handling all `switch` cases, using logical operators correctly, and checking return values of functions.  

---

#### **Examples**  

1. **Avoiding Side Effects in Conditions**  
   ```c  
   // Correct  
   if (b != 0) {  
       c = a / b;  
   }  

   // Incorrect  
   if (b != 0 && (c = a / b)) {  
       // Side effect in condition  
   }  
   ```  

2. **Handling Default in `switch`**  
   ```c  
   switch (option) {  
       case 1:  
           printf("Option 1\n");  
           break;  
       case 2:  
           printf("Option 2\n");  
           break;  
       default:  
           printf("Invalid option\n");  
   }  
   ```  

3. **Using Logical Operators Properly**  
   ```c  
   // Correct  
   if (strcmp(str1, str2) == 0) {  
       printf("Strings are equal\n");  
   }  

   // Incorrect  
   if (!strcmp(str1, str2)) {  
       printf("Strings are equal\n");  
   }  
   ```  

---

#### **Practical Problem**  

1. **Problem Statement**:  
   Write a program that:  
   - Takes an integer input.  
   - If the number is divisible by 2, print "Even".  
   - If the number is divisible by 3, print "Divisible by 3".  
   - Use defensive programming to handle invalid inputs.  

2. **Solution**:  
   ```c  
   #include <stdio.h>  
   #include <stdlib.h>  

   int main() {  
       int number;  

       printf("Enter an integer: ");  
       if (scanf("%d", &number) != 1) {  
           fprintf(stderr, "Invalid input\n");  
           return EXIT_FAILURE;  
       }  

       if (number % 2 == 0) {  
           printf("Even\n");  
       } else if (number % 3 == 0) {  
           printf("Divisible by 3\n");  
       } else {  
           printf("Other\n");  
       }  

       return EXIT_SUCCESS;  
   }  
   ```  

---

### **Section 7: Input/Output and Signal Handling**  
**Guidelines**: 11, 12, 29, 30  
**Theme**: Safe and consistent handling of input/output operations and signal processing.  

---

#### **Introduction**  
This section addresses how to manage input and output securely, avoid unsafe functions, and handle signals for graceful program behavior under interruptions.  

---

#### **Examples**  

1. **Writing Error Messages to `stderr`**  
   ```c  
   fprintf(stderr, "%s: Error occurred\n", argv[0]);  
   ```  

2. **Replacing Unsafe Functions**  
   ```c  
   // Avoid: gets(buffer);  
   // Use:  
   fgets(buffer, sizeof(buffer), stdin);  

   // Avoid: atoi(string);  
   // Use:  
   int value = strtol(string, NULL, 10);  
   ```  

3. **Signal Handling**  
   ```c  
   #include <signal.h>  
   #include <stdio.h>  
   #include <stdlib.h>  

   void handle_signal(int signal) {  
       printf("Caught signal %d\n", signal);  
       exit(EXIT_SUCCESS);  
   }  

   int main() {  
       signal(SIGINT, handle_signal);  
       while (1) {  
           printf("Running...\n");  
           sleep(1);  
       }  
       return 0;  
   }  
   ```  

---

#### **Practical Problem**  

1. **Problem Statement**:  
   Write a program that reads strings safely using `fgets` and terminates gracefully when the `SIGINT` signal is received.  

2. **Solution**:  
   ```c  
   #include <stdio.h>  
   #include <stdlib.h>  
   #include <signal.h>  

   void handle_sigint(int sig) {  
       printf("\nTerminating program gracefully.\n");  
       exit(EXIT_SUCCESS);  
   }  

   int main() {  
       signal(SIGINT, handle_sigint);  

       char buffer[100];  
       printf("Enter text (Ctrl+C to exit): ");  
       while (fgets(buffer, sizeof(buffer), stdin)) {  
           printf("You entered: %s", buffer);  
       }  

       return EXIT_SUCCESS;  
   }  
   ```  

---