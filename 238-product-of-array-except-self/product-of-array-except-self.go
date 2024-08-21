func productExceptSelf(nums []int) []int {
    n := len(nums)
    pref := make([]int, n)
    suff := make([]int, n)
    ans := make([]int, n)

    mult := 1
    for i := 0; i < n; i++ {
        mult *= nums[i]
        pref[i] = mult
    }

    mult = 1
    for i := n - 1; i >= 0; i-- {
        mult *= nums[i]
        suff[i] = mult
    }

    for i := 0; i < n; i++ {
        if i == 0 {
            ans[i] = suff[1]
        } else if i == n-1 {
            ans[i] = pref[n-2]
        } else {
            ans[i] = pref[i-1] * suff[i+1]
        }
    }

    return ans
}
