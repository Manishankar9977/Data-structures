#include <stdio.h>
#include<stdlib.h>
int g[10][10],v[10]={0,0,0,0,0,0,0,0,0,0},n;
void dfs(int s){
    printf("%d ",s);
    v[s]=1;
    for(int j=0;j<n;j++){
        if(g[s][j]==1 && v[j]!=1){
            dfs(j);
        }
    }
}
int main()
{
    int i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    
    printf("enter the adjacency matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    dfs(0);
    return 0;
}

