class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string str = "";

        for (auto row : board) {
            for (auto col : row) {
                str.push_back('0' + col);
            }
        }

        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        unordered_set<string> visited;
        visited.insert(str);
        queue<string> q;
        q.push(str);
        
        int level = 0;
        string target = "123450";

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target)
                    return level;
                int indexOfZero = current.find('0');

                for (auto zero : mp[indexOfZero]) {
                    string next = current;
                    swap(next[zero], next[indexOfZero]);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};