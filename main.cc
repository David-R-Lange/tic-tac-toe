#include <iostream>
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


int main() {
  char board[3][3] = { { ' ', ' ', ' ' }, 
                       { ' ', ' ', ' ' }, 
                       { ' ', ' ', ' ' } };

  char player = 'X';
  int row,col;
  int turn;

  cout << "Welcome to a simple terminal version of tic tac toe";

  // Game Loop
  for(turn = 0; turn < 9; ++turn) {
    drawBoard(board);

    while(true) {
      cout << "Player " << player << ", enter row (1-3) and column (1-3): ";
      cin >> row >> col;

      if(board[row-1][col-1] != ' ' || row < 1 || row > 3 || col < 1 || col > 3) {
        cout << "Invalid move. Try again\n";
      }
      else {
        break;
      }
    }

    board[row-1][col-1] = player;

    if(checkWin(board, player)) {
      drawBoard(board);
      cout << "Player " << player << " has won the match.";
      break;
    }

    // Switch player with the tertiary
    player = (player == 'X') ? 'O' : 'X';
  }
  
  if(turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
    cout << "It's a draw";
  }

  return 0;
}
