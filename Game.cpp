#include <bits/stdc++.h>
#include "SkipList.cpp"
#include <map>
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
private:
    map<string, int> mp;
public:
    SkipList<Player> *board;
    GameManger(){
        Player head ("head", INT_MIN), tail ("tail", INT_MAX);
        board = new SkipList<Player>(head, tail);
    }
   
    void Join(){
        string name;
        int initScore = 0;
        cout << "Enter your name: ";
        cin >> name;
        Player player = Player(name, initScore);
        if(CheckIfExist(player)){
            cout << name << " is already in the game!" << endl;
        } else {
            mp[name] = initScore;
            board->insert(player);
            cout << name << " have joined the game!" << endl;
        }
    }

    void Join(Player player){
        
        if(CheckIfExist(player)){
            cout << player.Name << " is already in the game!" << endl;
        } else {
            mp[player.Name] = player.score;
            board->insert(player);
            cout << player.Name << " have joined the game!" << endl;
        }
    }
    bool CheckIfExist(Player player){
        if(board->Search(player))
            return true;
        return false;
    }
        
    void GetTop_N_Players(){
        int N;
        cout << "Enter the number of top players to display: ";
        cin >> N;  
        board->printTopN(N);
    }
    
    void GetPlayers(){
        board->print();
    }
    
    void PrintPlayerScore(){
        string name;
        cout << "Enter the name of the player: ";
        cin >> name;
        Player targetPlayer(name, mp[name]);
        cout << board->Search(targetPlayer)->key << endl;        
    }
    
    void Leave(){
        string name;
        cout << "Enter your name: ";
        cin >> name;
        Player deletedPlayer(name , mp[name]);
        board->Delete(deletedPlayer);
        mp.erase(deletedPlayer.Name);
    }
    void LeaveByName(string name){
        Player deletedPlayer(name , mp[name]);
        if(CheckIfExist(deletedPlayer)){
            board->Delete(deletedPlayer);
            mp.erase(deletedPlayer.Name);
        } else {
            cout << "This player is not in the game!" << endl;
        }
    }
    void Update(){
        string name;
        int newScore;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your new score: ";
        cin >> newScore;
        Player updatedPlayer(name, newScore);
        this->LeaveByName(name);
        this->Join(updatedPlayer);
    }

};


void printMenu() {
    cout << "Game Menu:" << endl;
    cout << "1. Join Game" << endl;
    cout << "2. Print Player Score" << endl;
    cout << "3. Print Top N Players" << endl;
    cout << "4. Leave Game" << endl;
    cout << "5. Update Score" << endl;
    cout << "6. Retrive All Players" << endl;
    cout << "7. Exit" << endl;
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
                manager.Update();
                return;
            case 6:
                manager.GetPlayers();
                break;
            case 7:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


int main() {
    // Player head ("head", INT_MIN), tail ("tail", INT_MAX);
    // SkipList<Player> *mySL = new SkipList<Player>(head, tail);
    // Player p1("p1", 10);
    // Player p2("p2", 20);
    // Player p3("p3", 30);
    // Player p4("p4", 50);
    // Player p5("p5", 50);
    // Player p6("p6", 2);

    // mySL->insert(p1);
    // mySL->insert(p2);
    // mySL->insert(p3);
    // mySL->insert(p4);
    // mySL->insert(p5);
    // mySL->insert(p6);

    // mySL->printSkipList();

    // cout << "-------------------------\n";

    mySL->print();

    // mySL->printSkipList();
    
    
    GameManger manager;
    menu(manager);

    Player removed ("p4", 50);
    mySL->Delete(removed);

    mySL->print();
    return 0;
}