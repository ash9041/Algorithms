class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
         int i=0;
       int j=n-1;
       int ans=n-1;
       int mid;
       while(i<=j){
            mid=i+(j-i)/2;
           if(mid-1>=0&&mid+1<n&&arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
               return mid;
           }
          else if(mid-1>=0&&arr[mid]>=arr[mid-1]||mid+1<n&&arr[mid+1]>arr[mid]){
                  i=mid+1; 
               }
           else {
              j=mid-1;
          }
           }
       
      return mid;
    }
};