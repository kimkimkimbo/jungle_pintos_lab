#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include <hash.h>

/* 파일 디스크립터의 타입을 저장하기 위한 enum */
enum fd_type { FD_NONE, FD_STDIN, FD_STDOUT, FD_FILE };

/* 파일 디스크립터의 단위가 되는 구조체 */
struct fd_value {
	enum fd_type type;
	struct file *file;
};

/* 프로세스마다 파일 디스크립터를 관리하기 위한 구조체 */
struct fd_table {
	struct fd_value fd_node[64];
};

int process_file_open (const char *file_name);
int process_file_length (int fd);
int process_file_read (int fd, const void *buffer, unsigned size);
int process_file_write (int fd, const void *buffer, unsigned size);
void process_file_close (int fd);
tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);

#endif /* userprog/process.h */
