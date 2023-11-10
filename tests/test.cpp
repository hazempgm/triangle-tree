#include <cstdio>
#include <gtest/gtest.h>
#include <string>

#include "../src/sol.hpp" 

// can ignore, just a progress bar to see what's happening
#define PROGRESS_BAR(n, limit) { \
  float progress = static_cast<float>(n - 4) / (limit - 4); \
  int barWidth = 50; \
  int barLength = static_cast<int>(progress * barWidth); \
  std::cout << "["; \
  for (int j = 0; j < barWidth; ++j) { \
      if (j < barLength) std::cout << "="; \
      else std::cout << " "; \
  } \
  std::cout << "] " << std::setw(3) << static_cast<int>(progress * 100) << "%\r"; \
  std::cout.flush(); \
};

TEST(ParseTreeFromFileTest, ValidFile) {
    int result = system("python generate.py 2 triangle_tree.txt");
    ASSERT_EQ(result, 0) << "Failed to generate the triangle tree!";

    TreeNode* root = parseTreeFromFile("triangle_tree.txt");
    ASSERT_TRUE(root != nullptr) << "File opened but tree wasn't parsed!";
}

TEST(ParseTreeFromFileTest, InvalidFile) {
    TreeNode* root = parseTreeFromFile("invalid_tree.xyz");
    ASSERT_TRUE(root == nullptr) << "Should fail since the file don't exist!";
}



TEST(MaxPathSumTest, ValidSum) {
  // we're generating for every row numbers from 1 to the max row length
  // that way we can use the geometric series formula to calculate the largest sum n * (n + 1) /2
  int limit = 400;

  for(int n = 4; n < limit; ++n) {

    // using C style just because system uses const char *
    char command[255] = {0};
    
    // parsing command
    sprintf(command, "python generate.py %d triangle_tree.txt", n);
    int result = system(command);
    ASSERT_EQ(result, 0) << "Couldn't generate the tree with row " << n << " !";


    TreeNode* root = parseTreeFromFile("triangle_tree.txt");
    ASSERT_TRUE(root != nullptr) << "Couldn't parse the tree with row " << n << " !";


    int maxSum = maxPathSum(root);
     

    ASSERT_EQ(maxSum, n * (n + 1) / 2) << "Value is not right on row " << n << " !" 
                                       << " Should be " << n * (n + 1) / 2 <<" but it was "
                                       << maxSum << " !";

    PROGRESS_BAR(n, limit);
    delete root; 
  }

}

TEST(MaxPathSumTest, EmptyTree) {
    TreeNode* root = nullptr;
    int maxSum = maxPathSum(root);
    ASSERT_EQ(maxSum, 0) << "Should return 0 on empty tree!";
}




TEST(MaxPathSumTest, BigSum) {
  // This will generate 230 MB file..
  int n = 10000;
  // using C style just because system uses const char *
  char command[255] = {0};

  // parsing command
  sprintf(command, "python generate.py %d triangle_tree_giant.txt", n);
  int result = system(command);
  ASSERT_EQ(result, 0) << "Couldn't generate the tree with row " << n << " !";

  TreeNode* root = parseTreeFromFile("triangle_tree_giant.txt");
  ASSERT_TRUE(root != nullptr) << "Couldn't parse the tree with row " << n << " !";


  int maxSum = maxPathSum(root);
  ASSERT_EQ(maxSum, n * (n + 1) / 2) << "Value is not right on row " << n << " !" 
                                     << " Should be " << n * (n + 1) / 2 <<" but it was "
                                     << maxSum << " !";

  delete root; 
     
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
