//� - ��� �᫠.�।� �ᥫ � ��⥬� ��᫥��� � �᭮������ K(2?K?10) ��।�����
//᪮�쪮 ������� �ᥫ �� N(1 < N < 20, N + K < 26) ࠧ�冷� ⠪��, �� � �� �����
//ᮤ�ন��� ��� � ����� ����� ����� �㫥�.��� ⮣�, �⮡� �������� ��९�������, �⢥�
//�।�⠢�� � ���� ����⢥����� �᫠.

#include <iostream>
#include <cmath>


using namespace std;

int main() {
    //FIXME ������� ����䨪���
    setlocale(LC_ALL, "ru");
    int k, n;

    cout << "������ K (2<=K<=10) : ";
    cin >> k;

    cout << "������ N (1<N<20, N+K<26) : ";
    cin >> n;

    double nz, oz, tz;
    nz = k - 1; // ��᫠ ��� ������ �㫥�
    oz = 1;     // ��᫠, �����稢��騥�� �� 0 (��� ����� ����� �㫥�)
    tz = 0;     // ��᫠, ᮤ�ঠ騥 ����� ���騥 �㫨

    for (int i = 2; i <= n; i++) {
        double _nz = nz;
        double _oz = oz;
        double _tz = tz;

        nz = (_nz + _oz) * (k - 1);
        oz = _nz;
        tz = _tz * k + _oz;
    }

    //FIXME �� �ॡ���� � �����
    //cout << "��᫠ ��� ���� ����� ����� �㫥�: " << fixed << nz + oz << "\n";
    cout << "��᫠ � ���� � ����� ����� ���騬� ��ﬨ: " << fixed << tz << "\n";

    return 0;
}
