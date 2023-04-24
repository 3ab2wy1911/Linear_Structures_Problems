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
//2. Longest Valid Parentheses
void Longest_Valid_Parentheses(string & str)
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
// 2. Implement a Stack
template <typename type>
class Stack_using_queue
{
private:
  Queue<type> q1, q2;
public:
    void push(type element){
            q2.enqueue(element);
            while(!q1.isEmpty()){
                q2.enqueue(q1.first());
                q1.dequeue();
            }
            q1=q2;
            while(!q2.isEmpty()){
                q2.dequeue();
            }
        }
    void pop(){
        q1.dequeue();
    }
    void print(){
        q2=q1;
        q2.print();
    }
    type top(){
       return q1.first();
    }
    int size(){
       return q1.queueSize();
    }
    bool isEmpty(){
       return q1.isEmpty();
    }
};
//________________________________________________________________
template<typename type>
void Queue_sort(Queue<type> q){

}
//============================================================================
int main() {
//test cases of function 1
//test cases of function 2
//...
//________________________________________________________________
//Test cases of Stack problems
cout<<"Test cases of Stack problems:\n";
cout<<"====================================================================\n";
// 2.Test cases of Longest Valid Parentheses problem
    cout<<"2.Test cases of Longest Valid Parentheses problem:\n";
    cout<<"________________________________________________________________\n";
    string str1 = "(()";
    string str2 = " ";
    string str3 = ")()()))";
    cout<<"input : "<< str1<<"\noutput:";
    Longest_Valid_Parentheses(str1);
    cout<<"input : "<< str2<<"\noutput:";
    Longest_Valid_Parentheses(str2);
    cout<<"input : "<< str3<<"\noutput:";
    Longest_Valid_Parentheses(str3);
    cout<<"================================================================\n";
////===============================================================
    cout<<"Test cases of Queue problems:\n";
    cout<<"================================================================\n";
//2.Test cases of Implement a Stack problem
    cout<<"2.Test cases of Implement a Stack problem:\n";
    cout<<"________________________________________________________________\n";
    Stack_using_queue <int> stackUsingQueue;
    for(int i=0;i<=5;i++){
        stackUsingQueue.push(i);    //0 1 2 3 4 5
    }
    cout << "Stack size: " << stackUsingQueue.size() << endl;   //6
    stackUsingQueue.print();    //[5 4 3 2 1 0]
    cout<<endl;
    cout << stackUsingQueue.top() << endl; //5
    stackUsingQueue.pop();  //5
    cout << stackUsingQueue.top() << endl;  //4
//________________________________________________________________
}
