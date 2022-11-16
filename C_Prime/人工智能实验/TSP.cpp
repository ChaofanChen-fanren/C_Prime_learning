// 用遗传算法求解TSP问题
#include "math.h"
#include "time.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace::std;
// 遗传算法参数
#define POPSIZE 100  // 种群规模
#define GEN 200      // 迭代次数
#define PC 0.85      // 交叉概率
#define PM 0.15      // 变异概率

#define CITY_NUM 10     // 城市编号是0~CITY_NUM-1
#define MAXVALUE 10000  // 路径越短越好
#define N 3000          // 需要根据实际求得的路径值修正
unsigned seed = (unsigned)time(0);

int Hash[CITY_NUM + 1];
typedef struct CityPosition
{
    int x;
    int y;
} CityPosition;

// 10城市坐标
CityPosition
CityPos[10]={{87,7},{91,38},{83,46},{71,44},{64,60},{68,58},{83,69},{87,76},{74,78},{71,71}};

// 30城市坐标

// CityPosition
// CityPos[30]={{87,7},{91,38},{83,46},{71,44},{64,60},{68,58},{83,69},{87,76},{74,78},{71,71},
// {58,69},{54,62},{51,67},{37,84},{41,94},{2,99},{7,64},{22,60},{25,62},{18,54},{4,50},{13,40},{18,40},
// {24,42},{25,38},{41,26},{45,21},{44,35},{58,35},{62,32}};


double CityDistance[CITY_NUM][CITY_NUM];

typedef struct
{
    int colony
        [POPSIZE]
        [CITY_NUM +
         1];  // 城市种群,默认出发城市编号为0，则城市编号的最后一个城市还应该为0
    double fitness[POPSIZE];  // 路径适应值

    double Distance[POPSIZE];       // 路径实际长度
    int BestRooting[CITY_NUM + 1];  // 最优城市路径序列
    double BestFitness;             // 最优路径适应值
    double BestValue;               // 最优路径长度
    double WorstValue;              // 最差路径长度
    double AvgValue;                // 平均路径长度
} TSP, *PTSP;

void CalculatDist()
{
    int i, j;
    int temp1, temp2;
    for (i = 0; i < CITY_NUM; i++) {
        for (j = 0; j <= CITY_NUM; j++) {  // 最后一个城市还应该返回到出发节点
            temp1 = CityPos[j].x - CityPos[i].x;
            temp2 = CityPos[j].y - CityPos[i].y;
            CityDistance[i][j] = sqrt(temp1 * temp1 + temp2 * temp2);
        }
    }
}
void copy(int a[], int b[])
{
    int i = 0;
    for (i = 0; i < CITY_NUM + 1; i++) {
        a[i] = b[i];
    }
}

bool check(TSP& city, int pop, int num, int k)
{  // 用来检查新生成的节点是否在当前群体中，0号节点是默认出发节点和终止节点
    int i;
    for (i = 0; i <= num; i++) {
        if (k == city.colony[pop][i])
            return true;  // 新生成节点存在于已经生成的路径中
    }
    return false;  // 新生成节点没有存在于已经生成的路径中
}

void InitColony(TSP& city)
{
    int i, j, r;
    for (i = 0; i < POPSIZE; i++) {
        city.colony[i][0] = 0;
        city.colony[i][CITY_NUM] = 0;
        city.BestValue = MAXVALUE;
        city.BestFitness = 0;  // 适应值越大越好
        city.WorstValue = MAXVALUE;
        city.AvgValue = 0;
    }

    for (i = 0; i < POPSIZE; i++) {
        for (j = 1; j < CITY_NUM; j++) {
            r = rand() % (CITY_NUM - 1) + 1;  // 产生1～CITY_NUM-1之间的随机数
            while (check(city, i, j, r)) {
                r = rand() % (CITY_NUM - 1) + 1;
            }

            city.colony[i][j] = r;
        }
    }
}

void CalFitness(TSP& city)
{
    int i, j;
    int start, end;
    int Best = 0;
    int Worst = 0;
    double sum = 0;
    for (i = 0; i < POPSIZE; i++) {  // 求适应值
        city.Distance[i] = 0;
        for (j = 1; j <= CITY_NUM; j++) {
            start = city.colony[i][j - 1];
            end = city.colony[i][j];
            city.Distance[i] = city.Distance[i] + CityDistance[start][end];
        }

        city.fitness[i]=pow(2,N/(city.Distance[i]));  //适应度函数

        //city.fitness[i] = 1 / (city.Distance[i]);  // 适应度函数
        sum += city.Distance[i];
        if (city.fitness[i] > city.fitness[Best])
            Best = i;
    }
    copy(city.BestRooting, city.colony[Best]);
    city.BestFitness = city.fitness[Best];
    city.BestValue = city.Distance[Best];
    city.AvgValue = sum / POPSIZE;
}

