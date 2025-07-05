class Solution{
public:
  bool isPalindrome(int x){
    int n = x;
    double num = 0;
    int a;

    while(n > 0){
      a = n % 10;
      num = (num * 10) + a;
      n = n / 10;
    }

    if(num == x){
      return true;
    }
    return false;
  }
};
