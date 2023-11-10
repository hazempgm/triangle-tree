#include "sol.hpp"




TreeNode* parseTreeFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Error: Unable to open file." << std::endl;
      return nullptr;
  }

  std::vector<TreeNode*> nodes;
  int val;
  while (file >> val) {
      nodes.push_back(new TreeNode(val));
  }

  for (size_t i = 0; i < nodes.size(); ++i) {
    size_t n = std::ceil((-1 + std::sqrt(8 + 8 * i)) / 2);
    

    size_t leftChildIndex = n + i;
    size_t rightChildIndex = n + i + 1;

    if (leftChildIndex < nodes.size()) {
        nodes[i]->left = nodes[leftChildIndex];
    }

    if (rightChildIndex < nodes.size()) {
        nodes[i]->right = nodes[rightChildIndex];
    }
  }

  file.close();
    return nodes[0];
}

int maxPathSum(TreeNode* root) {
  if(!root)
    return 0;
  if(root->visited)
    return root->val;

  int rightSum = maxPathSum(root->right);
  int leftSum = maxPathSum(root->left);

  root->val += std::max(leftSum, rightSum);
  root->visited = true;

  return root->val;
}




