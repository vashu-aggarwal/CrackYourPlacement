class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tGas = 0, tCost = 0;
        tGas = accumulate(gas.begin(), gas.end(), 0);
        tCost = accumulate(cost.begin(), cost.end(), 0);

        if(tGas < tCost){
            return -1;
        }
        int n = gas.size();
        int ind = 0; 
        int tank = 0;

        for(int i=0; i<n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                ind = i+1;
            }

        }

        return ind;
    }
};