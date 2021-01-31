void nextPermutation(vector<int>& nums) {
    int ind = -1, n = nums.size();
    for(int i=n-1;i>=1;--i){
        if(nums[i] > nums[i-1]){
            ind = i-1;
            break;
        }
    }
    if(ind == -1) reverse(nums.begin(), nums.end());
    else{
        auto itr = upper_bound(nums.rbegin(), nums.rbegin() + n - ind - 1, nums[ind]);
        int dist = itr - nums.rbegin();
        swap(nums[ind], nums[n-1-dist]);
        reverse(nums.begin() + ind + 1, nums.end());
    }
}

// Traverse the array from right and find the first element that does
// not follow the descending order. Swap this element with the closest
// greater element present to its right. Sort the array after this index
// and you'll have the next permutation.
// 4 1 5 3 2
// 4 2 5 3 1
// 4 2 1 5 3