#pragma once

template <class T>
class MyList {
public:

	size_t get_size() noexcept;

	T& operator[] (const size_t) noexcept;

	void instToTail(T&) noexcept;

	void destroyItemByIndex(const size_t) noexcept;

private:

  template<class U>
	struct Node {
		Node(U data = U(), Node<U>* prev = nullptr, Node<U>* next = nullptr) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
		U data = U();
		Node<U>* prev;
		Node<U>* next;
	};

	size_t size = 0;

	Node<T>* head = nullptr;

	Node<T>* tail = nullptr;
};


template<class T>
inline size_t MyList<T>::get_size() noexcept {
	return this->size;
}

template<class T>
T& MyList<T>::operator[](const size_t index) noexcept {
	Node<T>* tmp = this->head;
	for (size_t ii = 0; tmp != nullptr; ++ii, tmp = tmp->next) {
		if (ii == index)
			return tmp->data;
	}
}

template<class T>
void MyList<T>::instToTail(T& node) noexcept {
	if (this->head == nullptr) {
		head = tail = new Node<T>(node);
	} else {
		tail->next = new Node<T>(node);
		tail->next->prev = tail;
		tail = tail->next;
	}
	++size;
}

template<class T>
void MyList<T>::destroyItemByIndex(const size_t index) noexcept { // хз работает ли???
	auto item = this->operator[](index);
	auto _next = item->next;
	auto _prev = item->prev;
	if (_prev != nullptr) {
		item->prev->next = _next;
	}
	if (_next != nullptr) {
		item->next->prev = _prev;
	}
	free(item);
	--size;
}
