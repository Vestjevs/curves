//
// Created by vestj on 29.10.2022.
//

#include "curves.h"

#include <cmath>

/* Parametric circle formula
 * x = r * cos(t);
 * y = r * sin(t);
 * */
GeometricCurve::Point_3 Circle::getPoint(double t) {
    return {a_ * std::cos(t), a_ * std::sin(t), 0};
}

/* first derivative
 * x' = -r * sin(t);
 * y' = r * cos(t);
 * */
GeometricCurve::Vector_3 Circle::getFirstDerivative(double t) {
    return {-a_ * std::sin(t), a_ * std::cos(t), 0}; // TODO: COMMENT
}

/* Parametric ellipse formula
 * x = a * cos(t);
 * y = b * sin(t);
 * */
GeometricCurve::Point_3 Ellipse::getPoint(double t) {
    return {a_ * std::cos(t), b_ * std::sin(t), 0}; // TODO: COMMENT
}

/* first derivative
 * x' = -a * sin(t);
 * y' = b * cos(t);
 * */
GeometricCurve::Vector_3 Ellipse::getFirstDerivative(double t) {
    return {-a_ * std::sin(t), b_ * std::cos(t), 0}; // TODO: COMMENT
}

/* Parametric ellipse formula
 * x = a * cos(t);
 * y = a * sin(t);
 * z = b * t;
 * */
GeometricCurve::Point_3 Helix::getPoint(double t) {
    return {a_ * std::cos(t), a_ * std::sin(t), b_ * t}; // TODO: COMMENT
}

/* first derivative
 * x' = -a * sin(t);
 * y' = a * cos(t);
 * z' = b;
 * */
GeometricCurve::Vector_3 Helix::getFirstDerivative(double t) {
    return {-a_ * std::sin(t), a_ * std::cos(t), b_}; // TODO: COMMENT
}
