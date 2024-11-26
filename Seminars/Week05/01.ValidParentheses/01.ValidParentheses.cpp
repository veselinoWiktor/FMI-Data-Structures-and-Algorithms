#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
	std::stack<char> stack;

	for (auto curBrace : s) {
		if (curBrace == '(' || curBrace == '{' || curBrace == '[') {
			stack.push(curBrace);
		}

		else {
			if (stack.empty()) return false;

			char innerMostOpeningBrace = stack.top();
			stack.pop();

			if (curBrace == ')' && innerMostOpeningBrace != '(') return false;
			if (curBrace == '}' && innerMostOpeningBrace != '{') return false;
			if (curBrace == ']' && innerMostOpeningBrace != '[') return false;
		}
	}

	if (!stack.empty()) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	std::cout << isValid("()");
}