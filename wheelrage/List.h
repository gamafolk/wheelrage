
#pragma once
#include <iostream>
#include"Cell.h"

using namespace std;

template<class T> class List {

private:
	Cell<T>* first;
	Cell<T>* last;
	int length;

	bool isEmpty();

public:

	List();
	int size();
	void push(T object);
	T get(int index);
	void remove(int index);

};

