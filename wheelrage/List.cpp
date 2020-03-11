#include "List.h"

template <class T>
List<T>::List() {
	this->first = nullptr;
	this->last = nullptr;
	this->length = 0;
}

template <class T>
bool isEmpty() {
	return (this->first == nullptr);
}

template <class T>
int List<T>::size() {
	return this->length;
}

template <class T>
void List<T>::push(T object) {

	Cell<T>* newCell = new Cell<T>();
	newCell->setObject(object);

	if (this->isEmpty()) {

		this->first = newCell;
		this->last = newCell;

	} else {

		newCell->setPrevious(this->last);
		this->last->setNext(newCell);
		this->last = newCell;

	}

	this->length++;

}

template <class T>
T List<T>::get(int index) {

	if (index < 0 || index >= this->length) throw "Index provided is invalid.";

	Cell<T>* f;

	if (index < this->length / 2) {

		f = this->first;
		for (size_t i = 0; i < index; i++) f = f->getNext();

	} else {

		f = this->last;
		for (size_t i = this->length - 1; i > index; i--) f = f->getPrevious();

	}

	return f->getObject();

}

template <class T>
void List<T>::remove(int index) {

	if (index < 0 || index >= this->length) throw "Index provided is invalid.";

	Cell<T>* aux;

	if (index == 0) {

		aux = this->first;

		if (this->length == 1) {
			this->first = nullptr;
			delete aux;
			this->length--;
			return;
		}

		this->first = this->first->getNext();
		delete aux;
		this->length--;
		return;

	}

	if (index == (this->length - 1)) {

		aux = this->last;

		this->last->getPrevious()->setNext(nullptr);
		this->last = this->last->getPrevious();
		delete aux;
		this->length--;
		return;

	}

	if (index < this->length / 2) {

		aux = this->first;
		for (size_t i = 0; i < index; i++) aux = aux->getNext();

	} else {

		aux = this->last;
		for (size_t i = this->length - 1; i > index; i--) aux = aux->getPrevious();

	}

	aux->getPrevious()->setNext(aux->getNext());
	aux->getNext()->setPrevious(aux->getPrevious());

	delete aux;
	this->length--;
	return;

}