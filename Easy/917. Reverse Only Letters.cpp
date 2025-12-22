class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // If left is not a letter, move left
            if (!isalpha(s[left])) {
                left++;
            }
            // If right is not a letter, move right
            else if (!isalpha(s[right])) {
                right--;
            }
            // Both are letters → swap
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
