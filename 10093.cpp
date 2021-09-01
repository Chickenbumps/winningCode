#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false), cin.tie(NULL);
  long long a,b;
  cin >> a >> b;
  vector<long long> v;
  long long mx = max(a,b), mn= min(a,b);
  long long count = mx-mn-1;
  if(mx == mn){
    cout << 0 <<"\n";
    return 0;
  }
  cout << count << "\n";
  for (long long i = mn+1; i < mx; i++)
  {
    cout << i <<" ";
  }
  
 
}