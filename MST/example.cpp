#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdlib>

#define MAX_ARC_NUM 200000
#define MAX_NODE_NUM 100000

//表示每个顶点的根节点位置
int root[MAX_NODE_NUM];

//图的边储存结构
typedef struct arc{
    //起点
    int start;
    //终点
    int end;
    //边长度
    int length;
}arc;

//找到node节点的root
int find(int node){

    int temp=node;
    while(root[temp]!=temp){
        temp = root[temp];
    }
    //路径压缩
    int r = temp;
    temp = node;
    int w;
    while(root[temp] != r){
        w = root[temp];
        root[temp] = r;
        temp = w;
    }
    //返回结果
    return r;
}

//小于<
bool cmp(arc a,arc b){
    return a.length<b.length;

}
int main(){
    //n:点个数
    //m：边个数
    int m,n;
    cin >> n >> m;

    arc *a;
    a = (arc*)malloc(sizeof(arc)*m);

    int ind;
    int start,end,length;
    for(ind = 0 ;ind < m;ind++){
        cin >> start>>end>>length;
        a[ind].start = start-1;
        a[ind].end = end-1;
        a[ind].length = length;
    }

    sort(a,a+m,cmp);
    //根节点初始化为本身
    for(ind=0;ind<n;ind++){
        root[ind] = ind;
    }

    int k=0;
    int value = 0;
    //选取所有的边，从小-》大
    for(ind=0;ind<m;ind++){
        int start_root = find(a[ind].start);
        int end_root = find(a[ind].end);
        if(start_root!=end_root){
            root[end_root] = start_root;
            k++;
        }
        if(find(0) == find(n-1)){
            value = a[ind].length;
            break;
        }
    }


    cout<<value;

    return 0;
}
