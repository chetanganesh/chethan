#include<stdio.h>
#include<sys/types.h>
#include<error.h>
int main()
{
   pid_t cpid;
    
   cpid=fork();
   if(cpid==0)
	{
		printf("child process %d , parent process %d\n",getpid(),cpid);
        }
   else
{
       sleep(2);
       printf("parent process %d child %d \n",getpid(),getppid());
}
return 0;
}      





