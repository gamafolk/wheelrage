#pragma once
template <class T> class Cell {

private:
	Cell<T>* next;
	Cell<T>* previous;
	T object;

public:

	Cell () { };
	Cell (Cell<T>* next, Cell<T>* previous, T object) {
		this->next = next;
		this->previous = previous;
		this->object = object;
	};

	void setNext (Cell<T>* next) {
		this->next = next;
	}

	Cell<T>* getNext () {
		return this->next;
	}

	void setPrevious (Cell<T>* previous) {
		this->previous = previous;
	}

	Cell<T>* getPrevious () {
		return this->previous;
	}

	void setObject (T object) {
		this->object = object;
	}

	T getObject () {
		return this->object;
	}

};

