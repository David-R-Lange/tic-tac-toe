#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void drawBoard(char board[3][3]) {
  cout << "-------------\n";
  for(int i = 0; i < 3; ++i) {
    cout << "| ";
    for(int j = 0; j < 3; ++j) {
      cout << board[i][j] << " | ";
    }
    cout << "\n-------------\n";
  }
}

bool checkWin(char board[3][3], char player) {

  for(int i = 0; i < 3; ++i) {
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      return true;
    }
  }
  return false;
}

bool isNumber(string s) {
  for(int i = 0; i < s.length(); ++i) {
    if( !isdigit( s[i] )) {
      return false;
    }
  }
  return true;
}


int main() {
  char board[3][3] = { { ' ', ' ', ' ' }, 
                       { ' ', ' ', ' ' }, 
                       { ' ', ' ', ' ' } };

  char player = 'X';
  string rowInput,colInput;
  unsigned int row, col;
  int turn;

  cout << "Welcome to a simple terminal version of tic tac toe\n";

  // Game Loop
  for(turn = 0; turn < 9; ++turn) {
    drawBoard(board);

    while(true) {
      cout << "Player " << player << ", enter row (1-3) and column (1-3): ";
      cin >> rowInput >> colInput;

      if(!isNumber(rowInput) || !isNumber(colInput)) {
        cout << "Please enter only numbers" << endl;
        continue;
      }

      row = (stoul(rowInput) - 1) % 3;
      col = (stoul(colInput) - 1) % 3;

      if(board[row][col] != ' ') {
        cout << "Invalid move. Try again\n";
        continue;
      }

      break;
    }

    board[row][col] = player;

    if(checkWin(board, player)) {
      drawBoard(board);
      cout << "Player " << player << " has won the match.";
      break;
    }

    // Switch player with the tertiary
    player = (player == 'X') ? 'O' : 'X';
  }
  
  if(turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
    drawBoard(board);
    cout << "It's a draw\n";
  }

  return 0;
}
