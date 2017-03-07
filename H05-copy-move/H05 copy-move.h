// Support for precompiled header files (only under MS Visual Studio)
#ifdef _MSC_VER
#include "stdafx.h"
#endif

// Include header file for standard input/output stream library
#include <iostream>

// Include header file for initializer list
#include <initializer_list>

// Include header file for memory
#include <memory>

class Container{
private:
int length;
double *data;

public:
Container():length(0),data(nullptr){}; //Default constructor.

Container(int len):length(len), data(new double [length]){};//Parameterized constructor with explicit initialisation.

Container(std::initializer_list<double> list): Container((int) list.size())//Requirement 3.
{
std::uninitialized_copy(list.begin(), list.end(), data);
};

~Container() //Destructor.
    {
        delete[] data;
        length = 0;
    }
//Copy Constructor.
Container (const Container &b):Container(b.length){
for(auto i=0;i<b.length;i++)
    this->data[i] = b.data[i];
	};

//Move Constructor.
Container(Container&& b):Container(b.length){
for (auto i=0; i<b.length;i++)
    this->data[i] = b.data[i];

b.data = nullptr;//deallocate array type object.
b.length = 0;//set length to zero. could have used delete b.length as well.
}

//Copy Assignment Operator.
Container& operator=(const Container& other)
    {
        if (this != &other)
            {
                delete[] data;
                length = other.length;
                data   = new double(other.length);
                for (auto i=0; i<other.length; i++)
                    data[i] = other.data[i];
            }
        std::clog << "Copy assignment operator" << std::endl;
        return *this;
    }

//Move Assignment Operator.
Container& operator=(Container&& other)
    {
        if (this != &other)
            {
                delete[] data;
                length = other.length;
                data   = other.data;
                other.length = 0;
                other.data   = nullptr;
            }
        std::clog << "Move assignment operator" << std::endl;
        return *this;
    }


// Container that has the Sum of the input container with the container calling it. 
Container operator+(const Container &other) const{
Container d(other.length);
//d.length = other.length;
//d.data = other.data;
if (this->length == other.length)
    {
	//d.length = other.length;
	for (int i=0;i<other.length;i++)
	d.data[i] = this->data[i] + other.data[i];
	}
//print("This assignment operator adds two objects of the type Container and results in a new container.\n");
return d;
}
 void print()
    {
        std::cout << "Container: ";
        for (auto i=0; i<length; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    
    // Print container info
    void info()
    {
        std::cout << "Length of data pointer:  " << length << std::endl;
        std::cout << "Address of data pointer: " << &data << std::endl;
        std::cout << "Data pointer:            " << data << std::endl;
    }
};
	
int main()
{
    std::cout << "Container a({ 1, 2, 3 });" << std::endl;
    Container a({ 1, 2, 3 });//A container a is constructed by explicit intialization. 
    std::cout << "  a has address " << &a << std::endl;
    std::cout << "Container b = { 4, 5, 6 };" << std::endl;
    Container b = { 4, 5, 6 };//A container b is constructed by copy initialization. 
    std::cout << "  b has address " << &b << std::endl;
    std::cout << "Container c(a);" << std::endl;
    Container c(a);
    std::cout << "  c has address " << &c << std::endl;
    std::cout << "Container d = a + b;" << std::endl;
    Container d = a + b;
    std::cout << "  d has address " << &d << std::endl;
    //std::cout << "Container d;" << d << std::endl;
    std::cout << "Container e;" << std::endl;\
    Container e;
    std::cout << "  e has address " << &e << std::endl;
    std::cout << "e = a + b;" << std::endl;
    e = a + b;
    std::cout << "Container f(std::move(a + b));" << std::endl;
    Container f(std::move(a + b));
    std::cout << "  f has address " << &f << std::endl;
    std::cout << "Container g = a + b + c;" << std::endl;
    Container g = a + b + c;
    std::cout << "  g has address " << &g << std::endl;
    std::cout << "Container h;" << std::endl;
    Container h;
    std::cout << "  h has address " << &h << std::endl;
    std::cout << "h = a + b + c;" << std::endl;
    h = a + b + c;
    std::cout << "Container i = { a + b + c };" << std::endl;
    Container i = { a + b + c };
    std::cout << "  i has address " << &i << std::endl;
    std::cout << "end" << std::endl;

    return 0;
}


