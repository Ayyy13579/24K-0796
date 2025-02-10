#include <iostream>
#include <tuple>
using namespace std;

class Robot {
    public:
    string name;
    int hits;
    int x;
    int y;
    tuple <int, int> Goal;
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
    void move(int &dx, int &dy) {
        x = dx;
        y = dy;
    }
    tuple <int,int> getPosition() {
        return make_tuple(x,y);
    }
    void isGoalReached(int &ballX, int &ballY) {
        if (ballX == 3 && ballY == 3) {
            cout << "Goal!" << endl;
        } else {
            cout << "No goal..." << endl;
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
    tuple <int, int> ball;
    tuple <int, int> goal;
    void startGame() {
        cout << "Game started!" << endl;
    }
    int play(Team* team1) {
        string direction;
        int ballX = 0, ballY = 0;
        cout << "Where do you want to hit the ball?" << endl;
        cin >> direction;
        int hits = team1->r1->hitBall(ballX, ballY, direction);
        team1->r1->move(ballX, ballY);
        team1->r1->isGoalReached(ballX, ballY);
        return hits;
    }
    void declareWinner(Robot* r1, Robot* r2) {
        if (r1->hits < r2->hits) {
            cout << "Team 1 is the winner!" << endl;
        } else if (r2->hits < r1->hits) {
            cout << "Team 2 is the winner!" << endl;
        }
    }
}