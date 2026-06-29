class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAr=0;
        int left =0;
        int right = height.size()-1;

        while(left<right){
            int breadth = right - left;
            int length = min(height[right], height[left]);
            int area = length* breadth;

            maxAr = max(area,maxAr);

            if(height[left]<height[right]) left++;
            else if(height[right]<height[left]) right--;
            else{
                left++;
                right--;
            }
        }

        return maxAr;
    }
};
