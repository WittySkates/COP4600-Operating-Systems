#include <stdio.h>
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string>

void fuwunction(int id, int rNumber) {
    
    int match = rand() % 10000;
    
    while(match != rNumber) {
        match = rand() % 10000;
    }
    
    printf("Thread %d completed\n" ,id);

    //cout was causing formatting issues with threads completing close to the same time
    //std::cout << "Thread " << id << " completed. \n";
}

int main(int argc, char *argv[]) {
    std::thread myThreads[10];

    for (int i = 0; i < 10; i++) {
        myThreads[i] = std::thread(fuwunction, i, std::stoi(argv[1]));
    }

    for (int i = 0; i < 10; i++) {    
        myThreads[i].join();
    }

    std::cout << "All threads have finished finding numbers" << std::endl;

    return 0;
}
