#include <iostream>

using namespace std;

int main()
{
    int n,m,node1,node2,weight;
    cin>>n>>m;
    int *C;
    C=new int[n];

    for(int i=0;i<m;i++)
    {
        if(i==0)
        {
            for(int j =0;j<n;j++)
            {
                C[j]=0;
            }
        }

        cin>>node1>>node2>>weight;
        C[node1]++;
        C[node2]++;
    }
    for(int i =0;i<n;i++)
    {
        cout<<C[i]<<'\n';
    }
}
