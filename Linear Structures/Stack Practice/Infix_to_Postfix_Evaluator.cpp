#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int evalMathHelper(char op, int num1, int num2){
    /*Given op, num1, num2, return the evaluated expression*/
    if (op == '+'){
        return num1 + num2;
    } else if (op == '-'){
        return num1 - num2; 
    } else if (op == '*'){
        return num1 * num2;
    } else if (op == '/'){
        return num1 / num2;
    }

    return 0;
}

string infixToPostfix(string infixexpr){
    /*
    Converts infix expressions to postfix expressions
    Example: ( A + B ) * ( C + D ) -> A B + C D + *
    */

    unordered_map <char,int> precedance;
    precedance['*'] = 3;
    precedance['/'] = 3;
    precedance['+'] = 2;
    precedance['-'] = 2;
    precedance['('] = 1;

    stack<char> operatorStack;
    vector<char> postfixVector;
    string letsnums = "ABDCEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    for(char token:infixexpr){
        if(token == ' '){continue;}
        else if(letsnums.find(token) <= letsnums.length()){
            postfixVector.emplace_back(token);
        }
        else if (token == '('){
            operatorStack.push(token);
        }
        else if (token == ')'){
            char current_elem = operatorStack.top();
            operatorStack.pop();
            while (current_elem != '('){
                postfixVector.emplace_back(current_elem);
                current_elem = operatorStack.top();
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.empty() && precedance[operatorStack.top()] >= precedance[token]){
                postfixVector.emplace_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    while(!operatorStack.empty()){
        postfixVector.emplace_back(operatorStack.top());
        operatorStack.pop();
    }

    string s(postfixVector.begin(), postfixVector.end());

    return s;
}

int postfixEval(string postfixExpr){
    /*
    Takes a postfix expression and evaluates it
    */
    stack<int> mathStack;
    string nums = "0123456789";

    for (char op:postfixExpr){
        if(op == ' '){
            continue;
        }
        else if(nums.find(op) <= nums.length()){
            mathStack.push(int(op) - 48);
        } else {
            int op2 = mathStack.top();
            mathStack.pop();
            int op1 = mathStack.top();
            mathStack.pop();
            int result = evalMathHelper(op, op1, op2);
            mathStack.push(result);
        }
    }

    return mathStack.top();
}

int main() {
    cout <<"infix: A * B + C * D\n" << "postfix: ";
    cout << infixToPostfix("A * B + C * D") << endl;
    cout << "infix: ( A + B ) * C - ( D - E ) * ( F + G )\n" << "postfix: ";
    cout << infixToPostfix("( A + B ) * C - ( D - E ) * ( F + G )") << endl;

    cout << "7 8 + 3 2 + /" << endl;
    cout << postfixEval("7 8 + 3 2 + /") << endl;

    return 0;
}
