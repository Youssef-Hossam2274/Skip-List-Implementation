#include <bits/stdc++.h>
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

    void operator<<(const Player& other) const {
        cout << this->Name << "   " << this->score << endl;
    }

};

class GameManger {
public:
    
GameManger(){}
    void Join(string name , int score = 0){
        
    }
    void Leave(string name){

    }
    void GetTop_N_Players(){
        
    }
};
