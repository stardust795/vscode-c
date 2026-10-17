#include <stdio.h>

/* 冒泡排序：输入 10 个整数，从小到大排序后输出 */
int main()
{
    int AAA[10];
    int i,j,k;
    printf("input ten numbers\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&AAA[i]);
    }
    printf("\n");
    for (j = 0; j < 9; j++)
    {
        for (i = 0; i < 9 - j; i++)
        {   if(AAA[i]>AAA[i+1])
            {   k = AAA[i];
                AAA[i]=AAA[i+1];
                AAA[i+1]=k;

            }
        }
    }
    printf("the result:\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",AAA[i]);
    }
    
           
    return(0);
}



