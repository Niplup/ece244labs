//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include "ShapeList.h"
#include <iostream>

ShapeList::ShapeList() {head = nullptr;}

ShapeList::~ShapeList() {
	ShapeNode* fakehead = head;
	ShapeNode* tempptr = nullptr;
	while (fakehead != nullptr) {
		tempptr = fakehead->getNext();
		delete fakehead;
		fakehead = tempptr;
	}
}

ShapeNode* ShapeList::getHead() const {return head;}

void ShapeList::setHead(ShapeNode *ptr) {head = ptr;}

ShapeNode* ShapeList::find(string name) const {
	ShapeNode* fakehead = head;
	ShapeNode* prev = nullptr;
	if (fakehead == nullptr) return nullptr;
	while (fakehead != nullptr) {
		if (fakehead->getShape()->getName() == name) return fakehead;
		fakehead = fakehead->getNext();
	}
	return nullptr;
}

void ShapeList::insert(ShapeNode *s) {
	s->setNext(nullptr);
	if (head == nullptr) head = s;
	else {
		ShapeNode* fakehead = head;
		while (fakehead->getNext() != nullptr) fakehead = fakehead->getNext();
		fakehead->setNext(s);
	}
}

ShapeNode* ShapeList::remove(string name) {
	ShapeNode* removeptr = head;
  ShapeNode* prev = nullptr;
  if(removeptr == nullptr) return nullptr;
  while(removeptr != nullptr) {
    if(removeptr->getShape()->getName()==name) break;
    prev = removeptr;
    removeptr = removeptr->getNext();
  }
  if(removeptr == head){
    head=head->getNext();
    return removeptr;
  }
  prev->setNext(removeptr->getNext());
  return removeptr; 
}

void ShapeList::print() const {
	ShapeNode* fakehead = head;
	while (fakehead != nullptr) {
		fakehead->print();
		fakehead=fakehead->getNext();
	}
}
