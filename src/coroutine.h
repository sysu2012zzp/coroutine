#ifndef __COROUTINE_H__
#define __COROUTINE_H__


#include "context.h"


extern int g_init;


void coroutine_init();


/**
 * Create a new coroutine but not yet run it.
 *
 * @attr: attributes of coroutine (have no meaning at present).
 * @start_rtn: function pointer run by coroutine once started.
 * @arg:  argument of start_rtn.
 *
 * @return: a coroutine context if success, NULL if error.
 */
coroutine_ctx_t* coroutine_create(const void *attr,
    void*(*start_rtn)(void*), void *arg);


/**
 * Run a coroutine with given coroutine id.
 * The caller routine will be suspended at once.
 *
 * @ctx: coontext of coroutine which you want to run now.
 */
void coroutine_resume(coroutine_ctx_t *ctx);


/**
 * Pause the current coroutine and schedule to anyone if ready.
 */
void coroutine_yield();


/**
 * Return the current running coroutine context.
 *
 * @return: context related to current coroutine.
 */
coroutine_ctx_t* coroutine_running();


#endif

