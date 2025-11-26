#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

char dungeon[ROWS][COLS];
int playerX = 1, playerY = 1;
int currentLevel = 1;


// ===================== LINKED LIST INVENTORY =====================
struct Item {
    string name;
    Item* next;
};
Item* inventory = NULL;

void addItem(string name) {
    Item* temp = new Item;
    temp->name = name;
    temp->next = inventory;
    inventory = temp;
    cout << " + Added to inventory: " << name << endl;
}

void displayInventory() {
    cout << "\n--- Inventory ---\n";
    Item* ptr = inventory;
    if (!ptr) cout << "(empty)\n";
    while (ptr != NULL) {
        cout << " - " << ptr->name << endl;
        ptr = ptr->next;
    }
    cout << "----------------\n";
}

void sortInventory() {
    for (Item* i = inventory; i != NULL; i = i->next) {
        for (Item* j = i->next; j != NULL; j = j->next) {
            if (i->name > j->name) {
                string temp = i->name;
                i->name = j->name;
                j->name = temp;
            }
        }
    }
    cout << "Inventory sorted!\n";
}

bool searchInventory(string name) {
    Item* ptr = inventory;
    while (ptr != NULL) {
        if (ptr->name == name) return true;
        ptr = ptr->next;
    }
    return false;
}


// ===================== STACK FOR LEVEL HISTORY =====================
struct LevelNode {
    int level;
    LevelNode* next;
};
LevelNode* levelStack = NULL;

void pushLevel(int level) {
    LevelNode* temp = new LevelNode;
    temp->level = level;
    temp->next = levelStack;
    levelStack = temp;
}
void popLevel() {
    if (!levelStack) return;
    LevelNode* t = levelStack;
    levelStack = levelStack->next;
    delete t;
}
int peekLevel() {
    return levelStack ? levelStack->level : 1;
}


// ===================== STACK FOR PLAYER POSITION HISTORY =====================
struct MoveNode {
    int x, y;
    MoveNode* next;
};
MoveNode* moveStack = NULL;

void pushMove(int x, int y) {
    MoveNode* t = new MoveNode;
    t->x = x; t->y = y;
    t->next = moveStack;
    moveStack = t;
}
void undoMove() {
    if (!moveStack) return;
    MoveNode* t = moveStack;
    dungeon[playerX][playerY] = '.';
    playerX = t->x;
    playerY = t->y;
    dungeon[playerX][playerY] = 'P';
    moveStack = moveStack->next;
    delete t;
    cout << "Undo successful.\n";
}


// ===================== QUEUE FOR MONSTER TURNS =====================
struct MonsterQ {
    int mx, my;
    MonsterQ* next;
};
MonsterQ* front = NULL;
MonsterQ* rear = NULL;

void enqueueMonster(int x, int y) {
    MonsterQ* t = new MonsterQ;
    t->mx = x; t->my = y;
    t->next = NULL;
    if (!rear) front = rear = t;
    else rear->next = t, rear = t;
}

void monsterTurn() {
    if (!front) return;
    cout << "Monster rattles nearby...\n";
    MonsterQ* t = front;
    front = front->next;
    if (!front) rear = NULL;
    delete t;
}


// ===================== RECURSION MAZE SOLVER =====================
bool solveMaze(int x, int y) {
    if (dungeon[x][y] == '#') return false;
    if (x == ROWS - 2 && y == COLS - 2) return true;

    dungeon[x][y] = '*';

    if (solveMaze(x+1,y) || solveMaze(x,y+1) || solveMaze(x-1,y) || solveMaze(x,y-1))
        return true;

    dungeon[x][y] = '.';
    return false;
}


// ===================== LEVEL LOADING =====================
void loadLevel(int level) {
    cout << "\n=== Loading Level " << level << " ===\n";

    // Walls + Empty
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            dungeon[i][j] = (i==0||j==0||i==ROWS-1||j==COLS-1) ? '#' : '.';

    // Reset monsters queue
    front = rear = NULL;

    // Reset player
    playerX = 1; playerY = 1;

    // Level Layouts
    if (level == 1) {
        dungeon[3][5]='C'; dungeon[7][4]='C';
        dungeon[5][6]='M'; enqueueMonster(5,6);
        dungeon[8][8]='E';
    }
    if (level == 2) {
        dungeon[2][4]='#'; dungeon[3][4]='#'; dungeon[4][4]='#';
        dungeon[3][6]='C';
        dungeon[6][7]='M'; enqueueMonster(6,7);
        dungeon[8][8]='E';
    }
    if (level == 3) {
        dungeon[4][3]='#'; dungeon[5][3]='#'; dungeon[6][3]='#';
        dungeon[5][5]='M'; enqueueMonster(5,5);
        dungeon[8][8]='E';
    }

    dungeon[playerX][playerY] = 'P';
}

void displayMap() {
    cout << "\n===== LEVEL " << currentLevel << " =====\n";
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cout << dungeon[i][j] << " ";
        }
        cout << endl;
    }
}


// ===================== PLAYER MOVEMENT =====================
void movePlayer(char mv) {
    int newX = playerX, newY = playerY;
    if(mv=='W'||mv=='w') newX--;
    if(mv=='S'||mv=='s') newX++;
    if(mv=='A'||mv=='a') newY--;
    if(mv=='D'||mv=='d') newY++;

    if (dungeon[newX][newY] == '#') return;

    pushMove(playerX, playerY);

    if(dungeon[newX][newY]=='C'){
        addItem("Sword");
    }
    if(dungeon[newX][newY]=='M'){
        cout<<"Monster defeated!\n";
        addItem("Monster Claw");
    }
    if(dungeon[newX][newY]=='E'){
        cout<<"\nLevel Complete!\n";
        pushLevel(currentLevel);
        currentLevel++;

        if(currentLevel > 3){
            cout<<"\n🎉 You Escaped The Dungeon!! 🎉\n";
            exit(0);
        }
        loadLevel(currentLevel);
        return;
    }

    dungeon[playerX][playerY]='.';
    playerX = newX;
    playerY = newY;
    dungeon[playerX][playerY]='P';
}


// ===================== MAIN =====================
int main() {
    loadLevel(1);
    char input;

    while(true) {
        displayMap();
        cout << "\nControls:\n";
        cout << "W/A/S/D = Move | U=Undo | I=Inventory | T=Sort | F=Search | M=Solve | B=Back Level | Q=Quit\n";
        cout << "Choice: ";
        cin >> input;

        if(input=='Q'||input=='q') break;
        if(input=='U'||input=='u'){ undoMove(); continue; }
        if(input=='I'||input=='i'){ displayInventory(); continue; }
        if(input=='T'||input=='t'){ sortInventory(); continue; }
        if(input=='F'||input=='f'){
            string name;
            cout<<"Enter item to search: "; cin>>name;
            cout<<(searchInventory(name)?"Found!\n":"Not found!\n");
            continue;
        }
        if(input=='M'||input=='m'){
            if(solveMaze(playerX,playerY)) cout<<"Path found!\n";
            else cout<<"No path exists!\n";
            continue;
        }
        if(input=='B'||input=='b'){
            if(levelStack){
                currentLevel = peekLevel();
                popLevel();
                loadLevel(currentLevel);
            }
            else cout<<"Already at Level 1!\n";
            continue;
        }

        movePlayer(input);
        monsterTurn();
    }

    cout << "\nGame Over!\n";
    return 0;
}
