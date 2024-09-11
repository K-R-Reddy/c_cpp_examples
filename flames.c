#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char name1[50];
    char name2[50];
    char f[]="flames";
    char g[6];
    int i,j,len1,len2,len1wod=0,len2wod=0,tc;
    int ri,k,fc=6,s;
    printf("Enter the name of first person\n");
    scanf("%s",&name1);
    printf("Enter the name of second person\n");
    scanf("%s",&name2);
    len1=strlen(name1);
    len2=strlen(name2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(name1[i]==name2[j])
            {
                name1[i]='.';
                name2[j]='.';
                break;
            }
        }
    }
    //printf("\n name1 : %s ",name1);
    //printf("\n name2 : %s ",name2);
    for(i=0;i<len1;i++)
    {
        if(name1[i]!='.')
        {
            len1wod++;
        }
    }
    for(i=0;i<len2;i++)
    {
        if(name2[i]!='.')
            len2wod++;
    }
    //printf("\n name1 length after removing common letter : %d ",len1wod);
    //printf("\n name2 length after removing common letter : %d ",len2wod);
    tc=len1wod+len2wod;
    i=0;
    tc=tc-1;
    while(i<5)
    {
        ri=tc%fc;
        for(k=ri;k<fc-1;k++)
        {
            f[k]=f[k+1];
        }
        f[k]='\0';
       // printf("\n ------> %s = ",f);
        fc--;
        for(s=0,k=ri;k<(fc+ri);k++,s++)
        {
            g[s]=f[k%fc];
        }
        g[fc]='\0';
       // printf("\n ------> %s = ",g);
        strcpy(f,g);
        i++;
    }
    switch (f[0])
    {
    case 'f':printf("you are friends ");
        break;
    case 'l':printf("you are lovers ");
        break;
    case 'a':printf("you have affection");
        break;
    case 'm':printf("you get marriage ");
        break;
    case 'e':printf("you are enemies ");
        break;
    case 's':printf("your sister ");
        break;
    default:
        break;
    }
  getch();
}