    // BEGIN CUT HERE  
    /* 
     
    */  
    // END CUT HERE  
    #line 7 "HiddenSquares.cpp"  
    #include <cstdlib>  
    #include <cctype>  
    #include <cstring>  
    #include <cstdio>  
    #include <cmath>  
    #include <algorithm>  
    #include <vector>  
    #include <string>  
    #include <iostream>  
    #include <sstream>  
    #include <map>  
    #include <set>  
    #include <queue>  
    #include <stack>  
    #include <fstream>  
    #include <numeric>  
    #include <iomanip>  
    #include <bitset>  
    #include <list>  
    #include <stdexcept>  
    #include <functional>  
    #include <utility>  
    #include <ctime>  
    using namespace std;  
      
    #define PB push_back  
    #define MP make_pair  
      
    #define REP(i,n) for(i=0;i<(n);++i)  
    #define FOR(i,l,h) for(i=(l);i<=(h);++i)  
    #define FORD(i,h,l) for(i=(h);i>=(l);--i)  
      
    typedef vector<int> VI;  
    typedef vector<string> VS;  
    typedef vector<double> VD;  
    typedef long long LL;  
    typedef pair<int,int> PII;  
    using namespace std;      
    struct T {int a,b,c;};
    T p[1000];
    int m1[1000],m2[1000];
    bool g[105][105][2];
  //  bool up[50][50][50][50],right[50][50][50][50];
    bool cmp(T a,T b){ return a.a<b.a;}
    bool judge(int a,int b,int c,int d)
    {
        for (int i=a;i<c;i++) if (!g[i][d][0]) return false;
        for (int i=b;i<d;i++) if (!g[c][i][1]) return false;
        return true;
    }
    class HiddenSquares  
    {  
            public:  
            int count(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)  
            {  
                int n=x1.size();
                for (int i=0;i<n;i++)
                {
                        p[i*2].a=x1[i];
                        p[i*2].b=i;
                        p[i*2].c=1;
                        p[i*2+1].a=x2[i];
                        p[i*2+1].b=i;
                        p[i*2+1].c=2;
                }
                sort(p,p+2*n,cmp);
                int now=0;
                if (p[0].c==1) x1[p[0].b]=now;else x2[p[0].b]=now;
                m1[0]=p[0].a;
                for (int i=1;i<n*2;i++)
                {
                        if (p[i].a!=p[i-1].a) now++;
                        if (p[i].c==1) x1[p[i].b]=now;else x2[p[i].b]=now;
                        m1[now]=p[i].a;
                }
                int s1=now;
                for (int i=0;i<n;i++)
                {
                        p[i*2].a=y1[i];
                        p[i*2].b=i;
                        p[i*2].c=1;
                        p[i*2+1].a=y2[i];
                        p[i*2+1].b=i;
                        p[i*2+1].c=2;
                }
                sort(p,p+2*n,cmp);
                now=0;
                if (p[0].c==1) y1[p[0].b]=now;else y2[p[0].b]=now;
                m2[0]=p[0].a;
                for (int i=1;i<n*2;i++)
                {
                        if (p[i].a!=p[i-1].a) now++;
                        if (p[i].c==1) y1[p[i].b]=now;else y2[p[i].b]=now;
                        m2[now]=p[i].a;
                }
                int s2=now;
               // for (int i=0;i<n;i++) printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
                memset(g,false,sizeof(g));
                for (int i=0;i<n;i++)
                {
                        for (int j=x1[i];j<x2[i];j++)
                        {
                                g[j][y1[i]][0]=true;
                                g[j][y2[i]][0]=true;
                        }
                        for (int j=y1[i];j<y2[i];j++)
                        {
                                g[x1[i]][j][1]=true;
                                g[x2[i]][j][1]=true;
                        }
                }
                int ans=0;
                for (int i=0;i<s1;i++)
                        for (int j=0;j<s2;j++)
                        {
                                int down=i,right=j,sd=0,sr=0;;
                                while (true)
                                {
                                        bool ok=true;
                                        while ((sd<sr)&&(down<s1)&&(g[down][j][0]))
                                        {
                                                sd+=m1[down+1]-m1[down];
                                                down++;
                                                ok=false;
                                        }
                                        while ((sr<sd)&&(right<s2)&&(g[i][right][1]))
                                        {
                                                sr+=m2[right+1]-m2[right];
                                                right++;
                                                ok=false;
                                        }
                                        if (sd==sr)
                                        {
                                                if (judge(i,j,down,right)) ans++;
                                                if ((down>=s1)||(!g[down][j][0])) break;
                                                else
                                                {
                                                        sd+=m1[down+1]-m1[down];
                                                        down++;
                                                }
                                                if ((right>=s2)||(!g[i][right][1])) break;
                                                else
                                                {
                                                        sr+=m2[right+1]-m2[right];
                                                        right++;
                                                }
                                                ok=false;
                                        }
                                        if (ok) break;
                                }
                                ans--;
                        }
                 return ans;
            }  
            
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 14; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,4,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {453453463,453453500,453453495,453453512,453453478,453453489,
 453453466,453453500,453453498,453453510,453453472,453453512,
 453453519,453453514,453453521,453453518,453453523,453453517,
 453453466,453453525,453453496,453453495,453453463,453453461,
 453453460,453453522,453453471,453453468,453453479,453453517,
 453453485,453453518,453453499,453453464,453453494}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {364646438,364646402,364646449,364646438,364646415,364646401,
 364646446,364646416,364646456,364646414,364646463,364646407,
 364646436,364646450,364646421,364646411,364646414,364646419,
 364646445,364646427,364646405,364646442,364646418,364646464,
 364646457,364646463,364646432,364646426,364646444,364646431,
 364646450,364646418,364646434,364646458,364646402}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {453453488,453453510,453453525,453453523,453453493,453453500,
 453453470,453453511,453453499,453453521,453453518,453453524,
 453453523,453453523,453453524,453453523,453453525,453453519,
 453453473,453453526,453453511,453453517,453453470,453453464,
 453453511,453453524,453453516,453453516,453453492,453453524,
453453513,453453522,453453520,453453505,453453512}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {364646460,364646454,364646462,364646466,364646464,364646455,
 364646457,364646461,364646457,364646450,364646466,364646453,
 364646441,364646451,364646460,364646461,364646446,364646464,
 364646447,364646460,364646454,364646450,364646444,364646466,
 364646458,364646466,364646455,364646442,364646462,364646435,
 364646464,364646444,364646455,364646459,364646430}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 124; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
    };  
      
    // BEGIN CUT HERE  
    int main()  
    {  
            HiddenSquares ___test;  
            ___test.run_test(3);
            system("pause");
            return 0;
    }  
    // END CUT HERE

