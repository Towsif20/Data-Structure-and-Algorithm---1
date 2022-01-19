#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;

    cin>>n;

    double * arr = new double[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    double max, min;

    max = min = arr[0];

    for(int i=1;i<n;i++)
    {
        if(max<arr[i]) max = arr[i];

        if(min>arr[i]) min = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i] - min;
    }

    double d = 1.0;

    if(max >= 1.0) d = max - min + 1;

    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i] / d;
    }

    vector<double> bucket[5];

    for(int i=0;i<n;i++)
    {
        int ind = 5 * arr[i];

        bucket[ind].push_back(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<bucket[i].size();j++)
        {
            arr[index] = bucket[i][j];
            index++;
        }
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i] * d;
    }

    for(int i=0;i<n;i++)
    {
       arr[i] = arr[i] + min;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
