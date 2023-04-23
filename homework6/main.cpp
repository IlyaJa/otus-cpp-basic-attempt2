#include<iostream>
#include "mycontainer.h"
#include "my_list.h"

int main()
{   
    std::cout<<"MyContainer"<<std::endl;
    MyContainer cont;
    for(int i=0; i<10; ++i){
        cont.push_back(i);
    }
    cont.Print();
    std::cout<<cont.Size()<<std::endl;
    cont.Erase(3);
    cont.Erase(4);
    cont.Erase(5);
    cont.Print();
    cont.Insert(1,10);
    cont.Print();
   // int value=cont.Size();
    int mean=cont.Size()/2+1;
    cont.Insert(mean, 20);
    cont.Print();
    cont.push_back(30);
    cont.Print();
    //list_();  
    std::cout<<"MyList"<<std::endl;
   MyList lst;  
   for(int i=0; i<10; ++i){
        lst.push_back(i);
    } 
    lst.Print(lst);
    std::cout<<lst.Getsize()<<std::endl;
    lst.removeAt(2);
    lst.removeAt(3);
    lst.removeAt(4);
    lst.Print(lst);
    lst.push_front(10);
    lst.Print(lst);
    mean=lst.Getsize()/2;
    lst.insert(20,mean);
    lst.Print(lst);
    lst.push_back(30);    
    lst.Print(lst);

    /*for (int i = 0; i < lst.Getsize(); i++) {
        std::cout << lst[i] << "  ";    
        
    }
   std::cout<< std::endl;*/
    return 0;
}