#include <iostream>
#include "mycontainer.h"

    void MyContainer:: push_back(int a) {
        if (m_size == 0) {
            m_arr = new int[++m_size];
            m_arr[0] = a;
             }
        else {
            ++m_size;
            int* TempArr = new int[m_size];
            // std::cout << m_size << std::endl;
            for (int i = 0; i < m_size-1; i++)
            {
                TempArr[i] = m_arr[i];
            }
            TempArr[m_size-1] = a;
            delete[] m_arr;
            m_arr = TempArr;
            TempArr=nullptr;           
            //m_arr[m_size - 1] = a;
        }
    }

    void MyContainer::pop_back() {
        if (m_size == 0) {
            std::cout << "Error" << std::endl;
        }
        else {
            --m_size;
            int* TempArr = new int[m_size];
            // std::cout << m_size << std::endl;
            for (int i = 0; i < m_size; i++)
            {
                TempArr[i] = m_arr[i];
            }           
            delete[] m_arr;
            m_arr = TempArr;
            TempArr = nullptr;
             //m_arr[m_size - 1] = a;
        }
    }

    void MyContainer::Insert(int poz, int a) {
        if (poz>m_size||poz==0) {
            std::cout << "Error" << std::endl;
        }
        else {
            ++m_size;
            int *TempArr = new int[m_size];            
            for (int i = 0; i < poz-1; i++)
            {
                TempArr[i] = m_arr[i];
            }

            TempArr[poz-1] = a;
            
            for (int i = poz; i < m_size; i++) {
                TempArr[i] = m_arr[i-1];
            }

            delete[] m_arr;
            m_arr = TempArr;
            TempArr = nullptr;            
        }
    }

    void MyContainer::Erase(int poz) {
        if (poz > m_size || poz == 0) {
            std::cout << "Error" << std::endl;
        }
        else {
            --m_size;
            int* TempArr2= new int[m_size];
            // std::cout << m_size << std::endl;
            for (int i = 0; i < poz - 1; i++)
            {
                TempArr2[i] = m_arr[i];
                //std::cout <<i<<"   "<< TempArr2[i] << std::endl;
            } 
            //std::cout << m_arr[poz - 1] << std::endl;
           // m_arr[poz - 1] = NULL;
            for (int i = poz; i < m_size+1; i++) {
                TempArr2[i-1] = m_arr[i];
               // std::cout <<i-1<<"  "<< TempArr2[i-1] << std::endl;
            }

            delete[] m_arr;
            m_arr = TempArr2;                   
            TempArr2=nullptr;           
             //m_arr[m_size - 1] = a;
        }
    }

    void MyContainer::Print() {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_arr[i] << "  ";
        } 
        std::cout<<std::endl;

    }
    int MyContainer::Size() {
        //std::cout << _msize(m_arr) / sizeof(int) << std::endl;
        //return _msize(m_arr) / sizeof(int);
        return m_size;
    }

    int& MyContainer::operator[](int index) {
        return m_arr[index];
    }

    

