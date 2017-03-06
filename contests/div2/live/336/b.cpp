#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  string str1, str2;
  
  cin>>str1>>str2;

  int len1 = str1.size(), s = 0;
  int len2 = str2.size();

  for(int i = 0; i < len1; i++)
      s += abs(str1[i] - str2[i]);
   
  for(int i = len1; i < (len2 - len1 + 1); i++)
    s += abs(str1[i] - str2[i]) - abs(str1[i-len1] - str2[i - len2]);

  cout<<s<<endl;
  return 0;
}
