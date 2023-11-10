#include "sol.hpp"

// Function to parse a tree from a file and return the root
TreeNode* parseTreeFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Error: Unable to open file." << std::endl;
      return nullptr;
  }

  std::vector<TreeNode*> nodes;
  int val;

  // Read values from the file and create tree nodes
  while (file >> val) {
      nodes.push_back(new TreeNode(val));
  }

  // Build the binary tree from the vector of nodes
  for (size_t i = 0; i < nodes.size(); ++i) {
    size_t n = std::ceil((-1 + std::sqrt(8 + 8 * i)) / 2);
    

    size_t leftChildIndex = n + i;
    size_t rightChildIndex = n + i + 1;

    // Connect the left child if it exists
    if (leftChildIndex < nodes.size()) {
        nodes[i]->left = nodes[leftChildIndex];
    }

    // Connect the right child if it exists
    if (rightChildIndex < nodes.size()) {
        nodes[i]->right = nodes[rightChildIndex];
    }
  }

  file.close();
    return nodes[0]; // Return the root of the binary tree
}

// Function to find the maximum path sum in a binary tree
int maxPathSum(TreeNode* root) {

  // Base cases: if the tree is empty or the node has been visited, return 0
  if(!root)
    return 0;
  if(root->visited)
    return root->val;

  // Recursively calculate the maximum path sum for the left and right subtrees
  int rightSum = maxPathSum(root->right);
  int leftSum = maxPathSum(root->left);

  // Dynamic Programming
  // Update the value of the current node to include the maximum path sum
  root->val += std::max(leftSum, rightSum);
  root->visited = true; // Mark the node as visited to remove unnecessary calls

  return root->val; // Return the updated value
}




