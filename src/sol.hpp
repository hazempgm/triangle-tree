#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <system_error>
#include <vector>
#include <fstream>
#include <cmath>

class TreeNode {
public:
  int val;
  TreeNode* left;
  TreeNode* right;
  bool visited;

  TreeNode(int x) : val(x), left(NULL), right(NULL), visited(false) {}
  TreeNode() : val(0), left(NULL), right(NULL), visited(false) {}
  ~TreeNode() {
    if(!left) delete left; 
    if(right) delete right;

    left = nullptr;
    right = nullptr;
  }
};

TreeNode* parseTreeFromFile(const std::string& filename);
int maxPathSum(TreeNode* root);

