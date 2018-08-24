#include <iostream>
#include <cstdio>
using namespace std;
const int N = int(1e5) + 7;
int A[N];
long long Tree[N];
int n;
void update(int j, int zn)
{
    while(j < n)
    {
        //cout << "j = " << j << endl;
        Tree[j] = Tree[j] + zn;
        j = (j|(j + 1));
        //cout << "Tree[" << j << "] = " << Tree[j] << endl;
    }
}
long long get(int k)
{
    long long sum = 0;
    while(k >= 0)
    {
        //cout << "k = " << k << endl;
        sum = sum + Tree[k];
        k = (k & (k + 1)) - 1;
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        update(i, 0);
        A[i] = 0;
    }
    //cout << "hey" << endl;
    string S;
    int ind;
    int am;
    for(int i = 0; i < m; ++i)
    {
        cin >> S >> ind >> am;
        ind--;
        if(S == "add")
        {
            update(ind, am);
            //cout << "Tree:" << endl;
            //for(int i = 0; i < n; ++i)
            //{
              //  cout << "Tree[" << i << "] = " << Tree[i] << endl;
            //}
            //cout << endl;
            A[ind] = A[ind] + am;
        }
        else
        {
            am--;
            long long t = get(am) - get(ind - 1);
            cout << t << endl;
        }
    }
    return 0;
}
