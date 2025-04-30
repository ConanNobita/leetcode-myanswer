#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size();
		if (rows == 0 || word.empty()) {
			return false;
		}

		int count = 0;
		vector<char>& column0 = board[0];
		vector<vector<int>> cache(rows, vector<int>(column0.size(), 0));

		backtract(board, cache, word, 0, 0, column0.size(), count);
		return count == word.size();
	}

private:
	void backtract(vector<vector<char>>& board, vector<vector<int>>& cache, string& word, int rows, int columns, int row, int column, int& count) {
		if (row < 0 || row >= board.size() || column < 0 || column >= columns) {
			return;
		}

		if (cache[row][column] != 0 || count == word.size()) {
			return;
		}

		if (board[row][column] == word[count]) {
			if ((row > 0 && cache[row - 1][column] == 1) || (row < rows - 1 && cache[row + 1][column] == 1) ||
				(column > 0 && cache[row][column - 1] == 1) || (column < columns - 1 && cache[row][column + 1] == 1)) {
				count++;
			}
		}

		backtract(board, cache, word, row - 0, column - 1, columns, count);
		backtract(board, cache, word, row + 0, column + 1, columns, count);
		backtract(board, cache, word, row - 1, column - 0, columns, count);
		backtract(board, cache, word, row + 1, column + 0, columns, count);
	}
};

int main(int argc, char* argv[]) {
	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};

	Solution solution;
	solution.exist(board, "ABCCED");
	return 0;
}