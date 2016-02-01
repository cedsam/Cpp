#include <stdlib.h>
#include <stdio.h>

//Si le processus pere (proc_zomb.exe) est arrete, la generation des processus zombie s'arrete (condition else).
int main()
{
	pid_t pid;//Capture le PID utilise par ce programme (proc_zomb.exe) via pid_t.
	int i;
	printf("Generation de processus zombie...\n");
	for (i = 0; ; i++)
	{
		pid = fork(); //Fork permet de cree le processus fils.
		if (pid > 0)
		{
			i + 1;
			sleep(10);
		}
		else //Critique(permet d'eviter de creer un "fork bomb").
		{
			exit(0);
		}
	}
	return 0;
}
