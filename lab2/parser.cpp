#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define MAX_NODE_NUMBER = 5000;

void functionPicker (string);
void errorHandler (int);

int main(void) {
	while (!cin.eof()) {
		string func;
		cout << "> ";
		cin >> func;
		functionPicker (func);
	}
	return 0;
}

void functionPicker (string fin) {
	double resistorVal;
	int node1, node2;
	string resistorName, entry;
	cout.precision(2);
	cin >> resistorName >> resistorVal >> node1 >> node2;
	if (fin == "insertR") {

        if (node1 == node2) errorHandler(1);
		cout << "Inserted: " << resistorName << " " << resistorVal << " "
			<< node1 << " -> " << node2;
	} else if (fin == "modifyR") {
		//cin >> resistorName >> resistorVal;
	} else if (fin == "printR") {
		//cin >> entry;
	} else if (fin == "printNode") {
		//cin >> entry;
	} else if (fin == "deleteR") {
		//cin >> entry;
	} else {
		errorHandler(1);
	}
    cout << '\n';
}

void errorHandler(int errorCode) {
	cout << "Error: ";
	switch (errorCode) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			cout << "Unknown error";
			break;
	}
}
