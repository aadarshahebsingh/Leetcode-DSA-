struct Node{
    unordered_map<string, Node*>links;
    bool flag=false;
    bool containsKey(string key){
        return links.count(key)>0;
    }

    void put(string key,Node* node){
        links[key]=node;
    }

    Node* get(string key){
        return links[key];
    }

    void setEnd(){
        flag=true;
    }

};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }    
    void insert(vector<string> paths){
        Node* ptr=root;
        for(auto x:paths){
            if(!ptr->containsKey(x)){
                ptr->put(x,new Node());
            }
            ptr=ptr->get(x);
        }
        ptr->setEnd();
    }
    
    bool search(vector<string> paths){
        Node* ptr=root;
        for(auto x:paths){
            if(!ptr->containsKey(x)){
                return false;
            }
            ptr=ptr->get(x);

        }
        return true;
    }

    Node* getRoot(){
        return root;
    }
};


class Solution {

public:
    string dfs(Node* node,unordered_map<string,int>& hash,unordered_map<string,vector<Node*>>& dupMap){
        if(node->links.empty()){
            return "";
        }
        vector<pair<string,string>> children;
        for(auto &[name,child]:node->links){
            string sub=dfs(child,hash,dupMap);
            children.push_back({name,sub});
        }
        sort(children.begin(),children.end());

        string serial="";
        for(auto &[name,sub]:children){
            serial+=name+'('+sub+')';
        }

        hash[serial]++;
        dupMap[serial].push_back(node);
        return serial;
    }

    void finalDfs(Node* node,vector<string> path,vector<vector<string>>& ans,unordered_set<Node*>& deleted){
        for(auto& [name,child]:node->links){
            if(deleted.count(child))continue;
            path.push_back(name);
            ans.push_back(path);
            finalDfs(child,path,ans,deleted);
            path.pop_back();
        }
    }


    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;

        for(auto x:paths){
            trie.insert(x);
        }

        unordered_map<string,int> hash;
        unordered_map<string,vector<Node*>> dupMap;

        // making dfs call
        dfs(trie.getRoot(),hash,dupMap);


        // delete the folders
        unordered_set<Node*> deleted;
        for(auto &[serial,count]:hash){
            if(count>1){
                for(auto x:dupMap[serial]){
                    deleted.insert(x);
                }
            }
        }

        // call for final dfs
        vector<vector<string>> ans;
        finalDfs(trie.getRoot(), {}, ans, deleted);
        return ans;
    }
};


























