//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include "GroupList.h"
#include "GroupNode.h"
#include <iostream>

GroupList::GroupList() {head = nullptr;}

GroupList::~GroupList() {
	GroupNode* fakehead = head;
	GroupNode* tempptr = nullptr;
	while (fakehead != nullptr) {
		tempptr = fakehead->getNext();
		delete fakehead;
		fakehead = tempptr;
	}
}

GroupNode* GroupList::getHead() const {return head;}

void GroupList::setHead(GroupNode* ptr) {head = ptr;}

void GroupList::insert(GroupNode *s) {
	GroupNode* fakehead = head;
	s->setNext(nullptr);
	if (head == nullptr) {
		head = s;
		return;
	}
	while (fakehead->getNext() != nullptr) {fakehead = fakehead->getNext();}
	fakehead->setNext(s);
}

GroupNode* GroupList::remove(string name) {
	GroupNode* removeptr = head;
	GroupNode* prev = nullptr;

	if (removeptr != nullptr && removeptr->getName() == name) {
		head = removeptr->getNext();
		return removeptr;
	} else {
		while (removeptr != nullptr && removeptr->getName() != name) {
			prev = removeptr;
			removeptr = removeptr->getNext();
		}
		if (removeptr == nullptr) return nullptr;
		prev->setNext(removeptr->getNext());
	}
	return removeptr;
}

void GroupList::print() const {
	GroupNode* fakehead = head;
	while (fakehead != nullptr) {
		fakehead->print();
		fakehead=fakehead->getNext();
	}
}



