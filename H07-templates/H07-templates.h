
#include <iostream>
#include <typeinfo>
#define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
    << " (type: " << typeid(expr).name() << ")" << std::endl

template<typename A>
auto add_simple(A a, A b)->decltype(a+b)
{
	return a+b;
}

template<typename T1, typename T2>
auto add(T1 a, T2 b)->decltype(a+b)
{
	return a+b;
}

template<typename T1>
bool is_int(T1 a)
{ int b = 1;
return (typeid(a).name()==typeid(b).name()); //We can directly write this instead of and if-else condition.
}

template<typename T>
class Number{
public:
 const T value;//attribute.

//constructor and destructor.
Number():value(0){}//default
Number(T a):value(a){}

//Operators
template<typename U>
Number<T>& operator+(const Number<U> &other) //adds two number objects and returns a new number object.
{Number a;
a.value = value+other.value;
    return a;}

template<typename U>
Number<T>& operator-(const Number<U> &other) //subtracts two number objects and returns a new number object.
{Number a;
a.value = value - other.value;
    return a;}

template<typename U>
Number<T>& operator*(const Number<U> &other) //multiplies two number objects and returns a new number object.
{Number a;
a.value = value * other.value;
    return a;}
    
template<typename U>
Number<T>& operator/(const Number<U> &other) //divides two number objects and returns a new number object.
{Number a;
a.value = value / other.value;
    return a;}

};

template<int n>
struct Fibonacci{
	static const int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value; //general template for nth Fibonacci number.
};
template<>
struct Fibonacci<1>
{    static const int value = 1;};//Defines the first Fibonacci number.

template<>
struct Fibonacci<2>
{    static const int value = 1;};//Defines the second Fibonacci number. 



int main()
{
    PRINT_EXPRESSION(add_simple(1, 2));//check for add_simple.
    PRINT_EXPRESSION(add_simple(1.5, 2.2));
    PRINT_EXPRESSION(add(1, 2));//check for add.
    PRINT_EXPRESSION(is_int("Goookaaa"));//check for function is_int, 
    PRINT_EXPRESSION(Number<int>(2).value + Number<double>(1.2).value);	//checks for additon, subtraction, multiplication and division of two numbers.
    PRINT_EXPRESSION(Number<int>(2).value - Number<double>(1.2).value);
    PRINT_EXPRESSION(Number<int>(2).value * Number<double>(1.2).value);
    PRINT_EXPRESSION(Number<int>(2).value / Number<double>(1.2).value);
    PRINT_EXPRESSION(Fibonacci<5>::value);//checks for Fibonacci sequence.
    return 0;
}
