#include <iostream>
#include<string>

using namespace std;

int max(int a, int b);

int main(){

  string x = {"ACCUGTATAUCGUCACTU"};
  string y = {"GCAUTTC"};

  int c[19][8];

  for(int i=0 ; i<19 ; i++){
    c[i][0] = 0;
  }

  for(int j=0 ; j<8 ; j++){
    c[0][j] = 0;
  }

  for(int i=1 ; i<19 ; i++){
    for(int j=1 ; j<8 ; j++){
      if(x[i-1] == y[j-1]){
        c[i][j] = c[i-1][j-1] + 1;
      }
      else{
        c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
    }
  }

  for(int i=0 ; i<19 ; i++){
    for(int j=0 ; j<8 ; j++){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

int max(int a, int b){

  if(a>b)
    return a;
  return b;
}
