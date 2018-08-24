#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct point
{
    long double x, y;
    void read() { cin >> x >> y; }
    long double operator%(point b)
    {
        return 1ll * x * b.y - 1ll * b.x * y;
    }
    point operator-(point c)
    {
        point Q;
        Q.x = x - c.x;
        Q.y = y - c.y;
        return Q;
    }
};


point All[2*int(1e4) + 7];
bool comp(point a, point b)
{
    if(a.x < b.x)
    {
        return true;
    }
    else
    {
        if(a.x == b.x)
        {
            if(a.y < b.y)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
bool comp2 (point a, point b)
{
    point c = a - All[0];
    point d = b - All[0];
    return(c % d > 0);
}
long double dist(point a, point b)
{
    return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
vector <point> Ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> All[i].x >> All[i].y;
        //cout << "point: " <<All[i].x <<" "<< All[i].y<<endl;
    }
    sort(All, All + n, comp);
    cout << "All[0] = " << All[0].x << " " << All[0].y << endl;
    sort(All + 1, All + n, comp2);
    for(int i = 1; i < n; ++i)
    {
        cout << "All[" << i << "] = " << All[i].x <<" " << All[i].y << endl;
    }
    Ans.push_back(All[0]);
    Ans.push_back(All[1]);
    cout << "Ans:" << endl;
    for(int i = 0; i < Ans.size(); ++i)
    {
        cout << Ans[i].x << " " << Ans[i].y << endl;
    }
    cout << endl;
    for(int j = 2; j < n; ++j)
    {
        while(Ans.size() > 1 && ((All[j] - Ans[Ans.size() - 1]) % (Ans[Ans.size() - 2] - Ans[Ans.size() - 1]) < 0))
        {
            Ans.pop_back();
            cout << "Ans:"<< endl;
            for(int i = 0; i < Ans.size(); ++i)
            {
                cout << Ans[i].x << " " << Ans[i].y << endl;
            }
            cout << endl;
        }
        Ans.push_back(All[j]);
        cout << "Ans:" << endl;
        for(int i = 0; i < Ans.size(); ++i)
        {
            cout << Ans[i].x << " " << Ans[i].y << endl;
        }
        cout << endl;
    }
    long double P = 0;
    long double S = 0;
    cout.precision(8);
    for(int i = 1; i < Ans.size(); ++i)
    {
        P += dist(Ans[i - 1], Ans[i]);
        cout <<"P = " << fixed << P << endl;
        S += (Ans[i - 1] % Ans[i])/2;
        cout <<"S = " << fixed << S << endl;
    }
    P = P + dist(Ans[0], Ans[Ans.size() - 1]);
    S = S + (Ans[Ans.size() - 1] % Ans[0])/2;
    S = fabs(S);
    cout << fixed << P << endl << fixed << S << endl;
    return 0;
}
