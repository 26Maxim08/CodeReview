#include <fstream>
#include <iostream>
// FIXME подключение неиспользуемой в программе библиотеки
//#include <string>
#include "main.h"
#include <vector>

using namespace std;
//FIXME некорректные названия параметром функции
//void find_numbers(vector <vector <int>> &Mvector, int i, int j, vector <int> &Wvector)


int main()
{
    //FIXME
    //int n, b, weight , volume, ind_i, ind_j; //k - убрана из-за не надобности
    int n = 0;
    int b = 0;
    int weight = 0;
    int volume = 0;
    int ind_i = 0;
    int ind_j = 0;
    //FIXME добавьте обработку возможных ошибок при чтении данных из файла
    //ifstream stream;
    //stream.open("a.txt");

    ifstream stream("a.txt");
    if (!stream.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    stream >> n;
    stream >> b;

    //FIXME не повторяйте тип переменной в ее имени и не добавляйте лишний элемент в векторе
    //vector <int> weight_vector(n+1);
    vector <int> weights(n);

    //FIXME индексация вектора начинается с 0
    //for (int i = 1; i <= n; i++)
    //    stream >> weight_vector[i];
    for (int i = 0; i < n; i++) {
        stream >> weights[i];
    }

    //vector <int> volume_vector(n+1);
    vector <int> volumes(n);

    //for (int i = 1; i <= n; i++)
    //    stream >> volume_vector[i];
    for (int i = 0; i < n; i++) {
        stream >> volumes[i];
    }

    //FIXME не забывайте закрыть файл после чтения
    stream.close();
    //vector <vector <int>> main_vector(n+1, vector <int>(b+1, 0));
    vector <vector <int>> dp(n+1, vector <int>(b+1, 0));
    vector <vector <int>> sum_volume(n+1, vector <int>(b+1, 0));


    for (int i = 1; i <= n; i++) {
        //FIXME масса не должна превышать b
        //for (int j = 1; j <= b; j++)
        for (int j = 1; j < b; j++) {
            // FIXME индексация с 0
            //if (j >= weights[i])
            if (j >= weights[i-1]) {
                //FIXME некорректного расчета веса и объема артефактов
                //main_vector[i][j] = main_vector[i-1][j] + weight_vector[i];
                //sum_volume_vector[i][j] = sum_volume_vector[i-1][j] + volume_vector[i];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
                sum_volume[i][j] = max(sum_volume[i - 1][j], sum_volume[i - 1][j - weights[i - 1]] +
                    volumes[i - 1]);
            } else {
                dp[i][j] = dp[i-1][j];
                sum_volume[i][j] = sum_volume[i-1][j];
            }
        }
    }

    //FIXME слишком сложный алгоритм с использованием вложенных циклов O(n*b^2) и используется лишняя память для переменных k и flag
    /*k = b;
    bool flag = true;
    while (flag == true && k >= 1)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = b; j >= 1; j--)
            {
                if (main[i][j] == k)
                {
                    ind_i = i; ind_j = j;
                    weight = main[i][j];
                    volume = sum_volume[i][j];
                    flag = false;
                }
                if (flag == false)
                    break;
            }
            if (flag == false)
                    break;
        }
        k--;
    }*/
    //FIXME теперь сложность O(n*b+1)
    for (int i = n; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            if (dp[i][j] > 0 && dp[i][j] < b) {
                ind_i = i;
                ind_j = j;
                weight = dp[i][j];
                volume = sum_volume[i][j];
                goto exit_search;
            }
        }
    }
    exit_search:
    if (weight == 0) {
        weight = 0;
        volume = 0;
    }

    cout << "weight: " << weight << " volume: " << volume << endl;
    cout << "artifact numbers: ";
    find_numbers(dp, ind_i, ind_j, weights);

    //FIXME функция int main() должна возвращать целочисленное значение
    return 0;
}