void Select(TSP& city)
{  // 选择算子
    int TempColony[POPSIZE][CITY_NUM + 1];
    int i, j, t;
    double GaiLv[POPSIZE];
    int SelectP[POPSIZE + 1];
    double avg, s;
    //	int MAXN=1000000;//有待改进
    double sum = 0;
    for (i = 0; i < POPSIZE; i++) {
        sum += city.fitness[i];
    }
    //	avg=sum/POPSIZE;
    for (i = 0; i < POPSIZE; i++) {
        GaiLv[i] = city.fitness[i] / sum;
    }
    SelectP[0] = 0;
    for (i = 0; i < POPSIZE; i++) {
        SelectP[i + 1] = SelectP[i] + GaiLv[i];
    }

    for (t = 0; t < POPSIZE; t++) {
        s = ((double)(rand() % RAND_MAX)) / RAND_MAX;  // 产生0-1随机数
        for (i = 1; i < POPSIZE; i++) {
            if (SelectP[i] >= s)
                break;
        }
        copy(TempColony[t], city.colony[i - 1]);
    }

    for (i = 0; i < POPSIZE; i++) {
        copy(city.colony[i], TempColony[i]);
    }
}

void Cross(TSP& city, double pc)
{  // 交叉概率是pc
    int i, j, t;
    int a, b;
    int Temp1[CITY_NUM + 1], Temp2[CITY_NUM + 1];
    for (i = 0; i < POPSIZE - 1; i++) {
        double s = ((double)(rand() % RAND_MAX)) / RAND_MAX;
        if (s < pc) {
            a = rand() % (CITY_NUM - 4) + 1;

            memset(Hash, 0, sizeof(Hash));
            Temp1[0] = Temp1[CITY_NUM] = 0;
            for (j = 1; j < 5; j++) {
                Temp1[j] = city.colony[i + 1][a + j - 1];
                Hash[Temp1[j]] = 1;
            }
            for (t = 1; t < CITY_NUM; t++) {
                if (Hash[city.colony[i][t]] == 0) {
                    Temp1[j++] = city.colony[i][t];
                    Hash[city.colony[i][t]] = 1;
                }
            }

            memset(Hash, 0, sizeof(Hash));
            Temp2[0] = Temp2[CITY_NUM] = 0;
            for (j = 1; j < 5; j++) {
                Temp2[j] = city.colony[i][a + j - 1];
                Hash[Temp2[j]] = 1;
            }
            for (t = 1; t < CITY_NUM; t++) {
                if (Hash[city.colony[i + 1][t]] == 0) {
                    Temp2[j++] = city.colony[i + 1][t];
                    Hash[city.colony[i + 1][t]] = 1;
                }
            }

            copy(city.colony[i], Temp1);
            copy(city.colony[i + 1], Temp2);
        }
    }
}
double GetFittness(int a[CITY_NUM + 1])
{
    int i, start, end;
    double Distance = 0;
    for (i = 0; i < CITY_NUM; i++) {
        start = a[i];
        end = a[i + 1];
        Distance += CityDistance[start][end];
    }
    return N / Distance;
}
void Mutation(TSP& city, double pm)
{  // 变异概率是pm
    int i;
    int Temp[CITY_NUM + 1];
    for (i = 0; i < POPSIZE; i++) {
        double s = ((double)(rand() % RAND_MAX)) / RAND_MAX;
        if (s < pm) {
            int a, b, t;
            a = (rand() % (CITY_NUM - 1)) + 1;
            b = (rand() % (CITY_NUM - 1)) + 1;
            copy(Temp, city.colony[i]);
            t = Temp[a];
            Temp[a] = Temp[b];
            Temp[b] = t;
            if (GetFittness(Temp) < GetFittness(city.colony[i])) {
                a = (rand() % (CITY_NUM - 1)) + 1;
                b = (rand() % (CITY_NUM - 1)) + 1;
                copy(Temp, city.colony[i]);
                t = Temp[a];
                Temp[a] = Temp[b];
                Temp[b] = t;
            }
            copy(city.colony[i], Temp);
        }
    }
}

void OutPut(TSP& city)
{
    int i, j;
    double Worst_dist = 0.0;
    printf("The population is:\n");
    for (i = 0; i < POPSIZE; i++) {
        for (j = 0; j <= CITY_NUM; j++) {
            printf("%5d", city.colony[i][j]);
        }
        Worst_dist = max(Worst_dist, city.Distance[i]);
        printf("    %f\n", city.Distance[i]);
    }

    
    printf("\n最优路径:");
    for (i = 0; i <= CITY_NUM; i++)
        printf("%5d", city.BestRooting[i]);
    printf("\n最差路径长度：%f\n", Worst_dist);
    printf("\n最短路径长度：%f\n", (city.BestValue));
    printf("\n平均路径长度：%f\n", (city.AvgValue));
}

int main()
{
    TSP city;
    int i;
    time_t start, end;

    srand(seed);

    CalculatDist();  // 求城市间两两之间的距离

    //	city=(PTSP)malloc(sizeof(TSP));
    InitColony(city);  // 生成初始种群

    CalFitness(city);  // 计算适应值,考虑应该在这里面把最优选出来
    start = clock();  // 开始计时
    for (i = 0; i < GEN; i++) {
        Select(city);        // 选择(复制)
        Cross(city, PC);     // 交叉
        Mutation(city, PM);  // 变异
        CalFitness(city);    // 计算适应值
    }
    end = clock();                                               // 计时结束
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;  // 计算耗时

    OutPut(city);  // 输出

    printf("\n运行时间：%f秒\n", duration);
    return 0;
}
