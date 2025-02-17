#include<stdio.h>
int main(){
        int pid[15],bt[15],pt[15],n,ct[15],wt[15],s=0,temp;
        float avg;
        printf("Enter Number of Process :: ");
        scanf("%d",&n);
        printf("Enter %d Process Ids :: \n",n);
        for (int i = 0; i < n; i++)
        {
        scanf("%d",&pid[i]);
        }
        for(int i=0; i < n;i++){
                printf("Enter process %d Burst Time :: ",pid[i]);
                scanf("%d",&bt[i]);
        }
        for(int i=0; i < n;i++){
                printf("Enter process %d Priority :: ",pid[i]);
                scanf("%d",&pt[i]);
        }
        for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                        if(pt[i]>pt[j]){
                temp=pt[i];
                pt[i]=pt[j];
                pt[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
                        }
                }

        }
        ct[0]=0;
                for(int i=0;i<n;i++){
                        ct[i+1]=ct[i]+bt[i];
                        wt[i]=ct[i+1]-bt[i];
                        s=s+wt[i];
                }
        printf("|        Process Id       |       Burst Time       |        Priorty        |       Complete Time      |       Waiting Time      |\n");
        printf("|-------------------------|------------------------|-----------------------|--------------------------|-------------------------|\n");
        for(int i=0;i<n;i++){
                printf("|%25d|%24d|%23d|%26d|%25d|\n",pid[i],bt[i],pt[i],ct[i+1],wt[i]);
        }
        avg=(float)s/n;
        printf("Average Waiting Time using First Come First Serve Technique :: %.2fms",avg);
        printf("\n"); 
        return 0;
}