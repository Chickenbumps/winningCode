#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  getline(cin,s);
  int count = 0;
  if(s.empty()) {
    cout << "0";
    return 0;
  }
  for(auto p:s){
    if(p == ' '){
      count++;
    }
  }
  if(s[0] == ' ')  count--;
  if(s[s.length()-1]  == ' ') count--;
  cout << count+1;

  return 0;
}