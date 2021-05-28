#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<iostream>
#include <bits/stdc++.h> 

int main(int argc, char* argv[]) {


    pid_t p;

    int pipe_1[2];
    int pipe_2[2];
    int pipe_3[2];
    int pipe_4[2];

    if (pipe (pipe_1)) {
        fprintf (stderr, "Pipe failed.\n");
        return 1;
    }

    if (pipe (pipe_2)) {
        fprintf (stderr, "Pipe failed.\n");
        return 1;
    }

    if (pipe (pipe_3)) {
        fprintf (stderr, "Pipe failed.\n");
        return 1;
    }

    if (pipe (pipe_4)) {
        fprintf (stderr, "Pipe failed.\n");
        return 1;
    }
    
    p = fork();

    if (p < 0) {
        fprintf(stderr, "Fork Failed" );
        return 1;
    }

    //Parent Process
    else if (p > 0) { 

        for (int i = 1; i < argc; i++) {
            int temp = atoi(argv[i]);
            write(pipe_1[1], &temp, sizeof(int));
        }

        for (int i = 0; i < argc-1; i++) {
            int temp;
            read(pipe_3[0], &temp, sizeof(int));
            std::cout <<  temp << " ";
        }

        std::cout << "\n";

        wait(NULL);
        p = fork();
 
        if (p < 0) {
            fprintf(stderr, "Fork Failed" );
            return 1;
        }

        //Parent Process
        else if (p > 0) {
            wait(NULL);

            int median;
            read(pipe_4[0], &median, sizeof(int));
            std::cout << median << "\n";

        }

        // Child Process
        else {
            int arr[argc-1];
            int temp;

            for (int i = 0; i < argc-1; i++) {
                read(pipe_2[0], &temp, sizeof(int));
                arr[i] = temp;
            }

            int n = sizeof(arr) / sizeof(arr[0]);

            // I dont know why, but just in case there is an even number of inputs
            if((argc-1)%2 == 0) {
                int left = arr[(n/2)-1];
                int right = arr[n/2];
                int median = (left+right)/2;
                write(pipe_4[1], &median, sizeof(int));
            }
            else {
                write(pipe_4[1], &arr[n/2], sizeof(int));
            }

            exit(0);
        }
    }

    // Child Process
    else { 
        int arr[argc-1];
        int temp;

        for(int i = 0; i < argc-1; i++){
            read(pipe_1[0], &temp, sizeof(int));
            arr[i] = temp;
        }

        int n = sizeof(arr) / sizeof(arr[0]);
        std::sort(arr, arr + n);

        //Going to second child
        for (int i = 0; i < argc-1; i++) {
            temp = arr[i];
            write(pipe_2[1], &temp, sizeof(int));
        }

        //Going to parent
        for (int i = 0; i < argc-1; i++) {
            temp = arr[i];
            write(pipe_3[1], &temp, sizeof(int));
        }
    }
}
