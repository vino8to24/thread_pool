#ifndef THREADPOOL_H_
#define THREADPOOL_H_

typedef struct threadpool_t threadpool_t;
/*
 * @function threadpool_create
 * @desc creates a threadpool_t object
 * @param thr_num thread num
 * @param max_thr_num max thread num
 * @param queue_max_size size of the queue
 * @return a newly created thread pool for NULL
 */
threadpool_t * threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);

/**
 * @function threadpool_add
 * @desc add a new task in the queue of a thread pool
 * @param pool thread pool to which add the task
 * @param function pointer to the function that will perform the task
 * @param argument argument to be passed to the function
 * @return 0 if all goes well, else -1
 */
int threadpool_add(threadpool_t *pool, void*(*function)(void *arg), void *arg);

/**
 * @function threadpool_destroy
 * @desc stops and destroys a thread pool
 * @param pool thread pool to destroy
 * @return 0 if destroy success else -1
 */
int threadpool_destroy(threadpool_t *pool);

/**
 * @desc get the thread num
 * @param pool thread pool
 * @return num of the thread
 */
int threadpool_all_threadnum(threadpool_t *pool);

/**
 * @desc get the busy thread num
 * @param poll thread pool
 * @return num of the busy thread
 */
int threadpool_busy_threadnum(threadpool_t *pool);
 
#endif
