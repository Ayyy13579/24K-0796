#include <iostream>
using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        for (long i = 1; i <= 1000000000; ++i) {}
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        for (long i = 1; i <= 1000000000; ++i) {}
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        cout << "Starting juice making process..." << endl;
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready to serve!" << endl;
    }
};

int main() {
    JuiceMaker juicer;
    juicer.makeJuice();
    return 0;
}
