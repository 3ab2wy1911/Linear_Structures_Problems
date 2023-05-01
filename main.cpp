// Authors: Mohammed 3ab2awy
// Authors: Omar Mohammad
// last modification: 1/5/2023
// Data Structure Assignment II Final Edition :)
#include <bits/stdc++.h>
#include "LinearStructure.cpp"
using namespace std;

//Problems of LinkedList
//============================================================================
//1. Combine Nodes Between Zeros
void CombineNodes(Single_Linked_List<int>::node* first) {
	Single_Linked_List<int> new_sll;
	bool start, end; start = end = false;// start and end
	Single_Linked_List<int>::node* st = NULL, * nd = NULL; // two pointers to start and end
	Single_Linked_List<int>::node* newNode = new Single_Linked_List<int>::node; // to iterate
	newNode = first;
	while (newNode != NULL) {
		// if it is the first zero in the list
		if (newNode->item == 0 and start == false and end == false) {
			st = newNode;
			start = true;
		}
		// if it is the second zero(end)
		else if (newNode->item == 0 and end == false and start == true) {
			nd = newNode;
			end = true;
		}
		// if we found the start and end of the list (we found a range)
		if (start == true and end == true) {
			int sum = 0;
			Single_Linked_List<int>::node* newNode1 = new Single_Linked_List<int>::node; // to iterate within the start and end
			newNode1 = st->next;
			// while the end is not reached
			while (newNode1 != nd) {
				//cout << newNode1->info << " ";
				sum += newNode1->item;
				newNode1 = newNode1->next;
			}
			new_sll.insertAtTail(sum);
			st = nd; // make the end of the range is the start of the next range
			start = true; // mark the start of the next range to be true
			end = false; // mark the end of the next range to be false
		}
		newNode = newNode->next; // iterate through the original ll
	}
	new_sll.print();
}
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
int operatorPrec(char op) {
	if (op == '^')
		return 3;
	else if (op == '/' or op == '*')
		return 2;
	else if (op == '+' or op == '-')
		return 1;
	else
		return 0;
}
string infixToPostfix(string infix) {
	Stack<char> st;
	string postfix = "";
	for (int i = 0; i < infix.size(); i++) {
		if (isalpha(infix[i]) or (infix[i] >= '0' and infix[i] <= '9')) {
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			st.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (st.Top() != '(') {
				postfix += st.Top();
				st.pop();
			}
			st.pop();
		}
		// operator
		else {
			while (!st.isEmpty() and (operatorPrec(infix[i]) <= operatorPrec(st.Top()))) {
				postfix += st.Top();
				st.pop();
			}
			st.push(infix[i]);
		}
	}
	while (!st.isEmpty()) {
		postfix += st.Top();
		st.pop();
	}
	return postfix;
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
    cout<<"Test cases of 1. Combine Nodes Between Zero problem:\n";
    cout<<"====================================================================\n";
//1. Combine Nodes Between Zeros
    Single_Linked_List<int>ll;
	cout << "tc 1: [0, 3, 1, 0, 4, 5, 2, 0] ==> ";
	ll.insertAtTail(0);
	ll.insertAtTail(3);
	ll.insertAtTail(1);
	ll.insertAtTail(0);
	ll.insertAtTail(4);
	ll.insertAtTail(5);
	ll.insertAtTail(2);
	ll.insertAtTail(0);
	CombineNodes(ll.returnFirst());
	cout << endl;
	ll.clear();
	cout << "tc 2: : [0, 1, 0, 3, 0, 2, 2, 0] ==> " ;
	ll.insertAtTail(0);
	ll.insertAtTail(1);
	ll.insertAtTail(0);
	ll.insertAtTail(3);
	ll.insertAtTail(0);
	ll.insertAtTail(2);
	ll.insertAtTail(2);
	ll.insertAtTail(0);
	CombineNodes(ll.returnFirst());
	cout <<  "\n====================================================================\n";
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
    cout<<"1.Test cases of Infix Expression to Postfix Expression:\n";
    cout<<"________________________________________________________________\n";
    string str00 = "a+c-d/y";
    string str01 = "X^Y/(5*Z)+2";
    string str02 = "A+B*C+D";
    string str03 = "(A+B)*(C+D)";
    cout << "input ==>" << str00 << endl;
    cout << "output ==> " << infixToPostfix(str00) << endl;
    cout << '\n';
    cout << "input ==> " << str01 << endl;
    cout << "output ==> " << infixToPostfix(str01) << endl;
    cout << '\n';
    cout << "input ==> " << str02 << endl;
    cout << "output ==> " << infixToPostfix(str02) << endl;
    cout << '\n';
    cout << "input ==> " << str03 << endl;
    cout << "output ==> " << infixToPostfix(str03) << endl;
    cout<<"====================================================================\n";
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
