/*
 * Copyright (c) 2025 Brilliant Labs
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_LOG_BACKEND_FS_H_
#define ZEPHYR_LOG_BACKEND_FS_H_

#include <zephyr/toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_LOG_BACKEND_FS)
/**
 * @brief Reset the filesystem log backend.
 *
 * @details Closes the currently open log file and resets the backend to its
 *          uninitialized state. The next log message will trigger a fresh
 *          initialization that scans the log directory and allocates a new
 *          file. This is intended to be called after external code deletes
 *          log files (e.g. a user-initiated clear operation) so that the
 *          backend does not keep operating on stale, deleted file handles.
 */
void log_backend_fs_reset(void);
#else
static inline void log_backend_fs_reset(void)
{
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_LOG_BACKEND_FS_H_ */
