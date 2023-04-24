#include <bits/stdc++.h>
#include "LinearStructure.cpp"
using namespace std;

//Problems of LinkedList
void function1()
{

}
//________________________________________________________________
void function2()
{

}
//============================================================================
// Problems of Stack
 void function3()
{

}
//________________________________________________________________
void  Longest_Valid_Parentheses(string & str)
{
    Stack<char> s;
    auto n = str.length();
    for(int i=0;i<n;i++) {
        if(s.isEmpty() or s.Top() == str[i] or (s.Top() == ')' and str[i] == '('))
        {
            s.push(str[i]);
        }
        else
        {
            s.pop();
        }
    }
    cout << n-s.stackSize() << endl;
}
//________________________________________________________________
void function5()
{

}
//============================================================================
// Problems of Queue
void function6()
{

}
//________________________________________________________________
void function7()
{

}
//________________________________________________________________
void function8()
{

}
//============================================================================
int main() {
//test cases of function 1
//test cases of function 2
//...
//________________________________________________________________
//Test cases of Longest Valid Parentheses problem
    cout<<"Test cases of Longest Valid Parentheses problem:\n";
    string str1 = "(()";
    string str2 = "";
    string str3 = ")()()))";
    cout<<"input : "<< str1<<"\noutput:";
    Longest_Valid_Parentheses(str1);
    cout<<"input : "<< str2<<"\noutput:";
    Longest_Valid_Parentheses(str2);
    cout<<"input : "<< str3<<"\noutput:";
    Longest_Valid_Parentheses(str3);
//________________________________________________________________
}
