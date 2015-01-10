/*
    libsubstitute - https://github.com/comex/substitute
    This header file is in the public domain.
*/

#pragma once

#include <stdlib.h>

// TODO add numbers
enum {
    SUBSTITUTE_OK = 0,

    SUBSTITUTE_ERR_MODULE_NOT_FOUND,
};

int substitute_hook_function(void *function, void *replacement, int options, void *result);

#if 1 /* declare substitute_find_syms? */

#ifdef __APPLE__
#include <mach-o/nlist.h>
#ifdef __LP64__
typedef struct nlist_64 substitute_sym;
#else
typedef struct nlist substitute_sym;
#endif
#else
#error No definition for substitute_sym!
#endif

/* Look up private symbols in an image currently loaded into the process.
 *
 * @filename the executable/library path (c.f. dyld(3) on Darwin)
 * @names an array of symbol names to search for
 * @nlist an array of substitute_sym *, one per name; on return, each entry
 * will be a pointer into the symbol table for that image, or NULL if the
 * symbol wasn't found
 * @count number of names
 *
 * @return SUBSTITUTE_OK or SUBSTITUTE_ERR_MODULE_NOT_FOUND
 */
int substitute_find_syms(const char *filename, const char **names,
                         substitute_sym **syms, size_t count);

#endif /* 1 */
