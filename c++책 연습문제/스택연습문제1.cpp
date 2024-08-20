//실수가  저장된 스택에서 가장작은 값을 찾아 출력
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<double> myStack;
	myStack.push(3.14);
	myStack.push(2.71);
	myStack.push(4.98);
	myStack.push(12.23);
	double a = myStack.top();

		while (!myStack.empty()) {
			if (myStack.top() <= a) a = myStack.top();
			myStack.pop();
		}
	cout << a << endl;
	return 0;
}