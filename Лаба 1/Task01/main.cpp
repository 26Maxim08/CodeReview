#include <fstream>
#include <iostream>
// FIXME ������祭�� ���ᯮ��㥬�� � �ணࠬ�� ������⥪�
//#include <string>
#include "main.h"
#include <vector>

using namespace std;
//FIXME �����४�� �������� ��ࠬ��஬ �㭪樨
//void find_numbers(vector <vector <int>> &Mvector, int i, int j, vector <int> &Wvector)


int main()
{
    //FIXME
    //int n, b, weight , volume, ind_i, ind_j; //k - �࠭� ��-�� �� ���������
    int n = 0;
    int b = 0;
    int weight = 0;
    int volume = 0;
    int ind_i = 0;
    int ind_j = 0;
    //FIXME ������� ��ࠡ��� ��������� �訡�� �� �⥭�� ������ �� 䠩��
    //ifstream stream;
    //stream.open("a.txt");

    ifstream stream("a.txt");
    if (!stream.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    stream >> n;
    stream >> b;

    //FIXME �� ������� ⨯ ��६����� � �� ����� � �� �������� ��譨� ����� � �����
    //vector <int> weight_vector(n+1);
    vector <int> weights(n);

    //FIXME �������� ����� ��稭����� � 0
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

    //FIXME �� ���뢠�� ������� 䠩� ��᫥ �⥭��
    stream.close();
    //vector <vector <int>> main_vector(n+1, vector <int>(b+1, 0));
    vector <vector <int>> dp(n+1, vector <int>(b+1, 0));
    vector <vector <int>> sum_volume(n+1, vector <int>(b+1, 0));


    for (int i = 1; i <= n; i++) {
        //FIXME ���� �� ������ �ॢ���� b
        //for (int j = 1; j <= b; j++)
        for (int j = 1; j < b; j++) {
            // FIXME �������� � 0
            //if (j >= weights[i])
            if (j >= weights[i-1]) {
                //FIXME �����४⭮�� ���� ��� � ��ꥬ� ���䠪⮢
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

    //FIXME ᫨誮� ᫮��� ������ � �ᯮ�짮������ ��������� 横��� O(n*b^2) � �ᯮ������ ����� ������ ��� ��६����� k � flag
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
    //FIXME ⥯��� ᫮������ O(n*b+1)
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

    //FIXME �㭪�� int main() ������ �������� 楫��᫥���� ���祭��
    return 0;
}
