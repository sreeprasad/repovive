#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <numeric>
#include <functional>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>

//#define sz(a) ((int)((a).size()))
//#define char unsigned char
#define endl '\n'

using namespace std;
// mt19937 rnd(239);

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    /*
 istringstream tokenstream(s);
 string token;
 string result;
 while(getline(tokenstream, token, '.')){
   result = token;
} 
*/

typedef long long ll;
vector<pair<int,int>> all_directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};


template <typename T>
void print(const vector<T> &a) {
    for (const auto &x : a) {
        cout << x << " ";
    }
    cout << endl;
    cout << "-------------" << endl;
}
template <typename T>
void print(const vector<vector<T>> &a) {
    for (const auto &row : a) {
        print(row); 
    }
    cout << "=============" << endl;
}

struct Point {
  ll x,y;
  Point(ll x, ll y):x(x),y(y){}
  bool operator<(const Point &p) const {
    if(x==p.x){
      return y<p.y;
    }
    return x<p.x;
  }
  
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}


void solve(){
  int n;
  cin>>n;
  vector<int> freq(26, 0);
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    freq[c-'A']++;
  }
  int k;
  cin>>k;
  sort(freq.rbegin(), freq.rend());
  int max_freq = freq[0];
  int gaddhe = (max_freq-1);
  int idle_slots = gaddhe*k;

  for(int i=1;i<26;i++){
    idle_slots -= min(freq[i], gaddhe);
  }
  if(idle_slots>0){
    cout<<n+idle_slots<<endl;
  } else {
    cout<<n<<endl;
  }







  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //int test = 0; cin>>test;while(test--)
    solve();
       
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
