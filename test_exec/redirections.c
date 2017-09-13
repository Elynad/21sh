  #include <stdio.h>
  #include <memory.h>
  #include <unistd.h>
  #include <fcntl.h>
 
  int main( int argc, char ** argv )
  {
    char  *args[3];
    char  *args2[3];

    args[0] = "cat";
    args[1] = "-e";
    args[2] = NULL;
    args2[0] = "ls";
    args2[1] = "-l";
    args2[2] = NULL;
   /* create the pipe */
   int pfd[2];
   if (pipe(pfd) == -1)
     {
       printf("pipe failed\n");
       return 1;
     }
 
   /* create the child */
   int pid;
   if ((pid = fork()) < 0)
     {
       printf("fork failed\n");
       return 2;
     }
 
   if (pid == 0)
     {
       /* child */
       close(pfd[1]); /* close the unused write side */
     //   pfd[0] = open("test.txt", O_WRONLY);
       // pfd[0] = open("test.txt", O_RDONLY);    // SET READ SIDE IN THE FILE TEST.TXT
       dup2(pfd[0], 0); /* connect the read side with stdin */
       close(pfd[0]); /* close the read side */
       /* execute the process (cat command) */
        execve("/bin/cat", args, NULL);
       return (-1);
     }
   else
     {
       /* parent */
       close(pfd[0]); /* close the unused read side */
     // pfd[1] = open("test.txt", O_WRONLY);    // SET WRITE SIDE IN THE FILE TEST.TXT => ls > test.txt
      pfd[1] = open("test.txt", O_RDWR);
       dup2(pfd[1], 1); /* connect the write side with stdout */

       close(pfd[1]); /* close the write side */
       /* execute the process (ls command) */
      execve("/bin/ls", args2, NULL);
       return (-1);
     }
   return 0;
  }