#include <iostream>
#include <new>

/*Stack class
*buffer holds values
*size is a total number of pushed values
*maxsize is the capacity of obj.buffer
*/
template <class T>
class Stack {
  T* buffer;
  int size;
  int maxsize;
  void resize();
public:
  Stack();
  ~Stack();
  void push(T elem);
  T pop();
  bool isempty();
  int getmaxsize();
  int getsize();
};


//Constructor, default obj.buffer size is 10
template<class T> Stack<T>::Stack() {
  buffer = new T[10];
  maxsize = 10;
  size = 0;
}


//Destructor
template<class T> Stack<T>::~Stack() {
  delete[] buffer;
}

//Increases Stack obj.buffer size
template<class T> void Stack<T>::resize() {
  T* newBuffer = new T[maxsize*=2];
  for(int i = 0; i < size; i++) {
    newBuffer[i] = buffer[i];
  }
  delete[] buffer;
  buffer = newBuffer;
}

//Adds element to Stack obj.buffer
template<class T> void Stack<T>::push(T elem) {
  if(size == maxsize) {
    this->resize();
  }
  buffer[size++] = elem;
}


//Returns last element from Stack obj
template<class T> T Stack<T>::pop() {
  if(size != 0) {
    return buffer[--size];
  }
  else return 0;
}

//Returns capacity of the Stack obj
template<class T> int Stack<T>::getmaxsize() {
  return maxsize;
}

//Returns current size of the Stack obj
template<class T> int Stack<T>::getsize() {
  return size;
}

//checks if Stack obj is empty
template<class T> bool Stack<T>::isempty() {
  if(size == 0) {
    return true;
  }
  else {
    return false;
  }
}

//function that pushes N elements into Stack class object
template<class T> void push_test(Stack<T> stack, int N) {
  std::cout << "->Pushing elements..." << std::endl;
  std::cout << "stack.getmaxsize() = " << stack.getmaxsize() << std::endl;

  for(int i = 0; i < N; i++) {
    stack.push(i);
  }
}

//function that pops all elements from Stack class object
template<class T> void pop_test(Stack<T> stack) {
  std::cout << "->Popping elements..." << std::endl;
  while(!stack.isempty()) {
    std::cout << "Popped: " << stack.pop() << std::endl;
  }
}

//To create object of class Stack write:
//Stack<type> name;
//example: Stack<int> istack;
int main() {
  return 0;
}
