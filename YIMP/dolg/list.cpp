#include <iostream>

struct Node {
	int data;
	Node* next;
}

class List {
private:
	Node* head, *tail;
public:
	List();
	void addToFront(int el);
	void addToBack(int el);
	void printNodes();
	void delNodes();
	int countNodes();
	bool isEmpty();
	void delFirst();
	void delLast();
	int searchEl(int el);
	int FindMin();
	int FindMax();
	void delNodeWith(int el);
}

List::List() {
	head = NULL;
	tail = NULL;
}

void List::addToFront(int el) {
	Node* tmpNode = new Node;
	tmpNode->data = el;
	tmpNode->next = head;
	head = tmpNode;
}

void List::addToBack(int el) {
	Node* tmpNode = new Node;
	tmpNode->data = el;
	tmpNode->next = NULL;

	if(!head) {
		head = tmpNode;
		tail = tmpNode;
		tmpNode = NULL;
	} 

	else {
		tail->next = tmpNode;
		tail = tmpNode;
	}
}

void List::printNodes() {
	Node* tmpNode = head;

	while(tmpNode) {
		std::cout << tmpNode->data << " ";
		tmpNode = tmpNode->next;
	}
	std::cout << std::endl;
}

void List::delNodes() {
	Node* curNode = head;
	Node* nextNode;

	while(curNode) {
		nextNode = curNode->next;
		delete curNode;
		curNode = nextNode;
	}

	head = NULL;

}

int List::countNodes() {
	Node* tmpNode = head;
	int count = 0;

	while(tmpNode) {
		count++;
		tmpNode = tmpNode->next;
	}

	return count;
}

bool List::isEmpty() {
	return head;
}

void List::delFirst() {
	if(head) {
		Node* tmpNode = head;
		head = head->next;
		delete tmpNode;
	}
}

void List::delLast() {
	if(head) {
		Node* tmpNode = head;
		Node* prevNode;

		while(tmpNode) {
			prevNode = tmpNode;
			if(!tmpNode->next) {
				delete tmpNode;
			}
			tmpNode = tmpNode->next;
		}

		tail = prevNode;
		prevNode = NULL;
	}
}

int List::searchEl(int el) {
	Node* tmpNode = head;
	int index = 0;
	
	while(tmpNode) {
		if(tmpNode->data == el) {
			return el;
		}

		tmpNode = tmpNode->next;
		index++;
	}

	return -1;
}

int List::findMin() {
	if(head) {
		Node* tmpNode = head;
		int min = tmpNode->data;

		while(tmpNode) {
			if(min > tmpNode->data) {
				min = tmpNode->data;
			}
			tmpNode = tmpNode->next;
		}

		return min;
	}
}

int List::findMax() {
	if(head) {
		Node* tmpNode = head;
		int max = tmpNode->data;

		while(tmpNode) {
			if(max < tmpNode->data) {
				max = tmpNode->data;
			}
			tmpNode = tmpNode->next;
		}

		return max;
	}
}

void List::delNodeWith(int el) {
	if(head) {
		Node* tmpNode = head;
		Node* prevNode;

		while(tmpNode) {
			if(tmpNode->data == el) {
				prevNode->next = tmpNode->next;
				delete tmpNode;
				break;
			}

		}
	}
}
