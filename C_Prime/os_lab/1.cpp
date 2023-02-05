#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int N = 10;    // 页表大小
const int n = 1000;  // 物理块数目
const int T = 1024;    // 页的大小

// 页表
struct PageTable
{
    int page_num;   // 逻辑页号
    int block_num;  // 物理块号
};

// 逻辑地址
struct LogicalAdd
{
    int page_num;  // 页号
    int page_add;  // 偏移量
};

PageTable pt[N];
LogicalAdd La;
bool visited[n];

// 产生随机数 防止产生映射到同一个物理页号
int g_random()
{
    srand((int)time(0));
    while (1) {
        int t = rand() % n;
        if (visited[t])
            continue;
        visited[t] = true;
        return t;
    }
}

void init()
{
    // 随机产生逻辑页号到物理页号的映射
    for (int i = 0; i < N; i++) {
        pt[i].page_num = i;
        pt[i].block_num = g_random();
    }

    cout << "*******************The page_table*****************" << endl;
    cout << "page_num: "
         << "\t"
         << "block_num: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "   " << pt[i].page_num << "       -->\t    " << pt[i].block_num
             << endl;
    }
    cout << "*******************The page_table*****************" << endl;
}

int solve(LogicalAdd la)
{
    for (int i = 0; i < N; i++) {
        if (pt[i].page_num != la.page_num)
            continue;
        cout << "block_num : " << pt[i].block_num << endl;
        return pt[i].block_num * T + la.page_add;
    }
    return -1;
}

int main()
{
    init();
    int pn, pa;
    cout << "please input page_num and page_add: " << endl;
    cin >> pn >> pa;
    La.page_num = pn;
    La.page_add = pa;
    int physcial_addr = -1;
    if (pa > 1024)
        cout << "error : block size : 1024  over range !" << endl;
    else
        physcial_addr = solve(La);
    // block_num * 1024 + page_add
    if (physcial_addr != -1)
        cout
            << " physcial addr = block_num * 1024 + page_add : physcial addr = "
            << physcial_addr << endl;
    else
        cout << "not found " << endl;

    return 0;
}
