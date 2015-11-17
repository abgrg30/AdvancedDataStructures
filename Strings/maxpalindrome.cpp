#include<iostream>
using namespace std;

int logic(char* str, int isize, int& start)
{
    int left = 0;
    int right = 0;
    int maxi = 1;

    //odd
    for(int i=1;i<isize;i++)
    {
        left = i-1;
        right = i+1;

        while((left>=0)&&(right<isize)&&(str[left]==str[right]))
        {
            if((right-left+1)>maxi)
            {
                maxi = right-left+1;
                start = left;
            }

            left--;
            right++;
        }
    }

    //even
    for(int i=1;i<isize;i++)
    {
        left = i-1;
        right = i;

        while((left>=0)&&(right<isize)&&(str[left]==str[right]))
        {
            if((right-left+1)>maxi)
            {
                maxi = right-left+1;
                start = left;
            }

            left--;
            right++;
        }
    }

    return maxi;
}

int main()
{
    char str[] = "radarradar";
    int start = 0;
    int maxi = logic(str, sizeof(str), start);
    //cout<<maxi<<"\t"<<start;
    cout<<"\nmax palindrome length = "<<maxi;
    cout<<"\npalindrome string = ";

    for(int i=start;i<(start+maxi);i++)
    {
        cout<<str[i];
    }

    return 0;
}
