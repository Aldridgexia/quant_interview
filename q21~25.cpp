// Q21. What is encapsulation?
// A:
// Encapsulation is the ability to expose an interface while hiding implementation.
// This is usually achieved through access modifiers(public, private, protected, etc.).

// Q22. What is a polymorphism?
// A:
// Polymorphism is the ability for a set of classes to all be referenced through a common interface.

// Q23. What is inheritance?
// A:
// Inheritance is the ability for one class to extend another through sub-classing.
// This is also referred to as "white-box" (the opposite of "black-box") re-use. A library can provide
// base classes that may be extended by the application developer.

// Q24. What is a virtual function? What is a pure virtual function and when do you use it?
// A:
// Virtual functions are functions that are resolved by the compiler, at runtime, to the most derived 
// version with the same signature. This means that if a function that was defined using a base class Foo,
// with a virtual member function f, is called using an instance of a sub class FooChild, that function is going to be dynamically
// binded to the implementation of the sub class(regardless that the actual code only refers to the base class).
// A pure virtual function is a virtual function with no implementation in the base class, making the base class abstract(and thus can't be instantiated).
// Derived classes are forced to override the pure virtual function if they want to be instantiated.
// You use the same syntax as the virtual function but add =0 to its declaration within the class.

// Q25. Why are virtual functions used for destructors? Can they be used for constructors?
// A:
// Destructors are recommended to be defined as virtual, so the proper destructor (in the class hierarchy) is called at running time.
// When calling a constructor. the caller needs to know the exact type of the object to be created, and thus they cannot be virtual.
