#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
const int M = 10;    // 页目录表大小
const int N = 10;    // 页表大小
const int n = 1000;  // 物理块数目
const int T = 1024;    // 页的大小
// 页目录表
struct CatalogPage
{
    int page_num;   // 一级页号
    int block_num;  // 物理块号
};
// 页表
struct PageTable
{
    int page_num;   // 二级页号
    int block_num;  // 物理块号
};
// 逻辑地址
struct LogicalAdd
{
    int page_num_1;  // 一级页号
    int page_num_2;  // 二级页表
    int page_add;    // 偏移量
};
CatalogPage cp[M];   // 页目录表
PageTable pt[M][N];  // 页表
bool visited[n];
LogicalAdd La;

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
    // 产生一级逻辑页号到物理页号的映射
    for (int i = 0; i < M; i++) {
        cp[i].page_num = i;
        cp[i].block_num = i;
        visited[i] = true;
    }
    // 随机产生二级逻辑页号到物理页号的映射
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            pt[i][j].page_num = g_random();
            pt[i][j].block_num = g_random();
        }
    }

    cout << "******************* The Catalog Page*****************" << endl;
    cout << "1_page_num: "
         << "\t"
         << "block_num: " << endl;
    for (int i = 0; i < M; i++) {
        cout << "   " << cp[i].page_num << "       -->\t    " << cp[i].block_num
             << endl;
    }
    cout << "******************* The Catalog Page*****************" << endl;

    cout << "*******************The page_table*****************" << endl;
    for (int i = 0; i < M; i++) {
        cout << "The page_table: " << i << endl;
        cout << "2_page_num: "
             << "\t\t"
             << "block_num: " << endl;
        for (int j = 0; j < N; j++) {
            cout << "   " << pt[i][j].page_num << "\t   -->  \t"
                 << pt[i][j].block_num << endl;
        }
    }
    cout << "*******************The page_table*****************" << endl;
}

int solve(LogicalAdd la)
{
    int page_2 = -1;
    // 寻找一级列表
    for (int i = 0; i < M; i++) {
        if (la.page_num_1 == cp[i].page_num)
            page_2 = i;
    }
    if (page_2 == -1)
        return -1;  // 没找到二级页表 ，非法
    cout << "pagetbale block num :" << page_2 << endl;
    // 寻找二级列表
    for (int j = 0; j < N; j++) {
        if (pt[page_2][j].page_num != la.page_num_2)
            continue;
        cout << "block_num : " << pt[page_2][j].block_num << endl;
        return pt[page_2][j].block_num * T + la.page_add;
    }
    return -1;  // 没找到真物理地址，非法
}

int main()
{
    init();
    int pn1, pn2, pa;
    cout << "please input page_num_1 ,page_num_1, and page_add: " << endl;
    cin >> pn1 >> pn2 >> pa;
    La.page_num_1 = pn1;
    La.page_num_2 = pn2;
    La.page_add = pa;
    int physcial_addr = -1;
    if (pa > 1024)
        cout << "error : block size : 1024  over range !" << endl;
    else
        physcial_addr = solve(La);
    // block_num * 1024 + page_add
    if (physcial_addr != -1)
        cout << " physcial addr = block_num * 1024 + page_add : physcial addr = "
             << physcial_addr << endl;
    else
        cout << "not found "<<endl;

    return 0;
}
