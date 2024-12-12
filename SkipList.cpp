#include <iostream>
#include <cstdlib>
#include <limits>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
struct Node
{
public:
    T key;
    Node<T> *next;
    Node<T> *prev;
    Node<T> *up;
    Node<T> *down;

    Node(const T &key){
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
        this->up = nullptr;
        this->down = nullptr;
    };
    Node() {}
};

template <class T>
class SkipList
{
private:
    T minValue;
    T maxValue;
    int Levels;
    int length;
    vector<Node<T> *> Heads; 

    Node<T> *insertToLevel(T N, int level, Node<T> *down);
    void DeleteNode(Node<T> *N);
public:
    SkipList() {};
    SkipList(T minValue, T maxValue);
    int size();
    Node<T> *Search(T key);
    void insert(T N);
    void Delete(T N);
    void printTopN(int n);
    void printSkipList();
    void print();
};


template <class T>
SkipList<T>::SkipList(T minValue, T maxValue) : Levels(0), length(0), minValue(minValue), maxValue(maxValue)
{
    // Set seed for random number generator to ensure randomness
    srand(static_cast<unsigned int>(time(NULL)));

    Node<T> *head = new Node<T>(minValue);

    Node<T> *tail = new Node<T>(maxValue);

    head->next = tail;

    tail->prev = head;

    Heads.push_back(head);
}

template <class T>
int SkipList<T>::size(){
    return length;
}


// search

template <class T>
Node<T> *SkipList<T>::Search(T key)
{
    Node<T> *topleft;
    topleft = Heads[Heads.size() - 1];
    Node<T> *pt = new Node<T>(minValue);
    pt = topleft;
    while (pt != nullptr)
    {
        if (pt->key == key)
           return pt;
        else if(key < pt->next->key)
            pt = pt->down;
        else
            pt = pt->next;
    }
    return nullptr;
}

// insertion

template <class T>
Node<T> *SkipList<T>::insertToLevel(T data, int level, Node<T> *Down)
{
    int i = level;
    Node<T> *N = new Node<T>(data);
    N->down = Down;
    Node<T> *pt = new Node<T>();
    pt = Heads[i];

    while (pt->next != nullptr && data > pt->next->key)
    {
        pt = pt->next;
    }
    N->prev = pt;
    N->next = pt->next;
    pt->next = N;
    N->next->prev = N;
    return N;
}

template <class T>
void SkipList<T>::insert(T data)
{
    int i = 0;
    length++;
    Node<T> *Down = insertToLevel(data, i, nullptr); 

    int isAddUp = (rand() % 2) == 0;
    while (isAddUp == 0)
    {
        i++;
        if (Levels < i)
        {
            Levels += 1;
            Node<T> *NewHead = new Node<T>(minValue);
            Node<T> *NewTail = new Node<T>(maxValue);
            NewHead->next = NewTail;
            NewTail->prev = NewHead;
            Heads[i - 1]->up = NewHead;
            NewHead->down = Heads[i - 1];
            Heads.push_back(NewHead);
        }
        Node<T> *N = insertToLevel(data, i, Down);
        Down->up = N;
        Down = N;
        isAddUp = (rand() % 2) == 0;
    }

    return;
}


// deleting

template <class T>
void SkipList<T>::Delete(T N){
    Node<T> *pt = Search(N);
    while (pt != nullptr){
        Node<T> *temp = pt->down;
        DeleteNode(pt);
        pt = temp;
    }
}

template <class T>
void SkipList<T>::DeleteNode(Node<T> *N)
{
    if (N->down != nullptr)
        N->down->up = nullptr;
    if (N->up != nullptr)
        N->up->down = nullptr;
    Node<T> *Next = N->next;
    Node<T> *Prev = N->prev;
    Prev->next = Next;
    delete (N);
    Next->prev = Prev;

    length--;
}


// printing in all ways

template <class T>
void SkipList<T>::printTopN(int n)
{
    int topN = n;
    if (n > length)
    {
        cout << "Skip list has a " << length << '\n';
        topN = length;
    }
    cout << "Top " << n << ":\n";
    vector<T> lastLevel;
    for (Node<T> *cur = Heads[0]; cur; cur = cur->next)
    {
        lastLevel.push_back(cur->key);
    }

    reverse(lastLevel.begin(), lastLevel.end());

    // start from 1 to avoid the tailVal
    for (int i = 1; i <= topN; ++i)
    {
        cout << lastLevel[i] << '\n';
    }
}

template <class T>
void SkipList<T>::printSkipList()
{
    vector<vector<T>> res;
    for (int i = 0; i != Heads.size(); i++)
    {
        vector<T> resLevel;
        Node<T> *pt = new Node<T>(minValue);
        pt = Heads[i];
        while (pt != nullptr)
        {
            resLevel.push_back(pt->key);
            pt = pt->next;
        }
        res.push_back(resLevel);
    }

    for (int level = res.size() - 1; level >= 0; level--)
    {
        for (int i = 0; i < res[level].size(); ++i)
        {
            if (i)
            {
                cout << " -> ";
            }
            if (res[level][i] == minValue)
                cout << "-inf";
            else if (res[level][i] == maxValue)
                cout << "inf";
            else
                cout << res[level][i];
        }
        cout << '\n';
    }
}

template <class T>
void SkipList<T>::print(){
    for(Node<T>* cur = Heads[0]; cur ; cur = cur->next){
        if(cur->key == minValue || cur->key == maxValue)
            continue;
        cout << cur->key << '\n';
    }
}
