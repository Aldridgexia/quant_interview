// Q16. C++ constructors support the initialization of member data via an initializer list.
// When is this preferable to initialization inside the body of the constructor?
// A:
// The initialization list has to be used for const members, references and with members without default
// constructors, but for any type of members initialization through the initialization list is still preferable,
// since it is for efficient. Using the initialization list, the memers are initialized calling directly their constructors.
// If the initialization is done in the body of the constructor for each member being initialized there is an instance of it created
// and then a copy assignment operation is called to assign that instance to its respective member.

// Q17. What is a copy constructor, and how can the default copy constructor cause problems when you have pointer data members?
// A:
// A copy constructor allows you to create a new object as a copy of an existing instance.
// The default copy constructor creates the new object by copying the existing object, member by member, and thus when there are 
// member pointer you end up with two bojects pointing to the same object.
// It is important to note that the copy constructor is called every time a function receives an object via the pass-by-value mechanism.
// This means that the copy constructor needs to be implemented using a pass by reference. Otherwise you will be recursively calling the copy constructor.
// You should always set the parameter for a copy constructor to be const.

ClassName(const ClassName& other);
ClassName(ClassName& other);
ClassName(volatile const ClassName& other);
ClassName(volatile ClassName& other);

// Q18. What is the output of the following code:
#include <iostream>
using namespace std;

class A
{
public:
	int * ptr;
	~A()
	{
		delete(ptr);
	}
};

void foo(A object_input)
{
	;
}

int main() {
	A aa;
	aa.ptr = new int(2);
	foo(aa);
	cout<<(*aa.ptr)<<endl;
	return 0;
}

// A:
// The output of the code is an uncertain number, depending on the compiler used;
// for some compilers it could generate an error. The reason for this is that we do not define 
// our own copy constructor.
// When we call the foo function, the compiler will generate a default copy constructor which will shallow copy every data
// members defined in class A. This will lead to the result that two pointers, one in temporary object and the other in the object aa,
// will point to the same area in memory. When we get out the foo function, the compiler will automatically call the destructor function of the temporary
// object in which the pointer will be deleting and the area it points to will be free.
// In this situation, the pointer in aa will still point to the same area which has been free. When we try to visit the data through the pointer in aa,
// we will get garbage information.

// Q19. How do you overload an operator?
// A:
type operator symbol (parameter_list);
// If you define the operator outside of the class, then it will be a global operator function.
// Example:
struct FooClass{int a;};
int operator + (FooClass lhs, FooClass rhs) {
	return lhs.a +rhs.a;
}

// Q20. What are smart pointers?
// A:
// A smart pointer is a class built to mimic a pointer (offering dereferencing, indirection, arithmetic) that also ofers extra features to simplify the usage, sharing and 
// management of resources.
// C++ 11 comes with three implementations of smart pointers: shared_ptr, unique_ptr, and weak_ptr.
// Example:

// shared_pointer maintains a reference count
// when the count is zero the object pointed to is destroyed
std::shared_ptr<int> foo(new int(3));
str::shared_ptr<int> bar = foo;

// memory not released, bar is still in scope
foo.reset();

// releases the memory, since no one is using it
bar.reset();