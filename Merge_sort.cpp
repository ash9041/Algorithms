class Solution {
public:
void divide(vector<int>& nums,int st,int ed){
    if(ed==st)return;
    int mid=(ed+st)/2;
    divide(nums,st,mid);
    divide(nums,mid+1,ed);
    merge(nums,st,mid,ed);
}
void merge(vector<int>&nums,int st,int mid,int ed){
    int l=st;
    int e=ed;
    int m=mid+1;
    vector<int>temp;
   while(l!=mid+1&&m!=ed+1){
    if(nums[l]<=nums[m]){
        temp.push_back(nums[l]);
        l++;
    }
    else{
        temp.push_back(nums[m]);
        m++; 
    }
   }
    while(l!=mid+1){
        temp.push_back(nums[l]);
        l++;
    }
    while(m!=ed+1){
       temp.push_back(nums[m]);
        m++; 
    }
    int i=0;
    l=st;
    while(i<temp.size()){
        nums[l]=temp[i];
        i++;
        l++;
    }
    
}
    vector<int> sortArray(vector<int>& nums) {
       divide(nums,0,nums.size()-1);
       return nums;
    }
};
