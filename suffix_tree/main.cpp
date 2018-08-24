#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
vector<pair <int, string> > Graph[N];
int am;
void to_bor(string T, int v)
{
    if(T != "")
    {
        string T1 = "";
        T1.push_back(T[0]);
        bool findd = false;
        string Q = "";
        for(int j = 1; j < T.length(); j++)
        {
            Q.push_back(T[j]);
        }
        for(int i = 0; i < Graph[v].size(); ++i)
        {
            if(Graph[v][i].second == T1)
            {
                to_bor(Q, Graph[v][i].first);
                findd = true;
            }
        }
        if(!findd)
        {
            Graph[v].push_back({am, T1});
            am++;
            to_bor(Q, am - 1);
        }
    }
}
void dfs(int u, int col)
{
    for(int i = 0; i < Graph[u].size(); ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            cout << "->";
        }
        cout << Graph[u][i].first << " " << Graph[u][i].second << endl;
        dfs(Graph[u][i].first, col + 1);
    }
}
int main()
{
    am = 1;
    string S;
    cin >> S;
    S.push_back('$');
    for(int i = 0; i < S.length(); ++i)
    {
        string S1 = "";
        for(int j = 0; j + i < S.length(); ++j)
        {
            S1.push_back(S[i + j]);
        }
        to_bor(S1, 0);
    }
    //for(int i = 0; i < am; ++i)
    //{
      //  cout << "Graph[" << i << "]:" << endl;
        //for(int j = 0; j < Graph[i].size(); ++j)
        //{
          //  cout<< Graph[i][j].first << " " << Graph[i][j].second << endl;
        //}
    //}
    cout << "0" << endl;
    dfs(0, 1);
    return 0;
}
