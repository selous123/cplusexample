/*
问题描述
　　目前在一个很大的平面房间里有 n 个无线路由器,每个无线路由器都固定在某个点上。任何两个无线路由器只要距离不超过 r 就能互相建立网络连接。
　　除此以外,另有 m 个可以摆放无线路由器的位置。你可以在这些位置中选择至多 k 个增设新的路由器。
　　你的目标是使得第 1 个路由器和第 2 个路由器之间的网络连接经过尽量少的中转路由器。请问在最优方案下中转路由器的最少个数是多少?
输入格式
　　第一行包含四个正整数 n,m,k,r。(2 ≤ n ≤ 100,1 ≤ k ≤ m ≤ 100, 1 ≤ r ≤ 108)。
　　接下来 n 行,每行包含两个整数 xi 和 yi,表示一个已经放置好的无线 路由器在 (xi, yi) 点处。输入数据保证第 1 和第 2 个路由器在仅有这 n 个路由器的情况下已经可以互相连接(经过一系列的中转路由器)。
　　接下来 m 行,每行包含两个整数 xi 和 yi,表示 (xi, yi) 点处可以增设 一个路由器。
　　输入中所有的坐标的绝对值不超过 10^8,保证输入中的坐标各不相同。
输出格式
　　输出只有一个数,即在指定的位置中增设 k 个路由器后,从第 1 个路 由器到第 2 个路由器最少经过的中转路由器的个数。

*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100 + 100;
int nn;//已有路由器的个数
int k;//最多新增路由的个数

struct {
    long long x, y;
} coord[N+1];

struct node {
    long long x, y;
    int step, flag;
};

bool visited[N+1];
int res[N+1];

int bfs(int n, int begin, int end, long long r)
{
    // 变量初始化
    memset(visited, false, sizeof(visited));

    // 设置根结点
    node start, front, v;
    start.x = coord[begin].x;
    start.y = coord[begin].y;
    start.step = 0;
    start.flag = 0;//标识有几个新的路由器
    queue<node> q;
    q.push(start);

    // 设置根结点为已经访问过
    visited[begin] = true;

    while(!q.empty()) {
        front = q.front();
        q.pop();

        // 到达终点则结束
        if(front.x == coord[end].x && front.y == coord[end].y)
            return front.step - 1;

        // 搜索可以连接的路由器
        for(int i=0; i<n; i++) {
            // 访问过的坐标则跳过
            if(visited[i]&& front.flag >= res[i])
                continue;

            // 判定下一个路由器的坐标是否在半径r之内, 不在半径之内则跳过，在半径之内则继续搜索
            if((front.x - coord[i].x) * (front.x - coord[i].x) + (front.y - coord[i].y) * (front.y - coord[i].y) > r * r)
                continue;
            else {
                // 第i个路由器设为已经访问过
                visited[i] = true;
                res[i] = front.flag;
                // 计算步数，并且将第i个路由器加入队列
                if(i >= nn)
                    v.flag = front.flag+1;
                else
                    v.flag = front.flag;
                v.x = coord[i].x;
                v.y = coord[i].y;
                v.step = front.step + 1;
                if(v.flag <= k)
                    q.push(v);
            }
        }
    }

    return 0;
}

int main()
{
    int m;
    long long r;

    // 输入数据
    cin >> nn >> m >> k >> r;
    for(int i=0; i<nn+m; i++)       // n个路由器的位置＋可以增设的m个路由器的位置
        cin >> coord[i].x >> coord[i].y;

    // BFS
    int ans = bfs(nn + m, 0, 1, r);

    // 输出结果
    cout << ans << endl;

    return 0;
}

/*
7 2 1 3
7 4
1 7
7 2
5 1
3 2
1 2
0 4
3 5
5 5
*/

/*
9 2 1 3
7 4
6 7
4 7
1 7
7 2
5 1
3 2
1 2
0 4
3 5
5 5
*/


