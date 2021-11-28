//
//  Triangle.h
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include <string>
using namespace std;


#include "Shape.h"
// This class implements the triangle Shape objects.
// ECE244 Student: Write the definition of the class here.
class Triangle : Shape {
    private:
        float x1;
        float y1;
        float x2;
        float y2;
        float x3;
        float y3;
    public:
        //Constructor
        Triangle (string n, float xcent, float ycent, float xin1, float yin1, float xin2, float yin2, float xin3, float yin3);
        
        //Destructor
        virtual ~Triangle();

        //Accessor
        float getx1() const;
        float gety1() const;
        float getx2() const;
        float gety2() const;
        float getx3() const;
        float gety3() const;

        //Mutator
        void setx1(float x);
        void sety1(float y);
        void setx2(float x);
        void sety2(float y);
        void setx3(float x);
        void sety3(float y);

        //Utility methods
        virtual void draw() const;
        virtual float computeArea() const;
        virtual Shape* clone() const;

};

#endif /* Triangle_h */
