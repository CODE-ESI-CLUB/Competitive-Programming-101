#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,Q;
    cin>>N>>Q;
    
    vector<int> X(N);
    for(int i=0;i<N;i++)
    {
        cin>>X[i];
    }
    
    for(int i=0;i<Q;i++)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int c,x;
            cin>>c>>x;
            X[c-1]=x;
        }
        else
        {
            int a,b;
            cin>>a>>b;
            cout<<abs(X[a-1]-X[b-1])<<endl;
        }
    }
    
}