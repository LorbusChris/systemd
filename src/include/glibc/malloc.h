/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <malloc.h>        /* IWYU pragma: export */

/* mallinfo2() was added in glibc-2.33 (deprecating mallinfo(), whose int-sized fields overflow on
 * large processes). On older glibc synthesize it from mallinfo(); the fields carry the same
 * meaning. */
#if !__GLIBC_PREREQ(2, 33)
struct mallinfo2 {
        size_t arena;    /* non-mmapped space allocated from system */
        size_t ordblks;  /* number of free chunks */
        size_t smblks;   /* number of fastbin blocks */
        size_t hblks;    /* number of mmapped regions */
        size_t hblkhd;   /* space in mmapped regions */
        size_t usmblks;  /* always 0, preserved for backwards compatibility */
        size_t fsmblks;  /* space available in freed fastbin blocks */
        size_t uordblks; /* total allocated space */
        size_t fordblks; /* total free space */
        size_t keepcost; /* top-most, releasable (via malloc_trim) space */
};

static inline struct mallinfo2 mallinfo2(void) {
        struct mallinfo m = mallinfo();

        return (struct mallinfo2) {
                .arena    = (unsigned) m.arena,
                .ordblks  = (unsigned) m.ordblks,
                .smblks   = (unsigned) m.smblks,
                .hblks    = (unsigned) m.hblks,
                .hblkhd   = (unsigned) m.hblkhd,
                .usmblks  = (unsigned) m.usmblks,
                .fsmblks  = (unsigned) m.fsmblks,
                .uordblks = (unsigned) m.uordblks,
                .fordblks = (unsigned) m.fordblks,
                .keepcost = (unsigned) m.keepcost,
        };
}
#endif
