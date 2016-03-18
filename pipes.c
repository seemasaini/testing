
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
   int child_pid=0,len=0;
   int fpipes[2];
   char arr[]="hi this is parent";
   char newarr[20];
   child_pid=fork();
   if(pipe(fpipes)==0)
   {
   	switch(child_pid)
   	{
       		case  0:
		printf("entered child process\n");
		len=read(fpipes[0],newarr,sizeof(arr));
                printf("Data read:%d\n",len);
       		sleep(1);
                close(fpipes[0]);
		break;
       		case -1:
                exit(EXIT_FAILURE);
		break;
       		default:
                printf("entered parent process\n");
                len=write(fpipes[1],arr,sizeof(arr));
                printf("data written is %d\n",len);
                sleep(2);
                close(fpipes[1]);
                printf("parent exit");
       		break;

   	}
   }
   exit(EXIT_SUCCESS);
}
