// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef CONDITION_H
#define CONDITION_H

#include "macro_utils.h"
#include "lock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* COND_HANDLE;

#define COND_RESULT_VALUES \
    COND_OK, \
    COND_ERROR, \
    COND_TIMEOUT \

/** @brief Enumeration specifying the lock status.
*/
DEFINE_ENUM(COND_RESULT, COND_RESULT_VALUES);

/**
* @brief	This API creates and returns a valid condition handle.
*
* @return	A valid @c COND_HANDLE when successful or @c NULL otherwise.
*/
extern COND_HANDLE Condition_Init(void);

/**
* @brief	unblock all currently working condition.
*
* @param	handle	A valid handle to the lock.
*
* @return	Returns @c COND_OK when the condition object has been
* 			destroyed and @c COND_ERROR when an error occurs
* 			and @c COND_TIMEOUT when the handle times out.
*/
extern COND_RESULT Condition_Post(COND_HANDLE  handle);

/**
* @brief	block on the condition handle unti the thread is signalled
*           or until the timeout_milliseconds is reached.
*
* @param	handle	A valid handle to the lock.
*
* @return	Returns @c COND_OK when the condition object has been
* 			destroyed and @c COND_ERROR when an error occurs
* 			and @c COND_TIMEOUT when the handle times out.
*/
extern COND_RESULT Condition_Wait(COND_HANDLE  handle, LOCK_HANDLE lock, int timeout_milliseconds);

/**
* @brief	The condition instance is deinitialized.
*
* @param	handle	A valid handle to the condition.
*
* @return	Returns @c COND_OK when the condition object has been
* 			destroyed and @c COND_ERROR when an error occurs.
*/
extern COND_RESULT Condition_Deinit(COND_HANDLE  handle);

#ifdef __cplusplus
}
#endif

#endif /* LOCK_H */
