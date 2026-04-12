class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

    sort(sides.begin(),sides.end());
        
        if(sides[2]<(sides[0]+sides[1])){
            vector <double> arr;
            double res1,res2,res3;

            res1 = (double)((sides[1]*sides[1]) + (sides[2]*sides[2]) - (sides[0]*sides[0]))/(2*sides[1]*sides[2]);

            res1 = acos(res1);
            res1= (double)(res1*(double)(180/M_PI));

            arr.push_back(res1);

            res2 = (double)((sides[0]*sides[0]) + (sides[2]*sides[2]) - (sides[1]*sides[1]))/(2*sides[0]*sides[2]);

            res2 = acos(res2);
            res2= (double)(res2*(double)(180/M_PI));

            arr.push_back(res2);

            res3 = (double)((sides[1]*sides[1]) + (sides[0]*sides[0]) - (sides[2]*sides[2]))/(2*sides[1]*sides[0]);

            res3 = acos(res3);
            res3= (double)(res3*(double)(180/M_PI));

            arr.push_back(res3);

            return arr;

        }
            
        return{};
            
    }
};
