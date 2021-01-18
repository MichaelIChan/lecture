#ifndef __LINESEGMENT_H_
#define __LINESEGMENT_H_

#include "Point.h"

class LineSegment {
public:
    friend bool operator==(const LineSegment&, const LineSegment&);
    friend std::ostream &operator<<(std::ostream &, const LineSegment&);
public:
    LineSegment(Point start, Point end)
        { this->start = start; this->end = end; slot = start.slopeTo(end); }
    Point getStart() const { return start; }
    double getSlot() const { return slot; }

private:
    Point start, end;
    double slot;
};

bool operator==(const LineSegment& x, const LineSegment& y)
{
    return (x.start == y.start) & (x.end == y.end);
}

std::ostream &operator<<(std::ostream &output, const LineSegment& line)
{
    output << line.start << " -> " << line.end;
    return output;
}

struct hash_fun {
    long operator()(const LineSegment &line) const
    {
        return line.getStart().getX() + line.getSlot() * 1000000;
    }
};

#endif /* __LINESEGMENT_H_ */