#include<stdio.h>
int producer(int counter){
        if(counter==10){
                printf("\nBuffer is Full");
                return counter;
        }
        else{
                counter++;
                printf("\nProducer produce 1 good\n Buffer Contains %d goods",counter);
                return counter;
        }
}
int consumer(int counter){
        if(counter==0){
                printf("\nBuffer is Empty");
                return counter;
        }
        else{
                counter--;
                printf("\nConsumer consume 1 good\n Buffer Contains %d goods",counter);
                return counter;
        }
}
int main(){
        int counter=0,ch;
        printf("Enter 1 for producer produces good\nEnter 2 for Consumer to consume good\nEnter 3 to Exit\n");
        do{
                printf("\nEnter your Choice ::");
                scanf("%d",&ch);
                switch (ch)
                {
                case 1:
                        counter=producer(counter);
                        break;
                case 2:
                        counter=consumer(counter);
                        break;
                default:
                        printf("Program Terminated");
                        break;
                }
        }while(ch!=3);
        return 0;
}
