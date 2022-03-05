#include "vec.h"

const size_t VEC_INIT_CAP = 10;

void vec_init(struct vec *vec, dtor_t dtor) {
	vec->elms = malloc(sizeof(void*)*VEC_INIT_CAP);
	vec->cap = VEC_INIT_CAP;
	vec->cnt = 0;
	vec->dtor = dtor;
}

int vec_set_cap(struct vec *vec, size_t cap) {
	if(cap < vec->cnt) {
		fprintf(stderr, "Failed to set vector capacity to %lu, which is smaller than the element count [%lu].\n", cap, vec->cnt);
		return -1;
	}
	vec->elms = realloc(vec->elms, sizeof(void*)*cap);
	vec->cap = cap;
	return 0;
}
