#include <bits/stdc++.h>
using namespace std;

template<typename type>
class Array_Based_List{
private:
    type *array;
    int size,capacity;
public:
    explicit Array_Based_List(int Capacity)
    {
        capacity=Capacity;
        size=0;
        array=new type[capacity];
    }
//________________________________________________________________
    ~Array_Based_List(){
        delete[] array;
    }
//________________________________________________________________
    bool isEmpty(){
        return size == 0;
    }
//________________________________________________________________
    bool isFull(){
        return size == capacity;
    }
//________________________________________________________________
    void insert(type element)
    {
        if(isFull())
            throw out_of_range ("List is full");
        array[size++]=element;
    }
//________________________________________________________________
    void insertAt(type element,int index)
    {
        if (index < 0 or index >= capacity) {
            throw out_of_range("Out of Range");
        }
        if (isFull())
            throw out_of_range("List is full");
        for (int i = size; i > index; i--) {
            array[i] = array[i-1];
        }
        array[index] = element;
        size++;
    }
//________________________________________________________________
    type retrieveAt(int index)
    {
        if (isEmpty())
            throw out_of_range("List is empty");
        if (index < 0 or index >= capacity) {
            throw out_of_range("Out of Range");
        }
        return array[index];
    }
//________________________________________________________________
    void removeAt(int index){
        if (isEmpty())
            throw out_of_range("List is empty");
        if (index < 0 or index >= capacity) {
            throw out_of_range("Out of Range");
        }
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i+1];
        }
        size--;
    }
//________________________________________________________________
    void replaceAt (type newElement, int index){
        if (isEmpty())
            throw out_of_range("List is empty");
        array[index] = newElement;
    }
//________________________________________________________________
    bool isItemAtEqual (type element, int index) {
        if (isEmpty())
            throw out_of_range("List is empty");
        return array[index] == element;
    }
//________________________________________________________________
    int listSize(){
        return size;
    }
//________________________________________________________________
    int maxListSize(){
        return capacity;
    }
//________________________________________________________________
    void clear(){
        size = 0;
        delete[] array;
        array = new type [capacity];
    }
