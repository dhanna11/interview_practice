#include <iostream>
#include <vector>

using namespace std;

void copyTopRow(const vector<vector<int>> & inputMatrix, int rowIdx, int start, int end, vector<int>& dest) {
  const vector<int>& row = inputMatrix.at(rowIdx);
  for (int i = start; i <= end; i++) {
    dest.push_back(row.at(i));
  }
}

void copyBottomRow(const vector<vector<int>> & inputMatrix, int rowIdx, int start, int end, vector<int>& dest) {
  const vector<int> & row = inputMatrix.at(rowIdx);
  for (int i = start; i >= end; i--) {
    dest.push_back(row.at(i));    
  }
}

void copyRightCol(const vector<vector<int>> & inputMatrix, int col, int start, int end, vector<int>& dest) {
  for (int i = start; i <= end; i++) {
    const vector<int> & row = inputMatrix.at(i);
    dest.push_back(row.at(col));
  }
}

void copyLeftCol(const vector<vector<int>> & inputMatrix, int col, int start, int end, vector<int>& dest) {
  for (int i = start; i >= end; i--) {
    const vector<int> & row = inputMatrix.at(i);
    dest.push_back(row.at(col));
  }
}

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) {

  vector<int> result;
  int topRowIdx = 0;
  int topRowStartIdx = 0;
  int topRowEndIdx = inputMatrix[0].size() - 1;
  
  int rightColIdx = inputMatrix[0].size() - 1;
  int rightColStartIdx = 1;
  int rightColEndIdx = inputMatrix.size() - 2;
  
  int bottomRowIdx = inputMatrix.size() - 1;
  int bottomRowStartIdx = inputMatrix.at(0).size() - 1;
  int bottomRowEndIdx  = 0;
  
  int leftColIdx = 0;
  int leftColStartIdx = inputMatrix.size() - 2;
  int leftColEndIdx = 1;
  while (topRowIdx <= bottomRowIdx) {
    copyTopRow(inputMatrix, topRowIdx, topRowStartIdx, topRowEndIdx, result);
    copyRightCol(inputMatrix, rightColIdx, rightColStartIdx, rightColEndIdx, result);
    if (topRowIdx != bottomRowIdx) {
      copyBottomRow(inputMatrix, bottomRowIdx, bottomRowStartIdx, bottomRowEndIdx, result);
    }
    copyLeftCol(inputMatrix, leftColIdx, leftColStartIdx, leftColEndIdx, result);
    
    topRowIdx++;
    topRowStartIdx++;
    topRowEndIdx--;
    
    rightColIdx--;
    rightColStartIdx++;
    rightColEndIdx--;
    
    bottomRowIdx--;
    bottomRowStartIdx--;
    bottomRowEndIdx++;
    
    leftColIdx++;
    leftColStartIdx--;
    leftColEndIdx++;    
  }
  return result;
}
int main() {
  vector<vector<int>> input {{1,    2,   3,  4,    5},
			     {6,    7,   8,  9,   10},
			     {11,  12,  13,  14,  15},
			     {16,  17,  18,  19,  20}};

  for (auto & i : spiralCopy(input)) 
    std::cout << i << std::endl; 

  return 0;
}
