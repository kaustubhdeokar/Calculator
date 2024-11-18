#include <iostream>
#include <cstring>
#include "add.h"

const int max_len = 255;

namespace MyNamespace
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::string chars{};
    
    unsigned int i;
    unsigned int j;
    std::cin>>i>>j;
    std::cout<<i-j;
    
    while(false){
        std::cout << "Enter a string: ";
        std::getline(std::cin >> std::ws, chars);
        std::cout<<chars<<" ";
        if(chars == "exit"){
            break;
        }
    }

    return 0;
}
