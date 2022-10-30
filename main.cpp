#include "curves.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>
#include <algorithm>

const double PI = std::acos(-1);

using ptr_type = std::unique_ptr<GeometricCurve>;
using ptr_container_type = std::vector<ptr_type>;

std::string typeStr(int type) {
    if (type == GeometricCurve::CIRCLE)
        return "circle";
    else if (type == GeometricCurve::ELLIPSE)
        return "ellipse";
    return "helix";
}

auto print = [](const auto &toPrint) {
    std::cout << "x : " << toPrint[0] << " y: " << toPrint[1] << " z: " << toPrint[2];
};

void printRadiusCircles(const std::vector<GeometricCurve *> &circles) {
    for (const auto &circle: circles) {
        std::cout << "circle radius: " << circle->a() << std::endl;
    }
}

// TBD: better to split by points and derivatives
void printPointsAndDerivativesCurvesAt(const ptr_container_type& curves, double t)
{
    for (const auto &curve: curves) {
        auto der = curve->getFirstDerivative(t);
        auto pt = curve->getPoint(t);
        std::cout << "curve type: " << typeStr(curve->type()) << std::endl;
        std::cout << "derivative: (";
        print(der);
        std::cout << ")" << std::endl;
        std::cout << "point: (";
        print(pt);
        std::cout << ")" << std::endl;
    }
}

int main() {

    std::srand(1024);

    int quantity = std::rand() % 100;
    ptr_container_type curves;

    // #2 Populating a container. Chosen a simple random manner populating to simplify task
    for (int i = 0; i < quantity; i++) {
        int kind = std::rand() % 3;
        double a = std::rand() % 20 + 1; // TODO: random
        double b = std::rand() % 20 + 1; // TODO: random
        switch (kind) {
            case GeometricCurve::CIRCLE: {
                curves.push_back(std::make_unique<Circle>(a));
                break;
            }
            case GeometricCurve::ELLIPSE: {
                curves.push_back(std::make_unique<Ellipse>(a, b));
                break;
            }
            default: {
                curves.push_back(std::make_unique<Helix>(a, b));
                break;
            }
        }
    }

    // #3 Print coordinates of points and derivatives
    printPointsAndDerivativesCurvesAt(curves, PI * 0.25);

    // #4 Populating a second container only CIRCLE
    std::vector<GeometricCurve *> circles;
    for (const auto &curve: curves)
        if (curve->type() == GeometricCurve::CIRCLE) {
            circles.push_back(curve.get());
        }

//    std::cout << "\nUnsorted circles by radius" << std::endl;
//    printRadiusCircles(circles); // Uncomment to see order of circles` radius

    // #5 Sorting container with simple sorting method(Bubble sort)
    size_t size = circles.size();
    GeometricCurve *tempPointer;
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (circles[j]->a() > circles[j + 1]->a()) {
                tempPointer = circles[j];
                circles[j] = circles[j + 1];
                circles[j + 1] = tempPointer;
            }
        }
    }

//    std::cout << "\nSorted circles:" << std::endl;
//    printRadiusCircles(circles); // Uncomment to see ascending order of circles` radius

    // #6 Sum of all curves in the second container
    double sum = 0;
    for (const auto &circle: circles)
        sum += circle->a();

    std::cout << '\n';
    std::cout << "Sum of all curves in the second container : " << sum << std::endl;

    return 0;
}
