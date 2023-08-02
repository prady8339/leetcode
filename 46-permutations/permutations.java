class Solution {

    public void solve(int idx, int nums[],List<Integer> curr, List<List<Integer>> ans, boolean vis[] )
    {
        if(curr.size()==nums.length)
        {
            ans.add(new ArrayList<>(curr));
            return;
        }


        for(int i=idx; i<nums.length; i++)
        {
            if(vis[i]==true)
            continue;

            curr.add(nums[i]);
            vis[i]=true;
            solve(idx,nums,curr,ans,vis);
            curr.remove(curr.size()-1);
            vis[i]=false;

        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> curr= new ArrayList<>();
        List<List<Integer>> ans= new ArrayList<>();

        boolean vis[]= new boolean[nums.length];

        solve(0,nums,curr,ans,vis);
        return ans;
    }
}