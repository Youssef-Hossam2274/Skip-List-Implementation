#include<iostream>
#include<vector>
#include "SkipList.cpp"
using namespace std;



int main(){
    SkipList<int> skiplist;

    skiplist.Insert(1);    
    skiplist.Insert(2);    
    skiplist.Insert(7);

    skiplist.print();


    skiplist.Delete(1);
    skiplist.print();

    skiplist.Delete(4);
    skiplist.print();
    
    skiplist.Delete(2);
    skiplist.print();

    return 0;
}