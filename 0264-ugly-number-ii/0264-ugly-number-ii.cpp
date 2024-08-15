class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return true;

        int p1=0,p2=0,p3=0;
        vector<int> arr(n);
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=min(arr[p1]*2,min(arr[p2]*3,arr[p3]*5));

            if(arr[i]==arr[p1]*2) p1++;
            if(arr[i]==arr[p2]*3) p2++;
            if(arr[i]==arr[p3]*5) p3++;
        }

        return arr[n-1];
    }
};