class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<int> indices(positions.size()), robots;
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&positions](int& a, int& b) {
            return positions[a] < positions[b];
        });
        for (int i : indices) {
            if (directions[i] == 'R')
                robots.push_back(i);
            else {
                while (!robots.empty() && healths[i] > 0) {
                    int n = robots.back();
                    if (healths[n] > healths[i]) {
                        healths[n]--;
                        healths[i] = 0;
                    } else {
                        robots.pop_back();
                        healths[i] -=
                            (healths[n] < healths[i] ? 1 : healths[i]);
                        healths[n] = 0;
                    }
                }
            }
        }
        healths.erase(remove(healths.begin(), healths.end(), 0), healths.end());
        return healths;
    }
};