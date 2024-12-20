#include <stdio.h>
#include <math.h>
void Bsearch(int a[],int s,int k){
    int i,u=s,m,l=0,c=0;
    for(i=0;i<s;i++){
        m=(l+u)/2;
        if(a[m]==k){
            printf("%d found at position %d",k,m+1);
            c=1;
            break;
        }
        else if(a[m]>k){
            u=m-1;
        }
        else{
            l=m+1;
        }
        }
        if(c==0){
            printf("Key not Found");
        }
}
int main() {
    int n,a[30],key,i;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    printf("Enter %d elements : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter key to search : ");
    scanf("%d",&key);
    Bsearch(a,n,key);
    return 0;
}

