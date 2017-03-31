#include <iostream>
#include <typeinfo>
#include <cmath>

template<int value> 
struct ConstInt{
	static const double eval(double x){
	    return (int)value;	
	};	
	typedef ConstInt<0> derivative; //defines return type as a ConstInt = 0 which itself is a struct, therefore derivative is a struct.
};

template<typename A, typename B>
struct Add{
    static const double eval(double x){
    return A::eval(x) + B::eval(x);
    };
	typedef Add<typename A::derivative, typename B::derivative> derivative;
};

template<typename A, typename B>
struct Mul{
    static const double eval(double x){
    return A::eval(x)*B::eval(x);
    };
	typedef Add<Mul<typename A::derivative,B> , Mul<A,typename B::derivative>> derivative;
};

template<int exponent> 
struct Monomial{
	static const double eval(double x){
		return x*Monomial<exponent-1>::eval(x);		
	};
	typedef Mul<ConstInt<exponent>,Monomial<exponent-1>> derivative;
	
};

template<>
struct Monomial<0>{
    static const double eval(double x){
        return 1;
    };
    typedef ConstInt<0> derivative;
    
};

template<typename A>
struct Neg{
	static const double eval(double x){
		return -1*A::eval(x);
	};
    typedef typename A::derivative derivative;
};

template<double angle_D>
class Cos;
template<double angle_D>
class Sin{
	double angle = angle_D*M_PI/180;
	static const double eval(double angle){
		return sin(angle)
	};
	typedef Cos<angle_D> derivative;
};

class Cos{
	double angle = angle_D*M_PI/180;
	static const double eval(double angle){
		return cos(angle)
	};
	typedef Neg<Sin<angle_D>> derivative;
};

int main(){
    typedef ConstInt<2> a; //define a constant integer a = 2.
    typedef Monomial<3> b; // define a monomial = x^3.
    typedef Neg<b> c;
std::cout<<a::eval(1)<<std::endl; // evaluate `a` at `1`, should give 1.
std::cout<<a::derivative::eval(1)<<std::endl;// should diffrentiate the constant and evaluate it again, giving zero. 
std::cout<< Mul<a,b>::eval(2) <<std::endl;// should multiply a and b and evaluate it to give 16. (2*2^3).
std::cout<< Mul<a,b>::derivative::eval(2) <<std::endl;//should diffrentiate a*b and result in (2*3*x^2).
std::cout<< Mul<b,c>::eval(2)<< std::endl;
    return 0;
}