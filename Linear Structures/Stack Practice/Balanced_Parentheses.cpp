// program checks for missing parenthesis

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool parChecker(string str){
    /*
    Given a string of paenthesis, check for balance;
    type: str:strng
    rtype: bool
     */

    stack<char> s;
    int index = 0;
    bool balanced = true;

    while (index < str.length() && balanced){
        char current_char = str[index];
        if (current_char == ')'){
            if (s.empty()){
                balanced = false;
            } else {
                s.pop();
            }
        } else {
            if (index > 0 && s.empty()){
                balanced = false;
            } else{
                s.push(current_char);
            }
        }
        index++;
    }
    if (balanced && s.empty()){
        return true;
    }
    return false;
}

int main() {
    cout << parChecker("((()))") << endl;
    cout << parChecker("(()") << endl;
    cout << parChecker("()()") << endl;
}