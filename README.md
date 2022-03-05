# Vector

## Data Structures

### Element destructor

Destructor for an element in a vector should be declared in accordance with the following function prototype.

```
typedef void (*dtor_t)(void*);
```

### Vector

```
struct vec {
        size_t cap,
               cnt;
        void **elms;
        dtor_t dtor;
};
```

- `cap`: capacity of the vector
- `cnt`: number of elements in the vector
- `elms`: array of pointers to the elements
- `dtor`: destructor for an element

## Functions

```
void vec_init(struct vec *vec, dtor_t dtor);
```

Initialize a vector.

Initial capacity `VCTR_INIT_CAP` of a vector can be modified in source file *vec.c*.

```
int vec_set_cap(struct vec *vec, size_t cap);
```

Set the capacity of a vector.

If argument `cap` is smaller than the number of elements in the vector, no operation is performed, and -1 is returned.

```
void vec_psh_bk(struct vec *vec, void *elm);
```

Add an element at the end of a vector.

Memory space of the element to be added should be dynamically allocated.

If the vector is full, it is automatically expanded. Expand factor `VCTR_EXPN_FAC` can be modified in source file *vec.c*.

```
void vec_fnl(struct vec *vec);
```

Thoroughly clear a vector, including all its elements.
