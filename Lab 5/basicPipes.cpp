#include <iostream>
#include <string>

int main(int argc, char* argv[]) 
{
    std::string s;
    int count = 0;
    while(getline(std::cin, s)){
        count++;
    }
    std::cout << "Program failed on operation " << count << std::endl;
    return 0;
}
