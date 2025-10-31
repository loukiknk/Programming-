#include<stdio.h>
void towers(int n,char src,char dest,char aux){
if(n==1){
    printf("move 1 disk from peg %c to peg %c\n",src,dest);
    return;
}
towers(n-1,src,aux,dest);
printf("move % d disk from peg %c to peg %c\n",n,src,dest);
towers(n-1,aux,dest,src);
}
void main(){
    int n;
    printf("enter the number of disk");
    scanf("%d",&n);
    printf("moves made");
    towers(n,'A','C','B');
   
}
