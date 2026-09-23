#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void)
{
  int pid = fork();

  if(pid < 0){
    printf("idsdemo: fork failed\n");
    exit(1);
  }

  if(pid > 0){
    // Let the worker continue independently.
    printf("IDS combined attack demo started. Worker PID = %d\n", pid);
    exit(0);
  }

  // ---------- FORK ACTIVITY ----------
  for(int i = 0; i < 12; i++){
    int child = fork();

    if(child < 0)
      break;

    if(child == 0)
      exit(0);

    wait(0);
  }

  // ---------- FILE ACTIVITY ----------
  int fd = open("idsdemo.tmp", O_CREATE | O_RDWR);

  if(fd >= 0){
    char buf[] = "IDS DEMO\n";

    for(int i = 0; i < 25; i++){
      write(fd, buf, sizeof(buf));
    }

    close(fd);
  }

  // ---------- SYSTEM CALL ACTIVITY ----------
  for(int i = 0; i < 150; i++){
    getpid();
  }

  // ---------- CPU ACTIVITY ----------
  volatile unsigned long x = 0;

  for(unsigned long i = 0; i < 1000000000UL; i++){
    x++;
  }

  printf("IDS combined activity generated. Worker remains active.\n");

  // Keep the process alive so ids can inspect it.
  volatile unsigned long keepalive = 0;
  for(;;){
    keepalive++;
  }

  exit(0);
}
