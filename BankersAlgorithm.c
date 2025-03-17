#include<stdio.h>
int main(){
int alloc[10][10],max[10][10],need[10][10],avb[10],n,m,o=0,pid[10],Total[10],count,safe=0,check=1,order[10];
printf("Enter No of Process :: ");
scanf("%d",&m);
printf("Enter No of Resourses :: ");
scanf("%d",&n);
printf("Enter Available Resourses :: ");
for(int i=0;i<n;i++){
        scanf("%d",&avb[i]);
        Total[i]=avb[i];
}
for(int i=0;i<m;i++){
        pid[i]=i;
        printf("Enter process %d Allocated Resources:: ",pid[i]);
        for(int j=0;j<n;j++){
              scanf("%d",&alloc[i][j]);
              Total[j]+=alloc[i][j];
        }        
        printf("Enter process %d Max Resources:: ",pid[i]);
        for(int j=0;j<n;j++){
              scanf("%d",&max[i][j]);
        }
        for(int j=0;j<n;j++){
              need[i][j]=max[i][j]-alloc[i][j];  
        }
}
printf("Need Matrix :: \n");
for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
            printf("%d ",need[i][j]);
      }
      printf("\n");
}
while(check!=0){
      check=0;
for(int i=0;i<m;i++){
      count=0;
      for(int j=0;j<n;j++){
            if(Total[j]!=avb[j]){
                  break;
            }
            count++;
      }
      if(count==n){
            check=0;
            safe=1;
            break;
      }
      count=0;
      for(int j=0;j<n;j++){
            if(avb[j]>=need[i][j]){
                  count++;
            }
      }
      if(count==n){
            for(int j=0;j<n;j++){
                  avb[j]+=alloc[i][j];
                  alloc[i][j]=0;
            }
            order[o++]=pid[i];
            check=1;
      }
}
}
printf("Total Resources :: \n");
for(int i=0;i<n;i++){
        printf("Resource %d :: %d\n",i+1,Total[i]);
}
if(safe==1){
      printf("There is a Safe Sequence => ");
      for(int i=0;i<m;i++){
            printf("%d ",order[i]);
      }
}
else{
      printf("There is a Deadlock => ");
      for(int i=0;i<n;i++){
            printf("%d ",avb[i]);
      }
}
}
