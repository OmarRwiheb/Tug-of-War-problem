#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define all(v) ((v).begin()), ((v).end())

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int arr[] = { 3, 4, 5, -3, 100, 1, 89, 54, 23, 20 };
int n = (int)sizeof(arr) / sizeof(arr[0]);
int i = 0, sum = 0, curSum = 0, numberOFelements = 0;
int mn = INT_MAX;
vector<bool>curr_elements(n);
vector<bool>ans(n);

void solve() {

    if (i == n) //out of bound
        return;

    // find the minimum difference between the sum of 
    // the two subset by substract the current sum from the total sum
    if (numberOFelements == n / 2) { 
        if (abs(sum / 2 - curSum) < mn) {
            mn = abs(sum / 2 - curSum);
            for (int i = 0; i < n; i++) 
                ans[i] = curr_elements[i]; // curr_elements vector indecate indexes the element that we have selected
        }
    }

    //this recurence function to skip the current element 
    i++;
    solve();
    i--;

    //if we will take the element then
    curr_elements[i] = 1;
    numberOFelements++;
    curSum += arr[i];
    i++;
    solve();
    //backTrack
    i--;
    numberOFelements--;
    curSum -= arr[i];
    curr_elements[i] = 0;
}
int main() {
    ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
#pragma warning(disable : 4996)
#ifndef ONLINE_JUDGE
    //freopen("input.in", "rt", stdin); 
#endif
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    solve();
    cout << "The First Subset : ";
    for (int i = 0; i < ans.size(); i++) {
        if(ans[i])
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The Second Subset : ";
    for (int i = 0; i < ans.size(); i++) {
        if (!ans[i])
            cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
