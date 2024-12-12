#include <iostream>
#include <vector>
#include "SkipList.cpp"
#include "Game.cpp"
using namespace std;

int main()
{
  // SkipList<int> *mySL = new SkipList<int>();
  Player head ("head", INT_MIN), tail ("tail", INT_MAX);
  SkipList<Player> *mySL = new SkipList<Player>(head, tail);
  Player p1("p1", 10);
  Player p2("p2", 20);
  Player p3("p3", 30);

  mySL->insert(p1);
  mySL->insert(p2);
  mySL->insert(p3);

  mySL->printData();


  // mySL->insert(23);
  // mySL->insert(20);
  // mySL->insert(8);
  // mySL->insert(5);
  // mySL->insert(100);
  // mySL->insert(3);
  // mySL->insert(3);


  // mySL->printData();

  // mySL->Delete(3);
  // cout << "--------------------------------\n";
  // mySL->printData();

  // cout << mySL->length << '\n';

  // mySL->printTopN(5);
  return 0;
}