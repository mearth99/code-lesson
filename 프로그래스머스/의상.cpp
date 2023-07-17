#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main(){
  map<string, string> m;
  m.insert({"test","zz"});
  m.insert({"test","zy"});
  m.insert({"test","zy"});

  m.insert({"test","zy"});

  cout << m.size();
  return 0;
}