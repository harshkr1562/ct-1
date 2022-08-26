//name-Harsh Kumar
// roll no-2010991562
// set no-4
//grp-20
#include <bits/stdc++.h>
using namespace std;


int lenOfLongSubarr(int arr[],
                    int n,
                    int k)
{

    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    
    for (int i = 0; i < n; i++)
    {

        // accumulate sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;

        
        if (um.find(sum) == um.end())
            um[sum] = i;

        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end())
        {

            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    // required maximum length
    return maxLen;
}

// Driver Code
int main()
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;
    int res;

    try
    {
        res = lenOfLongSubarr(arr, n, k);
        if (!res)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "The longest subarray Length = " << res;
    return 0;
}


