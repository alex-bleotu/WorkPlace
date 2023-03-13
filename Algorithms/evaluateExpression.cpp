#include <iostream>
#include <stack>

using namespace std;

int precedence(char operation) {
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;
    return 0;
}

int makeOperation(int a, int b, char operation) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evaluate(string expression) {
    stack<int> values;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;
        else if (expression[i] == '(')
            operators.push(expression[i]);
        else if (isdigit(expression[i])) {
            int value = 0;

            while (i < expression.length() && isdigit(expression[i]))
                value = value * 10 + (expression[i++] - '0');

            values.push(value);
            i--;
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int firstNumber = values.top();
                values.pop();
                int secondNumber = values.top();
                values.pop();

                char operation = operators.top();
                operators.pop();

                values.push(makeOperation(secondNumber, firstNumber, operation));
            }

            if (!operators.empty())
                operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int firstNumber = values.top();
                values.pop();
                int secondNumber = values.top();
                values.pop();

                char operation = operators.top();
                operators.pop();

                values.push(makeOperation(secondNumber, firstNumber, operation));
            }

            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int firstNumber = values.top();
        values.pop();
        int secondNumber = values.top();
        values.pop();

        char operation = operators.top();
        operators.pop();

        values.push(makeOperation(secondNumber, firstNumber, operation));
    }

    return values.top();
}

int main() {
    cout << evaluate("100 + 10 * (5 + 10 * 2) - 10");
}