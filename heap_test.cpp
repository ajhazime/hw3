#include <iostream>
#include "heap.h"


#include<vector>
#include<string>

using namespace std;

struct Greater {
	bool operator()(int a, int b) const {
		return a > b;
	}
};

int main()
{
	cout << "comparator" << endl;

	Heap<int> minheaptest;

	minheaptest.push(5);
	minheaptest.push(4);
	minheaptest.push(7);
	minheaptest.push(9);
	minheaptest.push(57);


	cout << "size() :" << minheaptest.size()<< '\n';
	cout <<"\n\ntop()\nExpected: 4\n Actual: " << minheaptest.top() << "\n\n\n";

	cout << "POPPING ELEMENTS" <<endl;

	while(!minheaptest.empty()){
		cout << minheaptest.top()<< ", " << '\n';
		minheaptest.pop();
	}

	cout << "Head after popping: " << minheaptest.empty() << endl;

	cout << "\n==============\nMax Heap test\n===============\n";

	Heap<int, Greater> maxheaptest;

	vector<int> nums = {12,10,13,20,4,2,3,14};

	cout <<"pushing: \n";
	for(int n : nums){
		maxheaptest.push(n);
	}

	cout << "Popping elements: " << endl;
	while(!maxheaptest.empty()) {
		maxheaptest.pop();
	}

	cout << "\n\n==========\nTEST on empty lists\n========\n\n";
		try {
			minheaptest.top();
		}catch(const underflow_error &e){
			cout <<"Catch: top()" <<'\n';
		}




	return 0;
}