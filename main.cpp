#include <iostream>
#include <vector>

class TicTacToe {
private:
  std::vector<std::vector<char>> board;
  char currentPlayer;

public:
  TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

  char getCurrentPlayer() const { return currentPlayer; }

  void drawBoard() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        std::cout << board[i][j];
        if (j < 2)
          std::cout << "|";
      }
      std::cout << "\n";
      if (i < 2)
        std::cout << "-----\n";
    }
  }

  bool makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
      return false;
    }
    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;
  }

  void makeAIMove() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (board[i][j] == ' ') {
          makeMove(i, j);
          return;
        }
      }
    }
  }

  char checkWin() {
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
          board[i][0] != ' ') {
        return board[i][0];
      }
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
          board[0][i] != ' ') {
        return board[0][i];
      }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != ' ') {
      return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != ' ') {
      return board[0][2];
    }
    return ' ';
  }
};

int main() {
  TicTacToe game;
  int row, col;
  while (true) {
    game.drawBoard();
    if (game.getCurrentPlayer() == 'X') {
      std::cout << "(number 0 - 2 separated by spaces)" << std::endl;
      std::cout << "Enter row and column: ";
      std::cin >> row >> col;
      if (!game.makeMove(row, col)) {
        std::cout << "Invalid move. Try again.\n";
        continue;
      }
    } else {
      game.makeAIMove();
    }
    char winner = game.checkWin();
    if (winner != ' ') {
      game.drawBoard();
      std::cout << "Player " << winner << " wins!\n";
      break;
    }
  }
  return 0;
}
