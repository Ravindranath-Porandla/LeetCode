class Solution {
public:
    float Dia(vector<int>& rec) {
        float len = (float)rec[0];
        float bre = (float)rec[1];
        float dia = float(sqrt(len * len + bre * bre));
        return dia;
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int maxArea = 0;
        float maxDia = 0;
        for (int i = 0; i < dim.size(); i++) {
            float dia = Dia(dim[i]);
            if (dia > maxDia) {
                maxDia = dia;
                maxArea = dim[i][0] * dim[i][1];
            } else if (dia == maxDia) {
                if ((dim[i][0] * dim[i][1]) > maxArea)
                    maxArea = dim[i][0] * dim[i][1];
            }
        }
        return maxArea;
    }
};
