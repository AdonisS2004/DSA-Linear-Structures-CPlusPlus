#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool palchecker(string str){
    /*Given string str, return True if it is a palindrome.*/
    deque<char> pal;
    bool isPal = true;

    for(char c:str){
        pal.push_back(c);
    }

    while(pal.size() >= 2 && isPal){
        char left = pal.front();
        pal.pop_front();
        char right = pal.back();
        pal.pop_back();
        if (left != right){
            isPal = false;
        }
    }

    return isPal;
}

int main(){
    cout << palchecker("lsdkjfskf") << endl;
    cout << palchecker("radar") << endl;
}