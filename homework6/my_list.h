#pragma once
class MyList {
public:
    MyList();
    ~MyList();
    void Print(MyList &llst);
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

};
