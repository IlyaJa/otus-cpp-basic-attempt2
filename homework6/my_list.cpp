#include<iostream>
#include"my_list.h"

/*class MyList {
public:
    MyList();
    ~MyList();

    void pop_back();
    void removeAt(int index);
    void insert(int data, int index);
    void push_front(int data);
    void clear();
    void pop_front();
    void push_back(int data);
    int Getsize() { return size; }
    int& operator[](const int index);
    void Gethead() {
        std::cout << head << std::endl;
    }
    void GetPnext() { std::cout << head->pNext << std::endl; }

private:
    class Node {
    public:
        Node(int data = 0, Node* pNext = nullptr) : data(data), pNext(pNext) {}
        Node* pNext;
        int data;
    };

    int size;
    Node* head;

};*/

MyList::MyList() {
    size = 0;
    head = nullptr;
}

MyList::~MyList()
{
    clear();
}


/*void list_(){
   MyList lst;   
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_front(5);
    lst.insert(100, 3  );

    for (int i = 0; i < lst.Getsize(); i++) {
        std::cout << lst[i] << std::endl;
    }
      
   // return 0; 
}*/

void MyList::pop_back()
{
    removeAt(size - 1);
}

void MyList::removeAt(int index)
{
    if (index == 0) {
        pop_front();
    }
    else {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        size--;
    }

}

void MyList::insert(int data, int index)
{
    if (index == 0) {
        push_front(data);
    }
    else {
        Node* previous = this->head;        
        for(int i=0; i<index-1; i++)
        {           
            previous = previous->pNext;            
        }
        previous->pNext= new Node(data, previous->pNext);
        size++;
    }
}

void MyList::push_front(int data)
{
     head = new Node(data, head);
     size++;
}

void MyList::clear()
{
    while (size)
    {
        pop_front();
    }
}

void MyList::pop_front()
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

void MyList::push_back(int data)
{
    if (head == nullptr) {
        head = new Node(data);
    }
    else {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}

int& MyList::operator[](const int index)
{
    if (index >= size) { std::cout << "Error"; 
    }
    else {
        int counter = 0;
        Node* current =this->head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
    return head->data;
}

void MyList::Print(MyList &llst)
{
    for (int i = 0; i<size; i++)
     { std::cout << llst[i]<< "  "; }      
    std::cout<< std::endl;
}
 


