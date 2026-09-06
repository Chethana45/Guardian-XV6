#ifndef IDS_H
#define IDS_H

// IDS thresholds
#define IDS_FORK_THRESHOLD       10
#define IDS_SYSCALL_THRESHOLD    100
#define IDS_FILE_THRESHOLD       20
#define IDS_CPU_THRESHOLD        80

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

void ids_check_process(int pid);

#endif