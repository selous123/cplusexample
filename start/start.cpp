#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define LEN 10

void print(int *a){

    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}

int main(){

    int a[LEN] = {1,5,2,1,4,6,7,8,9,0};

    sort(a,a+10);


    print(a);
    cout<<"hello world\n"<<endl;
    return 0;
}
