**Solution**:  
```makefile  
   all: program  

   program: main.o math.o string_utils.o  
       gcc -o program main.o math.o string_utils.o  

   main.o: main.c  
       gcc -std=c99 -c main.c  

   math.o: math.c  
       gcc -std=c99 -c math.c  

   string_utils.o: string_utils.c  
       gcc -std=c99 -c string_utils.c  

   clean:  
       rm -f *.o program  
   ```  

---

