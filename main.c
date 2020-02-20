#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#define TRUE 1
#define FALSE  0
int place(int x[],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
        {
            return FALSE;
        }
    }
    return TRUE;
}
void queens(int n)
{
    int i;
    int x[10];
    int count=0;
    int k=1;
    x[k]=0;
    while(k!=0)
    {
     x[k]=x[k]+1;
       while((x[k]<=n)&&(!place(x,k)))
        {
         x[k]=x[k]+1;
        }
        if(x[k]<=n)
        {
            if(k==n)
             {
                printf("\n Solution number:%d",++count);
                for(i=1;i<=n;i++)
                   printf("\n%d queen is found and is placed in %d row and %d column \n",i,i,x[i]);
             }
             else
            {
             k++;
             x[k]=0;
            }
    }
    else k--;
   }
}
int main()
{
    int n;
     struct timeval s;
     double start,stop,total;
    printf("Enter the number of queens: \n");
    scanf("%d",&n);
     gettimeofday(&s,NULL);
     start=s.tv_sec+(s.tv_usec)/1000000.0;
    if(n<=3 && n>1)
    printf("No solution\n");
    else
    queens(n);
    gettimeofday(&s,NULL);
    stop=s.tv_sec+(s.tv_usec)/1000000.0;
    total=stop-start;
    printf("Total time elapsed:%f\n",total);
    return 0;
}

