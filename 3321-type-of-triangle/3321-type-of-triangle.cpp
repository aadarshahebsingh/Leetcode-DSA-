class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x=nums[0],y=nums[1],z=nums[2];

        if((x+y<=z) || (y+z<=x) || (x+z<=y))
            return "none";
        else if(x==y && y==z)
            return "equilateral";
        else if((x!=y && y!=z && x!=z))
            return "scalene";
        return "isosceles";
    }
};