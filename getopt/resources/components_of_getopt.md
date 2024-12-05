**Understand the Components of `getopt`:**  
   Before diving into usage, familiarize yourself with key variables:  
   - `int opt`: Stores the option returned by `getopt`. This value corresponds to the option character (e.g., h for -h).
   - `char *optarg`: Holds the argument of the current option, if it requires one.  
   - `int optind`: Index of the next element to process in `argv`.  
   - `int opterr`: Controls error messages. Set to `0` to suppress them.  
   - `int optopt`: Stores an unknown option character.  

3. **Define the Option String:**  
   Create a string where each character represents a valid option:  
   - A single character (e.g., `h`) indicates an option without an argument.  
   - A colon (`:`) after a character indicates the option requires an argument (e.g., `o:`).  
   - A double colon (`::`) indicates an **optional argument** (GNU `getopt` extension).  

   Example:
   ```c
   const char *optstring = "ho:v";
   ```

   This allows:
   - `-h`: No argument required.  
   - `-o [filename]`: Requires an argument.  
   - `-v`: No argument required.
