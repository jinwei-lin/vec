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

Initial capacity `VCTR_INIT_CAP` of a vector can be modified in source file *vctr.c*.

```
int vec_set_cap(struct vec *vec, size_t cap);
```

Set the capacity of a vector.

If argument `cap` is smaller than the number of elements in the vector, no operation is performed, and -1 is returned.
