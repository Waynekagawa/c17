#include <iostream>
#include <string>
// Include header file to enable use of std::function 
#include <functional> 

class Derivative{
	public:
	virtual double differentiate(
    std::function<double(double)> func, double x) = 0;//Pure VIrtual Function
	
	double h;//attribute.
	
	Derivative():h(1e-8){}; //Default Constructor.
	
	Derivative(double x):h(x){
		std::cout<<"Enter value of h"<<std::endl;
		std::cin>>x;
		
	//~Derivative():h(0){}; //Destructor.
	}
};

class CentralDifference: public Derivative
{public:
    using Derivative::Derivative;//inheriting Derivative constructor from base class.
    virtual double differentiate(std::function<double(double)> func, double x){
		double f = 0;
		f += (func(x+h) - func(x-h)) / (2*h);		
		return f;
	};
};

class ForwardDifference: public Derivative
{public:
    using Derivative::Derivative;//inheriting Derivative constructor from base class.
	virtual double differentiate(std::function<double(double)> func, double x){
		//(func(x+h) - func(x)) / h;		
		return (func(x+h) - func(x)) / h;		
	}
};

// Define function to integrate 
const double myfunc1(const double x) { return x*2; };

// Define function to integrate as lambda expression 
auto myfunc2 = [](double x) { return 3*x; };

int main(){
	//Using CentralDifference.
	//Derivative r(1e-2);
	CentralDifference CD(1e-2);
	std::cout<<"Central Difference Derivative:  "<< CD.differentiate(myfunc1,1)<<std::endl;
	std::cout<<"Central Difference Derivative:  "<< CD.differentiate(myfunc2,1)<<std::endl;
	
	ForwardDifference FD;
	std::cout<<"Forward Difference Derivative:  "<< FD.differentiate(myfunc1,1)<<std::endl;
	std::cout<<"Forward Difference Derivative:  "<< FD.differentiate(myfunc2,1)<<std::endl;
	return 0;
}
