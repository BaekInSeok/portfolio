//정수로구성된 벡터가 주어졌을때 사용자에게 입력받은숫자가 벡터에 포함되어있는지 출력
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> numbers = { 3, 8, 1, 6, 2, 7, 5, 4, 9 };

	int userInput;

	cout << "찾고자 하는 숫자를 입력하세요: ";
	cin >> userInput;

	vector<int>::iterator it = find(numbers.begin(), numbers.end(), userInput);
	if (it != numbers.end()) {
		cout << *it << endl;
	}
	else {
		cout << "없음" << endl;
	}

	return 0;
}