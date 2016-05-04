// Q1. How do you declare an array?
// A: An array can be declared either on stack, or on heap.

// created on stack, uninitialized
T identifier[size];

// created on stack, initialized
T identifier[] = initializer_list;

// created on heap, uninitialized
T* identifier = new T[size];

// Example:
int foo[3];
int bar[] = {1,2,3};
int* baz = new int[3];

// Q2. How do you get the address of a variable?
// A: Use the ampersand before the name of the variable, e.g.

T var;
T* ptr = &var;

// Example
int foo = 1;
int* foo_ptr = &foo;

// Q3. How do you declare an array of pointers?
// A: The same way as declaring an array, but making the type, T, a pointer:
T* identifier[size];
T* identifier[] = initializer_list;
T** identifier = new T*[size];

// Example:
int a = 1, b = 2, c = 3;
int* foo[3];
int* bar[] = {&a, &b, &c};
int** baz = new int*[3];

// Q4. How do you declare a const pointer, a pointer to a const and a const pointer to a const?
// A: 
// pointer to a read only variable
const T* identifier;
T const* identifier;

// read only pointer to a variable
T *const identifier = rvalue;

// read only pointer to a read only variable
const T *const identifier = rvalue;
T const *const identifier = rvalue;

// Example:
const int a = 2, b = 2;
int c = 1;

// pointer to a read only b
int const* foo_two;
foo_two = &a; foo_two = &b;

// pointer to a read only a
const int* foo;
foo = &a; foo = &b;

// read only pointer to c
// it needs to be initialized
int *const bar = &c;

// read only pointer to read only a
// it needs to be initialized
const int *const baz = &a;

// Q5. How do you declare a dynamic array?
// A: 
T* identifier = new T[size];
T* identifier = nullptr;
T* identifier;

delete[] identifier;

// Example:
int *foo = new int[4];
int *bar = nullptr;
bar = new int[4];
