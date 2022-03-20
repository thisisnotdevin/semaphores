/*
* Devin Lin
* CISC 3320
* Homework 2
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <semaphore.h>
#include <time.h>

using namespace std;

struct Semaphores {
    int count;
};

struct Semaphores printer = {5};
struct Semaphores plotter = {6};
struct Semaphores scanner = {4};

void request()
{

    // initializing semaphores
    sem_t *printers = sem_open("printers", O_CREAT, 0660, 5);
    sem_t *plotters = sem_open("plotters", O_CREAT, 0660, 6);
    sem_t *scanners = sem_open("scanners", O_CREAT, 0660, 4);


    srand(time(0));

    int randomNumber = rand() % 3 + 1;
    //generates a random number to see which resource to pick

    int SleepRandom = rand() % 4 + 2;

    switch (randomNumber)
    {
    case 1: // printer is requested

        cout << "pid(" << getpid() << ")" << " Requested printer\n";
        printf("Printer Semaphore value (%d)\n", printer.count);

        printer.count = printer.count - 1;
        if (printer.count > 0) //resource is available!
        {
            sem_wait(printers);
            cout << "pid(" << getpid() << ")" << " Successful request\n";
            printf("Printer Semaphore value (%d)\n", printer.count);
            sleep(randomNumber); //sleep random 1-3 sec
            sem_post(printers);
            printer.count = printer.count + 1;
            sem_close(printers);
            break;
        }
        else //resource is not available
        {
            cout << "pid(" << getpid() << ")" << " Printer resource is not available.\n";
            sleep(SleepRandom); // resource is not available, go sleep
            return;
        }

    case 2: // plotter is requested

        cout << "pid(" << getpid() << ")" << " Requested plotter\n";
        printf("Plotter Semaphore value (%d)\n", plotter.count);

        plotter.count = plotter.count - 1;
        if (plotter.count > 0) //resource is available!
        {
            sem_wait(plotters);
            cout << "pid(" << getpid() << ")" << " Successful request\n";
            printf("Plotter Semaphore value (%d)\n", plotter.count);
            sleep(randomNumber); //sleep random 1-3 sec
            sem_post(plotters);
            plotter.count = plotter.count + 1;
            sem_close(plotters);
            break;
        }
        else //resource is not available
        {
            cout << "pid(" << getpid() << ")" << " Plotter resource is not available.\n";
            sleep(SleepRandom); // resource is not available, go sleep
            return;
        }

    case 3: // scanner is requested

        cout << "pid(" << getpid() << ")" << " Requested scanner\n";
        printf("Scanner Semaphore value (%d)\n", scanner.count);

        scanner.count = scanner.count - 1;
        if (scanner.count > 0) //resource is available!
        {
            sem_wait(scanners);
            cout << "pid(" << getpid() << ")" << " Successful request\n";
            printf("Scanner Semaphore value (%d)\n", scanner.count);
            sleep(randomNumber); //sleep random 1-3 sec
            sem_post(scanners);
            scanner.count = scanner.count + 1;
            sem_close(scanners);
            break;
        }
        else //resource is not available
        {
            cout << "pid(" << getpid() << ")" << " Scanner resource is not available.\n";
            sleep(SleepRandom); // resource is not available, go sleep
            return;
        }
    }
}

int main()
{
    for (int i = 0; i <= 4; i++)
    {
        fork(); //creates child process
        request();
        sleep(rand() % 3 + 1); // step b sleep for 1-3 secs
    }

    return 0;
}






