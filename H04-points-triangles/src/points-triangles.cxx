/*

    Comment on `const` and `&` here.  See ../README.md.

 */

#include <cmath>
#include <ostream>
#include <iomanip>



class Point
{
public:
//the default constructor
   Point(){x = 0; y= 0;}

//Declaring a constructor of doubles and initialising it to take the values of x and y
   Point(double a, double b){x=a;y=b;}

    // operators

   Point operator+(const Point& other) const{
      Point c;//defining a third point which is the result of the addition of the other two.
       c.x += this->x + other.x;//Calling the x coordinate of the point to which another point is being added using the this-> pointer.
       c.y += this->y + other.y;
       return c;}
       
 Point operator-(const Point& other) const{
      Point c;//defining a third point which is the result of the subtraction of the other two.
       c.x += this->x - other.x;
       c.y += this->y - other.y;
       return c;} 

 Point operator+=(const Point& other) {
      //don't need to define a third point as we can store the result in the object (Point) calling the operator.
       this->x = this->x + other.x;
       this->y = this->y + other.y;
       return *this;} 
	   
Point operator-=(const Point& other) {
      
       this->x = this->x - other.x;
       this->y = this->y - other.y;
       return *this;}    
    
    // methods
double distance(){
 double d=0;
 d = sqrt(pow (this->x,2) + pow(this->y,2));
 return d;} //gives distance wrt origin 0,0.

double distance(const Point &other){
 double d=0;
 d = sqrt(pow (this->x - other.x,2) + pow(this->y - other.y,2));
 return d;}//gives distance wrt another point.

Point rotated(double angle_D){ 
 //angle entered in degrees.
 double angle = angle_D*M_PI/180;// converted to radians.
 Point d;// creation of dummy point
 d.x += this->x*cos(angle) - this->y*sin(angle);
 d.y += this->x*sin(angle) + this->y*cos(angle);
 return d;}
 
Point rotated(double angle_D,Point other){ //angle entered in degrees.
 double angle = angle_D*M_PI/180;//converted to radians.
 Point d;
 d.x = (this->x- other.x)*cos(angle) - (this->y-other.y)*sin(angle) ;
 d.y = (this->x- other.x)*sin(angle) + (this->y-other.y)*cos(angle) ;
 return d;}  

Point &rotate(double angle_D){ //angle entered in degrees.
 double angle = angle_D*M_PI/180;//converted to radians.
 Point d = {d.x=x,d.y=y};//a point d is created as a copy of the original point and then the original will be overriden using this copy.
 this->x = d.x*cos(angle) - d.y*sin(angle);
 this->y = d.x*sin(angle) + d.y*cos(angle);
 return *this;} 

Point &rotate(double angle_D, const Point &other){ //angle entered in degrees.
 double angle = angle_D*M_PI/180;//converted to radians.
 Point d = {d.x=x,d.y=y};
 this->x = (d.x - other.x)*cos(angle) - (d.y - other.y)*sin(angle);
 this->y = (d.x - other.x)*sin(angle) + (d.y - other.y)*cos(angle);
 return *this;} 
   
 double x;double y;
    
};

class Triangle
{//Angle is entered in degree everywhere and converted within the function.
public:
    // constructors
//default constructor
 Triangle(){a.x=0.0;a.y=0.0;b.x=0.0;b.y=1.0;c.x=1.0;c.y=1.0;};
//General constructor. When we call the triangle, a takes the value of the first co-ordi and so on.       
 Triangle(Point d, Point e, Point f){
        a=d;b=e;c=f;};
  
  // operators
 Triangle translated(const Point &t){
        Triangle r={a,b,c};//dummy triangle created.
        r.a=r.a+t;//first point accessed here and translated and so on.
        r.b=r.b+t;
        r.c=r.c+t;
        return (r);}

