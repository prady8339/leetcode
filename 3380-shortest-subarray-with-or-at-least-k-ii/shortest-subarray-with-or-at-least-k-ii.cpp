class Solution {
private:
    bool chekky(vector<int> &bits,int k){
        int x = 0;
         for (int i = 0; i < 32; ++i) {
            if (bits[i] > 0) {
                x |= (1 << i);
            }
        }
       return x >= k;
    }

    void placeBits(vector<int> &bits, int val) {
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                bits[i]++;
            }
        }
    }

    void delBits(vector<int> &bits, int val) {
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                bits[i]--;
            }
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        int l = 0, r = 0, n = nums.size(), ans = n + 1;
        while (r < n) {
            if(nums[r] >= k) return 1;
            placeBits(bits, nums[r]);
            while (l <= r && chekky(bits, k)) {
                ans = min(ans, r - l + 1);
                delBits(bits, nums[l]);
                l++;
            }
            r++;
        }
        if(chekky(bits, k)){
         ans = min(ans, r - l);
        }
        return ans == n + 1 ? -1 : ans;
    }
};