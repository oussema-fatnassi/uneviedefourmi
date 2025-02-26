#include <iostream>
#include "Headers/Coucou.hpp"
#include "Headers/Ant.hpp"
using namespace std;

int main() {
    Coucou coucou;
    coucou.hello();
    Ant F1;
    Ant F2;
    F1.lookAround();
    F2.lookAround();
    F1.stay();
    F2.stay();
    F1.move("S1");
    F2.move("S2");
    F1.stay();
    F2.stay();
    F1.move("Sd");
    F2.move("Sd");
    F1.stay();
    F2.stay();
    return 0;
}
