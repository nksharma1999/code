class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ma(0), i(0);
        for(const auto &c: s) {
            int top = st.top();
                 if(top != -1 && s[top] == '('  && c == ')') {
                    st.pop();
                    int valtop = st.top();
                     ma = max(ma, i - valtop);
                } else
                    st.push(i);
                i++;
            }
        return ma;
    }
};
