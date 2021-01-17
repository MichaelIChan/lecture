#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"
#include "LineSegment.h"

class BruteCollinearPoints {
public:
    BruteCollinearPoints(std::vector<Point> points)
    {
        std::vector<Point> internalPoints = std::vector<Point>(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i] == points[j]) {
                    std::cout << "duplicate  point" << std::endl;
                    exit(0);
                }
            }
            internalPoints[i] = points[i];
        }

        std::sort(internalPoints.begin(), internalPoints.end());

        int length = internalPoints.size();
        for (int a = 0; a < length; a++) {
            for (int b = a + 1; b < length; b++) {
                for (int c = b + 1; c < length; c++) {
                    for (int d = c + 1; d < length; d++) {
                        double slope1 = internalPoints[a].slopeTo(internalPoints[b]);
                        double slope2 = internalPoints[b].slopeTo(internalPoints[c]);
                        double slope3 = internalPoints[c].slopeTo(internalPoints[d]);
                        if (compare_float(slope1, slope2) == 0 && compare_float(slope2, slope3) == 0) {
                            segments.push_back(LineSegment(internalPoints[a], internalPoints[d]));
                        }
                    }
                }
            }
        }
    }

    // the number of line segments
    int numberOfSegments() { return segments.size(); }

    // the line segments
    std::vector<LineSegment>& getSegments() { return segments; }

private:
    std::vector<LineSegment> segments;
};

int main(int argc, char const *argv[])
{
    int num;
    std::cin >> num;
    std::vector<Point> points;
    Point point;

    while (std::cin >> point) {
        points.push_back(point);
    }

    BruteCollinearPoints bcp = BruteCollinearPoints(points);

    for (auto iter : bcp.getSegments()) {
        std::cout << iter << std::endl;
    }

    return 0;
}
