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