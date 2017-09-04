#include<iostream>
using namespace std;

#define MAX_NODE_NUM 1005

//学号对应的位置
int s_p[MAX_NODE_NUM];

//位置对应的学号
int p_s[MAX_NODE_NUM];

int main(){
    int n,times;
    cin>>n>>times;

    int ind;
    for(ind=1;ind<=n;ind++){
        s_p[ind] = ind;
        p_s[ind] = ind;
    }

    int st,step;
    int flag;
    int j;
    for(ind=0;ind<times;ind++){
        cin>>st>>step;

        if(step>0) flag=1;
        else flag = -1;

        int sp = s_p[st];
        s_p[st]+=step;

        for(j=sp;j!=s_p[st];j+=flag){
            p_s[j] = p_s[j+flag];
            s_p[p_s[j]]-=flag;
        }
        p_s[j] = st;
    }

    for(ind=1;ind<=n;ind++){
        cout<<p_s[ind]<<" ";
    }



    return 0;
}
