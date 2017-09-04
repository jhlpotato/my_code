#include "pthread_monitor.h"

struct list_head pthread_monitor_list_head;
pthread_rwlock_t pthread_monitor_rwlock;

int pthread_monitor_init(void)
{
	int ret = 0;
	LIST_HEAD(pthread_monitor_list_head);
	ret = pthread_rwlock_init(pthread_monitor_rwlock, NULL);
	return ret;
}

struct pthread_info * pthread_monitor_regsiter(void)
{
	struct pthread_info *info = (struct pthread_info *)malloc(sizeof(struct pthread_info));
	if (NULL == info) {
		printf("pthread_monitor_regsiter() malloc fail!\n");
		return NULL;
	}

	pthread_rwlock_wrlock(&pthread_monitor_rwlock);
	info->tid = pthread_self();
	info->time = time(NULL);
	list_add_tail(&info->node, &pthread_monitor_list_head);
	pthread_rwlock_unlock(&pthread_monitor_rwlock);
	return info;
}

void pthread_monitor_update(struct pthread_info *info)
{
	info->time = time(NULL);
}

void pthread_monitor_process(void)
{
	pthread_info *item;
	time_t now = time(NULL);
	pthread_rwlock_rdlock(&pthread_monitor_rwlock);
	list_for_each(item, &pthread_monitor_list_head) {
		if (now - item->time > MAX_EXPIRE_TIME) {
			pthread_kill(item->tid);
			printf("pthread %d is killed.\n", item->tid);	
			pthread_rwlock_unlock(&pthread_monitor_rwlock);
			return;
		}
	}
	pthread_rwlock_unlock(&pthread_monitor_rwlock);
}
