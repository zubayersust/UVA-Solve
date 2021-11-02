/**
Online Judge : UVA Online Judge
Problem No   : 12747
Problem Name : Back to Edit Distance
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 3.000s
CPU          : 0.000s
Memory       :
Algorithm    : Dynamic Programming (Edit Distance)
*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define db double
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define NL puts("")

#define mem(a,b) memset(a,b,sizeof(a))

#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)

// Input/Output
#define II ({int a; scanf("%d",&a); a;})
#define IL ({int64 a; scanf("%lld",&a); a;})
#define ID ({db a; scanf("%lf",&a); a;})
#define IC ({char a; scanf("%c",&a); a;})
#define IS ({string a; cin>>a; a;})
#define ICA(n) ({char a[n]; scanf("%s",&a); a;})
#define Output printf("Case %d: %d\n",cs,result)

#define forab(i,a,b) for(__typeof (b) i = (a); i <= (b); ++i)
#define rep(i,n) forab(i, 0, n -1)
#define For(i,n) forab(i, 1, n)
#define rofba(i,a,b) for(__typeof (b) i = (b); i >= a; --i)
#define per(i,n) rofba(i, 0, (n) - 1)
#define rof(i,n) rofba(i, 1, n)
#define forstl(i,s) for(__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)

#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

typedef long long int64;
typedef unsigned long long int64u;
typedef vector<int> vi;
typedef vector<int64> vl;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<string,int> psi;
typedef pair<int64,int64> pll;
typedef pair<db,db> pdd;
typedef vector<pii> vpii;

// templates
template <class T> inline void MAX(T &a, T &b)
{
    if (a < b) a = b;
}
template <class T> inline void MIN(T &a, T &b)
{
    if (a > b) a = b;
}
template <class T> inline void SWAP(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// constants
const int INF = 1<<29;
const int MOD = 1000000007;

const int MAX_N = 2e5 + 7;
int A[MAX_N], B[MAX_N];

int LCS(int n)
{
    int lookup[n+1] = {0};

    forab(i,0,n)
    {
        int prev = lookup[0];
        forab(j,0,n)
        {
            int backup = lookup[j];

            if (i==0 || j==0)
                lookup[j] = 0;
            else if (A[i-1] == B[j-1])
                lookup[j] = prev + 1;
            else MAX(lookup[j], lookup[j-1]);

            prev = backup;
        }
    }

    return lookup[n];
}

int main()
{
#ifndef ONLINE_JUDGE
    FI;
#endif // ONLINE_JUDGE

    int T = II;

    For(cs,T)
    {
        int N = II;

        rep(i,N) A[i] = II;
        rep(i,N) B[i] = II;

        int result = (2*N) - (2 * LCS(N));
        Output;
    }

    vi v;

    v.pb(13);
    v.pb(5);
    v.pb(9);
    v.pb(19);
    v.pb(2);
    v.pb(39);
    v.pb(45);

    int x = lower_bound(v.begin(), v.end(), 21) - v.begin();
    cout << x << endl;


    return 0;
}
