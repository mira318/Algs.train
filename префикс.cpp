#include <iostream>
#include <vector>
using namespace std;
vector<int> Prefix(string S)
{
    cout << "S = " << S<< endl;
    vector<int> Pref;
    Pref.push_back(0);
    cout << "I am"<< endl;
    int k = 0;
    cout << "Pref[" << 0 << "] = " << Pref[0] << endl;
    for(int i = 1; i < S.length(); ++i)
    {
        while(k > 0 && S[k] != S[i])
        {
            k--;
            k = Pref[k];
        }
        if(S[k] == S[i])
        {
            k++;
        }
        Pref.push_back(k);
        cout << "Pref[" << i << "] = " << Pref[i] << endl;
    }
    return Pref;

}
int main()
{
    string a, b;
    cin >> a >> b;
    string v = b + '*' + a;
    cout << "v = " << v<< endl;
    vector<int> Res = Prefix(v);
    for(int i = 0; i < Res.size(); ++i)
    {
        if(Res[i] == b.length())
        {
            cout << "place = " << (i - b.length()) << endl;
        }
    }
    return 0;
}

