#include "iostream"


void printByValue(std::string val) // The function parameter is a copy of str
{
    val = {"change0"};
    std::cout << val << '\n'; // print the value via the copy
}


void printByReference(std::string& ref) // The function parameter is a reference that binds to str
{
    ref = "changed by reference"; 
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    *ptr = "change 2";
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    std::cout<<str<<std::endl;
    printByReference(str);
    std::cout<<str<<std::endl;
     // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str
    std::cout<<str<<std::endl;
    return 0;
}