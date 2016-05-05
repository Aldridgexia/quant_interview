// Q6. What is the general form for a function signature?
// A:
return_type function_name(parameter_list);
// Example:
int my_sum(int a, int b);

// Q7. How do you pass-by-reference?
// A:
return_type function_name(T& identifier);
// The identifier is now an alias for the argument.

// Q8. How do you pass a read only argument by reference?
// A:
return_type function_name(const T& identifier);
// Once you define a parameter as const, you will not be able to modify it in the function.

// Q9. What are the important differences between using a pointer and a reference?
// A:
// 1. A pointer can be re-assigned any number of times, while a reference cannot be reassigned after initialization.
// 2. A pointer can point to NULL (nullptr in C++11), while a reference can never be referred to NULL.
// 3. It is not possible to take the address of a reference as it is done with pointers.
// 4. There is no reference arithmetic.

// Q10. How do you set a default value for a parameter?
// A:
return_type function_name(T identifier = rvalue);
// The parameter with default value must be placed at the end of the parameter list.
