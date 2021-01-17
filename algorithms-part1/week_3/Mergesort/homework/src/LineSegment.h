#ifndef __LINESEGMENT_H_
#define __LINESEGMENT_H_

#include "Point.h"

class LineSegment {
public:
    friend std::ostream &operator<<(std::ostream &output, const LineSegment& line)
    {
        output << line.p << " -> " << line.q;
        return output;            
    }
public:
    LineSegment(Point p, Point q) { this->p = p; this->q = q; }

private:
    Point p, q;
};

#endif /* __LINESEGMENT_H_ */