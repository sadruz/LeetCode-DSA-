/**375. Guess Number Higher or Lower II
Medium
We are playing the Guessing Game. The game will work as follows:
I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick **/

// [375. Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)
//solution:

class Solution {
    int fun(int low, int high, vector<vector<int>> &dp){
        if(low>=high) return 0;

        if(dp[low][high] != -1) return dp[low][high];
        int miniCost=INT_MAX;

        for(int guess=low; guess<=high; guess++){
            int cost = guess + max(fun(low,guess-1,dp), fun(guess+1,high,dp));

            miniCost = min(miniCost,cost);
        }

        return dp[low][high] = miniCost;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+1,-1));
        return fun(1,n,dp);
    }
};
