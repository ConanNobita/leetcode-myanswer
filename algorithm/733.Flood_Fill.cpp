#include "common.h"

USESTD

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            std::vector<int>& colors = image[sr];
            fill(image, image.size(), colors.size(), sr, sc, colors[sc], color);
            return image;
        }
    
    private:
        void fill(vector<vector<int>>& image, int rows, int columns, int sr, int sc, int srcColor, int newColor) {
            if (sr < 0 || sr >= rows || sc < 0 || sc >= columns) {
                return;
            }
    
            vector<int>& colors = image[sr];
            int& color = colors[sc];
    
            if (color != srcColor || color == newColor) {
                return;
            }
    
            color = newColor;
            fill(image, rows, columns, sr + 0, sc - 1, srcColor, newColor);
            fill(image, rows, columns, sr + 0, sc + 1, srcColor, newColor);
            fill(image, rows, columns, sr - 1, sc - 0, srcColor, newColor);
            fill(image, rows, columns, sr + 1, sc + 0, srcColor, newColor);
        }
    };