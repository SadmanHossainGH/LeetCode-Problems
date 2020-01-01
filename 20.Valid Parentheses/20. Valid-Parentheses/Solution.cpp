/*20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValid(string s);

int main() {
	string input;
	bool valid;

	cout << "Enter a String\n";
	cin >> input;
	
	if (isValid(input) == true) {
		cout << "Input is TRUE \n";
	}
	else {
		cout << "Input is FALSE \n";
	}
	return 0;
}

bool isValid(string s) {
	char round1 = '(';
	char round2 = ')';

	char point1 = '{';
	char point2 = '}';

	char square1 = '[';
	char square2 = ']';

	vector<char> paren;
	bool valid = true;

	for (int i = 0; i < s.length(); ++i) {
		if (s.at(i) == round1 || s.at(i) == point1 || s.at(i) == square1) {
			paren.push_back(s.at(i));
		}
		else {
			if (paren.size() == 0) {
				return false;
			}

			if (s.at(i) == round2) {
				if (paren.back() != round1) {
					return false;
				}
				paren.pop_back();
			}
			else if (s.at(i) == point2) {
				if (paren.back() != point1) {
					return false;
				}
				paren.pop_back();
			}
			else if (s.at(i) == square2) {
				if (paren.back() != square1) {
					return false;
				}
				paren.pop_back();
			}
		}
	}

	if (paren.size() != 0) {
		valid = false;
	}
	return valid;
}