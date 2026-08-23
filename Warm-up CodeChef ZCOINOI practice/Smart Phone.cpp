#include <bits/stdc++.h>
using namespace std;

// Define directions for checking neighbors: top, right, bottom, left
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int calculatePerimeter(int m, const vector<pair<int, int>>& positions) {
    // Use set to store unique cells covered by stamps
    set<pair<int, int>> stampedCells;
    
    // Add all cells covered by the m x m stamps
    for (const auto& pos : positions) {
        // Convert from 1-based to 0-based indexing
        int x = pos.first - 1;
        int y = pos.second - 1;
        
        // Add all cells covered by the current stamp
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                stampedCells.insert({x + i, y + j}); // Keep everything 0-based
            }
        }
    }
    
    int perimeter = 0;
    
    // For each stamped cell, check its neighbors
    for (const auto& cell : stampedCells) {
        int x = cell.first;
        int y = cell.second;
        
        // Check all 4 directions
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            // If neighbor is not stamped, add to perimeter
            if (stampedCells.find({nx, ny}) == stampedCells.end()) {
                perimeter++;
            }
        }
    }
    
    return perimeter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t,customers=0;
    long long max_val=-1;
    map<long ,long > p;
    
    cin >> t;  
    
    while (t--) {
		int x;
		cin >> x;
		p[x]++;
    }
    
    for (auto i = p.rbegin(); i != p.rend(); ++i)
	{
		customers += i->second;
		
		long long revenue = i->first * customers;
		
		max_val = max(max_val, revenue);
		
	}
	
	 // Iterate through each customer's budget as the chosen price
    //~ for (int i = 0; i < n; i++) {
        //~ // Number of customers who can afford at least budgets[i]
        //~ long long potential_customers = n - i;
        //~ long long current_revenue = budgets[i] * potential_customers;
        
        //~ max_revenue = max(max_revenue, current_revenue);
    //~ }
	
    
    cout<<max_val<<'\n';
    
    return 0;
}
