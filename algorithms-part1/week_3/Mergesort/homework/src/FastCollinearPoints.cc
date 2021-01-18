#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#include "Point.h"
#include "LineSegment.h"

#define DEBUG

class FastCollinearPoints {
public:
    FastCollinearPoints(std::vector<Point>& points)
    {
        initCheck(points);

        int length = internalPoints.size();
        for (int i = 0; i < length - 1; i++) {
#ifdef DEBUG
            std::cout << "round: " << i + 1 << std::endl;
#endif
            //int cntOtherPoints = 0;
            //std::vector<Point> otherPoints = std::vector<Point>(length - 1);
            std::vector<Point> otherPoints;

            for (int j = 0; j < length; j++) {
                if (i != j) {
                    otherPoints.push_back(internalPoints[j]);
#ifdef DEBUG
                    std::cout << "origin point:" << internalPoints[i] << " push " << internalPoints[j] << " in" << std::endl;
#endif
                }
            }
#ifdef DEBUG
            {
                std::cout << "before sort by slot, origin point: " << internalPoints[i] << std::endl;
                for (auto iter : otherPoints) {
                    std::cout << iter << " : " << internalPoints[i].slopeTo(iter) << std::endl;
                }
            }
#endif
            SlotComp slopOrder = SlotComp(internalPoints[i]);
            std::sort(otherPoints.begin(), otherPoints.end(), slopOrder);
#ifdef DEBUG
            {
                std::cout << "after sort by slot, origin point: " << internalPoints[i] << std::endl;
                for (auto iter : otherPoints) {
                    std::cout << iter << " : " << internalPoints[i].slopeTo(iter) << std::endl;
                }
            }
#endif  
            std::vector<std::vector<Point> > points_set;
            splitPointsBySlot(points_set, otherPoints, internalPoints[i]);
            for (int i = 0; i < points_set.size(); ++i) {
#ifdef DEBUG
                {
                    std::cout << "before sort by point" << std::endl;
                    for (auto iter : points_set[i]) {
                        std::cout << iter << " : " << internalPoints[i].slopeTo(iter) << std::endl;
                    }
                }
#endif 
                std::sort(points_set[i].begin(), points_set[i].end());
#ifdef DEBUG
                {
                    std::cout << "after sort by point" << std::endl;
                    for (auto iter : points_set[i]) {
                        std::cout << iter << " : " << internalPoints[i].slopeTo(iter) << std::endl;
                    }
                }
#endif
                auto tmp = LineSegment(points_set[i][0], points_set[i][points_set[i].size() - 1]);
                line_set.insert(tmp);
                // segments.push_back(tmp);
#ifdef DEBUG
                std::cout << "push line : " << tmp << " in" << std::endl;
#endif
            }
        }
    }

    int numberOfSegments() { return segments.size(); }

    // std::vector<LineSegment>& getSegments() { return segments; }

    std::vector<LineSegment>& getSegments()
    {
        for (auto& iter : line_set) {
            segments.push_back(iter);
        }
        return segments;
    }

private:
    void initCheck(std::vector<Point>& points)
    {
        internalPoints = std::vector<Point>(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i] == points[j]) {
                    std::cout << "duplicate  point" << std::endl;
                    exit(0);
                }
            }
            internalPoints[i] = points[i];
        }
        //std::sort(internalPoints.begin(), internalPoints.end());
    }

    void splitPointsBySlot(std::vector<std::vector<Point> >& points_set, 
                           std::vector<Point>& points, Point& pivot)
    {
#ifdef DEBUG
        std::cout << "in splitPointsBySlot, origin point : " << pivot << std::endl;
#endif
        double target = pivot.slopeTo(points[0]);
        std::vector<Point> tmp;
        for (int i = 0; i < points.size();) {
#ifdef DEBUG
            std::cout << "target: " << target << std::endl;
            std::cout << "pivot.slopeTo(points[i]) = " << pivot.slopeTo(points[i]) << std::endl;
#endif
            if (pivot.slopeTo(points[i]) == target) {
#ifdef DEBUG
                std::cout << "target check, we push " << points[i] << " in" << std::endl;
#endif
                tmp.push_back(points[i++]);
                if (tmp.size() >= 3 && i == points.size()) {
                    tmp.push_back(pivot);
                    points_set.push_back(tmp);
                    target = pivot.slopeTo(points[i]);
                    tmp = std::vector<Point>();
#ifdef DEBUG
                    std::cout << "tmp : " << std::endl;
                    for (auto iter : tmp) {
                        std::cout << iter << " slot : " << target << std::endl;
                    }
#endif
                }
            } else {
                if (tmp.size() >= 3) {
                    tmp.push_back(pivot);
                    points_set.push_back(tmp);
#ifdef DEBUG
                    std::cout << "tmp : " << std::endl;
                    for (auto iter : tmp) {
                        std::cout << iter << " slot : " << target << std::endl;
                    }
#endif
                } else {
                    //target = pivot.slopeTo(points[i]);
                }
                target = pivot.slopeTo(points[i]);
                tmp = std::vector<Point>();
            }
        }
    }

private:
    const double EPSILON = 0.0000001f;
    std::vector<LineSegment> segments;      // 用来存储筛选出来到线段
    std::vector<Point> internalPoints;      // 用来存储初始化后的 Point 集合
    // std::vector<std::vector<Point> > points_set; // 用来存储按照斜率分割的 point 集合
    std::unordered_set<LineSegment, hash_fun> line_set;
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

    FastCollinearPoints fcp = FastCollinearPoints(points);

    std::cout << fcp.numberOfSegments() << std::endl;
    for (auto iter : fcp.getSegments()) {
        std::cout << iter << std::endl;
    }

    return 0;
}