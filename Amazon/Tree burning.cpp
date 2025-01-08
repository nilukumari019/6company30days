/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void makeGraph(unordered_map<int,vector<int>>&adj, TreeNode*curr, int parent)
{
    if(curr==NULL)
    return;

    if(parent!=-1)
    {
        adj[curr->val].push_back(parent);
    }
    if(curr->left)
    adj[curr->val].push_back(curr->left->val);
    if(curr->right)
    adj[curr->val].push_back(curr->right->val);

    makeGraph(adj,curr->left,curr->val);
    makeGraph(adj,curr->right,curr->val);
}
    int amountOfTime(TreeNode* root, int start) {
        if(root->left==NULL && root->right==NULL)
        return 0;
        unordered_map<int,vector<int>>adj;
        // -1 is depicting parent of root node
        makeGraph(adj,root,-1);
        queue<int>q;
        unordered_set<int>vis;
        q.push(start);
        vis.insert(start);
        int time=0;

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int curr=q.front();
                q.pop();
                for(auto nebr:adj[curr])
                {
                    if(vis.find(nebr)==vis.end())
                    {
                        q.push(nebr);
                        vis.insert(nebr);
                    }
                }
            }
            time++;
        }
        return time-1;
        
    }
};
