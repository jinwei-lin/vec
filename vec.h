#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
#include <stdio.h>

typedef void (*dtor_t)(void*);

struct vec {
	size_t cap,
	       cnt;
	void **elms;
	dtor_t dtor;
};

extern const size_t VEC_INIT_CAP;

void vec_init(struct vec *vec, dtor_t dtor);
int vec_set_cap(struct vec *vec, size_t cap);

#endif
