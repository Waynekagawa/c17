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
{
	if (typeid(a)==int){
	return true;}
	else
	{return false;}
}
int main()
{
    PRINT_EXPRESSION(add_simple(1, 2));
    PRINT_EXPRESSION(add_simple(1.5, 2.2));
    PRINT_EXPRESSION(add(1, 2));
    return 0;
}