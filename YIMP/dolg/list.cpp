#include <iostream>
#include <map>

struct Node {
	int data;
	Node* next;
};

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
	int findMin();
	int findMax();
	void delNodeWith(int el);
	void delNodesWith(int el);
	void updateNode(int el, int newEl);
	int uniqueCount();

	void printHead();
	void printTail();
};

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
	return !head;
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
			if(!tmpNode->next) {
				delete tmpNode;
				break;
			}
			prevNode = tmpNode;
			tmpNode = tmpNode->next;
		}

		tail = prevNode;
		prevNode->next = NULL;
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
				if (head == tmpNode) {
					head = NULL;
				}
				if (tail == tmpNode) {
					tail = prevNode;
				}
				prevNode->next = tmpNode->next;
				delete tmpNode;
				break;
			}
			prevNode = tmpNode;
			tmpNode = tmpNode->next;

		}
	}
}

void List::delNodesWith(int el) {
	Node* tmpNode = head;
	Node* prevNode = NULL;

	while(tmpNode) {
		if (tmpNode->data == el) {
			if (tmpNode == head) {
				head = head->next;
			}
			if (tmpNode == tail) {
				tail = prevNode;
			}
			delete tmpNode;
		}
		prevNode = tmpNode;
		tmpNode = tmpNode->next;
	}
}

void List::updateNode(int el, int newEl) {
	Node* tmpNode = head;

	while (tmpNode) {
		if (tmpNode->data = el) {
			tmpNode->data = newEl;
		}
		tmpNode = tmpNode->next;
	}
}

int List::uniqueCount() {
	Node* tmpNode = head;
	std::map<int, int> unique;
	std::map<int, int>::iterator it;

	while (tmpNode) {
		it = unique.find(tmpNode->data);
		if (it != unique.end()) {
			unique[tmpNode->data]++;
		}
		else {
			unique[tmpNode->data] = 1;
		}
		tmpNode = tmpNode->next;
	}

	return (int)unique.size();
}

void List::printHead() {
	std::cout << "HEAD data: " << head->data << std::endl;
	std::cout << "HEAD next: " << head->next << std::endl;
}

void List::printTail() {
	std::cout << "TAIL data: " << tail->data << std::endl;
	std::cout << "TAIL next: " << tail->next << std::endl;
}
/*
	void addToFront(int el);
	void addToBack(int el);
	void printNodes();
	void delNodes();
	int countNodes();
	bool isEmpty();
	void delFirst();
	void delLast();
	int searchEl(int el);
	int findMin();
	int findMax();
	void delNodeWith(int el);
	void delNodesWith(int el);
	void updateNode(int el, int newEl);
	int uniqueCount();

	void printHead();
	void printTail();
*/

List list;

void printOptions() {
	std::cout << "1.addToFront()\n2.addToBack()\n3.printNodes()\n";
	std::cout << "4.delNodes()\n5.countNodes()\n6.isEmpty()\n";
	std::cout << "7.delFirst()\n8.delLast()\n9.searchEl()\n";
	std::cout << "10.findMin()\n11.findMax()\n12.delNodeWith()\n";
	std::cout << "13.delNodesWith()\n14.updateNode()\n15.uniqueCount()\n";
	std::cout << "16.printHead()\n17.printTail()\n"
	std::cout << "18 -> EXIT\n\n";
}

void interactiveTest() {
	int foo, bar, kar;

	printOptions();
	std::cin >> foo;

	while(foo != 18) {
		switch(foo) {
			case 1:
				std::cin >> bar;
				list.addToFront(bar);
			break;

			case 2:
				std::cin >> bar;
				list.addToFront(bar);
			break;

			case 3:
				list.printNodes();
			break;

			case 4:
				list.delNodes();
			break;

			case 5:
				std::cout << "countNodes returned: " << list.countNodes() << std::endl;
			break;

			case 6:
				std::cout << "isEmpty returned: " << list.isEmpty() << std::endl;
			break;

			case 7:
				list.delFirst();
			break;

			case 8:
				list.delLast();
			break;

			case 9:
				std::cin >> bar;
				std::cout << "searchEl returned: " << list.searchEl(bar) << std::endl;
			break;

			case 10:
				std::cout << "findMin returned: " << list.findMin() << std::endl;
			break;

			case 11:
				std::cout << "findMax returned: " << list.findMax() << std::endl;
			break;

			case 12:
				std::cin >> bar;
				list.delNodeWith(bar);
			break;

			case 13:
				std::cin >> bar;
				list.delNodesWith(bar);
			break;

			case 14:
				std::cin >> bar;
				std::cin >> kar;
				list.updateNode(bar, kar);
			break;

			case 15:
				std::cout << "uniqueCount returned: " << list.uniqueCount() << std::endl;
			break;

			case 16:
				list.printHead();
			break;

			case 17:
				list.printTail();
			break;
		}

		printOptions();
		cin >> foo;
	}
}

int main() {

	interactiveTest();

	return 0;
}
