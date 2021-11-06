#include <iostream>
using namespace std;

// tasks to implement in this game

// [x] make 3 Dimensional array (grid)
// [x] show all data to user to play the game
// [ ] take user choice and handle it using switch-case
// [ ] create 2 users to play game
// [ ] create functions for when user marks X and after that turn for 2nd user to mark 0
// [ ] check all status while any user mark to conclude the game

// [!] handle update status using clear screen and print again result

string grid[3][3] = { {"1","2","3"},{"4","5","6"},{"7","8","9"} };



int playAgain, choice;

bool switchUser = true;
bool gameOver = false;

int placeOnMark;

int trial = 1;

// class defining the grid of the game after each user sets it's position
class status {
public:

    void getData() {

        // system("cls");

        cout << "--------- Tic-Tac-Toe Game ---------" << endl << endl;
        cout << "player[1] : X , player[2] : 0" << endl << endl;

        for (int i = 0;i < 3;i++) {
            cout << "\t";
            for (int j = 0;j < 3;j++) {
                cout << grid[i][j];
                if (j > 1) {
                    break;
                }
                cout << " | ";
            }
            cout << endl;
            if (i > 1) {
                break;
            }
            cout << "\t";
            cout << "--|---|---" << endl;
        }
        cout << endl;
    }
}status;

// class to take the position of user to mark in the grid
class gameLogic {
public:

    void inputData() {
        status.getData();
        if (switchUser) {
            cout << "Enter location for player[1] : ";
            switchUser = false;
        }
        else {
            cout << "Enter location for player[2] : ";
            switchUser = true;
        }
        cin >> placeOnMark;
        // trial++;
        updateGrid();
        declareResult();
    }

    void updateGrid() {
        switch (placeOnMark) {
        case 1:
            grid[0][0] = checkUser();
            break;
        case 2:
            grid[0][1] = checkUser();
            break;
        case 3:
            grid[0][2] = checkUser();
            break;
        case 4:
            grid[1][0] = checkUser();
            break;
        case 5:
            grid[1][1] = checkUser();
            break;
        case 6:
            grid[1][2] = checkUser();
            break;
        case 7:
            grid[2][0] = checkUser();
            break;
        case 8:
            grid[2][1] = checkUser();
            break;
        case 9:
            grid[2][2] = checkUser();
            break;
        default:
            cout << "Invalid location...!" << endl;
            break;
        }

    }

    string checkUser() {
        if (switchUser) {
            return "0";
        }
        else {
            return "X";
        }
    }

    // to check conditions to conclude the game
    string gameResult() {

        // scanning the 1st row
        if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {
            gameOver = true;
            return grid[0][0];
        }
        // scanning the 2nd row
        else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {
            gameOver = true;
            return grid[1][0];
        }
        // scanning the 3rd row
        else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
            gameOver = true;
            return grid[2][0];
        }
        // scanning the 1st column
        else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {
            gameOver = true;
            return grid[0][0];
        }
        // scanning the 2nd column
        else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {
            gameOver = true;
            return grid[0][1];
        }
        // scanning the 3rd column
        else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) {
            gameOver = true;
            return grid[0][2];
        }
        // scanning the diagonals
        else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            gameOver = true;
            return grid[0][0];
        }
        else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            gameOver = true;
            return grid[0][2];
        }
        else {
            // gameOver = false;
            // cout << "in gameResult" << endl;
            return "gameover";
        }
        // trial = 0;
    }

    // to declare result according to conditions checked previously
    void declareResult() {
        cout << endl;

        if (gameResult() == "X") {
            if (gameOver) {
                status.getData();
                cout << "\tPlayer 1 Won...!" << endl;
            }
        }
        else if (gameResult() == "0") {
            if (gameOver) {
                status.getData();
                cout << "\tPlayer 2 Won...!" << endl;
            }
        }
        else {
            // cout << "in declareResult" << endl;
            if (gameOver) {
                // cout << "Inside if loop" << endl;
                status.getData();
                cout << "\tGame Tie...!" << endl;
            }
        }
        // trial = 0;
        cout << endl;
    }
}game;

// int main()
// {
//     cout << "WELCOME TO GAME... " << endl;
    // cout << "1. New game" << endl
    //      << "2. Rematch" << endl
    //      << "3. Exit" << endl;
    // cout << "Enter your choice: " ;
    // cin >> playAgain;
    // cout << endl;

    // switch (playAgain)
    // {
    //     case 1:
            // while(true)
            // {
            //     game.inputData();
                // if(trial == 0)
                // {
                //     cout << "Game over!" << endl;
                //     cout << "Do you want to play again? (yes:1, no:2): ";
                //     cin >> choice;
                //     cout << endl;
                    // switch (choice)
                    // {
                    //     case 1:
                    //         game.inputData();
                    //     break;
                    //     case 2:
                    //         cout << "Hope you enjoued playing. " << endl;
                    //         break;
                    //     default:
                    //         cout << "Invalid option.!" << endl;
                    //         break;
                    // }
                // }
            // }

    //         break;


    // }
    // return 0;
// }

// int main() {

//     while (true) {
//         if (trial == 0) {
//             cout << "============================================ " << endl;
//             cout << "Do you want to play again ? (yes:1 , no:2) : ";
//             cin >> playAgain;


//             cout << "Trial : " << trial << endl;
//             // trial = 1;         
//         }
//         else {
//             playAgain = 1;     
//             cout << "Welcome.. " << endl;       
//         }
//         switch (playAgain) {
//         case 1:

//             while (!gameOver) {
//                 if (trial > 9){
//                     // cout << "Game draw" << endl;
//                     break;   
//                 }
//                 else
//                 {
//                     game.inputData();
//                     // trial++;
//                     // cout << "Trial : " << trial << endl;

//                 }
//             }
//             break;
//         case 2:
//             cout << "Hope you enjoyed playing." << endl;
//             exit(0);
//             break;

//         default:
//             cout << "Invalid choice!" << endl;
//             exit(0);
//             break;
//         }

//     }
//     return 0;
// }


