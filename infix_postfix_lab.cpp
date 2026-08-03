#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Code by Ettisaf Rup

// Main Stack
char arr[100] = {};
int stp = -1;

void push(char x)
{
    arr[++stp] = x;
}

char pop()
{
    return arr[stp--];
}

char top()
{
    return arr[stp];
}

int isEmpty()
{
    if (stp == -1)
        return 1;
    else
        return 0;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string clean_expression(string x)
{
    string clean_string = "";

    for (int i = 0; i < x.length(); i++)
    {
        char c = x[i];

        if (c == ',' || c == ' ')
        {
            clean_string += "";
        }

        else
        {
            while (!isEmpty())
            {
                clean_string += top();
                pop();
            }
            clean_string += c;
        }
    }

    return clean_string;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ',' || c == ' ')
            postfix += "";
        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            push('(');

        else if (c == ')')
        {

            while (top() != '(')
            {
                postfix += top();
                pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(c) <= precedence(top()))
            {
                postfix += top();
                pop();
            }
            push(c);
        }
    }

    while (!isEmpty())
    {
        postfix += top();
        pop();
    }

    return postfix;
}

int main()
{
    string infix = "A+(B*C),,, *C ,, , ,, +A";
    cout << "Infix Expression: " << infix << endl;

    string cleanExp = clean_expression(infix);

    cout << "Clean: " << cleanExp << endl;

    cout << "Postfix Expression: " << infixToPostfix(cleanExp) << endl;
    return 0;
}
