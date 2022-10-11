#include <iostream>
#define _SIZE 5;

using namespace std;

class Stack {

	int top = -1;
	int size = _SIZE;
	int* buffer = new int[size];

	bool full();

public:

	Stack() = default;
	Stack(const Stack&);
	bool empty() const;
	bool pop();
	int fsize() const;
	int ftop() const;
	bool push(int);
	Stack& operator=(const Stack&);
	void Swap(Stack&);
	~Stack();
};

Stack::Stack(const Stack& right) : top(right.top), size(right.size), buffer(new int[size]) {
	for (int i = 0; i <= top; i++)
		buffer[i] = right.buffer[i];
}

bool Stack::full() {
	return top == size - 1;
}

bool Stack::empty() const {
	return top == -1;
}

bool Stack::pop() {
	if (empty()) return false;
	top--;
	return true;
}

int Stack::fsize() const {
	return top + 1;
}

int Stack::ftop() const {
	if (empty()) exit(1);
	return buffer[top];
}

bool Stack::push(int element) {
	if (full()) {
		int* new_buffer = new int[size * 2];
		if (!new_buffer)
			return false;
		for (int i = 0; i <= top; i++)
			new_buffer[i] = buffer[i];
		size = size * 2;
		delete[] buffer;
		buffer = new_buffer;
	}
	buffer[++top] = element;
	return true;
}

Stack& Stack::operator=(const Stack& right) {
	if (this != &right) {
		buffer = new int[right.size];
		for (int i = 0; i <= right.top; i++)
			buffer[i] = right.buffer[i];
		top = right.top;
	}
	return *this;
}

Stack::~Stack() {
	delete[] buffer;
}

void Stack::Swap(Stack& stack) {
	Stack tmp = stack;
	stack = *this;
	*this = tmp;
}

int main()
{
	Stack St;
	St.push(12);
	St.push(23);
	St.push(34);
	cout << St.ftop() << ' ' << St.fsize() << endl;

	Stack St2;
	St2.push(89);
	St2.push(78);
	cout << St2.ftop() << ' ' << St2.fsize() << endl;

	St.Swap(St2);
	cout << St.ftop() << ' ' << St.fsize() << endl;
	cout << St2.ftop() << ' ' << St2.fsize() << endl;

}