/*
Given an array of integers, find the subset of non-adjacent elements(one function) or adjacent elements(another function) with the maximum sum. Calculate the sum of that subset. It is possible that the maximum sum is , the case when all elements are negative.


Sample Input for non-adjacent
5
3 7 4 6 5
Sample Output
13


Sample Input for adjacent elements
6
3 -1 -1 4 3 -1
Sample Output
8
*/



#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxNonAdjacentSubsetSum(vector<int> arr) {
    int n = arr.size();
    int prepreSum = 0;
    int preSum;
    int maxSum;
    
    if(n == 0){
        return 0;
    }
    
    prepreSum = std::max({arr[0], 0});
    if(n == 1) {
        return prepreSum;
    }
    
    preSum = std::max({arr[1], 0});

    maxSum = std::max({prepreSum, preSum});
        
    for(int i=2; i<n; i++){
        
        preSum = prepreSum + arr[i];
        prepreSum = maxSum;
        maxSum = std::max({prepreSum, preSum});
    }
    return maxSum;  
}


int maxAdjacentSubsetSum(vector<int> arr) {
    int currSum = arr[0];
    int maxSum = arr[0];
    int n = arr.size();
    
    for(int i=1; i<n; i++){
        if(currSum <= currSum + arr[i]){
            currSum += arr[i];
        }
        else{
            currSum = arr[i];
        }
        
        if(maxSum < currSum){
            maxSum = currSum;
        }
    }
    
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

