#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t child_pid = fork();
    if(child_pid == 0){
        execl("sequential_min_max", " ", "1", "10", NULL);
    }
    else
        return 0;
}