#pragma once
void example1();
#include<iostream>
//#include<string>


class MyContainer {
public:

    MyContainer() :
        m_arr{ new int }, m_size{ 0 } {}

    ~MyContainer() { delete[] m_arr; }

    void push_back(int a);
    void pop_back();
    void Insert(int poz, int a);
    void Erase(int poz);
    void Print();
    int Size();
    int& operator[](int index);
    


private:
   int *m_arr;
   int m_size;
};
