#include "Point.h"

Point::Point(int x, int y) :xCordinate{x}, yCordinate{y}{}

Point::~Point()
{
    std::cout<<"Point with X-coordinate = "<< xCordinate<<" and Y-coordinate = "<<yCordinate<<" is destroyed\n";
}

Point Point::operator+(const Point &c)
{
    xCordinate = this->xCordinate + c.xCordinate;
    yCordinate = this->yCordinate + c.yCordinate;
    return Point(xCordinate,yCordinate);
};

Point Point::operator-(const Point &c)
{
    xCordinate = this->xCordinate - c.xCordinate;
    yCordinate = this->yCordinate - c.yCordinate;
    return Point(xCordinate,yCordinate);
}
Point Point::operator++(int)
{
    xCordinate = ++xCordinate;
    yCordinate = ++yCordinate;
    return Point(xCordinate,yCordinate);
};

std::ostream &operator<<(std::ostream &os, Point &p)
{
    os<<"X coordinate is: "<<p.getXCordinate()<<"\n"
      <<"Y coordinate is: "<<p.getYCordinate()<<"\n";
      return os;
};

// Point Point::operator-(const Point &p){
//      int x,y;
//      x= this->xCordinate - p.xCordinate;
//      y = this->yCordinate - p.yCordinate;
//      return Point(x,y);
// }