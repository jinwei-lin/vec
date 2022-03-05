#include "vec.h"

const size_t VEC_INIT_CAP = 10,
             VEC_EXPN_FAC = 2;

void vec_init(struct vec *vec, dtor_t dtor) {
	vec->elms = malloc(sizeof(void*)*VEC_INIT_CAP);
	vec->cap = VEC_INIT_CAP;
	vec->cnt = 0;
	vec->dtor = dtor;
}

int vec_set_cap(struct vec *vec, size_t cap) {
	if(cap < vec->cnt) {
		fprintf(stderr, "Failed to set vector capacity to %lu, which is smaller than element count [%lu].\n", cap, vec->cnt);
		return -1;
	}
	vec->elms = realloc(vec->elms, sizeof(void*)*cap);
	vec->cap = cap;
	return 0;
}

void vec_psh_bk(struct vec *vec, void *elm) {
	size_t cnt = vec->cnt;

	if(cnt == vec->cap)
		vec_set_cap(vec, (vec->cap)*VEC_EXPN_FAC);
	vec->elms[cnt] = elm;
	vec->cnt = cnt + 1;
}

void vec_fnl(struct vec *vec) {
	int i;
	size_t cnt = vec->cnt;
	void **elms = vec->elms;
	dtor_t dtor = vec->dtor;

	for(i = 0; i < cnt; ++i)
		dtor(elms[i]);
	free(elms);
	memset(vec, 0, sizeof(struct vec));
}
