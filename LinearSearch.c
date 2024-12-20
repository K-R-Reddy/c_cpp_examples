#include <stdio.h>
int main() {
    int n,a[30],key,i;
    int c=0;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    printf("Enter %d elements : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter key to search : ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key){
            printf("%d found at position %d",key,i+1);
            c=1;
            break;
        }
    }
    if(c==0){
        printf("Key Not Found");
    }
    return 0;
}
