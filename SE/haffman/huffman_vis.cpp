/*TODO:
*1. Fix binary tree recursion exit condition
*2. Get rid of unused stuff
*3. DFS
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <functional>
#include <cctype>
#include <queue>
#include <new>
#include <string>
using namespace std;

class btNode;
class Compare;
typedef priority_queue<pair<char, int>, vector<pair<char,int>>, Compare>* QUEUE_PTR;
typedef priority_queue<pair<char, int>, vector<pair<char,int>>, Compare> QUEUE;
typedef map<char,int>::const_iterator ITER;

class Compare {
public:
  bool operator()(pair<int,char> n1, pair<int,char> n2) {
    return n1.second < n2.second;
  }
};

class btNode {
public:
  btNode();
  btNode* left;
  btNode* right;
  string* sequence;
};

btNode::btNode() {
  sequence = new string[1];
}

void get_from_queue(QUEUE queue, vector<pair<char,int>>* vec_ptr) {
  cout << "Getting pairs from queue..." << endl;
  while(!(queue.empty())) {
    pair<char,int> tmpPair;
    tmpPair = queue.top();
    vec_ptr->push_back(tmpPair);
    cout << "Got: " << tmpPair.first << " " << tmpPair.second << endl;
    queue.pop();
  }
  cout << endl;
}

btNode* construct_tree(vector<pair<char,int>> vec, bool right) {
  static int v = 0;
  static int count = 0;
  if(count != ((vec.size() * 2) - 1)) {
    btNode* parentNode = new btNode;
    count++;

    pair<char,int> tmpPair;
    if(right) {
      parentNode->sequence[0] = "";
      if(v + 1 < vec.size()) {
        for(int i = v; i < vec.size(); i++) {
          tmpPair = vec[i];
          parentNode->sequence[0] += tmpPair.first;
        }
      }
      parentNode->left = construct_tree(vec, false);
      parentNode->right = construct_tree(vec, true);
      return parentNode;
    }
    else {
      parentNode->sequence[0] = vec[v++].first;
      parentNode->left = NULL;
      parentNode->right = NULL;
      return parentNode;
    }
  }
}

void make_queue(QUEUE_PTR ptr, map<char,int> mapex) {
  cout << "Making priority queue..." << endl;
  for(ITER iter = mapex.begin(); iter != mapex.end(); iter++) {
    pair<char,int> tmpPair;
    tmpPair.first = iter->first;
    tmpPair.second = iter->second;
    ptr->push(tmpPair);
    cout << "Pushed pair<" << tmpPair.first << "," << tmpPair.second << "> to ";
    cout << "queue!" << endl;
  }
  int qsize = ptr->size();
  cout << "Queue size: " << qsize << endl << endl;
}

void show_queue(QUEUE_PTR ptr) {
  int count = 1;
  cout << "Printing queue..." << endl;
  while(!(ptr->empty())) {
    pair<char,int> tmpPair = ptr->top();
    cout << count << ". " << tmpPair.first << " " << tmpPair.second << endl;
    ptr->pop();
    count++;
  }
}

void show_tree(btNode* node) {
  static int n = 1;
  cout << "====Showing Right Node №" << n << endl;
  cout << "Sequence: " << node->sequence[0] << endl;

  if(node->left) {
    btNode* lnode = node->left;
    cout << "Left child's ";
    cout << "sequence: " << lnode->sequence[0] << endl;
    n++;
  }
  if(node->right) {show_tree(node->right);}
}

//Выводит символ и сколько раз он встречается
void show_map(map<char,int> mapex) {
  cout << "Printing map..." << endl;
  for(ITER iter = mapex.begin(); iter != mapex.end(); iter++) {
    cout << iter->first << " " << iter->second;
    cout << endl;
  }
  cout << endl;
}

int main() {
  FILE* fd = fopen("input.txt", "r");
  FILE* fd_out = fopen("output.txt", "w");
  fseek(fd, 0, SEEK_END);
  int fsize = ftell(fd);
  char* buffer = new char[fsize + 1];

  fseek(fd, 0, SEEK_SET);
  fread(buffer, 1, fsize, fd);

  map<char,int> occur;
  for(int i = 0; i < fsize + 1; i++) {

    auto it = occur.find(buffer[i]);

    if(it != occur.end()) {
      occur[buffer[i]]++;
    }

    else {
      if(isalpha(buffer[i])) {occur[buffer[i]] = 1;}
    }
  }

  show_map(occur);
  QUEUE queue;
  make_queue(&queue, occur);

  vector<pair<char,int>> queue_vec;
  get_from_queue(queue, &queue_vec);

  btNode* fNodeptr = construct_tree(queue_vec, true);
  show_tree(fNodeptr);
  //show_queue(&queue);
  fclose(fd);
  fclose(fd_out);
  return 0;
}
