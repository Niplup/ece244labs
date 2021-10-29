//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void errorMessage(int i);
void shapeNotFound(string name);
void shapeExists(string name);
string trim (const string& line);
bool namePossible(string name);
bool nameExist (string name, int numShapes);
bool typePossible (string type);
bool sizeAndLocationPossible (int input);
bool anglePossible (int angle);

int main() {
    //This is the saddest and worst code I've ever written in my life. I have never used this many goto statements before.

    string line;
    string command;
    int numShapes = 0;
    string typesOfShapes[4] {"rectangle", "triangle", "ellipse", "circle"};
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        string name, type;
        int x_loc, y_loc, x_sz, y_sz, angle;
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        line = trim(line);
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if (command == keyWordsList[1]) {
            //maxShapes
            lineStream >> max_shapes;
            shapesArray = new Shape*[max_shapes]; 
            cout << "New database: max shapes is " << max_shapes << endl;

        } else if (command == keyWordsList[2]) {
            //create
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            else if (numShapes == max_shapes) {errorMessage(9); goto jmp;}
            else {

                lineStream >> name;

                if (lineStream.fail()) {errorMessage(1); goto jmp;}
                if (!namePossible(name)) {errorMessage(2); goto jmp;}
                if (nameExist(name, numShapes)) {shapeExists(name); goto jmp;}
                if (lineStream.eof()) {errorMessage(8); goto jmp;}

                if (namePossible(name) && !nameExist(name, numShapes)) {

                    lineStream >> type;

                    if (lineStream.fail()) {errorMessage(1); goto jmp;}
                    if (!typePossible(type)) {errorMessage(5); goto jmp;}
                    if (lineStream.eof()) {errorMessage(8); goto jmp;}

                    if (typePossible(type)) {
                        lineStream >> x_loc;

                        if (lineStream.fail()) {errorMessage(1); goto jmp;}
                        if (!sizeAndLocationPossible(x_loc)) {errorMessage(6); goto jmp;}
                        if (lineStream.eof()) {errorMessage(8); goto jmp;}

                        if (sizeAndLocationPossible(x_loc)) {
                            lineStream >> y_loc;

                            if (lineStream.fail()) {errorMessage(1); goto jmp;}
                            if (!sizeAndLocationPossible(y_loc)) {errorMessage(6); goto jmp;}
                            if (lineStream.eof()) {errorMessage(8); goto jmp;}

                            if (sizeAndLocationPossible(y_loc)) {
                                lineStream >> x_sz;

                                if (lineStream.fail()) {errorMessage(1); goto jmp;}
                                if (!sizeAndLocationPossible(x_sz)) {errorMessage(6); goto jmp;}
                                if (lineStream.eof()) {errorMessage(8); goto jmp;}

                                if (sizeAndLocationPossible(x_sz)) {
                                    lineStream >> y_sz;

                                    if (lineStream.fail()) {errorMessage(1); goto jmp;}
                                    if (!sizeAndLocationPossible(y_sz)) {errorMessage(6); goto jmp;}
                                    if (!lineStream.eof()) {errorMessage(7); goto jmp;}

                                    if (sizeAndLocationPossible(y_sz)) { 
                                        if (type == "circle" && x_sz != y_sz) {errorMessage(6); goto jmp;}
                                        shapesArray[numShapes] = new Shape(name, type, x_loc, x_sz, y_loc, y_sz);
                                        cout << "Created " << name << ": " << type << " " << x_loc << " " << y_loc << " " << x_sz << " " << y_sz << endl;
                                        numShapes++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (command == keyWordsList[3]) {
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            //move
            lineStream >> name;
            if (lineStream.fail()) {errorMessage(1); goto jmp;}
            if (!nameExist(name, numShapes)) {shapeNotFound(name); goto jmp;}
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            if (nameExist(name, numShapes)) {
                lineStream >> x_loc;
                if (lineStream.fail()) {errorMessage(1); goto jmp;}
                if (!sizeAndLocationPossible(x_loc)) {errorMessage(6); goto jmp;}
                if (lineStream.eof()) {errorMessage(8); goto jmp;}

                if (sizeAndLocationPossible(x_loc)) {
                    lineStream >> y_loc;
                    if (lineStream.fail()) {errorMessage(1); goto jmp;}
                    if (!sizeAndLocationPossible(y_loc)) {errorMessage(6); goto jmp;}
                    if (!lineStream.eof()) {errorMessage(7); goto jmp;}

                    if (sizeAndLocationPossible(y_loc)) {
                        for (int i = 0; i < numShapes; i++) {
                            if (name == shapesArray[i]->getName()) {
                                shapesArray[i]->setXlocation(x_loc);
                                shapesArray[i]->setYlocation(y_loc);
                                cout << "Moved " << shapesArray[i]->getName() << " to " << x_loc << " " << y_loc << endl;
                            }
                        }
                    }
                }
            } else {
                shapeNotFound(name);
                goto jmp;
            }
        } else if (command == keyWordsList[4]) {
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            //rotate
            lineStream >> name;
            if (lineStream.fail()) {errorMessage(1); goto jmp;}
            if (!nameExist(name, numShapes)) {shapeNotFound(name); goto jmp;}
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            if (nameExist(name, numShapes)) { 
                lineStream >> angle;
                if (lineStream.fail()) {errorMessage(1); goto jmp;}
                if (!anglePossible(angle)) {errorMessage(6); goto jmp;}
                if (!lineStream.eof()) {errorMessage(7); goto jmp;}
                
                if (anglePossible(angle)) {
                    for (int i = 0; i < numShapes; i++) {
                        if (name == shapesArray[i]->getName()) {
                            shapesArray[i]->setRotate(angle);
                            cout << "Rotated " << name << " by " << angle << " degrees" << endl;
                        }
                    }
                }    
            } else {
                shapeNotFound(name);
                goto jmp;
            }
        } else if (command == keyWordsList[5]) {
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            //draw
            lineStream >> name;
            if (lineStream.fail()) {errorMessage(1); goto jmp;}
            if (!nameExist(name, numShapes) && name != "all") {shapeNotFound(name); goto jmp;}
            if (!lineStream.eof()) {errorMessage(7); goto jmp;}

            if (nameExist(name, numShapes)) {
                for (int i = 0; i < numShapes; i++) {
                    if (name == shapesArray[i]->getName()) {
                        cout << "Drew ";
                        shapesArray[i]->draw();
                    }
                }
            } else if (name == "all") {
                cout << "Drew all shapes" << endl;
                for (int i = 0; i < numShapes; i++) {
                    shapesArray[i]->draw();
                }
            } else {
               shapeNotFound(name);
                goto jmp;
            }

        } else if (command == keyWordsList[6]) {
            //delete
            if (lineStream.eof()) {errorMessage(8); goto jmp;}
            lineStream >> name;
            if (lineStream.fail()) {errorMessage(1); goto jmp;}
            if (!nameExist(name, numShapes) && name != "all") {shapeNotFound(name); goto jmp;}
            if (!lineStream.eof()) {errorMessage(7); goto jmp;}

            if (nameExist(name, numShapes)) {
                cout << "Deleted shape " << name << endl;
                for (int i = 0; i < numShapes; i++) {
                    if (name == shapesArray[i]->getName()) {
                        delete shapesArray[i];
                        for (int j = i; j < numShapes; j++) {
                            if (shapesArray[j+1] != nullptr) {
                                shapesArray[j] = shapesArray[j+1];
                            }
                        }
                    }
                }
                numShapes--;

            } else if (name == "all") {
                cout << "Deleted: all shapes" << endl;
                for (int i = 0; i < numShapes; i++) {
                    delete shapesArray[i];
                    shapesArray[i] = nullptr;
                }
                numShapes = 0;
            } else {
                shapeNotFound(name);
                goto jmp;
            }
        } else errorMessage(0);
        
        
        
        // Once the command has been processed, prompt for the
        // next command
        jmp: cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

void errorMessage(int i) {
    switch (i) {
        case 0:
            cout << "Error: invalid command" << endl;
            break;
        case 1:
            cout << "Error: invalid argument" << endl;
            break;
        case 2:
            cout << "Error: invalid shape name" << endl;
            break;
        case 3:
            //Shouldn't be used
            cout << "Error: shape name exists" << endl;
            break;
        case 4:
            //Shouldn't be used
            cout << "Error: shape name not found" << endl;
            break;
        case 5:
            cout << "Error: invalid shape type" << endl;
            break;
        case 6:
            cout << "Error: invalid value" << endl;
            break;
        case 7:
            cout << "Error: too many arguments" << endl;
            break;
        case 8:
            cout << "Error: too few arguments" << endl;
            break;
        case 9:
            cout << "Error: shape array is full" << endl;
    }
}

void shapeNotFound(string name) {
    cout << "Error: shape " << name << " not found" << endl;
}

void shapeExists(string name) {
    cout << "Error: shape " << name << " exists" << endl;
}

string trim(const string& line) {
    const char* WhiteSpace = " \t\v\r\n";
    size_t start = line.find_first_not_of(WhiteSpace);
    size_t end = line.find_last_not_of(WhiteSpace);
    return start == end ? string() : line.substr(start, end - start + 1);
}

bool namePossible(string name) {
    for (int i = 0; i < NUM_KEYWORDS; i++) if (name == keyWordsList[i]) return false;
    for (int i = 0; i < NUM_TYPES; i++) if (name == shapeTypesList[i]) return false;
    
    return true;
}

bool nameExist(string name, int numShapes) {
    for (int i = 0; i < numShapes; i++) if (name == shapesArray[i]->getName()) return true;
    return false;
}

bool typePossible(string type) {
    for (int i = 0; i < NUM_TYPES; i++) if (type == shapeTypesList[i]) return true;
    return false;
}

bool sizeAndLocationPossible(int input) {
    if (input > 0) return true;
    return false;
}

bool anglePossible (int angle) {
    if (angle < 0 || angle > 360) return false;
    return true;
}
