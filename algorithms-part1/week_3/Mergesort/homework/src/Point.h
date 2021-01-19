#ifndef __POINT_H_
#define __POINT_H_

#include <iostream>
#include <limits>
#include <functional>
#include <cmath>

inline int compare_float(double x, double y){
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}

class Point {
public:
    friend bool operator==(const Point&, const Point&);
    friend bool operator<(const Point&, const Point&);
    friend bool operator>(const Point&, const Point&);
    friend std::ostream &operator<<(std::ostream &output, const Point& point)
    {
        output << "(" << point.x << ", " << point.y << ")";
        return output;            
    }

    friend std::istream &operator>>(std::istream &input, Point& point)
    {
        int x, y;
        input >> x >> y;
        point = Point(x, y);
        return input;            
    }

public:
    Point() { }
    Point(int x, int y) { this->x = x; this->y = y; }
    Point& operator=(const Point& point)
    {
        this->x = point.x;
        this->y = point.y;
        return *this;
    }
    Point(const Point& point) { *this = point; }
    int getX() const { return x; }
    int getY() const { return y; }

    /**
     * Returns the slope between this point and the specified point.
     * Formally, if the two points are (x0, y0) and (x1, y1), then the slope
     * is (y1 - y0) / (x1 - x0). For completeness, the slope is defined to be
     * +0.0 if the line segment connecting the two points is horizontal;
     * DOUBLE_POSITIVE_INFINITY if the line segment is vertical;
     * and DOUBLE_NEGATIVE_INFINITY if (x0, y0) and (x1, y1) are equal.
     *
     * @param that the other point
     * @return the slope between this point and the specified point
     */
    double slopeTo(Point that)
    {
        // (x0, y0) and (x1, y1) are equal.
        if (this->x == that.x && this->y == that.y) return DOUBLE_NEGATIVE_INFINITY;
        // the line segment is vertical
        if (this->x == that.x) return DOUBLE_POSITIVE_INFINITY;
        // the two points is horizontal
        if (this->y == that.y) return +0.0;
        return (double) (that.y - this->y) / (that.x - this->x);
    }

private:
    const double DOUBLE_POSITIVE_INFINITY =  std::numeric_limits<double>::infinity();
    const double DOUBLE_NEGATIVE_INFINITY = -std::numeric_limits<double>::infinity();    

    int x;
    int y;
};

bool operator==(const Point& p1, const Point& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

bool operator<(const Point& p1, const Point& p2)
{
    return (p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x));
}

bool operator>(const Point& p1, const Point& p2)
{
    return (p1.y > p2.y || (p1.y == p2.y && p1.x > p2.x));
}

class SlotComp {
public:
    SlotComp(Point& x) { p = x; }
    bool operator() (const Point& x, const Point& y)
    {
        return compare_float(p.slopeTo(x), p.slopeTo(y)) == -1;
    }
private:
    Point p;
};

#endif /* __POINT_H_ */