//converts a decimal number into desired base 1-16.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string baseConverter(int decNumber, int base){
    /*
    Converts any decicmal number to the value of desired base
    Note: decimal = base 10; binary = base 2
    */

    /*
    perform integer division for next whole number
    perform remainder division for remainders
    Push remainders to a stack
    continuously divide the values until integer division = 0
    build string with stack by popping elements and constructing in that order
    */


    string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    stack<int> remainders;
    int remainder;
    string res;

   while (decNumber > 0){
    remainder = decNumber % base;
    remainders.push(remainder);
    decNumber = decNumber / base;
   }

   while (!(remainders.empty())){
    int index = remainders.top();
    remainders.pop();
    res.append(digits[index]);
   }

   return res;
}

int main() {
  int mynum = 25;
  cout << baseConverter(mynum, 8) << endl;
  cout << baseConverter(mynum, 16) << endl;
  cout << baseConverter(256, 16) << endl;
  cout << baseConverter(26, 26) << endl;
  return 0;
}