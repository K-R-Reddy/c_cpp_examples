#include<stdio.h>
int main(){
    int a[30],n,f1=0,flag,f,j=0,frames[10],hit=0,fault=0;
    printf("Enter no of Pages :: ");
    scanf("%d",&n);
    printf("Enter Page Numbers :: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter no of Frames ::");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
    while(j<n){
        if(f1==(f)){
        f1=0;
        }
        flag=0;
        for(int i=0;i<f;i++){
            if(a[j]==frames[i]){
                hit++;
                flag=1;
                break;
            }
            }
        if(flag==0){
            frames[f1++]=a[j];
            fault++;
        }
        for(int i=0;i<f;i++){
            printf("%d ",frames[i]);
            }
            printf("\n");
        j++;
    }
    printf("Page faults : %d\n",fault);
    printf("Page Hits : %d\n",hit);
}