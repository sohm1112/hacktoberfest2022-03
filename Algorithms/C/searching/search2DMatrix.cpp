#include<bits/stdc++.h>
using namespace std;




bool searchMatrix(vector<vector<int>>& matrix, int target) {

	//start at the right most in the starting row -> i,j implies the starting point
	//if the element at matrix[i][j] is equal to target return true
	//else if it's less than target increment i (assures that target wont be in current row) as every element is sorted in row wise order and column wise order
	//else if it's greater than target decrement j (assures that target wont be in current column
	
	
	int row = matrix.size();
	int col = matrix[0].size();
	
	int i = 0;
	int j = col-1;
	
	while((i>=0&&j>=0)&&(i<row&&j<col)){
		
		if(matrix[i][j]==target)
			return true;
		else if (matrix[i][j]>target)
			j--;
		else 
			i++;
		
	}        
	
	return false;


}

int main()
{
	vector<vector<int>> v= { { 1, 3, 5 }, { 10, 11, 16 }, { 24, 36, 37 } };
	cout<< searchMatrix(v,11)<<endl;
	
}
