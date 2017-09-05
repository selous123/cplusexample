//多源bfs广度优先遍历
#include<iostream>
using namespace std;
#define MAX_NODE_NUM 1003
#include<vector>
#include<queue>
//路径的节点
typedef struct node{
    int x;
    int y;
    int num;
    node():x(0),y(0),num(0){}
    node(int x,int y):x(x),y(y){}
    node operator+(node n){
        return node(x+n.x,y+n.y);
    }

}node;
//记录路径信息
//vector <node> path
node direction[4] ={{0,1},{0,-1},{1,0},{-1,0}};
//记录节点是否可行
//1：可行，0：不可行
//int graph[MAX_NODE_NUM][MAX_NODE_NUM];
//记录节点是否访问
//1:访问，0：未访问
int visited[MAX_NODE_NUM][MAX_NODE_NUM];
//记录节点到起点的最近距离
//-1:表示不可行，0：表示起点
int dist[MAX_NODE_NUM][MAX_NODE_NUM];

bool judge(node n,int dir,int width){
    node new_node = n+direction[dir];
    if(new_node.x<=0||new_node.x>width) return false;
    if(new_node.y<=0||new_node.y>width) return false;
    if(visited[new_node.x][new_node.y]==1) return false;
    if(dist[new_node.x][new_node.y]==-1) return false;
    return true;
}

node walk(node n, int dir){
    return n+direction[dir];
}

vector<node> stores;
vector<node> clients;
int main(){
    //初始化数组


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
        dist[x][y]=-1;
    }


    //bfs
    node n_node;//next node
    while(!q.empty()){
        node p_node = q.front();
        q.pop();
        for(ind=0;ind<4;ind++){
            if(judge(p_node,ind,width)){
                n_node = walk(p_node,ind);
                dist[n_node.x][n_node.y]=dist[p_node.x][p_node.y]+1;
                visited[n_node.x][n_node.y] = 1;
                q.push(n_node);
            }
            //cout<<"hello world";
        }

    }
/*
    int j;
    for(ind=1;ind<=width;ind++){
        for(j=1;j<=width;j++){
            cout<<dist[ind][j]<<" ";
            //cout<<visited[ind][j]<<"*";
        }
        cout<<endl;
    }
*/
    long long sum = 0;
    for(ind=0;ind<clients.size();ind++){
        sum += dist[clients[ind].x][clients[ind].y]*clients[ind].num;
    }

    cout<<sum;


    return 0;
}
