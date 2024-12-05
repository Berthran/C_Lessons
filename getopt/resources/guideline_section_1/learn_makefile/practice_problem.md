#### **Practical Problem**

1. **Problem Statement**:
   Write a `Makefile` for a project with the following files:
   - `main.c`
   - `math.c`
   - `string_utils.c`

   Ensure it has the following:
   - An `all` target to build the executable `program`.
   - A `clean` target to delete all object files and executables.
   - Idempotent behavior (re-running `clean` does nothing new if files are already deleted)
