//
// Created by vestj on 29.10.2022.
//

#include <array>

class GeometricCurve {
public:
    using Point_3 = std::array<double, 3>;
    using Vector_3 = std::array<double, 3>;
    enum CurveType {
        CIRCLE,
        ELLIPSE,
        HELIX,
    };
public:
    GeometricCurve(int type, double a, double b) : type_(type), a_(a), b_(b) {};

    int type() const { return type_; }

    double a() const { return a_; }

    double b() const { return b_; }

    virtual Point_3 getPoint(double t) = 0;

    virtual Vector_3 getFirstDerivative(double t) = 0;

protected:
    double a_;
    double b_;
    int type_ = -1;
};

class Circle : public GeometricCurve {
public:
    Circle(double radius) : GeometricCurve(CIRCLE, radius, radius) {} // TBD: radius should be non-negative (assert)

    Point_3 getPoint(double t) override;

    Vector_3 getFirstDerivative(double t) override;

    double radius() const { return a(); }
};

class Ellipse : public GeometricCurve {
public:
    Ellipse(double a, double b) : GeometricCurve(ELLIPSE, a, b) {}

    Point_3 getPoint(double t) override;

    Vector_3 getFirstDerivative(double t) override;
};

class Helix : public GeometricCurve {
public:
    Helix(double a, double b) : GeometricCurve(HELIX, a, b) {}

    Point_3 getPoint(double t) override;

    Vector_3 getFirstDerivative(double t) override;
};

