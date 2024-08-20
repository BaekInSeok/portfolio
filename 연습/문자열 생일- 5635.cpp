#include <iostream>

struct Human
{
	std::string name = "";
	int day = 0;
	int month = 0;
	int year = 0;
};

int main() {

	int n = 0;
	std::cin >> n;

	struct Human hu[n];
	Human old = { "", 0, 0, 2010 };
	Human young = { "", 0, 0, 1990 };

	for (int i = 0; i < n; i++) {
		std::cin >> hu[i].name >> hu[i].day >> hu[i].month >> hu[i].year;
		//나이적은
		if (young.year < hu[i].year) {
			young = hu[i];
		}
		else if (young.year == hu[i].year) {
			if (young.month < hu[i].month)young = hu[i];
			else if (young.month == hu[i].month) {
				if (young.day < hu[i].day)young = hu[i];
			}
		}
		//나이많은
		if (old.year > hu[i].year) {
			old = hu[i];
		}
		else if (old.year == hu[i].year) {
			if (old.month > hu[i].month)old = hu[i];
			else if (old.month == hu[i].month) {
				if (old.day > hu[i].day)old = hu[i];
			}
		}
	}
	std::cout << young.name << std::endl << old.name;
	return 0;
}