
#pragma once
#include <iostream>
#include"Cell.h"

using namespace std;

template<class T> class List {

private:
	Cell<T>* first;
	Cell<T>* last;
	int length;

	bool isEmpt() {
		return (this->first == nullptr);
	}

public:

	List() {
		this->first = nullptr;
		this->last = nullptr;
		this->length = 0;
	}

	int size() {
		return this->length;
	}

	void push(T object) {

		Cell<T>* newCell = new Cell<T>();
		newCell->setObject(object);

		if (this->isEmpt()) {

			this->first = newCell;
			this->last = newCell;

		} else {

			newCell->setPrevious(this->last);
			this->last->setNext(newCell);
			this->last = newCell;

		}

		this->length++;

	}

	T get(int index) {

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

	void remove(int index) {

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


};

