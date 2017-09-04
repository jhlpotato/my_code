#ifndef __PTHREAD_MONITOR_H__
#define __PTHREAD_MONITOR_H__

#include <pthread.h>
#include <time.h>
#include "list.h"

#define MAX_EXPIRE_TIME 5

struct pthread_info
{
	pthread_t tid;
	struct list_head node;
	time_t time;
};

int pthread_monitor_init(void);
struct pthread_info * pthread_monitor_regsiter(void);
void pthread_monitor_update(struct pthread_info * info);
void pthread_monitor_process(void);

#endif
