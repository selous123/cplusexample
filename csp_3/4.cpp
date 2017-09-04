//多源bfs广度优先遍历
#include<iostream>
using namespace std;
#define MAX_NODE_NUM 1000000
#include<vector>
#include<queue>
//路径的节点
typedef struct node{
    int x;
    int y;
    int num;
    node():x(0),y(0){}
    node(int x,int y):x(x),y(y){}
    node operator+(node n){
        node()
    }

}node;
//记录路径信息
//vector <node> path
node direction[4] ={{0,1},{0,-1},{1,0},{-1,0}};
//记录节点是否可行
//1：可行，0：不可行
int graph[MAX_NODE_NUM][MAX_NODE_NUM];
//记录节点是否访问
//1:访问，0：未访问
int visited[MAX_NODE_NUM][MAX_NODE_NUM];
//记录节点到起点的最近距离
int dist[MAX_NODE_NUM][MAX_NODE_NUM];
vector<node> stores;
vector<node> clients;
int main(){
    int width,numStore,numClient,numHole;
    cin>>width>>numStore>>numClient>>numHole;
    int ind;
    //队列
    queue <node> q;
    //初始化商店的信息
    node store;
    for(ind=0;ind<numStore;ind++){
        cin>>store.x>>store.y;
        dist[store.x][store.y]=0;
        visited[store.x][store.y]=1;
        q.push(store);
    }

    //初始化客户的信息
    node client;
    for(ind=0;ind<numClient;ind++){
        cin>>client.x>>client.y>>client.num;
        clients.push_back(client);
    }

    //读取不通的位置信息
    int x,y;
    for (ind=0;ind<numHole;ind++){
        cin>>x>>y;
        graph[x][y]=0;
    }


    //bfs
    while(q.empty()){
        node p_node = q.front();
        q.pop();
        for(ind=1;ind<=4;ind++){
            if(judge(p_node,ind)){
                n_node = walk(p_node,ind);
                dist[n_node.x][n_node.y]=dist[p_node.x][p_node.y]+1;
                visited[n_node.x][n_node.y] = 1
            }
        }
    }




    return 0;
}
