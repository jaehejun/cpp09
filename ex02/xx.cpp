#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fordJohnsonSort(vector<int> input_list)
{
    int n = input_list.size();
    
    // Base case: if the list has 0 or 1 elements, return the list as is
    if (n <= 1) {
        return input_list;
    }
    
    // Step 1: Pairwise Comparison
    vector<int> max_values;
    vector<int> min_values;
    for (int i = 0; i < n / 2; i++) {
        max_values.push_back(max(input_list[i], input_list[i + n / 2]));
        min_values.push_back(min(input_list[i], input_list[i + n / 2]));
    }
    if (n % 2 == 1) {
        min_values.push_back(input_list[n - 1]);
    }
    
    // Step 2: Recursion and Renaming
    max_values = fordJohnsonSort(max_values);
    for (int i = 0; i < max_values.size(); i++) {
        for (int j = 0; j < input_list.size(); j++) {
            if (max_values[i] == input_list[j]) {
                min_values[i] = input_list[j];
                break;
            }
        }
    }
    
    // Step 3: Insertion
    vector<int> result;
    result.insert(result.end(), min_values.begin(), min_values.end());
    result.insert(result.end(), max_values.begin(), max_values.end());
    for (int i = 1; i < max_values.size(); i++) {
        result = binaryInsertion(max_values[i - 1], result);
    }
    
    return result;
}

vector<int> binaryInsertion(int value, vector<int> array)
{
    int left = 0, right = array.size() - 1;
    while (left <= right)
	{
        int mid = (left + right) / 2;
        if (array[mid] < value)
            left = mid + 1;
		else
            right = mid - 1;
    }
    vector<int> result(array.size() + 1);
    copy(array.begin(), array.begin() + left, result.begin());
    result[left] = value;
    copy(array.begin() + left, array.end(), result.begin() + left + 1);
    return result;
}

int main() {
    vector<int> input_list = {5, 2, 4, 6, 1, 3, 2, 5};
    vector<int> sorted_list = fordJohnsonSort(input_list);
    
    cout << "Sorted list: ";
    for (int num : sorted_list) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
