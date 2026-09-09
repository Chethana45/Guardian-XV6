#ifndef IDS_H
#define IDS_H

// IDS thresholds
#define IDS_FORK_THRESHOLD       10
#define IDS_SYSCALL_THRESHOLD    100
#define IDS_FILE_THRESHOLD       20
#define IDS_CPU_THRESHOLD        10

// Attack/event types
#define IDS_EVENT_FORK            1
#define IDS_EVENT_SYSCALL         2
#define IDS_EVENT_FILE            3
#define IDS_EVENT_CPU             4

// IDS functions
void ids_init(void);

void ids_record_fork(int pid);
void ids_record_syscall(int pid);
void ids_record_file_access(int pid);
void ids_record_cpu_usage(int pid);
struct proc;
void ids_check_process(struct proc *p);
// IDS risk assessment
int ids_calculate_risk(struct proc *p);
void ids_print_status(struct proc *p);

#endif