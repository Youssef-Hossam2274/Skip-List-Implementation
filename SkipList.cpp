#include<iostream>
#include<vector>
using namespace std;


template <typename T>
class SkipList
{
private:
    vector<T> data;
public:

    bool Search(T val){
        for(T it: data){
            if(it == val)
                return true;
        }

        return false;
    }
    void Insert(T val){
        data.push_back(val);
    }

    void Delete(T val){
        if(Search(val) == false){
            cout << val << " does not exist.\n";
        }

        int targetIdx = -1;
        for(int i = 0; i < data.size(); ++i){
            if(data[i] == val){
                targetIdx = i;
                break;
            }
        }   

        if(targetIdx != -1){
            swap(data[targetIdx], data.back());
            data.pop_back();
        }
    }

    void print(){
        for(T it: data){
            cout << it << ' ';
        }

        cout << '\n';
    }

};