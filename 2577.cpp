#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >>c;
  int d = a*b*c;
  string stringD = to_string(d);
  int arr[10]={0};
  for (int i = 0; i < stringD.size(); i++)
  {
    int temp =stringD[i] -'0';
    for (int j = 0; j < 10; j++)
    {
     if(temp == j){
        arr[j]++;
      }  
    }
    
  }
  for(int i =0; i< 10; i++){
    cout << arr[i] << "\n";
  }
  return 0;
}