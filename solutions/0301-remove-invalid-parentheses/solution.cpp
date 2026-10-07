class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                // More ')' than '('
                if (balance < 0)
                    return false;
            }
        }

        // All '(' must be matched
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                string curr = q.front();
                q.pop();

                // Check whether current string is valid
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // If valid strings are found at this level,
                // don't generate strings with more removals.
                if (found)
                    continue;

                // Try removing each parenthesis
                for (int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i)
                                + curr.substr(i + 1);

                    // Avoid duplicate states
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // First valid level = minimum removals
            if (found)
                break;
        }

        return ans;
    }
};
