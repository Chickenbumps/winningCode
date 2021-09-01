#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
      v.push_back(i+1);
    }
    
    for (int i = 0; i < 10; i++)
    {
      int s,e;
      cin >> s >> e;
      reverse(v.begin()+s-1,v.begin()+e);
    }
    for(auto p: v){
      cout << p << " ";
    }
    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     vector<int> v,t;
//     for (int i = 0; i < 20; i++)
//     {
//       v.push_back(i+1);
//     }
    
//     for (int i = 0; i < 10; i++)
//     {
//       int s,e;
//       cin >> s >> e;
//       int j = e-1, k = s-1;
//       while(j >= k){
//         int temp = v[j];
//         v[j] = v[k];
//         v[k] = temp;
//         j--;
//         k++;
//       }
//     }
//     for(auto p: v){
//       cout << p << " ";
//     }
//     return 0;
// }