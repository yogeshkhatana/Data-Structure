#include<stdio.h>
int main()
{

    char A[]="medical";
    char B[]="decimal";
    int i,H[26]={0};
    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }

    for(i=0;B[i]!='\0';i++)
    {
        H[B[i]-97]-=1;
        if(H[B[i]-97]<0)
            {printf("Not an Anagram");
            break;}

    }
    if(B[i]=='\0')
        printf("Volla !! You got It\n Its An ANAGRAM");
}
