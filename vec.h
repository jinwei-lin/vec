#ifndef VEC_H
#define VEC_H

#include <stdlib.h>

typedef void (*dtor_t)(void*);

struct vec {
	size_t cap,
	       cnt;
	void **elms;
	dtor_t dtor;
};

extern const size_t VEC_INIT_CAP;

void vec_init(struct vec *vec, dtor_t dtor);

#endif
