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
      //don't need to define a third point as we can store the result in the object calling the operator.
       this->x = this->x + other.x;//runs without this-> as well. Need to know why.
       this->y = this->y + other.y;
       return *this;} 
	   //Instead of defining c, just start with replacing this->x and this->y because I have removed the const in there to facilitate the change in variable b. Return this* instead as this is a pointer.
Point operator-=(const Point& other) {
      //don't need to define a third point as we can store the result in the object calling the operator.
       this->x = this->x - other.x;//runs without this-> as well. Need to know why.
       this->y = this->y - other.y;
       return *this;}    
    
    // methods
double distance(){double d=0;d = sqrt(pow (this->x,2) + pow(this->y,2));return d;}
double distance(Point other){double d=0;d = sqrt(pow (this->x - other.x,2) + pow(this->y - other.y,2));return d;}
Point rotated(double angle_D){ //angle in degrees.
 double angle = angle_D*M_PI/180;
 Point d;
 d.x += this->x*cos(angle) - this->y*sin(angle);
 d.y += this->x*sin(angle) + this->y*cos(angle);
 return d;}
 
Point rotated(double angle_D,Point other){ //angle in degrees.
 double angle = angle_D*M_PI/180;
 Point d;
 d.x += this->x*cos(angle) - this->y*sin(angle) - other.x;
 d.y += this->x*sin(angle) + this->y*cos(angle) - other.y ;
 return d;} 
Point &rotate(double angle_D){ //angle in degrees.
 double angle = angle_D*M_PI/180;
 Point d = {d.x=x,d.y=y};//a point d was created as a copy of the original point and then the original was overriden using this copy.
 this->x = d.x*cos(angle) - d.y*sin(angle);
 this->y = d.x*sin(angle) + d.y*cos(angle);
 return *this;}    
 double x;double y;
    
};

class Triangle
{
public:
    // constructors
    Triangle(){a.x=0;a.y=0;b.x=0;b.y=0;c.x=0;c.y=0;};//default
    Triangle(Point d, Point e, Point f){
        Point d
        : x=a.x, y=a.y
        Point e
        : x=b.x, y=b.y
        Point f
        : x=c.x, y=c.y
        };//constructor I think is bullshit. 
    // operators
    Triangle translated(Point t){
        Triangle( a,  b, c);//we've already specified what the input will be in the constructor so no need to write 'Point' before a. 
       /** a.x +=t.x;
        a.y +=t.y;
        b.x +=t.x;
        b.y +=t.y;
        c.x +=t.x;
        c.y +=t.y;
        */
        a=a+t;
        b=b+t;
        c=c+t;
        return Triangle( a,  b, c);}
    // methods

    Point a, b, c;
};


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

// ostream operator for `Triangle`s
std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    return os << "Triangle< " << t.a << ", " << t.b << ", " << t.c <<  " >";
}

#include <iostream>
using namespace std;

int main()
{
    // example, replace with your tests

    Point p;
    Point a = {1, 1};
    Point b = {3, 4};
    Point c;// = {3, 4};
    Point d;
    b += a;    // result: b.x = 4, b.y = 6
    c = b + a; // result: c.x = 5, c.y = 8
    //d = b - a;
    Triangle t;

    // set point `p` to (1, 2)
    p.x = 2;
    p.y = 2;

    // set triangle `t` to (1, 2), (3, 4), (5, 6)
    t.a.x = 1;
    t.a.y = 2;
    t.b.x = 3;
    t.b.y = 4;
    t.c.x = 5;
    t.c.y = 6;

    // print point `p` and triangle `t`
    std::cout<<p<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<a.distance()<<std::endl;
    std::cout<<a.distance(p)<<std::endl;
    std::cout<<p.rotated(90)<<std::endl;
    std::cout<<p.rotated(90,a)<<std::endl;//incorrect
    
    std::cout << t << std::endl;
    std::cout << t.translated(a) << std::endl;
}





