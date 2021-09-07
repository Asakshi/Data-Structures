// Infix To Postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<stack>

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string infixToPostfix(std::string expression) {
    std::string result = "";
    std::stack<int> s;
    for (int i = 0; i < expression.length(); i++) {
        int x = expression[i];

        if ((x >= 'a' && x <= 'z') || (x <= 'A' && x >= 'Z') || (x >= 0 && x <= 9)) {
            result += x;
        }
        else if (x == '(') {
            s.push(x);
        }
        else if (x == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && (prec(x) <= prec(s.top())) && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.push(x);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main()
{
    std::string expression = "a+b*(c^d-e)^(f+g*h)-i";
    std::string convertedExp = infixToPostfix(expression);
    std::cout << "Infix to postfix of " << expression << " is \n" << convertedExp;
}



/*************** OUTPUT ********************

Infix to postfix of a+b*(c^d-e)^(f+g*h)-i is
abcd^e-fgh*+^*+i-


********************************************/
