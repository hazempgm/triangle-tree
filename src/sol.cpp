#include "sol.hpp"


int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cout << "Usage: " << argv[0] << " [FILENAME]" << std::endl;
    std::exit(-1);
  }
  
  TreeNode* root = parseTreeFromFile(argv[1]);

  if (root) {
    std::cout << maxPathSum(root) << " is the sum." << std::endl;
  } else {
    std::cout << "Error parsing tree, invalid file." << std::endl;
  }
  return 0;
}


