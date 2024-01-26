#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Creates an infinite loop to keep the program running
 *
 * Return: Always 0 (infinite loop)
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    pid_t zombie_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        zombie_pid = fork(); // Create child process

        if (zombie_pid > 0)
        {
            printf("Zombie process created, PID: %d\n", zombie_pid);
        }
        else
        {
            exit(0); // Child exits immediately, becoming a zombie
        }
    }

    infinite_while(); // Keep the program running

    return (0);
}
