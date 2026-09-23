#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "proc.h"
#include "ids.h"

// Initialize IDS
void
ids_init(void)
{
  printk("IDS: Intrusion Detection System initialized\n");
}

// Record fork activity
void
ids_record_fork(int pid)
{
  printk("IDS: Process %d performed fork activity\n", pid);
}

// Record system call activity
void
ids_record_syscall(int pid)
{
  if(pid <= 0)
    return;
}

// Record file access
void
ids_record_file_access(int pid)
{
  if(pid <= 0)
    return;
}

// Record CPU usage
void
ids_record_cpu_usage(int pid)
{
  printk("IDS: Process %d has high CPU activity\n", pid);
}

// Calculate IDS risk score
int
ids_calculate_risk(struct proc *p)
{
  int risk = 0;

  if(p == 0)
    return 0;

  if(p->fork_count >= IDS_FORK_THRESHOLD)
    risk += 25;

  if(p->syscall_count >= IDS_SYSCALL_THRESHOLD)
    risk += 25;

  if(p->file_access_count >= IDS_FILE_THRESHOLD)
    risk += 25;

  if(p->cpu_ticks >= IDS_CPU_THRESHOLD)
    risk += 25;

  return risk;
}

// Check process for suspicious activity
void
ids_check_process(struct proc *p)
{
  int risk;

  if(p == 0)
    return;

  risk = ids_calculate_risk(p);

  // Fork activity detection
  if(p->fork_count >= IDS_FORK_THRESHOLD) {
    printk("IDS ALERT: PID %d (%s) - Excessive process creation\n",
           p->pid, p->name);
  }

  // System call detection
  if(p->syscall_count >= IDS_SYSCALL_THRESHOLD) {
    printk("IDS ALERT: PID %d (%s) - Excessive system calls\n",
           p->pid, p->name);
  }

  // File activity detection
  if(p->file_access_count >= IDS_FILE_THRESHOLD) {
    printk("IDS ALERT: PID %d (%s) - Excessive file access\n",
           p->pid, p->name);
  }

  // CPU activity detection
  if(p->cpu_ticks >= IDS_CPU_THRESHOLD) {
    printk("IDS ALERT: PID %d (%s) - Excessive CPU usage\n",
           p->pid, p->name);
  }

  // Automatic response for critical processes
  if(risk >= 75) {
    printk("IDS RESPONSE: PID %d (%s) marked CRITICAL\n",
           p->pid, p->name);

    p->killed = 1;
  }
}

// Print IDS process status
void
ids_print_status(struct proc *p)
{
  int risk;

  if(p == 0)
    return;

  risk = ids_calculate_risk(p);

  printk("PID %d (%s): Fork=%d Syscall=%d File=%d CPU=%d Risk=%d ",
         p->pid,
         p->name,
         p->fork_count,
         p->syscall_count,
         p->file_access_count,
         p->cpu_ticks,
         risk);

  if(risk >= 75)
    printk("CRITICAL\n");
  else if(risk >= 50)
    printk("SUSPICIOUS\n");
  else if(risk >= 25)
    printk("WARNING\n");
  else
    printk("NORMAL\n");
}
