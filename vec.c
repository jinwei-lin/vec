#include "vec.h"

const size_t VEC_INIT_CAP = 10;

void vec_init(struct vec *vec, dtor_t dtor) {
	vec->elms = malloc(sizeof(void*)*VEC_INIT_CAP);
	vec->cap = VEC_INIT_CAP;
	vec->cnt = 0;
	vec->dtor = dtor;
}
