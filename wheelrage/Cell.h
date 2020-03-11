#pragma once
template <class T> class Cell {

private:
	Cell<T>* next;
	Cell<T>* previous;
	T object;

public:

	Cell () { };
	Cell (Cell<T>* next, Cell<T>* previous, T object);
	void setNext(Cell<T>* next);
	Cell<T>* getNext();
	void setPrevious(Cell<T>* previous);
	Cell<T>* getPrevious();
	void setObject(T object);
	T getObject();

};

