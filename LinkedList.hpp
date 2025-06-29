#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <optional>

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& val) : data(val), next(nullptr) {}
	};

	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList() {
		clear();
	}
	void pushHead(const T& val) {
		Node* node = new Node(val);
		node->next = head;
		head = node;
		if (tail == nullptr) tail = head;
	}

	void pushTail(const T& val) {
		Node* node = new Node(val);
		if (tail == nullptr)
			head = tail = node;
		tail-next = node;
		tail = node;
	}
	std::optional<T> popTail() {
		if (head == nullptr)
			return std::nullopt;

		T popData = tail->data;
		if (head == tail) {
			delete tail;
			head = tail = nullptr;
			return popData;
		}
		Node* node = head;
		while (node->next != tail) {
			node = node->next;
		}
		delete tail;
		tail = node;
		tail->next = nullptr;
		return popData;
	}
	std::optional<T> popHead() {
		if (head == nullptr)
			return std::nullopt;
		T popData = head->data;
		Node* temp = head->next;
		delete head;
		head = temp;
		if (head == nullptr)
			tail = nullptr;
		return popData;
	}
	bool isEmpty() const {
		return head == nullptr;
	}
	size_t getLength() const {
		size_t length = 0;
		if (isEmpty()) return length;
		Node* node = head;
		while (node != nullptr) {
			node = node->next;
			length++;
		}
		return length;
	}
	void clear() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}
};


#endif
