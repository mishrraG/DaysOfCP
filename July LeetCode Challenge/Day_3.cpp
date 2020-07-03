#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<int> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
class Solution {
   public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map <int, vector <int> > m;
      if(!N) 
          return cells;
      set <vector <int> > visited;
      visited.insert(cells);
      for(int i = 1; i<=14 ; i++ ){
         vector <int> temp(8);
         for(int j = 1; j < 7; j++){
            temp[j]=!(cells[j - 1] ^ cells[j + 1]);
         }
         cells = temp;
         m[i] = temp;
         visited.insert(temp);
      }
      return m[N % 14 == 0? 14 : N % 14];        
    }
};
main(){
   vector<int> v1 = {0,1,0,1,1,0,0,1};
   Solution ob;
   print_vector(ob.prisonAfterNDays(v1, 7));
}
