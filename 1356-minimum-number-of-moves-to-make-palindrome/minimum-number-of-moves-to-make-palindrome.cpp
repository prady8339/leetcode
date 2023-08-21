class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int left = 0 , right = n-1;
        int swap_count = 0;
        while(left < right){
            int start = left , end = right;
            while(s[start]!=s[end]) start++;

            if(start==right){
                swap(s[right],s[right - 1]);
                swap_count++;
                continue;
            }else{
                while(start > left){
                    swap(s[start],s[start - 1]);
                    swap_count++;
                    start--;
                }
            }
            left++; right--;
        }
        
        return swap_count;
    }
};