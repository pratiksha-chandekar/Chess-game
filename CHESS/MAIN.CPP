#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class ChessBoard {
private:
    vector<vector<char>> board;

public:
    ChessBoard() : board(8, vector<char>(8, ' ')) {}

    void displayBoard() const {
        cout << "  a b c d e f g h\n";
        for (int i = 0; i < 8; ++i) {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; ++j) {
                cout << board[i][j] << " ";
            }
            cout << 8 - i << endl;
        }
        cout << "  a b c d e f g h\n";
    }

    void initializeBoard() {
        // Initialize pieces
        board[0] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
        board[1] = {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};
        for (int i = 2; i < 6; ++i) {
            board[i] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        }
        board[6] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
        board[7] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    }

    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        // Check for valid indices
        if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
            toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
            return false;
        }

        // Check if the selected piece can move to the destination
        char piece = board[fromRow][fromCol];
        if (piece == ' ' || (toRow == fromRow && toCol == fromCol)) {
            return false; // Empty cell or no movement
        }

        // Implement specific rules for each piece if needed

        return true;
    }

    void makeMove(int fromRow, int fromCol, int toRow, int toCol) {
        if (isValidMove(fromRow, fromCol, toRow, toCol)) {
            // Perform the move
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = ' ';
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
};

int main() {
    ChessBoard chessBoard;
    chessBoard.initializeBoard();

    cout << "Welcome to Chess!\n";
    chessBoard.displayBoard();

    int fromRow, fromCol, toRow, toCol;

    do {
        // Get the move from the player
        cout << "Enter your move (e.g., a2 to b3): ";
        char fromCoord, toCoord;
        cin >> fromCoord >> fromRow >> toCoord >> toRow;

        // Convert coordinates to indices
        fromCol = fromCoord - 'a';
        toCol = toCoord - 'a';
        fromRow = 8 - fromRow;
        toRow = 8 - toRow;

        // Make the move
        chessBoard.makeMove(fromRow, fromCol, toRow, toCol);

        // Display the updated board
        chessBoard.displayBoard();

        // Prompt for the next move
        cout << "Enter 'q' to quit or any other key to continue: ";
        char choice;
        cin >> choice;

        if (choice == 'q') {
            break;
        }

    } while (true);

    return 0;
}
