#include <iostream>
using namespace std;

// tasks to implement in this game

// [x] make 3 Dimensional array (grid)
// [x] show all data to user for play game
// [ ] take user choice and handle it using switch-case
// [ ] create 2 user to play game
// [ ] create functions for when user mark X and after that turn for 2nd user to mark 0
// [ ] check all status while any user mark (if X completed in row OR 0 completed)

// [!] handle update status using clear screen and print again result


string grid[3][3] = { {"1","2","3"},{"4","5","6"},{"7","8","9"} };

int playAgain;

bool switchUser = true;
bool gameOver = false;

int placeOnMark;

int trial = 1;

class status {
public:

    void getData() {

        system("cls");

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
        trial++;
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
            cout << "Invalid location choice...!" << endl;
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

    string gameResult() {

        // scanning in 1st row
        if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {
            gameOver = true;
            return grid[0][0];
        }
        // scanning in 2nd row
        else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {
            gameOver = true;
            return grid[1][0];
        }
        // scanning in 3rd row
        else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
            gameOver = true;
            return grid[2][0];
        }


        // scanning in 1st column
        else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {
            gameOver = true;
            return grid[0][0];
        }
        // scanning in 2nd column
        else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {
            gameOver = true;
            return grid[0][1];
        }
        // scanning in 3rd column
        else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) {
            gameOver = true;
            return grid[0][2];
        }

        // scanning in cross lines
        else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            gameOver = true;
            return grid[0][0];
        }
        else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            gameOver = true;
            return grid[0][2];
        }
        else {
            return "gameover";
        }
    }

    void declareResult() {
        cout << endl;

        if (gameResult() == "X") {
            if (gameOver) {
                status.getData();
                cout << "\tPlayer1 Won...!" << endl;
            }
        }
        else if (gameResult() == "0") {
            if (gameOver) {
                status.getData();
                cout << "\tPlayer2 Won...!" << endl;
            }
        }
        else {
            if (gameOver) {
                status.getData();
                cout << "\tGame Tie...!" << endl;
            }
        }
        trial = 0;
        cout << endl;
    }

}game;


int main() {


    while (true) {
        if (trial == 0) {
            cout << "Do you want to play again ? (yes:1 , no:2) : ";
            cin >> playAgain;
        }
        else {
            playAgain = 1;

            switch (playAgain) {
            case 1:
                while (!gameOver) {
                    if (trial >= 9)
                        break;
                    game.inputData();
                }
                break;
            case 2:
                exit(0);
                break;

            default:
                break;
            }
        }
    }

    return 0;
}