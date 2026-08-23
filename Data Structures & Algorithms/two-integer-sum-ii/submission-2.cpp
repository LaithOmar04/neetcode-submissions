class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        short start = 0;
        short end = numbers.size() - 1;

        while(start < end) {
            short curSum = numbers[start] + numbers[end];
            if(curSum < target) {
                ++start;
            } else if (curSum > target) {
                --end;
            } else {
                return {start + 1, end + 1};
            }
        }

        return {};
    }
};
