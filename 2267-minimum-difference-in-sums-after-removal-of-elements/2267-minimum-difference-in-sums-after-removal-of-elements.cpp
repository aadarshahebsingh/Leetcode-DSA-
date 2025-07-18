



class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n,1e15),suffix(n,1e15);

        priority_queue<long long> sumSecond;
        priority_queue<long long ,vector<long long>,greater<long long>> sumFirst;

        long long sum=0;
        for(int i=0;i<n/3;i++){
            sumSecond.push((long long)nums[i]);
            sum+=(long long )nums[i];
        }

        prefix[(n/3)-1]=sum;

        for(int i=(n/3);i<(2*n)/3;i++){
            if(sumSecond.top()>nums[i]){
                sum-=sumSecond.top();
                sum+=nums[i];
                sumSecond.pop();
                sumSecond.push((long long)nums[i]);
            }
            prefix[i]=sum;
        }

        sum=0;
        for(int i=n-1;i>=(2*n)/3;i--){
            sumFirst.push((long long)nums[i]);
            sum+=(long long)nums[i];
        }

        suffix[(2*n)/3]=sum;
        for(int i=((2*n)/3)-1;i>=n/3;i--){
            if(sumFirst.top()<nums[i]){
                sum-=sumFirst.top();
                sum+=nums[i];
                sumFirst.pop();
                sumFirst.push((long long)nums[i]);
            }
            suffix[i]=sum;
        }
        long long ans=1E15;
        for(int i=(n/3)-1;i<(2*n)/3;i++){
            if(i+1<n && ans>prefix[i]-suffix[i+1]){
                ans=prefix[i]-suffix[i+1];
            }
            
        }
        return ans;
    }
};