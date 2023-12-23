*************************************************************************************  Question  ***********************************************************************************************

In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. 

Example 1:

Input:
price = [10,7,19]
k = 45
Output: 
4
Explanation: 
A customer purchases 1 stock on day 1, 2 stocks on day 2 and 1 stock on day 3 for 10, 7 * 2 = 14 and 19 respectively. Hence, total amount is 10 + 14 + 19 = 43 and number of stocks purchased is 4.
Example 2:

Input: 
price = [7,10,4]
k = 100
Output: 
6
Explanation:
Buy on all 3 days.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function buyMaximumProducts() which takes an array price and an integer k and returns an integer as output.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 104
1 <= price[i] <= 104
1 <= k <= 104


**************************************************************************************  Solution  **********************************************************************************************
  //{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        int max=0;
        map<int,int>mp;
        int count=0;
        
        for(int i=0;i<n;i++){
            if(mp[price[i]]>0){
                  mp[price[i]]=mp[price[i]]+i+1;
                  count++;
                  price[i]=0;
            }else
              mp[price[i]]=mp[price[i]]+i+1;
          
          
         
        }
        
        sort(price,price+n);
        
        for(int i=count;i<n;i++){
            
            int a=price[i]*mp[price[i]];
            if(k>=price[i]){
                int b=k/price[i];
                if(b>=mp[price[i]]){
                k=k-a;
                max=max+mp[price[i]];
                }else{
            k=k-(b*price[i]);
            max=max+b;
                }
            }
            if(k<=0)
            break;
        }
        return max;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
