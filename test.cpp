#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
using namespace std;
void change_base(int n, int b)
{
    int r;
    
    r = n % b;
    n /= b;
    if (n > 0) change_base(n, b);
 
    if (r < 10) printf("%d", r);       // 10진수 이하 
    else printf("%c", r -10 + 'A');   // 11진수 이상 
}
bool prime(int num) {
	if (num < 2) return false;
	int temp = (int) sqrt(num);
	for (int i = 2; i <= temp; i++) if (num % i == 0) return false;
	return true;
}


map<string,pair<int,string> > m;

vector<int> r(11,0);
int main(){
  vector<int> v(11,2);
  r = v;
  for(auto p:r)
    cout << p << ' ';

  return 0;
}

