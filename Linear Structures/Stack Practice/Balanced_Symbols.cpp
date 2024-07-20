#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool matches(char open, char close){
    /*
    Matches open and close by index value.
     */
    string opens = "([{";
    string closes = ")]}";
    return opens.find(open) == closes.find(close);
}

bool inString(char c, string s){
    /*
    Checks if char c is in string s
    */
    return s.find(c) != string::npos;
}

bool parChecker(string str){
    /*
    Given a string of paenthesis, check for balance;
    type: str:strng
    rtype: bool
     */

    stack<char> s;
    int index = 0;
    bool balanced = true;
    string opens = "([{";
    string closes = ")]}";

    while (index < str.length() && balanced){
        char current_char = str[index];
        if (inString(current_char, closes)){
            if (s.empty()){
                balanced = false;
            } else if (matches(s.top(), current_char)){
                s.pop();
            } else {
                balanced = false;
            }
        } else {
            if (index > 0 && s.empty()){
                balanced = false;
            } else if (inString(current_char, opens)){
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
      cout << parChecker("{}") << endl;
      cout << parChecker("[{()}]") << endl;
      return 0;
  }