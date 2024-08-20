//벡터에서 홀수만 제거하고 짝수만 남은 벡터를 출력하는 코드


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> numbers = { 2, 7, 1, 8, 3, 6, 4, 5, 9 };

	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if ((*it % 2) != 0) cout << *it << endl;
	}

	return 0;
}

