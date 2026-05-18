class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =  nums.size();
        int l = 0;
        int r =n-1;
        int residx = 0;

        while(l<=r){
            while(l<r && nums[l]== nums[l+1]) l++; // these two to handle duplicates
            while(r>l && nums[r]== nums[r-1]) r--;
            int mid = l + (r-l)/2;

            if(nums[mid] < nums[residx])
            residx = mid;

            if(nums[mid] > nums[r]){  // this means array is rotated
                l = mid+1; 
            }
            else{
                r = mid-1;
            }

        }
    }
};