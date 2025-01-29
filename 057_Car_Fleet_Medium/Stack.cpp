// https://leetcode.com/problems/car-fleet/description/
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
       vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
       sort(cars.begin(), cars.end());
     stack<double> stack;
        /*
Calculating Time for Each Car:
For car at position 10 with speed 2: Time = (12 - 10) / 2 = 1 hour.
For car at position 8 with speed 4: Time = (12 - 8) / 4 = 1 hour.
For car at position 0 with speed 1: Time = (12 - 0) / 1 = 12 hours.
For car at position 5 with speed 1: Time = (12 - 5) / 1 = 7 hours.
For car at position 3 with speed 3: Time = (12 - 3) / 3 = 3 hours.

The cars are sorted based on their starting positions, 
resulting in the order: [0, 3, 5, 8, 10] with corresponding times [12, 3, 7, 1, 1].
                  times [12, 3, 7, 1, 1]

The stack is used to track the arrival times of the fleets at the target.
Starting from the car closest to the target (position 10, time 1 hour), we iterate backwards:
Car at position 10 (time 1) starts a fleet.
Car at position 8 (time 1) joins the fleet started by the car at position 10 because its time is not greater than the top of the stack.
Car at position 5 (time 7) starts a new fleet because 7 is greater than 1 (top of the stack).
Car at position 3 (time 3) joins the fleet started by the car at position 5 because 3 is not greater than 7.
Car at position 0 (time 12) starts another new fleet because 12 is greater than 3.

The stack now contains the times [1, 7, 12]  , so output the size 3 
*/
        for (int i = n - 1; i >= 0; --i){
            // If the current car's time is greater than the time of the last fleet on the stack,
            // it means this car will form a new fleet.
            if (stack.empty() || cars[i].second > stack.top()) {
                stack.push(cars[i].second);
            }
        }
        
        // The size of the stack is the number of fleets
        return stack.size();
    }
};