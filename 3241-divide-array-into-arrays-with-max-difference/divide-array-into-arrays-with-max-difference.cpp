class Solution {
private:
void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> temp;
    int l = start;
    int r = mid + 1;
    while(l <= mid && r <= end){
        if(arr[l] < arr[r]){
            temp.push_back(arr[l++]);
        }else{
            temp.push_back(arr[r++]);
        }
    }
    while(l <= mid){
        temp.push_back(arr[l++]);
    }
    while(r <= end){
        temp.push_back(arr[r++]);
    }
    for(int i = 0 ; i < temp.size() ; i++){
        arr[start + i] = temp[i];
    }
    return ;
}

void mergeSort(vector<int> &arr, int start,int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        mergeSort(nums,0, n - 1 );
        vector<vector<int>> ans;
        vector<int> v;
        for(int i = 0 ; i < n ; i++){
            if(v.size() == 0){
                v.push_back(nums[i]);
            }else if(nums[i] - v[0] <= k){
                v.push_back(nums[i]);
                if(v.size() == 3){
                    ans.push_back(v);
                    v.clear();
                }
            }else{
                return {};
            }
        }
        return ans;
    }
};