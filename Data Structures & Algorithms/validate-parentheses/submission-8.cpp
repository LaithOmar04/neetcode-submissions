class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) {
            return false;
        }
        if(s.size() == 0) {
            return true;
        }
        // if(s[0] == ']' || s[0] == ')' || s[0] == '}') {
        //     return false;
        // }

        stack<char> pStack;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
                pStack.push(s[i]);
                continue;
            } 
        
            char curP = s[i];
            switch(curP) {
                case ')':
                    if(pStack.empty() || pStack.top() != '(') { return false; }
                    pStack.pop();
                    break;
                case ']':
                    if(pStack.empty() || pStack.top() != '[') { return false; }
                    pStack.pop();
                    break;
                case '}':
                    if(pStack.empty() || pStack.top() != '{') { return false; }
                    pStack.pop();
                    break;
            }
        }

        if(!pStack.empty()) { return false; }
        return true;
    }
};
