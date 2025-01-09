class Codec {
public:

    string serialize(TreeNode* root) {
        // Create an output string stream to store serialized data
        ostringstream temp;
        
        // Call the helper function to serialize the tree
        ToString(root, temp);
        
        // Convert the output string stream to a string and return
        return temp.str();
    }

    TreeNode* deserialize(string data) {
        // Create an input string stream to read serialized data
        istringstream temp(data);
        
        // Call the helper function to deserialize the tree and return the root
        return ToStructure(temp);
    }
    
private:
    
    void ToString(TreeNode* root, ostringstream& temp) {
        // Base case: If the current node is NULL, append "N" to represent null node
        if (root == NULL) {
            temp << "N ";
            return;
        }
        
        // Append the value of the current node followed by a space
        temp << root->val << " ";
        
        // Recursively serialize left and right subtrees
        ToString(root->left, temp);
        ToString(root->right, temp);
    }
    
    TreeNode* ToStructure(istringstream& temp) {
        // Read the next value from the input string stream
        string value = "";
        temp >> value;
        
        // If the value is "N", indicating a null node, return NULL
        if (value == "N") {
            return NULL;
        }
        
        // Otherwise, create a new TreeNode with the integer value
        TreeNode* root = new TreeNode(stoi(value));
        
        // Recursively construct left and right subtrees
        root->left = ToStructure(temp);
        root->right = ToStructure(temp);
        
        // Return the root of the reconstructed tree
        return root;
    }
    
};
