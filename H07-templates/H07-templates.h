#include <iostream>
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
T value;//attribute.

//constructor and destructor.
Number():value(){}//default
Number(T a):value(a){}
//~Number():value(0){}

//Operators
template<typename U>
Number<T> &operator+(const Number<U> &other){
  value+=other.value;
return *this;}
};
int main()
{
    PRINT_EXPRESSION(add_simple(1, 2));
    PRINT_EXPRESSION(add_simple(1.5, 2.2));
    PRINT_EXPRESSION(add(1, 2));
    PRINT_EXPRESSION(is_int("Goookaaa"));
	PRINT_EXPRESSION();
    return 0;
}
