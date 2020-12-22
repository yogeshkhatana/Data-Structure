#include<stdio.h>
int main()
{
    char A[]="How Are You";
    int vc,cc;
    vc=cc=0;
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]==65||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'||A[i]==97||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
            vc++;
        else if(A[i]>=65 && A[i] <= 90 || A[i]>=97 && A[i] <= 122)
            cc++;

    }
    printf("Vowels:%d\nConsonants:%d",vc,cc);
}
