#include<stdio.h>
int main(){
int alloc[10][10],max[10][10],need[10][10],avb[10][10],n,m,pid[10],Total[0][10];
printf("Enter No of Process :: ");
scanf("%d",&m);
printf("Enter No of Resourses :: ");
scanf("%d",&n);
printf("Enter Available Resourses :: ");
for(int i=0;i<n;i++){
        scanf("%d",&avb[0][i]);
        Total[0][i]=avb[0][i];
}
for(int i=0;i<m;i++){
        pid[i]=i+1;
        printf("Enter process %d Allocated Resources:: ",pid[i]);
        for(int j=0;j<n;j++){
              scanf("%d",&alloc[i][j]);
              Total[0][j]+=alloc[i][j];
        }        
        printf("Enter process %d Max Resources:: ",pid[i]);
        for(int j=0;j<n;j++){
              scanf("%d",&max[i][j]);
        }
        for(int j=0;j<n;j++){
              need[i][j]=max[i][j]-alloc[i][j];  
        }
}
printf("Total Resources :: ");
for(int i=0;i<n;i++){
        printf("Resource %d :: %d",i+1,Total[0][i]);
}
}
