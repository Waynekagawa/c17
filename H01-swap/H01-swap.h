 /** Example program
#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
*/
/**
 * \file swap.cxx
 *
 * This file is part of the course wi4771tu:
 * Object Oriented Scientific Programming with C++
 *
 */

// Include header file for standard input/output stream library
#include <iostream>
int swap_byvalue(int a, int b){
        int c = a;//  value of first input variable is stored in another variable.
        a = b; // value of second variable is appointed to the first variable. 
        b = c; // the stored value is then recalled to be the value of the second variable.
        std::cout << "The first output after swapping by value is "<< a <<std::endl;
        std::cout<< "The second output after swapping by value  is "<< b <<std::endl;
        return 0;
    }
int swap_byreference(int& d, int &e){
    int f = d; //the value of the first input is referred to and then stored in variable f. 
    d = e;
    e = f;
    std::cout << "The first output after swapping by reference is "<< d <<std::endl;
    std::cout<< "The second output after swapping by reference  is "<< e <<std::endl;
        return 0;
    }
    
int swap_byaddress(int *p1, int *p2){
    //int *p1 = &h; //The pointer p1 is given the address of the first input by using the reference to find it.
    //int *p2 = &j;
    int g = *p1; // Done as in swap_by value.
    *p1 = *p2;
    *p2 = g;
    std::cout << "The first output after swapping by address is "<< *p1 <<std::endl;
    std::cout<< "The second output after swapping by address  is "<< *p2 <<std::endl;
    std::cout << p1 <<std::endl;
    std::cout << *p1 <<std::endl;
    /** The reference is just like a copy but not a physical copy that takes up memory. 
     * It is like the shadow of an object and you can call the object by calling the shadow.
     */
    return 0;
}
// The global main function that is the designated start of the program
int main(){

    // Read two integer values
    int i1; std::cin >> i1;
    int i2; std::cin >> i2;
    std::cout << "The first input value is "<< i1<<std::endl;
    std::cout << "The second input value is "<< i2<<std::endl;
    std::cout << &i1 <<std::endl;
    std::cout << &i2 <<std::endl;
    
    // Return code 0 to the operating system (=no error)
    swap_byvalue(i1,i2);
    swap_byreference(i1,i2);
    swap_byaddress(&i1,&i2);
    return 0;
}


 
