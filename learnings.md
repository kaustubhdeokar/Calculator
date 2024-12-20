- compiler - c++ code to machine language instructions -> object files.
  - 3 cpp means - 3 object files.
- linker - combine all object files into an executable file.
- Do not #include .cpp files 
  - In a large project it can be hard to avoid one definition rules (ODR) issues.
  - Any change to such a .cpp file will cause both the .cpp file and any other .cpp file that includes it to recompile, which can take a long time. Headers tend to change less often than source files.

In C++, storage classes define the scope (visibility) and lifetime of variables and/or functions within a C++ program. There are several storage classes in C++:

1. auto
Scope: Local to the block in which it is defined.
Lifetime: Exists until the block in which it is defined exits.
Default: By default, all local variables are auto.
Example:
2. register
Scope: Local to the block in which it is defined.
Lifetime: Exists until the block in which it is defined exits.
Usage: Suggests that the variable be stored in a CPU register instead of RAM for faster access. Modern compilers often ignore this.
Example:
3. static
Scope:
For local variables: Local to the block in which it is defined.
For global variables and functions: Local to the file in which it is defined.
Lifetime: Exists for the entire duration of the program.
Usage:
For local variables: Retains its value between function calls.
For global variables and functions: Restricts visibility to the file.
Example:
4. extern
Scope: Global.
Lifetime: Exists for the entire duration of the program.
Usage: Declares a variable or function that is defined in another file or later in the same file.
Example:
5. mutable
Scope: Member variables of a class.
Lifetime: Exists for the lifetime of the object.
Usage: Allows a member of an object to be modified even if the object is declared as const.
Example:
Summary
auto: Default storage class for local variables.
register: Suggests storing the variable in a CPU register.
static: Retains value between function calls or restricts visibility to the file.
extern: Declares a variable or function defined elsewhere.
mutable: Allows modification of a member variable in a const object.
These storage classes help manage the scope, visibility, and lifetime of variables and functions in C++ programs.

- Static Libraries (.lib)
  - File Extension: Typically .lib on Windows, .a on Unix-like systems.
  - Linking: Linked at compile time. The code from the static library is copied into the executable at the time of linking.
  - Distribution: The resulting executable is self-contained and does not require the static library to be present at runtime.
  - Size: The executable size increases because it contains all the code from the static libraries it uses.
  - Performance: Slightly faster at runtime since no dynamic linking is required.

- Dynamic Link Libraries (DLLs)
  - File Extension: Typically .dll on Windows, .so (shared object) on Unix-like systems.
  - Linking: Linked at runtime. The executable contains references to the DLL, which is loaded into memory when the program starts or when the DLL is explicitly loaded.
  - Distribution: The DLL must be present on the system where the executable runs. The executable is smaller because it does not contain the code from the DLL.
  - Size: The executable size is smaller, but the DLL must be distributed alongside the executable.
  - Performance: Slightly slower at runtime due to the overhead of dynamic linking.

### C++ compilation/Header files logic.

on compilation each of the cpp file is compiled to a .obj file. 
every .obj file is unaware of another .obj file. 
so each cpp file is unaware of the contents in another cpp file.

linker combines all of the .obj files into one, which is the application .exe. 

so, if we want to use the same function in multiple function, we will have to copy the declaration into all the required files. 

but if we copy the definition of the function also, we will get an error as the linker will throw an error on encountering multiple definitions. 

instead of this a .h (header) file is created where we have the function definitions,
a file with the same name is created as an implementation of the function in .h file.  
and then we can include the header files in the required cpp files.

#### Makefile

What Happens When make is Run?
Make Reads the Default Target:

The first target, all, is invoked by default.
It declares that $(LIB_DIR)/trig.lib, $(LIB_DIR)/compound_interest.dll, and calculator must be built.
Dependency Resolution:

Make checks if these files exist and if their dependencies are up-to-date.
If a dependency is missing or outdated, it invokes the corresponding rule to generate it.
Build Workflow:

Step 1: Build trig.lib.

Rule:

```
$(LIB_DIR)/trig.lib: $(BUILD_DIR)/trig_operations.o
    lib /OUT:$@ $^
```

```
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<
```

trig_operations.cpp is compiled into trig_operations.o.
The static library trig.lib is then created using lib.