class Solution {
public:
    typedef long long ll;
    //ri robot index
    //fi factory index
    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& t) {
        if(ri >= robot.size())  return 0; //no more robots to be covered

        if(fi >= positions.size())   return 1e12; //invalid case and minimum is required

        if(t[ri][fi] != -1)   return t[ri][fi];

        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions, t);
        ll skip = solve(ri, fi+1, robot, positions, t);

        return t[ri][fi] = min(take_current_factory, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //Step-1
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        int m = robot.size();
        
        //Step-2 (Expand factory positions to avoid tracking of limit and easy recursion)
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos   = factory[i][0];

            for(int j = 0; j < limit; j++)   positions.push_back(pos);
        }
        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll>(n+1, -1));

        //step-3 (solve)
        return solve(0, 0, robot, positions, t);

    }
};