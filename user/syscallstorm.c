#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int i;

  printf("Syscall storm test starting\n");

  for(i = 0; i < 150; i++) {
    getpid();
  }

  printf("Syscall storm test completed\n");
  exit(0);
}