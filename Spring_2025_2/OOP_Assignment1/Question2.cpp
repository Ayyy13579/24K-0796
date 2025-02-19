#include <iostream>
#include <tuple>
using namespace std;

class Robot {
    public:
    string name;
    int hits = 0;
    int x;
    int y;
    tuple <int, int> Goal{3,3};
    int hitBall(int &ballX, int &ballY, const string &direction) {
        if (direction == "left") {
            ballX -= 1;
            hits += 1;
        } else if (direction == "right") {
            ballX += 1;
            hits += 1;
        } else if (direction == "up") {
            ballY += 1;
            hits += 1;
        } else if (direction == "down") {
            ballY -= 1;
            hits += 1;
        }
        return hits;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void move(int dx, int dy) {
        x = dx;
        y = dy;
    }
    tuple <int,int> getPosition() {
        return make_tuple(x,y);
    }
    bool isGoalReached(int &ballX, int &ballY) {
        if (ballX == 3 && ballY == 3) {
            cout << "Goal!" << endl;
            return true;
        } else {
            cout << "No goal..." << endl;
            cout << "Ball's coordinates: " << ballX << " " << ballY << endl;
            return false;
        }
    }
};

class Team {
    public:
    string teamName;
    Robot* r1;
};

class Game {
    public:
    Team team1;
    Team team2;
    tuple <int, int> ball{0,0};
    tuple <int, int> goal{3,3};
    void startGame() {
        bool won = false;
        cout << "Game started!" << endl;
        while (won == false) {
            play(&team1);
            if (team1.r1->isGoalReached(get<0>(ball), get<1>(ball))) {
                won = true;
                break;
            }
            play(&team2);
            if (team2.r1->isGoalReached(get<0>(ball), get<1>(ball))) {
                won = true;
                break;
            }
        }
    }

    int play(Team* team1) {
        string direction;
        int& ballX = get<0>(ball);
        int& ballY = get<1>(ball);
        cout << "Where do you want to hit the ball?" << endl;
        cin >> direction;
        int shoots = team1->r1->hitBall(ballX, ballY, direction);
        team1->r1->move(ballX, ballY);
        return shoots;
    }
    void declareWinner(Robot* r1, Robot* r2) {
        if (r1->hits < r2->hits) {
            cout << "Team 1 is the winner!" << endl;
        } else if (r2->hits < r1->hits) {
            cout << "Team 2 is the winner!" << endl;
        }
    }
};

int main() {
    Robot r1;
    Robot r2;
    Team t1;
    Team t2;
    t1.r1 = &r1;
    t2.r1 = &r2;
    Game g1;
    g1.startGame();
    g1.declareWinner(&r1, &r2);
}