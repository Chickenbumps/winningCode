// 직접 구현 X


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> v(n,0);
  vector<ll> f(21,1);
  for (int i = 1; i < 21; i++)
  {
    f[i] = f[i-1] *i;
  }
    
  
  if(m == 1){
    ll k;
    cin >> k;
    k--;
    vector<int> ans(n,0);
    for(int i = 0; i < n; i++) ans[i] = i+1;  
    for(int i = 0; i < n; i++){
      ll q = k / f[n-1-i];
      k = k - q * f[n-1-i];
      cout << ans[q] << " ";
      ans.erase(ans.begin()+ q);
    }
    
  }else if(m == 2){
    ll ans = 0;
    vector<int> used(n+1);
    for(int i = 0; i < n; i++){
      int val;
      cin >> val;
      int count = 0;
      for(int j = 1; j < val; j++) count += (!used[j]);
      ans += count * f[n-1-i];
      used[val] = true;
    }
    cout << ans+1 << "\n";
  }
  
  return 0;
}