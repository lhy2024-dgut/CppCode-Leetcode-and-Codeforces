//Leetcode 221. Maximal Square

#include <iostream>  
#include <vector>     
#include <algorithm>  

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max1 = 0;
        int square[301][301] = {0};
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    continue;
                }
                else{
                    if(i - 1 < 0 || j - 1 < 0){
                        square[i][j] = 1;
                        max1 = max(max1, 1);
                    }
                    else{
                        square[i][j] = min(square[i - 1][j], min(square[i][j - 1], square[i - 1][j - 1])) + 1;
                        max1 = max(max1, square[i][j]);
                    }
                }
            }
        }
        return max1 * max1;
    }
};


//核心代码：square[i][j] = min(square[i - 1][j], min(square[i][j - 1], square[i - 1][j - 1])) + 1;
/*
在matrix[i][j] == '1'的情况下，square[i][j]的值取决于它左边、上边和左上方的三个位置的square值。具体来说：
- square[i - 1][j]：表示上方位置的最大正方形边长。
- square[i][j - 1]：表示左边位置的最大正方形边长。
- square[i - 1][j - 1]：表示左上方位置的最大正方形边长。
要形成一个新的正方形，当前的square[i][j]必须至少为1
*/