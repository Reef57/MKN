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

class compare;
class btNode;

typedef map<char,int> MAP;
typedef priority_queue<pair<char, int>, vector<pair<char,int>>, compare> QUEUE;
typedef map<char,int>::const_iterator MAP_ITER;
typedef vector<pair<char,int>> VECTOR;

class compare {
public:
  bool operator()(pair<int,char> n1, pair<int,char> n2) {
    return n1.second > n2.second;
  }
};

class btNode {
public:
  btNode();
  btNode* left;
  btNode* right;

  string* sequence;
  int val;
};

btNode::btNode() {
  sequence = new string[1];
  val = 0;
  left = NULL;
  right = NULL;
}

btNode* construct_tree(VECTOR vec) {
  int index = 0;
  pair<char,int> tmppair1, tmppair2;
  btNode* lnode = new btNode;
  btNode* rnode = new btNode;

  tmppair1 = vec[index++];
  tmppair2 = vec[index++];

  if(tmppair1.second < tmppair2.second) {
  	lnode->sequence[0] = tmppair1.first;
  	lnode->val = tmppair1.second;
  	rnode->sequence[0] = tmppair2.first;
  	rnode->val = tmppair2.second;
  } else {
  	lnode->sequence[0] = tmppair2.first;
  	lnode->val = tmppair2.second;
  	rnode->sequence[0] = tmppair1.first;
  	rnode->sequence[0] = tmppair1.second;
  }

  btNode* centralNode = new btNode;
  centralNode->left = lnode;
  centralNode->right = rnode;
  centralNode->val = lnode->val + rnode->val;
  centralNode->sequence[0] = lnode->sequence[0] + rnode->sequence[0];

  while(index < vec.size()) {
  	btNode* node = new btNode;
  	pair<char, int> tmppair;
  	tmppair = vec[index++];
  	node->sequence[0] = tmppair.first;
  	node->val = tmppair.second;

  	btNode* finalNode = new btNode;

  	if(centralNode->val < node->val) {
  		finalNode->left = centralNode;
  		finalNode->right = node;
  	} else {
  		finalNode->left = node;
  		finalNode->right = centralNode;
  	}

  	finalNode->val = centralNode->val + node->val;
  	centralNode->sequence[0].length() > node->sequence[0].length() ? finalNode->sequence[0] = node->sequence[0] + centralNode->sequence[0] : finalNode->sequence[0] = centralNode->sequence[0] + node->sequence[0];

  	centralNode = finalNode;
  }

  return centralNode;
}

void print_tree(btNode* head) {
	static int nodeCount = 1;
	cout << "Node #" << nodeCount << endl;
	cout << "sequence = " << head->sequence[0] << endl;
	cout << "val = " << head->val << endl;
	cout << "left = " << head->left << endl;
	cout << "right = " <<  head->right << endl;
	cout << "----------------------------------" << endl;

	nodeCount++;

	if(head->left) {
		print_tree(head->left);
	}
	if(head->right) {
		print_tree(head->right);
	}
}

string answer = "";
int search_tree(char c, btNode* node) {
	cout << "Looking for " << c << endl;
	btNode* lnode = node->left;
	btNode* rnode = node->right;

	bool isleft = false;
	lnode->sequence[0].length() == 1 ? isleft = true : isleft = false;

	if(isleft) {
		cout << "Checking left" << endl;
		if(c == lnode->sequence[0][0]) {
			answer += "0";
			int kostil = stoi(answer);
			cout << "Code for " << c << " is: " << answer << endl;
			return kostil;
		}

		answer += "1";
		if(rnode->sequence[0].length() == 1) {
			if(c == rnode->sequence[0][0]) {
				int kostil = stoi(answer);
				return kostil;
			}
		}
		if(rnode) {
			search_tree(c, rnode);
		}

	} else {
		cout << "Checking right" << endl;
		if(c == rnode->sequence[0][0]) {
			answer += "1";
			int kostil = stoi(answer);
			cout << "Code for " << c << " is: " << answer << endl;
			return kostil;
		}

		answer += "0";
		if(lnode->sequence[0].length() == 1) {
			if(c == lnode->sequence[0][0]) {
				int kostil = stoi(answer);
				return kostil;
			}
		}
		if(lnode) {
			search_tree(c, lnode);
		}
	}
}

void make_queue(QUEUE queue, MAP map, VECTOR* vec_ptr) {
  cout << "Making priority queue..." << endl;
  for(MAP_ITER iter = map.begin(); iter != map.end(); iter++) {
    pair<char,int> tmpPair;
    tmpPair.first = iter->first;
    tmpPair.second = iter->second;

    queue.push(tmpPair);
    cout << "Pushed pair<" << tmpPair.first << "," << tmpPair.second << "> to ";
    cout << "queue!" << endl;
  }

  int qsize = queue.size();
  cout << "Queue size: " << qsize << endl << endl;

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

int main() {
  FILE* fd = fopen("input.txt", "r");
  FILE* fd_out = fopen("output.txt", "w");

  fseek(fd, 0, SEEK_END);
  int fsize = ftell(fd);

  char* buffer = new char[fsize + 1];

  fseek(fd, 0, SEEK_SET);
  fread(buffer, 1, fsize, fd);

  MAP occur;
  for(int i = 0; i < fsize + 1; i++) {

  auto it = occur.find(buffer[i]);

  if(it != occur.end()) {
    occur[buffer[i]]++;
  }

  else {
    if(isalpha(buffer[i])) {occur[buffer[i]] = 1;}
  }
  }

  QUEUE queue;
  VECTOR vec;
  make_queue(queue, occur, &vec);

  for(int i = 0; i < vec.size(); i++) {
  	pair<char, int> tmpPair = vec[i];
  	cout << "vec[" << i << "].first = " << tmpPair.first << endl;
  	cout << "vec[" << i << "].second = " << tmpPair.second << endl;
  	cout << "---------------------------------------------------\n";
  }

  auto head = construct_tree(vec);
  print_tree(head);

  cout << "head->sequence[0][0] = " << head->sequence[0][0] << endl;

  string encoded = "";
  for(int i = 0; i < fsize + 1; i++) {
  	if(isalpha(buffer[i])) {
  		int tmp = search_tree(buffer[i], head);
  		string stmp = to_string(tmp);
  		answer = "";
  		encoded += stmp;
  	}
  	else {
  		encoded += buffer[i];
  	}
  }

  cout << "encoded : " << encoded << endl;

  fclose(fd);
  fclose(fd_out);
  return 0;
}