//________________________________________________________________
    void print(){
        cout<<"[ ";
        for(int i = 0; i < size;i++)
        {
            cout<<array[i]<<' ';
        }
        cout<<']'<<endl;
    }
};
//================================================================
template <typename type>
class Single_Linked_List{
private:
    struct node{
        type item;
        node *next;
    };
    node *head;
    node *tail;
    int length;
public:
    explicit Single_Linked_List(){
        length=0;
        head = tail = NULL;
    }
//________________________________________________________________
    bool isEmpty(){
        return length==0;
    }
//________________________________________________________________
    void insertAtHead(type element)
    {
        node *newNode = new node;
        newNode->item = element;
        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
        length ++;
    }
//________________________________________________________________
    void insertAtTail(type element) {
        node *newNode = new node;
        newNode->item = element;
        if (isEmpty()) {
            insertAtHead(element);
        } else {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
            length++;
        }
    }
//________________________________________________________________
    void insertAt(type element , int index)
    {
        if (index==0)
        {
            insertAtHead(element);
        }
        else if (index==length)
        {
            insertAtTail(element);
        }
        else {
            node *newNode = new node;
            newNode->item = element;
            node *curr = head;
            for (int i = 0; i < index; i++) {
                curr=curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            length++;
        }
    }
//________________________________________________________________
    void removeAtHead() {
        if (isEmpty())
            throw out_of_range("List is empty");
        node *newNode = head;
        head = head->next;
        delete newNode;
        length--;
    }
//________________________________________________________________
    void removeAtTail() {
        if (isEmpty())
            throw out_of_range("List is empty");
        node *curr=head;
        node *newNode = tail;
        for(int i=0;i<length;i++)
        {
            curr=curr->next;
        }
        curr->next=NULL;
        tail =curr;
        delete newNode;
        length--;
    }
//________________________________________________________________
    void removeAt (int index){
        if (isEmpty())
            throw out_of_range("List is empty");
        else if(index==0)
        {
            removeAtHead();
        }
        else if(index==length){
            removeAtTail();
        }
        else{
            node *curr=head;
            for(int i=0;i<index;i++)
            {
                curr=curr->next;
            }
            node *newNode = curr->next;
            curr->next=curr->next->next;
            delete newNode;
            length--;
        }
    }
//________________________________________________________________
    type retrieveAt(int index)
    {
        if (isEmpty())
            throw out_of_range("List is empty");
        node *curr=head;
        for(int i=0;i<=index;i++)
        {
            curr=curr->next;
        }
        return curr->item;
    }
//________________________________________________________________
    void replaceAt(type newElement,int index)
    {
        if (isEmpty())
            throw out_of_range("List is empty");
        node *curr=head;
        for(int i=0;i<=index;i++)
        {
            curr=curr->next;
        }
        curr->item = newElement;
    }
//________________________________________________________________
    bool isExist(type element)
    {
        node *curr=head;
        for(int i=0;i<=length;i++)
        {
            if(curr->item==element)
                return true;
            curr=curr->next;
        }
        return false;
    }
//________________________________________________________________
    bool isItemAtEqual(type element,int index){
        if (isEmpty())
            throw out_of_range("List is empty");
        node *curr=head;
        for(int i=0;i<=index;i++)
        {
            curr=curr->next;
        }
        return curr->item == element;
    }
//________________________________________________________________
    void print(){
        node *curr=head;
        cout<<"[ ";
        while(curr!=tail)
        {
            cout<<curr->item<<", ";
            curr=curr->next;
        }
        cout<<tail->item<<" ]";
    }
//________________________________________________________________
    int LinkedListSize(){
        return length;
    }
//________________________________________________________________
    void clear(){
        length=0;
        head = tail = NULL;
    }
//________________________________________________________________
};
//================================================================
template<typename type>
class Double_Linked_List{
private:
    struct node{
        type item;
        node *next , *prev;
    };
    int length;
    node *head,*tail;
public:
    explicit Double_Linked_List(){
        length = 0;
        head = tail = NULL;
    }
//________________________________________________________________
    bool isEmpty(){
        return length == 0;
    }
//________________________________________________________________
    void insertAtHead (type element){
        node *newNode = new node;
        newNode->prev = NULL;
        newNode->item=element;
        if(isEmpty())
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next=head;
            head ->prev = newNode;
            head = newNode;
        }
        length++;
    }
//________________________________________________________________
    void insertAtTail (type element){
        if(isEmpty()){
            insertAtHead(element);
        }
        else{
            node *newNode = newNode;
            newNode->next= NULL;
            newNode->prev = tail;
            tail ->next = newNode;
            tail = newNode;
            length++;
        }
    }
//________________________________________________________________
    void insertAt (type element, int index){
        if(index<0 and index > length )
            throw out_of_range("out of index range");
        if(index == 0)
        {
            insertAtHead(element);
        }
        else if(index == length)
        {
            insertAtTail(element);
        }
        else{
            node *newNode = new node;
            newNode->item=element;
            node *cur = head;
            for(int i = 0; i < index;i++)
            {
                cur=cur->nex;
            }
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
        }
    }
//________________________________________________________________
    void insertAfter (node *prev_node, int data){

    }
//________________________________________________________________
    void removeAtHead ()
    {
        if (isEmpty())
            throw out_of_range("List is empty");
        if(length==1)
        {
            delete head ;
            tail = head = NULL;
        }
        else {
            node * temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        length--;
    }
//________________________________________________________________
    void removeAtTail (){
        if(isEmpty())
            throw out_of_range("List is empty");
        if(length ==1){
            delete head;
            tail = head = NULL;
        }
        else {
            node *temp =tail;
            tail=tail->prev;
            tail -> next = NULL;
            delete temp;
        }
    }
//________________________________________________________________
    void removeAt (int index){
        node *cur = head;
        if(index<0 and index > length )
            throw out_of_range("out of index range");
        if(isEmpty())
            throw out_of_range("List is empty");
        if(index ==0)
        {
            removeAtHead();
        }
        else if(index == length){
            removeAtTail();
        }
        else{
            for(int i=1;i<index;i++){
                cur=cur->next;
            }
            node *next = cur->next;
            node *temp = cur;
            next->prev=cur->prev;
            cur = cur->prev;
            delete temp;
            cur-> next = next;
            length--;
        }
    }
//________________________________________________________________
    type retrieveAt (int index)
    {
        node *cur = head;
        if(index<0 and index > length )
            throw out_of_range("out of index range");
        if(isEmpty())
            throw out_of_range("List is empty");
        if(index ==0)
        {
            return head->item;
        }
        else if(index == length){
            return tail->item;
        }
        else{
            for(int i=1;i<index;i++){
                cur=cur->next;
            }
            return cur->item;
        }
    }
//________________________________________________________________
    void replaceAt (type newElement, int index){
        node *cur = head;
        if(index<0 and index > length )
            throw out_of_range("out of index range");
        if(isEmpty())
            throw out_of_range("List is empty");
        if(index ==0)
        {
            head->item = newElement;
        }
        else if(index == length){
            tail->item = newElement;
        }
        else{
            for(int i=1;i<index;i++){
                cur=cur->next;
            }
            cur->item = newElement;
        }
    }
//________________________________________________________________
    bool isExist (type element){
        node *cur = head;
        while(cur!=NULL){
            if (cur->item==element)
                return true;
            cur=cur->next;
        }
        return false;
    }
//________________________________________________________________
    bool isItemAtEqual (type element, int index){
        if(index<0 and index > length )
            throw out_of_range("out of index range");
        if(isEmpty())
            throw out_of_range("List is empty");
        node *cur = head;
        if(index ==0)
        {
            return head->item = element;
        }
        else if(index == length){
            return tail->item = element;
        }
        else{
            for(int i=1;i<index;i++){
                cur=cur->next;
            }
            return cur->item = element;
        }

    }
//________________________________________________________________
    void swap (int firstItemIdx, int secondItemIdx){

    }
//________________________________________________________________
    void reverse (){
        node* cur = head;
        node* temp = NULL;

        while (cur != NULL) {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
    }
//________________________________________________________________
    int doubleLinkedListSize ()
    {
        return length;
    }
//________________________________________________________________
    void clear (){
        length =0;
        delete head;
        delete tail;
        head = tail = NULL;
    }
//________________________________________________________________
    void forwardTraversal (){
        node *cur = head;
        cout <<"[ ";
        while(cur != NULL){
            cout <<cur->item<<' ';
            cur = cur->next;
        }
        cout << "]";
    }
//________________________________________________________________
    void backwardTraversal () {
        node *cur = tail;
        cout << "[ ";
        while (cur != NULL) {
            cout << cur->item << ' ';
            cur = cur->prev;
        }
        cout << "]";
    }
};
//============================================================================
class Circular_Linked_List{

};
//================================================================
template<typename type>
class Stack{
private:
    struct node{
        type item;
        node *next;
    };
    node *top , *cur;
    int length;
public:
    explicit Stack()
    {
        top = NULL;
        length = 0;
    }
//________________________________________________________________
    void push(type element)
    {
        node *newNode =new node;
        newNode->item = element;
        newNode->next =top;
        top = newNode;
        length++;
    }
//________________________________________________________________
    bool isEmpty()
    {
        return top == NULL;
    }
//________________________________________________________________
    void pop()
    {
        if (isEmpty())
            throw out_of_range("List is empty");
        node *newNode = top;
        top = top->next;
        newNode->next =NULL;
        delete newNode;
        length --;
    }
//________________________________________________________________
    int stackSize()
    {
        return length;
    }
//________________________________________________________________
    type Top(){
        return top->item;
    }
//________________________________________________________________
    void clear (){
        length=0;
        top=NULL;
    }
//________________________________________________________________
    void print(){
        node *node=top;
        cout<<"[ ";
        for(int i=0; i<=length; i++){
            cout<<node->item<<" ";
            node=node->next;
        }
        cout<<']';
        cout<<endl;
    }
};
//================================================================
template <typename type>
class Queue{
private:
    struct node{
        type  item;
        node *next;
    };
    node *front,*rear;
    int length;
public:
    explicit Queue(){
        front = rear = NULL;
        length = 0;
    }
//________________________________________________________________
    bool isEmpty()
    {
        return length == 0;
    }
//________________________________________________________________
    void enqueue(type element){
        node* newNode = new node;
        newNode->item=element;
        if(isEmpty())
        {
            newNode->next = NULL;
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->next = NULL;
            rear=newNode;
        }
        length++;
    }
//________________________________________________________________
    type dequeue(){
        node *newNode = front;
        if (isEmpty())
            throw out_of_range("Queue is empty");
        if(front==rear)
        {
            front = rear  = NULL;
        }
        else {
            front = front->next;
        }
        length--;
        return newNode->item;
    }
//________________________________________________________________
    type first(){
        if (isEmpty())
            throw out_of_range("List is empty");
        return front->item;
    }
//________________________________________________________________
    int queueSize(){
        return length;
    }
//________________________________________________________________
    void clear (){
        length=0;
        front = rear =NULL;
    }
//________________________________________________________________
    void print(){
        cout<<"[ ";
        while(front != NULL){
            cout<<front->item<<' ';
            front = front->next;
        }
        cout<<']';
    }
};