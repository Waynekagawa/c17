/*

    Comment on `const` and `&` here.  See ../README.md.

 */

#include <cmath>
#include <ostream>
#include <iomanip>

class Point
{
public:
   Point(){x = 0; y= 0;}//the default constructor
   Point(double a, double b){x=a;y=b;}//Declaring a constructor of doubles and initialising it to take the values of x and y
    // operators
   Point operator+(const Point& other) const{
      Point c;//defining a third point which is the result of the addition of the other two.
       c.x += this->x + other.x;//runs without this-> as well. Need to know why.
       c.y += this->y + other.y;
       return c;}
       
 Point operator-(const Point& other) const{
      Point c;//defining a third point which is the result of the addition of the other two.
       c.x += this->x - other.x;//runs without this-> as well. Need to know why.
       c.y += this->y - other.y;
       return c;} 
Point operator+=(const Point& other) {
       Point c;//defining a third point which is the result of the addition of the other two.
       this->x = this->x + other.x;//runs without this-> as well. Need to know why.
       this->y = this->y + other.y;
       return c;} 
	   //Instead of defining c, just start with replacing this->x and this->y because I have removed the const in there to facilitate the change in variable b. Return this* instead as this is a pointer.
    // methods
    
 double x;double y;
    
};
/**
class Triangle
{
public:
    // constructors
    // operators
    // methods

    Point a, b, c;
};
*/

// ostream operator for `Point`s
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    // remember current flags, precision
    auto flags = os.flags();
    auto current_precision = os.precision();
    // output numers with fixed point and three decimal precision
    os.setf(std::ios::fixed, std::ios::floatfield);
    os.precision(3);
    // output point `p`
    os << "(" << std::setw(6) << std::setfill(' ') << p.x
        << "," << std::setw(6) << std::setfill(' ') << p.y << ")";
    // restore current flags, precision
    os.flags(flags);
    os.precision(current_precision);
    return os;
}
/**
// ostream operator for `Triangle`s
std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    return os << "Triangle< " << t.a << ", " << t.b << ", " << t.c <<  " >";
}
*/
#include <iostream>
using namespace std;

int main()
{
    // example, replace with your tests

    Point p;
    Point a = {1, 2};
    Point b = {3, 4};
    Point c;// = {3, 4};
    Point d;
    b += a;    // result: b.x = 4, b.y = 6
    //c = b + a; // result: c.x = 4, c.y = 6
    //d = b - a;
    //Triangle t;

    // set point `p` to (1, 2)
    p.x = 211;
    p.y = 2;
/**
    // set triangle `t` to (1, 2), (3, 4), (5, 6)
    t.a.x = 1;
    t.a.y = 2;
    t.b.x = 3;
    t.b.y = 4;
    t.c.x = 5;
    t.c.y = 6;
*/
    // print point `p` and triangle `t`
    std::cout<<p<<std::endl;
    //std::cout<<c<<std::endl;
    std::cout<<b<<std::endl;
 //   cout << t << endl;
}

