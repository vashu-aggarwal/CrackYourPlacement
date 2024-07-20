class Solution {
private:
    vector<int> nextsmallerElement(vector<int> &arr, int n)
{
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!=-1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevsmallerElement(vector<int> &arr, int n)
{
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();

        vector<int> next(n);
        next=nextsmallerElement(heights,n);
        vector<int> prev(n);
        prev=prevsmallerElement(heights,n);
         int area=0;
        for(int i=0;i<n;i++)
        {
            int length=heights[i];
           
            if(next[i]==-1)
            {
                next[i]=n;
            }
             int breath=next[i]-prev[i]-1;
            int newarea=length*breath;
             area=max(area,newarea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector <int> ans(m,0);
        int newarea=INT_MIN;
	 int k=0;
	for(int i=0;i<n;i++)
	{
       for(int j=0;j<m;j++)
	   {
		   if(mat[i][j]!='0')
		   {
		   ans[j]=ans[j]+(mat[i][j]-'0');
	   }
	   else{
		   ans[j]=0;
	   }
	   }
      int area=largestRectangleArea(ans);
	   newarea=max(newarea,area);

	}

   return newarea; 
    }
};