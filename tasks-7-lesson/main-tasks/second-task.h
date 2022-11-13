#ifndef first_task_h
#define first_task_h

#include "../core-file.h"
#include "../utils/main_menu.h"
#include <iterator>
#include <algorithm>
#include <iomanip>


using namespace std;

namespace mainTasks {

    struct Point {
        double x;
        double y;
    };

    void initPoints(Point &point1, Point &point2);
    void calcAndDisplayDistance(Point &point1, Point &point2);

    void euclideanDistanceSolveRunner() {
        Point point1, point2;
        
        initPoints(point1, point2);
    }

    void initPoints(Point &point1, Point &point2) {
        point1.x = inputValidatorsUtils::getDoubleInput("Enter point [I] x=");
        point1.y = inputValidatorsUtils::getDoubleInput("Enter point [I] Y=");

        point2.x = inputValidatorsUtils::getDoubleInput("Enter point [II] x=");
        point2.y = inputValidatorsUtils::getDoubleInput("Enter point [II] Y=");
    }

    void calcAndDisplayDistance(Point &point1, Point &point2) {
        double distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point2.y, 2) * 1.0);
        cout << "\nDistance: " << distance;
    }

} // namespace mainTasks


#endif