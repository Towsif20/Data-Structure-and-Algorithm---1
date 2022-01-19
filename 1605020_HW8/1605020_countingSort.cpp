#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int * arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for(int i=1;i<n;i++)
    {
        if(max<arr[i]) max = arr[i];

        if(min>arr[i]) min = arr[i];
    }

    int d = max - min;

    int * count = new int[d+1];
    int * index = new int[d+1];

    for(int i=0;i<=d;i++)
    {
        count[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        count[arr[i] - min]++;
    }

    for(int i=0;i<=d;i++)
    {
        cout<<count[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<=d;i++)
    {
        index[i] = count[i];
    }

    for(int i=1;i<=d;i++)
    {
        index[i] += index[i-1];
    }

    for(int i=d;i>0;i--)
    {
        index[i] = index[i-1];
    }

    index[0] = 0;

    for(int i=0;i<=d;i++)
    {
        cout<<index[i]<<" ";
    }

    cout<<endl;

    int * sorted = new int[n];

    for(int i=0;i<n;i++)
    {
        sorted[index[arr[i]-min]] = arr[i];
        index[arr[i] - min]++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<sorted[i]<<" ";
    }

    return 0;
}
