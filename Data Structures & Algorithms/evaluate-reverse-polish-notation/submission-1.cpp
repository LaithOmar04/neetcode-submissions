class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> nums;
        for(const auto& token : tokens) {
            if(!isOperator(token)) {
                nums.push(token);
                continue;
            }

            string num2 = nums.top();
            nums.pop();
            string num1 = nums.top();
            nums.pop();

            //int res = doOperation(num1, num2, token);
            nums.push(to_string(doOperation(num1, num2, token)));
        }

        return stoi(nums.top());
    }

    bool isOperator(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    int doOperation(const string& num1, const string& num2, const string& op) {
        if(op == "+")
            return stoi(num1) + stoi(num2);
        else if(op == "-") 
            return stoi(num1) - stoi(num2);
        else if(op == "*") 
            return stoi(num1) * stoi(num2);
        else if(op == "/")
            return stoi(num1) / stoi(num2);
    }
};
