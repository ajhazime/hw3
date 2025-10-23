#include "stack.h"
#include <iostream> 

using namespace std;


int main(){

  Stack<string> s;

  string item1 = "ITEM 1";
  string item2 = "ITEM 2";
  string item3 = "ITEM 3";



  s.push(item1);
  s.pop();


  for(int i = 0; i < 5; ++i){
    s.push(item1);
  }
  s.push(item3);

  std::cout << s.top();



  return 0;
}