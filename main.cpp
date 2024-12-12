#include <iostream>
#include <vector>
#include "SkipList.cpp"
using namespace std;

int main()
{
  SkipList<int> *mySL = new SkipList<int>();

  mySL->insert(23);
  mySL->insert(20);
  mySL->insert(8);
  mySL->insert(5);
  mySL->insert(100);
  mySL->insert(3);
  mySL->insert(3);


  mySL->printData();

  mySL->Delete(3);
  cout << "--------------------------------\n";
  mySL->printData();

  cout << mySL->length << '\n';

  mySL->printTopN(5);
  return 0;
}