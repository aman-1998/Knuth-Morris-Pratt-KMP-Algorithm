// Knuth-Morris-Pratt(KMP) Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int KMP(char str[],char sub[]);
int main()
{
    char str[100],sub[100];
    printf("Enter the main string: ");
    scanf("%[^\n]",str);
    printf("Enter the sub string to be tested: ");
    scanf("%*c%[^\n]",sub);
    int x=KMP(str,sub);
    if(x==1)
        printf("\nSubstring\n");
    else
        printf("\nNot a sub-string\n");
    return 0;
}
int KMP(char str[],char sub[])
{
    int len1=strlen(str);
    int len2=strlen(sub);
    int *pi=(int*)malloc(len2*sizeof(int));
    int i,j;
    j=0;i=1;
    pi[0]=0;
    while(i<=len2-1)
    {
        if(sub[j]==sub[i])
        {
            pi[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j==0)
            {
                pi[i]=0;
                i++;
            }
            else
                j=pi[j-1];
        }
    }
    i=0;
    j=0;
    while(1)
    {
        if(j==len2)
            return 1;
        if(i==len1)
            return 0;
        if(str[i]==sub[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0)
                i++;
            else
                j=pi[j-1];
        }
    }
}
