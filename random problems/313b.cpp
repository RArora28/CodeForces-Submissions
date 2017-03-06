#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n, len, a, b;
  string str;
  
  cin>>str;
  
  len = str.size();
  int s[len+2];

  s[10] = 0;

  //cout<<str;
  
  for(int i = 1; i < len; i++)
    {
      if(str[i] == str[i-1])
	  s[i] = s[i-1] + 1;
      else
	s[i] = s[i-1];
    }
  
  //for(int i = 0; i < len; i++)
  //cout<<s[i]<<" ";
  cin>>n;
  
  while(n--)
    {
      cin>>a>>b;
      cout<<(s[b-1] - s[a-1])<<endl;
    }
  
  return 0;
}
