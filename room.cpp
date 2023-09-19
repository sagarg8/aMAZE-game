#include <iostream>
#include <cstdlib>
using namespace std;

class Room {                    //The room class will structure the rooms for the maze. This structure includes the room and the door options for each room
private:
    int roomNumber = 0;         //initialising room number variables
    int door[2];                //initialising an empty array made for the 2 doors in each room

public:                         
    Room() {}                   //Default constructor

    Room(int roomNum, int door1, int door2) {
        roomNumber = roomNum;
        door[0] = door1;    
        door[1] = door2;
    }

    int getRoomNumber() {       //Getter method for the current room number of the user
        return roomNumber;
    }

    int* getDoors() {           //Getter method for the current door options
        return door;
    }
};