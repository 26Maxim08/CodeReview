#include <vector>
#include <iostream>
#include "main.h"

using namespace std;

void find_numbers(vector<vector<int>>& matrix, int row, int col, vector<int>& weights) {
    if (matrix[row][col] == 0) {
        return;
    }
    if (matrix[row - 1][col] == matrix[row][col]) {
        find_numbers(matrix, row - 1, col, weights);
    }
    else {
        cout << row << " ";
        //FIXME �� ४��ᨢ��� �맮�� ����室��� ���뢠�� ��� ⥪�饣� ���䠪�
        //find_numbers(Mvector, i - 1, j, Wvector);
        find_numbers(matrix, row - 1, col - weights[row - 1], weights);
    }
}

