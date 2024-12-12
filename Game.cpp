#include <bits/stdc++.h>
#include "SkipList.cpp"
using namespace std;


class Player {
public:
    string Name;
    int score;
    Player (){}
    
    Player(string name, int score) {
        this->Name = name;
        this->score = score;
    }


    bool operator<(const Player& other) const {
        return this->score < other.score;
    }

    bool operator>(const Player& other) const {
        return this->score > other.score;
    }
    bool operator==(const Player& other) const {
        return this->score == other.score;
    }
    bool operator<=(const Player& other) const {
        return this->score <= other.score;
    }
    bool operator>=(const Player& other) const {
        return this->score >= other.score;
    }
   friend ostream& operator<<(ostream& os, const Player& other) {
        os << other.Name << "   " << other.score;
        return os;
    } 

};

// class GameManger {
// public:
//     SkipList<Player> board;
//     GameManger(){

//     }
//     void Join(string name , int score = 0){
//         Player player = Player(name, score);
//         board.insert(player);
//     }
//     void Leave(string name){
//         board.Delete(name);
//     }
//     void GetTop_N_Players(int N){
        
//         board.printTopN(N);
//     }
// };


// void printMenu() {
//     cout << "Game Menu:" << endl;
//     cout << "1. Join Game" << endl;
//     cout << "2. Print Player Score" << endl;
//     cout << "3. Print Top N Players" << endl;
//     cout << "4. Leave Game" << endl;
//     cout << "5. Exit" << endl;
//     cout << "Enter your choice: ";
// }

// void menu() {
//     int choice;
//     while (true) {
//         printMenu();
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 joinGameMenu();
//                 break;
//             }
//             case 2: {
//                 printPlayerScoreMenu();
//                 break;
//             }
//             case 3: {
//                 printTopNPlayersMenu();
//                 break;
//             }
//             case 4: {
//                 leaveGameMenu();
//                 break;
//             }
//             case 5:
//                 return;
//             default:
//                 cout << "Invalid choice. Please try again." << endl;
//         }
//     }
// }

// void joinGameMenu() {
//     string name;
//     int score;
//     cout << "Enter your name: ";
//     cin >> name;
//     cout << "Enter your initial score: ";
//     cin >> score;
//     addPlayer(Player(name, score));
//     cout << "You have joined the game!" << endl;
// }

// void printPlayerScoreMenu() {
//     string name;
//     cout << "Enter the name of the player: ";
//     cin >> name;
//     for (const auto& player : players) {
//         if (player.Name == name) {
//             cout << "Player " << name << " score: " << player.score << endl;
//             return;
//         }
//     }
//     cout << "Player not found." << endl;
// }

// void printTopNPlayersMenu() {
//     int N;
//     cout << "Enter the number of top players to display: ";
//     cin >> N;
//     printLeaderboard(N);
// }

// void leaveGameMenu() {
//     string name;
//     cout << "Enter your name: ";
//     cin >> name;
//     removePlayer(name);
//     cout << "You have left the game." << endl;
// }


int main() {
    // menu();
  Player head ("head", INT_MIN), tail ("tail", INT_MAX);
  SkipList<Player> *mySL = new SkipList<Player>(head, tail);
  Player p1("p1", 10);
  Player p2("p2", 20);
  Player p3("p3", 30);

  mySL->insert(p1);
  mySL->insert(p2);
  mySL->insert(p3);

  mySL->printData();
    return 0;
}