// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string s)
{     
  string ans = "";
  int i=0;
  while(i<s.length()){
      int j = i;
      int c = 0;
      while(j<s.length() && s[i]==s[j]){
          c++;
          j++;
      }
      ans.push_back(s[i]);
      ans.append(to_string(c));
      i=j;
  }
  return ans;
}     
 