//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle (string n, float xcent, float ycent, float xin1, float yin1, float xin2, float yin2, float xin3, float yin3):Shape(n, xcent, ycent) {
    x1 = xin1;
    x2 = xin2;
    x3 = xin3;
    y1 = yin1;
    y2 = yin2;
    y3 = yin3;
}

Triangle::~Triangle() {}

float Triangle::getx1() const {return x1;}
float Triangle::gety1() const {return y1;}
float Triangle::getx2() const {return x2;}
float Triangle::gety2() const {return y2;}
float Triangle::getx3() const {return x3;}
float Triangle::gety3() const {return y3;}

void Triangle::setx1(float x) {x1 = x;}
void Triangle::sety1(float y) {y1 = y;}
void Triangle::setx2(float x) {x2 = x;}
void Triangle::sety2(float y) {y2 = y;}
void Triangle::setx3(float x) {x3 = x;}
void Triangle::sety3(float y) {y3 = y;}

void Triangle::draw() const {
    cout << std::fixed;
    cout << std::setprecision(2);

    cout << "triangle: " << name << " "
         << x_centre << " " << y_centre
         << " " << x1 << " " << y1 
         << " " << x2 << " " << y2 
         << " " << x3 << " " << y3 
         << " " << computeArea()
         << endl;
}

float Triangle::computeArea() const {
return abs(0.5*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}
