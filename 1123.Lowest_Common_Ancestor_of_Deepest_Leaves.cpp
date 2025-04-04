#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// shit solution
// but it works
 
class Solution {

    private:
        TreeNode* finalAns;
        int currMaxDepth;
    
        bool checkIfAllNodesFound(unordered_map<int,bool>& myMap){
            for(const auto& [key,value] : myMap){
                if (!value){
                    return false;
                }
            }
            return true;
        }
    
    public:
    
        Solution(){
            this->currMaxDepth=INT_MIN;
            this->finalAns = nullptr;
        }
    
        int depthNikal(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            return 1 + max(depthNikal(root->left), depthNikal(root->right));
        }
    
        void dfsAndFindtheLowest(TreeNode* root,int depth, int reqDepth, unordered_map<int,bool>& lowestNodes){
    
            if(root==nullptr){
                return;
            }
    
            if(depth==reqDepth){
                lowestNodes[root->val]=false;
                return;
            }
    
            dfsAndFindtheLowest(root->left,depth+1,reqDepth,lowestNodes);
            dfsAndFindtheLowest(root->right,depth+1,reqDepth,lowestNodes);
    
        }
    
        void perNodeDFS(TreeNode* startingNode,TreeNode* root,unordered_map<int,bool>&lowestNodes,int depth){
            if(root==nullptr){
                return;
            }
    
            if(lowestNodes.find(root->val)!=lowestNodes.end()){
                if(!lowestNodes[root->val])
                    lowestNodes[root->val]=true;
            }
        
            if(checkIfAllNodesFound(lowestNodes)){
                if(depth > this->currMaxDepth){
                    this->finalAns=startingNode;
                    this->currMaxDepth=depth;
                }
            }
    
            perNodeDFS(startingNode,root->left,lowestNodes,depth);
            perNodeDFS(startingNode,root->right,lowestNodes,depth);
    
        }
    
        void mediatorForPassingByValue(TreeNode* root, unordered_map<int,bool>&lowestNodes,int depth){
            unordered_map<int,bool>newMap(lowestNodes);
            perNodeDFS(root,root,newMap,depth);
        }
    
        void dfsToGetToEachNode(TreeNode* root, unordered_map<int,bool>lowestNodes, int depth){
            if(root==nullptr){
                return;
            }
    
            mediatorForPassingByValue(root,lowestNodes,depth);
    
            dfsToGetToEachNode(root->left,lowestNodes,depth+1);
            dfsToGetToEachNode(root->right,lowestNodes,depth+1);
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
    
            int depthFinal = depthNikal(root);
            cout<<depthFinal<<endl;
    
            unordered_map<int,bool>lowestNodes;
            dfsAndFindtheLowest(root,1,depthFinal,lowestNodes);
    
            for (const auto& [key, value] : lowestNodes) {
                cout << key << " ";
            }
    
            dfsToGetToEachNode(root,lowestNodes,1);
    
            return this->finalAns;
        }
    
    };