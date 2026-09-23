#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  volatile int i;
  volatile int x = 0;

  printf("CPU abuse test starting\n");

  for(i = 0; i < 1000000000; i++) {
    x++;
  }

  printf("CPU abuse test completed\n");
  exit(0);
}