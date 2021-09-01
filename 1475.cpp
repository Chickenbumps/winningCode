#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(9,0);
  int count =0;
  int fin = 0;
  while(1){
    int num = n%10;
    if(num == 9) num = 6;
    if(v[num] == 0){
      count++;
      for(int i =0; i < 9; i++){
        v[i]++;
        if(i == 6) v[i]++;
      }
    }
    v[num]--;
   
    n /= 10;
    if(n == 0) break;
    
  }
  cout << count << "\n";
}


