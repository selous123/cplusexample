#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#define MAX_NODE_NUM 10000

typedef struct node{
    int x;
    int y;
    //该节点是否是新增节点
    bool newAdd;
    node():x(0),y(0),step(0),visited(0),newAdd(0){}
    node(int x,int y):x(x),y(y){}
    //返回距离
    float distance(node n){
        return sqrt(pow((n.x-x),2)+pow((n.y-y),2))
    }
    bool linked(node n,int r){
        if this.distance(n)<=r return true;
        else return false;
    }
}node;

//定义图，储存位置信息
node graph[MAX_NODE_NUM]
//该节点是否访问过
bool visited[MAX_NODE_NUM];
//到起点的最短距离
int step[MAX_NODE_NUM];

bool judge(node n,int index,int r){
    if(visited[index] && ) return false;
    if(n.linked(graph[index],r)==false) return false;
    return true;
}
int main(){

    int n,m,k,r;
    cin>>n>>m>>k>>r;
    int ind;
    for(ind=0;ind<n;ind++){
        cin>>graph[ind].x>>graph[ind].y;
        graph[ind].newAdd = false;
    }

    for(ind=n;ind<n+m;ind++){
        cin>>graph[ind].x>>graph[ind].y;
        graph[ind].newAdd = true;
    }

    //start:graph[0]
    //end :graph[1]

    queue <node> q;
    q.push(graph[0]);
    visited[0] = true
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(ind=0;ind<n+m;ind++){
            if(judge(p,ind,r)){

            }
        }

    }


    cout<<"hello world\n";
    return 0;
}
