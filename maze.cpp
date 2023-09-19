#include "room.cpp"

class Maze {                        //initialisation of the Maze class. Here the maze is made and includes the various methods needed including the game itself 
private:                        
    Room rooms[7];                      //array of 7 rooms
    int currentRoom = rand() % 2;       //starts in either room 1 or 2
    int attempts = 0;                   //max of 10 attempts allowed
    int hasKey = false;                 //whether the user has obtained the key or not.
    int roomWithKey = rand() % 2 + 4;   //the key will be randlomly placed in either room 4 or 5
    int choice = 0;                     //initialising the variable for the user door choice

public:
    Maze() {                        //this is the initialisation with the room number followed by the 2 door options for each room
        rooms[0] = Room(1, 2, 6);
        rooms[1] = Room(2, 5, 1);
        rooms[2] = Room(3, 4, 7);
        rooms[3] = Room(4, 5, 3);
        rooms[4] = Room(5, 4, 2);
        rooms[5] = Room(6, 1, 7);
        rooms[6] = Room(7, 6, -1);  //-1 represents the exit so if the user selects room 7, they win
    }

    int getAttemptsLeft() const {   //Getter method for the current room number of the user
        int attemptsLeft = 10-attempts;
        return attemptsLeft;
    }

    void playerChoice() {
        cout << "Which door would you like to choose? Enter 1 or 2: \n";
        cin >> choice;
    }

    void keyStatus() const {         //Getter method for whether the player found the key or not
        if (hasKey == false) {
            cout << "You still need to find the key!" << endl;
        }
        else if (hasKey == true) {
            cout << "You've got the key! Just find the exit." << endl;
        }
    }

    void play() {                   //the game method that the user interacts with
        cout << "\nWelcome to my game, aMAZE! You are in one of seven rooms of my maze!" << endl;
        cout << "You must reach the exit (room 7) before your lives run out!" << endl;
        cout << "Be aware, one of the rooms has a lion!" << endl;
        cout << "Step foot in there and you're it's dinner!" << endl;
        cout << "You are currently in room "<< rooms[currentRoom].getRoomNumber() <<".\n"<< endl;

        while (true) {
            int* door = rooms[currentRoom].getDoors();      //pointer for current door points at the room and then uses a getter method to get the doors for said room

            cout << "You have " << getAttemptsLeft() << " attempts left to escape!" << endl;
            if (getAttemptsLeft() == 0) {
                cout << "You're on your last chance...\n" << endl;
            }
            cout << "The key is in room " << roomWithKey << ". You'll need it to exit." << endl;
            keyStatus();
            cout << "\nYou have two doors to choose from: Door 1 leads to Room " << door[0] << ", Door 2 leads to Room " << door[1] << endl;

            playerChoice();       
            
            if (choice < 1 || choice > 2) {         //ensures that the user input is valid. Only door 1 or 2
                cout << "Invalid choice, please enter doors 1 or 2." << endl;
                continue;
            }

            if (choice == 1) {                      //the options if the user chooses door 1, no matter the room
                currentRoom = door[0] - 1;  

                //since i've set the key to be randomly placed in rooms 4 or 5, this if statement will check-
                //-whether the user is in the room with the key. If so, hasKey will be set to true and room 7 is accessible

                if (rooms[currentRoom].getRoomNumber() == 4 || rooms[currentRoom].getRoomNumber() == 5) { 
                    if (rooms[currentRoom].getRoomNumber() == roomWithKey) {
                        hasKey = true;
                        cout << "You've found the key! Make your way to the exit!" << endl;
                    }
                }
            }
            else if (choice == 2) {                 //the options if the user chooses door 2, no matter the room

                //the if statement here prevents the user from moving to room 7 without the key being true
                //the continue means it does not change the current room so the user stays where they are but it will cost them an attempt

                if (rooms[currentRoom].getRoomNumber() == 6 && hasKey == false) {
                    cout<< "\nYou can't access room 7 without the key! Go back and find it!" << endl;
                    cout << "You are still in room " << rooms[currentRoom].getRoomNumber() << "\n"<< endl;
                    continue;
                }
                currentRoom = door[1] - 1;
            }

            //this if statement is for if the user enters room 3 which will cause their death so the game ends. Extreme i know

            if (rooms[currentRoom].getRoomNumber() == 3) {
                cout << "You entered Room 3 and failed! Game over." << endl;
                break;
                //the break ends the game
            }

            //below is the winning scenario. if room 7 is selected, the user wins

            else if (rooms[currentRoom].getDoors()[1] == -1) {
                if (hasKey == true) {
                   cout << "Congratulations, you found the exit! You win aMAZE!" << endl;
                break;
                //the break ends the game
                }
            }

            attempts++;        //everytime an attempt is made, the number of attempts is incremented
            getAttemptsLeft();

            if (attempts > 10) {     //once 10 attempts are exceeded, the game is over
                cout << "Your 10 lives are up! You'll be stuck in my progr- I mean maze forever!" << endl;
                break;
            }

            cout << "\nYou are now in room " << rooms[currentRoom].getRoomNumber() << endl;
            //placed this at the end so the players position is always clear and they dont have to remember and will show whether they pass certain if statements or not
        }

    cout << "Game over." <<endl;
    //this will print only when the while loop is finished
    }
};

int main() {
    srand(time(NULL)); // Seeds the random number generator

    //an object of the maze class is made

    Maze game;
    game.play();

    //Here the play class is called with the game object and the game begins

    return 0;
}