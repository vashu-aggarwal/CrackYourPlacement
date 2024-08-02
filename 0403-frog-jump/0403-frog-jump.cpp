class Solution
{
public:
    int dp[2001][2001];
    bool jumps(int ind, int jumpSize, vector<int> &stones, map<int, int> &mp)
    {
        // If we've reached the last stone, a successful jump sequence is found.
        if (ind == stones.size() - 1)
        {
            return true;
        }
        // If the index is out of bounds, we can't proceed further.
        if (ind >= stones.size())
        {
            return false;
        }

        // If we have a cached result for this index and jump size, return it.
        if (dp[ind][jumpSize] != -1)
        {
            return dp[ind][jumpSize];
        }

        bool ans1 = false, ans2 = false, ans3 = false;

        // Attempt to jump with a reduced jump size by 1, checking if a valid jump is possible.
        // ind==0 will make a backward jump and jumpsize<=1 will make jump on same or previous stones which can lead to infinite
        // loops.
        if (ind != 0 && jumpSize > 1 && mp.count(stones[ind] + jumpSize - 1))
        {
            ans1 = jumps(mp[stones[ind] + jumpSize - 1], jumpSize - 1, stones, mp);
            if (ans1 == true)
            {
                return dp[ind][jumpSize] = true; // Cache and return the result.
            }
        }

        // Attempt to jump with the current jump size, checking if a valid jump is possible.
        if (mp.count(stones[ind] + jumpSize))
        {
            ans2 = jumps(mp[stones[ind] + jumpSize], jumpSize, stones, mp);
            if (ans2 == true)
            {
                return dp[ind][jumpSize] = true; // Cache and return the result.
            }
        }

        // Attempt to jump with an increased jump size by 1, checking if a valid jump is possible.
        // at ind==0 jump of only 1 unit is allowed
        if (ind != 0 && mp.count(stones[ind] + jumpSize + 1))
        {
            ans3 = jumps(mp[stones[ind] + jumpSize + 1], jumpSize + 1, stones, mp);
            if (ans3 == true)
            {
                return dp[ind][jumpSize] = true; // Cache and return the result.
            }
        }

        // No valid jumps found, so cache and return false.
        return dp[ind][jumpSize] = false;
    }

    bool canCross(vector<int> &stones)
    {
        memset(dp, -1, sizeof(dp));
        map<int, int> mp;
        for (int i = 0; i < stones.size(); i++)
        {
            mp[stones[i]] = i;
        }
        return jumps(0, 1, stones, mp);
    }
};