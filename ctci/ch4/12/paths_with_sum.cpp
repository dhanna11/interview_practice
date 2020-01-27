typedef struct Node {
  Node* left;
  Node* right;
  int value;
} Node;

int paths_with_sum(Node* root, int sum) {
  return paths_with_sum(root, 0, sum);
}

int paths_with_sum(Node* root, int runningSum, int sum) {
  if (!root)
    return 0;
  
  int totalPaths = 0;
  runningSum+= root->value;
  if (runningSum == sum)
    totalPaths++;

  // paths with root
  totalPaths += paths_with_sum(root->left, runningSum, sum);
  totalPaths += paths_with_sum(root->right, runningSum, sum);
  // paths without root
  totalPaths += paths_with_sum(root->left, 0, sum);
  totalPaths += paths_with_sum(root->right, 0, sum);
  return totalPaths;
  
}
