#include "common.h"

USESTD

#include "common.h"

USESTD

class Solution {
    enum Direction {
        Left    = 0,
        Right   = 1,
        Up      = 2,
        Down    = 3
    };

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
          
        vector<int> row0 = matrix[0];
        Direction direction = Direction::Right;

        int rows = matrix.size(), columns = row0.size();
		int row = 0, column = 0, step = 0, total = rows * columns;
		int vertical = rows, horizontal = columns;
     
        while (step < total) {
            switch (direction) {
                case Direction::Left:
                {
                    vector<int>& rowArray = matrix[row];
                    for (int i = 0; i < horizontal; i++) {
                        result.push_back(rowArray[column--]);
                        step++;
                    }

                    row--;
                    column++;
                    vertical--;
                    direction = Direction::Up;
                }
                break;

                case Direction::Right:
                {
                    vector<int>& rowArray = matrix[row];
                    for (int i = 0; i < horizontal; i++) {
						result.push_back(rowArray[column++]);
						step++;
                    }

                    row++;
                    column--;
                    vertical--;
					direction = Direction::Down;
                }
                break;

                case Direction::Up:
                {
                    for (int i = 0; i < vertical; i++) {
                        vector<int>& rowArray = matrix[row--];
                        result.push_back(rowArray[column]);
                        step++;
                    }

                    row++;
                    column++;
                    horizontal--;
                    direction = Direction::Right;
                }
                break;

                case Direction::Down:
                {
                    for (int i = 0; i < vertical; i++) {
						vector<int>& rowArray = matrix[row++];
                        result.push_back(rowArray[column]);
                        step++;
                    }

                    row--;
                    column--;
                    horizontal--;
					direction = Direction::Left;
                }
                break;

                default:
                    break;
            }
        }

        return result;
    }
};