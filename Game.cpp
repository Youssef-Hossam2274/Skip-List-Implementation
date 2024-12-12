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
        return (this->score == other.score && this->Name == other.Name);
    }
    bool operator<=(const Player& other) const {
        return this->score <= other.score;
    }
    bool operator>=(const Player& other) const {
        return this->score >= other.score;
    }
   friend ostream& operator<<(ostream& os, const Player& other) {
        os << "{" << other.Name << "," << other.score << '}';
        return os;
    } 

};

class GameManger {
public:
    SkipList<Player> *board;
    GameManger(){
        Player head ("head", INT_MIN), tail ("tail", INT_MAX);
        board = new SkipList<Player>(head, tail);
    }
    void Join(){
        string name;
        int score;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your initial score: ";
        cin >> score;
        Player player = Player(name, score);
        board.insert(player);
        cout << name << " have joined the game!" << endl;
    }
    void Leave(string name){
        board.Delete(name);
    }
    void GetTop_N_Players(int N){
        int N;
        cout << "Enter the number of top players to display: ";
        cin >> N;  
        board.printTopN(N);
    }
    void GetPlayers(){
        board->printData();
    }
    void PrintPlayerScore(){
        string name;
        cout << "Enter the name of the player: ";
        cin >> name;
        Player p = board->Search(name); 
        cout << p << endl;        
    }
    void Leave(){

        string name;
        int score;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your score: ";
        cin >> score;
        Player p = Player(name , score)
        board->Delete(p);
    }

};


void printMenu() {
    cout << "Game Menu:" << endl;
    cout << "1. Join Game" << endl;
    cout << "2. Print Player Score" << endl;
    cout << "3. Print Top N Players" << endl;
    cout << "4. Leave Game" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void menu(GameManger & manager) {
    int choice;
    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                manager.Join();
                break;
            }
            case 2: {
                manager.PrintPlayerScore();
                break;
            }
            case 3: {
                manager.GetTop_N_Players(); 
                break;
            }
            case 4: {
                manager.Leave();
                break;
            }
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


int main() {
    GameManger manager;
    menu(manager);
    // Player p1("Eslam", 10);
    // Player p2("Youssuf", 20);
    // Player p3("Mekkawy", 30);

    // manager.Join(p1.Name, p1.score);
    // manager.Join(p2.Name ,p2.score);
    // manager.Join(p3.Name, p3.score);

    // manager.GetTop_N_Players(2);
    // menu();
    Player head ("head", INT_MIN), tail ("tail", INT_MAX);
    SkipList<Player> *mySL = new SkipList<Player>(head, tail);
    Player p1("p1", 10);
    Player p2("p2", 20);
    Player p3("p3", 30);
    Player p4("p4", 50);
    Player p5("p5", 50);
    Player p6("p6", 2);

    mySL->insert(p1);
    mySL->insert(p2);
    mySL->insert(p3);
    mySL->insert(p4);
    mySL->insert(p5);
    mySL->insert(p6);

    mySL->printData();

    cout << "-------------------------\n";

    Player removed ("p4", 50);
    mySL->Delete(removed);

    mySL->printData();
    return 0;
}