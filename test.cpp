#include <iostream>
#include <cassert>
#include "maze.cpp"
using namespace std;

void test_room() {
    Room r1(1, 2, 3);
    assert(r1.getRoomNumber() == 1);
    int* doors = r1.getDoors();
    assert(doors[0] == 2);
    assert(doors[1] == 3);
}

void test_maze() {
    Maze mazeTest;
    assert(mazeTest.getAttemptsLeft() == 10);
    mazeTest.playerChoice(); // simulate player input
    mazeTest.keyStatus(); // should print "You still need to find the key!"
    mazeTest.play(); // play the game
    // assert something about the final state of the game
}

int main() {
    test_room();
    test_maze();
    cout << "All tests passed!" << endl;
    return 0;
}
