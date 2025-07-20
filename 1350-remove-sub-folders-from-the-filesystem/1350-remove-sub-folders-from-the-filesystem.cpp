// folder[i].compare(pos, len, str)


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string currFolder=ans.back();
            currFolder+="/";

            if(         folder[i].compare(0,currFolder.size(),currFolder        )!=0){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};