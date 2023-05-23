#ifndef POINT_H
#define POINT_H
#include<iostream>

class Point
{
private:
    int xCordinate;
    int yCordinate;
public:
    Point() = delete;
    Point(const Point &p) = default;
    Point(int x,int y);
    ~Point();
    Point operator+(const Point &c);
    Point operator-(const Point &c);
    Point operator++(int);
    int getXCordinate() const { return xCordinate; }
    void setXCordinate(int xCordinate_) { xCordinate = xCordinate_; }
    int getYCordinate() const { return yCordinate; }
    void setYCordinate(int yCordinate_) { yCordinate = yCordinate_; }
    friend std::ostream &operator<<(std::ostream &os, Point &p);
};

#endif // POINT_H
