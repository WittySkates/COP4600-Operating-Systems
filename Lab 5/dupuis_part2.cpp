#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) 
{
    std::ifstream file;
    file.open("namedPipe");

    std::string s;

    int count = 0;
    while(getline(file, s)){
        count++;
    }
    std::cout << "Program failed on operation " << count << std::endl;
    return 0;
}
