/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <unistd.h>        /* IWYU pragma: export */

int close_range_shim(unsigned int first, unsigned int last, int flags);
#define close_range close_range_shim

int pivot_root_shim(const char *new_root, const char *put_old);
#define pivot_root pivot_root_shim
