// https://leetcode.com/problems/car-fleet/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for(int i=0; i<n; i++)
            cars[i] = {position[i], (double)(target-position[i])/speed[i]};
        sort(cars.rbegin(), cars.rend());
        double max_time = 0.0;
        int ans = 0;
        for (auto& car : cars) {
            double time = car.second;
            if (time > max_time) {
                ans++;
                max_time = time;
            }
        }

        return ans;
    }
};