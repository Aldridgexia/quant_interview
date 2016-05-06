// Q11. How do you create a template function?
// A:
template <class T>
return_type function_name(parameter_list);

template <typename T>
return_type function_name(parameter_list);
// Note that the parameter type can be specified,
// when calling the function, explicitly or implicitly. 
// Also note that there is no technical difference
 // between using class or typename besides code readability
// (typename for primitive types and class for classes).

// Example:
template <typename T>
T tem_sum(T a, T b) {return a+b;}

struct Processor{
	int a;
	int apply(int b) {return a+b;}
};

template <class T>
int temp_sum_2(int a, int b) {
	T processor,
	processor.a = a;
	return processor.apply(b);
}

int main() {
	// implicit, foo equals 3
	int foo = tem_sum(1,2);

	// explicit, bar equals 3
	int bar = temp_sum_2<Processor>(1,2);
}

// Q12. How do you declare a pointer to a function?
// A:
return_type (*identifier) (list_parameter_types)

// Example:
int my_sum(int a, int b) {return a+b;}
int main() {
	int(*p_func)(int, int);
	p_func = &my_sum;

	// foo euqals 3
	int foo = p_func(1,2);
}

// Q13. How do you prevent the compiler from doing an implicit conversion with your class?
// A:
// Use the keyword explicit to define the constructor:
explicit Classname(parameter_list)

// Q14. Describe all the uses of the keyword static in C++.
// A:
// Inside a function, using the keyword static means that once the variable has been initialized it remains in memory up until the end of the progra.
// Inside a class definition, either for a variable or for a member function, using the keyword static
// means that there is only one copy of them per class, and shared between instance.
// As a global variable in al file of code, using the keyword static means that the variable is private within the scope of the file.

// Q15. Can a static member function be const?
// A:
// When the const qualifier is applied to a non-static member function it implies that
// member function can not change the instance class when called(i.e. can not change any non mutable members from *this)
// Since static member function are defined at a class level, where there is no notion of this the const qualifier for member functions does not apply.
