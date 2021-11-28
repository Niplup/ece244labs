//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
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
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void invalidName();
void shapeNotFound(string name);
void shapeExists(string name);
void groupNotFound(string name);
bool namePossible(string name);
bool nameExists(string name);
bool groupExists(string name);
GroupNode* nameFinder(string name);
GroupNode* groupFinder(string name);
string trim (const string& line);

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the poo group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        string name, type, group;
        int x_loc, y_loc, x_sz, y_sz;
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        line = trim(line);
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if (command == keyWordsList[0]) {
            //shape
            lineStream >> name;
            if (!namePossible(name)) {invalidName(); goto jmp;}
            if (nameExists(name) || groupExists(name)) {shapeExists(name); goto jmp;}
            lineStream >> type;
            lineStream >> x_loc;
            lineStream >> y_loc;
            lineStream >> x_sz;
            lineStream >> y_sz;
            Shape* namedShape = new Shape(name, type, x_loc, y_loc, x_sz, y_sz);
            ShapeNode* shapeptr = new ShapeNode();
            shapeptr->setShape(namedShape);
            shapeptr->getShape()->draw();
            poolGroup->getShapeList()->insert(shapeptr);
        } else if (command == keyWordsList[1]) {
            //group
            lineStream >> name;
            if (!namePossible(name)) {invalidName(); goto jmp;}
            GroupNode* namedGroup = new GroupNode(name);
            gList->insert(namedGroup);
            cout << name << ": group" << endl;
        } else if (command == keyWordsList[2]) {
            //move
            lineStream >> name;
            if (nameExists(name)) {
                lineStream >> group;
                if (groupExists(group)) {
                    GroupNode* movedShape = nameFinder(name);
                    GroupNode* destination = groupFinder(group);
                    destination->getShapeList()->insert(movedShape->getShapeList()->remove(name));
                    cout << "moved " << name << " to " << group << endl;
                } else {
                    groupNotFound(group);
                    goto jmp;
                }
            } else {
                shapeNotFound(name);
                goto jmp;
            } 

        } else if (command == keyWordsList[3]) {
            //delete
            lineStream >> name;
            if (!namePossible(name)) {invalidName(); goto jmp;}
            if (nameExists(name)) {
                GroupNode* shapeDelete = nameFinder(name);
                if (shapeDelete != nullptr) {
                    delete shapeDelete->getShapeList()->remove(name);
                    cout << name << ": deleted" << endl;
                } else {
                    shapeNotFound(name);
                    goto jmp;
                }
            } else if (groupExists(name)) {
                GroupNode* groupDelete = groupFinder(name);
                if (groupDelete != nullptr) {
                    while (groupDelete->getShapeList()->getHead() != nullptr) {
                        string shapeCounter = groupDelete->getShapeList()->getHead()->getShape()->getName();
                        ShapeNode* shapeCounterNode = groupDelete->getShapeList()->remove(shapeCounter);
                        poolGroup->getShapeList()->insert(shapeCounterNode);
                    }
                    delete gList->remove(name);
                    cout << name << ": deleted" << endl;
                }
            } else {
                shapeNotFound(name);
                goto jmp;
            }
        } else if (command == keyWordsList[4]) {
            //draw
            cout << "drawing: " << endl;
            gList->print();
        } else {
            cout << "error: invalid command" << endl;
            goto jmp;
        }
        // Once the command has been processed, prompt for the
        // next command
        jmp: cout << "> ";          // Prompt for input
        getline(cin, line);
    }  // End input loop until EOF.
    
    return 0;
}

string trim(const string& line) {
    const char* WhiteSpace = " \t\v\r\n";
    size_t start = line.find_first_not_of(WhiteSpace);
    size_t end = line.find_last_not_of(WhiteSpace);
    return start == end ? string() : line.substr(start, end - start + 1);
}

void invalidName() {cout << "error: invalid name" << endl;}
void shapeNotFound(string name) {cout << "error: shape " << name << " not found" << endl;}
void shapeExists(string name) {cout << "error: name " << name << " exists" << endl;}
void groupNotFound(string name) {cout << "error: group " << name << " not found" << endl;}

bool namePossible(string name) {
    for (int i = 0; i < NUM_KEYWORDS; i++) if (name == keyWordsList[i]) return false;
    for (int i = 0; i < NUM_TYPES; i++) if (name == shapeTypesList[i]) return false;
    
    return true;
}

bool nameExists(string name) {
    GroupNode* fakehead = gList->getHead();
    while (fakehead != nullptr) {
        if(fakehead->getShapeList()->find(name)) return true;
        fakehead = fakehead->getNext();
    }
    return false;
}

bool groupExists(string name) {
    GroupNode* fakehead = gList->getHead();
    while (fakehead != nullptr) {
        if (fakehead->getName() == name) return true;
        fakehead = fakehead->getNext();
    }
    return false;
}
GroupNode* nameFinder(string name) {
    GroupNode* fakehead = gList->getHead();
    while (fakehead != nullptr) {
        if (fakehead->getShapeList()->find(name) != nullptr) return fakehead;
        fakehead = fakehead->getNext();
    }
    return nullptr;
}

GroupNode* groupFinder(string name) {
    GroupNode* fakehead = gList->getHead();
    while (fakehead != nullptr) {
        if (fakehead->getName() == name) return fakehead;
        fakehead = fakehead->getNext();
    }
    return nullptr;
}

