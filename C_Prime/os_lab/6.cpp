#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define random(x) rand() % (x)
using namespace std;

int Max[5][3];                 // 最大需要的资源数
int allocation[5][3];          // 已分配的资源数
int Need[5][3];                // 需要的资源数
int available[3] = {3, 3, 2};  // 可申请的资源数
bool st[5];

void init()
{
    int m[5][3] = {
        0};  // = {{7, 5, 3},{3, 2, 2},{9, 0, 2},{2, 2, 2},{4, 3, 3}};
    int a[5][3] = {0};  // = {0, 1, 0, 2, 0, 0, 3, 0, 2, 2, 1, 1, 0, 0, 2};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++) {
            m[i][j] = random(10);
            a[i][j] = random(7);
            if (a[i][j] > m[i][j])
                a[i][j] = m[i][j];
        }

    for (int i = 0; i < 3; i++)
        available[i] = random(15) + 3;

    memcpy(Max, m, sizeof Max);
    memcpy(allocation, a, sizeof a);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            Need[i][j] = m[i][j] - a[i][j];
}

void show()
{
    cout << "资源情况    Max      Allocation    Need     Available" << endl;
    cout << "           A B C       A B C       A B C      A B C" << endl;
    cout << "进程" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "F" << i << "         ";
        for (int j = 0; j < 3; j++)
            cout << Max[i][j] << " ";
        cout << "      ";
        for (int j = 0; j < 3; j++)
            cout << allocation[i][j] << " ";
        cout << "      ";
        for (int j = 0; j < 3; j++)
            cout << Need[i][j] << " ";

        cout << "      ";
        if (i == 0)
            for (int j = 0; j < 3; j++)
                cout << available[j] << " ";

        cout << endl;
    }
}

bool judge(int k)
{
    return available[1] >= Need[k][1] && available[0] >= Need[k][0] &&
           available[2] >= Need[k][2];
}

void banker()
{
    int cnt = 0;
    while (true) {
        bool flag = true;
        for (int i = 0; i < 5; i++)
            if (!st[i])
                flag = false;

        if (flag) {
            cout << "已找到安全序列并全部完成" << endl;
            break;  // 所有进程都结束之后就跳出循环
        }

        cout << "请输入请求资源的进程(";
        for (int i = 0; i < 5; i++)
            if (!st[i])
                printf("%d ", i);
        printf(")\n");

        int k;
        cin >> k;
        if (judge(k)) {
            cout << "进程" << k << "可以被运行" << endl;
            for (int i = 0; i < 3; i++) {
                available[i] += allocation[k][i];
                allocation[k][i] = Need[k][i] = 0;
            }

            st[k] = true;
        }
        else
            cout << "进程" << k << "无法运行" << endl;

        cnt++;
        if (cnt >= 10) {
            cout << "无法找到安全序列!!!" << endl;
            break;
        }

        show();
    }
}

int main()
{
    srand((int)time(0));
    init();
    show();
    banker();

    return 0;
}