 Triangle &translate(const Point &t){
//No need to create a new triangle as we are altering the original.
        a=a+t;
        b=b+t;
        c=c+t;
        return *this;}

Triangle rotated(double angle_D){
  double angle = angle_D*M_PI/180;
        Triangle r={a,b,c};//dummy triangle created.
        r.a.x=this->a.x*cos(angle) - this->a.y*sin(angle);
        r.a.y=this->a.x*sin(angle) + this->a.y*cos(angle);
        r.b.x=this->b.x*cos(angle) - this->b.y*sin(angle);
        r.b.y=this->b.x*sin(angle) + this->b.y*cos(angle);
        r.c.x=this->c.x*cos(angle) - this->c.y*sin(angle);
        r.c.y=this->c.x*sin(angle) + this->c.y*cos(angle);
        return (r);}

Triangle rotated(double angle_D, const Point &other){
  double angle = angle_D*M_PI/180;
        Triangle r={a,b,c};
        r.a.x=(this->a.x - other.x)*cos(angle) - (this->a.y - other.y)*sin(angle);
        r.a.y=(this->a.x - other.x)*sin(angle) + (this->a.y - other.y)*cos(angle);
        r.b.x=(this->b.x - other.x)*cos(angle) - (this->b.y - other.y)*sin(angle);
        r.b.y=(this->b.x - other.x)*sin(angle) + (this->b.y - other.y)*cos(angle);
        r.c.x=(this->c.x - other.x)*cos(angle) - (this->c.y - other.y)*sin(angle);
        r.c.y=(this->c.x - other.x)*sin(angle) + (this->c.y - other.y)*cos(angle);
        return (r);}

Triangle &rotate(double angle_D){
  double angle = angle_D*M_PI/180;
        Point d=a;Point e = b; Point f = c;
        a.x=d.x*cos(angle) - d.y*sin(angle);
        a.y=d.x*sin(angle) + d.y*cos(angle);
        b.x=e.x*cos(angle) - e.y*sin(angle);
        b.y=e.x*sin(angle) + e.y*cos(angle);
        c.x=f.x*cos(angle) - f.y*sin(angle);
        c.y=f.x*sin(angle) + f.y*cos(angle);
        return *this;}

Triangle &rotate(double angle_D, const Point &other){
  double angle = angle_D*M_PI/180;
        Point d = a-other;Point e = b-other; Point f = c-other;//creating dummy points to make code readable.
        a.x=d.x*cos(angle) - d.y*sin(angle);
        a.y=d.x*sin(angle) + d.y*cos(angle);
        b.x=e.x*cos(angle) - e.y*sin(angle);
        b.y=e.x*sin(angle) + e.y*cos(angle);
        c.x=f.x*cos(angle) - f.y*sin(angle);
        c.y=f.x*sin(angle) + f.y*cos(angle);
        return *this;}

double area(){//function to calculate area using shoelace formula.
    return std::abs(0.5*((a.x*b.y - b.x*a.y + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y)));}


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
#include<iostream>
using namespace std;


int main()
{
    //creation of points and triangles used for tests.

    Point p;
std::cout<<"Point p is "<<p<<std::endl;// check for point constructor. 
    Point a = {1, 1};
std::cout<<"Point a is "<<a<<std::endl;
    Point b = {3, 4};
std::cout<<"Point b is "<<b<<std::endl;
    Point c;
    b += a;    // result: b.x = 4, b.y = 5
 std::cout<<"Test for operator += : b+=a: "<<b<<std::endl;
    c = b + a; // result: c.x = 5, c.y = 6
 std::cout<<"Test for operator '+' : c=b+a:"<<c<<std::endl;
    
   Triangle t;
   Triangle r; //Default Triangle.
   Triangle s; // Default Triangle for checking area.

    // set point `p` to (2, 2)
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
    
    std::cout<<"Distance of point a wrt origin is: "<<a.distance()<<std::endl;//check for distance wrt origin.
    std::cout<<"Distance of a wrt p is: "<<a.distance(p)<<std::endl;//check for distance wrt p.
    std::cout<<"Point obtained after rotating point p by 90 degrees: "<<p.rotated(90)<<std::endl;
    std::cout<<"Point obtained after rotating and translating p by 90 degrees wrt point a: "<<p.rotated(90,a)<<std::endl;
    
    std::cout <<"Triangle t is: "<< t << std::endl;
    std::cout <<"New Triangle obtained after translating it wrt point a: "<<t.translated(a) << std::endl;//check for translated.
    std::cout <<"Translating original triangle wrt point a"<< t.translate(a) << std::endl;//check for translate.
    std::cout << "New triangle obtained after rotating t by 90 degrees: "<<t.rotated(90) << std::endl;//check for rotated.
    std::cout << "New triangle obtained after rotating t by 90 degrees wrt point a: "<<t.rotated(90,a) << std::endl;//check for rotated wrt a point.
    std::cout << "Rotating triangle r by 90 degrees: "<<r.rotate(90) << std::endl;//check for rotation of original triangle.
    std::cout << "Chcek if original triangle r rotated: "<<r << std::endl;//check if original rotated.
    std::cout << "Rotating triangle r back by 90 degrees clockwise wrt point a: "<<r.rotate(-90,a) << std::endl;//check for rotation of triangle 'r' wrt a point.
    std::cout << "Area of default triangle s: "<<s.area() << std::endl; //check for area. 
    std::cout << s.translate({2, 3}).rotate(90, {-1, -3}).translate({5, 6})<<std::endl;

}





