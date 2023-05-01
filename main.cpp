#include <bits/stdc++.h>
#include "LinearStructure.cpp"
using namespace std;

//Problems of LinkedList
//============================================================================
//1. Combine Nodes Between Zeros
void function_name(){
    //Put ur code here and remember Arsenal 3amk
};
//________________________________________________________________
//2. Merge K Sorted Linked Lists
Single_Linked_List<int>:: node* merge_K_Lists(vector<Single_Linked_List<int> ::node*>& Linked_Lists) {
    Single_Linked_List<int>::node* head = new Single_Linked_List<int>::node;
    head->next= NULL;
    Single_Linked_List<int>::node* tail = new Single_Linked_List<int>::node;
    tail =head;
    int k = Linked_Lists.size();
    bool ck = true;
    while (ck) {
        int mini = INT_MAX;
        int mini_index = -1;
        ck = false;
        for (int i = 0; i < k; i++) {
            if (Linked_Lists[i] != NULL && Linked_Lists[i]->item < mini) {
                mini = Linked_Lists[i]->item;
                mini_index = i;
                ck = true;
            }
        }
        if (ck) {
            tail->next = Linked_Lists[mini_index];
            tail = tail->next;
            Linked_Lists[mini_index] = Linked_Lists[mini_index]->next;
        }
    }
    return head->next;
}
//============================================================================
//1. Convert the Infix Expression to Postfix Expression
 void function3()
{
//    Put ur code here don't forget to change the name of the function ... Milan 3amk hwa we elzamalek.
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
//============================================================================
// Problems of Queue
// 1. Generate Binary Numbers from 1 to N
void BinaryNumbers(int n)
{
    for(int i = 1; i <=n;i++){
        Queue<int> q,t_q;
        int k=i;
        while(k){
            t_q.enqueue(k%2);
            while(!q.isEmpty()){
                t_q.enqueue(q.dequeue());
            }
            q=t_q;
            while(!t_q.isEmpty()){
                t_q.dequeue();
            }
            k/=2;
        }
        while(!q.isEmpty()){
            cout<<q.dequeue();
        }
        cout<<' ';
    }
    cout<<endl;
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
                q2.enqueue(q1.dequeue());
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
//3. 3. Sorting a Queue.
void Queue_sort(Queue<int> &q){
    Queue<int>temp_q , Final_q;
    int n = q.queueSize();
    for(int i=0; i<n; i++){
        int mini = INT_MAX , index =-1 , mini_index=-1;
        while(!q.isEmpty()){
            index++;
            if(mini>q.first()){
                mini = q.first();
                mini_index = index;
            }
            temp_q.enqueue(q.dequeue());
        }
        int j=0;
        while(!temp_q.isEmpty()){
            if (j==mini_index)
            {
                Final_q.enqueue(temp_q.dequeue());
            }
            else
            {
                q.enqueue(temp_q.dequeue());
            }
            j++;
        }
    }
    q=Final_q;
}
//============================================================================
int main() {
    cout<<"Test cases of Stack problems:\n";
    cout<<"====================================================================\n";
//1. Combine Nodes Between Zeros
    //Put ur test cases here فما حاااااجة.
//________________________________________________________________
//2. Merge K Sorted Linked Lists
    cout<<"Test cases of 2. Merge K Sorted Linked Lists problem:\n";
    cout<<"________________________________________________________________\n";
    Single_Linked_List<int>l1,l2,l3,l4,l5,l6;
    l1.insertAtHead(5);
    l1.insertAtHead(4);
    l1.insertAtHead(1);
    l2.insertAtHead(4);
    l2.insertAtHead(2);
    l2.insertAtHead(1);
    l3.insertAtHead(6);
    l3.insertAtHead(2);
    l4.insertAtHead(7);
    l4.insertAtHead(5);
    l4.insertAtHead(3);
    l4.insertAtHead(1);
    l5.insertAtHead(8);
    l5.insertAtHead(6);
    l5.insertAtHead(4);
    l5.insertAtHead(2);
    l6.insertAtHead(10);
    l6.insertAtHead(9);
    l6.insertAtHead(0);
//------------------------------------------------------------------
    cout<<"First test case:\n";
    cout<<"________________________________________________________________\n";
    cout<<"First List ==> ";
    l1.print();
    cout<<endl;
    cout<<"Second List ==> ";
    l2.print();
    cout<<endl;
    cout<<"Third List ==> ";
    l3.print();
    cout<<endl;
    cout<<"Lists After Merging ==>";
    cout<<"[ ";
    vector <Single_Linked_List<int>::node*> lists = {l1.head,l2.head,l3.head};
    Single_Linked_List<int>::node* merged_list = merge_K_Lists(lists);
    while (merged_list) {
        cout << merged_list->item << " ";
        merged_list = merged_list->next;
    }
    cout<<" ]\n";
    cout<<"------------------------------------------------------------------\n";
    cout<<"Second test case:\n";
    cout<<"________________________________________________________________\n";
    cout<<"First List ==> ";
    l4.print();
    cout<<endl;
    cout<<"Second List ==> ";
    l5.print();
    cout<<endl;
    cout<<"Third List ==> ";
    l6.print();
    cout<<endl;
    cout<<"Lists After Merging ==>";
    cout<<"[ ";
    lists.clear();
    lists = {l4.head,l5.head,l6.head};
    merged_list = merge_K_Lists(lists);
    while (merged_list) {
        cout << merged_list->item << " ";
        merged_list = merged_list->next;
    }
    cout<<" ]\n";
    cout<<"====================================================================\n";
//====================================================================
//Test cases of Stack problems
cout<<"Test cases of Stack problems:\n";
cout<<"====================================================================\n";
// 1. Convert the Infix Expression to Postfix Expression
    // put ur test cases here and remember England has only one boss which is Arsenal.
//________________________________________________________________
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
    cout<<"________________________________________________________________\n";
    cout<<"================================================================\n";
//===============================================================
//Test cases of Queue problems
    cout<<"Test cases of Queue problems:\n";
    cout<<"================================================================\n";
//________________________________________________________________
// 1. Generate Binary Numbers from 1 to N
    cout<<"1. Test cases of Generate Binary Numbers from 1 to N Problem:\n";
    cout<<"________________________________________________________________\n";
    cout<<"Binary numbers till 3:\n";
    BinaryNumbers(3);
    cout<<"----------------------------------------------------------------\n";
    cout<<"Binary numbers till 5:\n";
    BinaryNumbers(5);
    cout<<"________________________________________________________________\n";
//________________________________________________________________
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
    cout<<"________________________________________________________________\n";
//________________________________________________________________
//3.Test cases of Sorting a Queue
    cout<<"3.Test cases of Sorting a Queue:\n";
    cout<<"________________________________________________________________\n";
    Queue<int>q1,q2;
    q1.enqueue(15);
    q1.enqueue(2);
    q1.enqueue(4);
    q2.enqueue(9);
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(1);
    cout<<"First Queue before sorting:";
    q1.print();
    cout<<endl;
    cout<<"First Queue after sorting: ";
    Queue_sort(q1);
    q1.print();
    cout<<endl;
    cout<<"----------------------------------------------------------------\n";
    cout<<"Second Queue before sorting:";
    q2.print();
    cout<<endl;
    cout<<"Second Queue after sorting:";
    Queue_sort(q2);
    q2.print();
    cout<<endl;
    cout<<"________________________________________________________________\n";
}