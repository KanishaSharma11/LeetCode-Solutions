#include <climits>
#include <cctype>
#include <string>
using namespace std;

class Solution{
  public:
    int myAtoi(string s){
      int i = 0;
      int n = s.length();
      int sign = 1;
      while(i < n && isspace(s[i])){
        i++;
      }
      if(i < n && (s[i] == '+' || s[i] == '-' )){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
      }
      long long result = 0;
      while(i < n && isdigit(s[i])){
        result = result * 10 + (s[i] - '0');

        if(sign * result <= INT_MIN){
          result INT_MIN;
        }
        if(sign * result >= INT_MAX){
          return INT_MAX;
        }

        i++;
      }

      return result * sign;
    }
};
