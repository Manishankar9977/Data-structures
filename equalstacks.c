/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int stcknum(int a,int b,int c){
    if(a>b && a>c){
        return 1;
    }
    else if(b>a && b>c){
        return 2;
    }
    else{
        return 3;
    }
}
int stcksum(int sum1,int sum2,int sum3,int top1,int top2,int top3,int stk1[],int stk2[],int stk3[]){
    while(!((sum1==sum2)&&(sum2==sum3))){
        int num=stcknum(sum1,sum2,sum3);
        if(num==1){
            sum1=sum1-stk1[top1--];
        }
        else if(num==2){
            sum2=sum2-stk2[top2--];
        }
        else if(num==3){
            sum3=sum3-stk3[top3--];
        }
    }
    return sum1;
}
int main()
{
    int i,n1,n2,n3;
    int  top1=-1,top2=-1,top3=-1;
    int sum1=0,sum2=0,sum3=0;
    printf("Enter the no of elements in a stack 1:");
    scanf("%d",&n1);
    int stk1[n1];
    for(i=0;i<n1;i++){
        int var;
        scanf("%d",&var);
        top1=top1+1;
        stk1[top1]=var;
        sum1=sum1+var;
    }
    printf("Enter the no of elements in a stack 2:");
    scanf("%d",&n2);
    int stk2[n2];
    for(i=0;i<n2;i++){
        int var;
        scanf("%d",&var);
        top2=top2+1;
        stk2[top2]=var;
        sum2=sum2+var;
    }
    printf("Enter the no of elements in a stack 3:");
    scanf("%d",&n3);
    int stk3[n3];
    for(i=0;i<n3;i++){
        int var;
        scanf("%d",&var);
        top3=top3+1;
        stk3[top3]=var;
        sum3=sum3+var;
    }
    int ans=stcksum(sum1,sum2,sum3,top1,top2,top3,stk1,stk2,stk3);
    printf("The equal sum is %d",ans);
    return 0;
}
