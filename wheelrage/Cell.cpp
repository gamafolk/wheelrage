#include "Cell.h"

template <class T>
Cell<T>::Cell() { }

template <class T>
Cell<T>::Cell(Cell<T>* next, Cell<T>* previous, T object) {
	this->next = next;
	this->previous = previous;
	this->object = object;
};

template <class T>
void Cell<T>::setNext(Cell<T>* next) {
	this->next = next;
}

template <class T>
Cell<T>* Cell<T>::getNext() {
	return this->next;
}

template <class T>
void Cell<T>::setPrevious(Cell<T>* previous) {
	this->previous = previous;
}

template <class T>
Cell<T>* Cell<T>::getPrevious() {
	return this->previous;
}

template <class T>
void Cell<T>::setObject(T object) {
	this->object = object;
}

template <class T>
T Cell<T>::getObject() {
	return this->object;
}