#include <bits/stdc++.h>
using namespace std;

// Approach 1: Separate pos/neg and interleave them
vector<int> RearrangeBySign1(vector<int> arr, int n) {
    vector<int> pos, neg, result;

    // Separate positives and negatives
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) pos.push_back(arr[i]);
        else if (arr[i] < 0) neg.push_back(arr[i]);
    }

    // Interleave elements safely
    int minCount = min(pos.size(), neg.size());
    for (int i = 0; i < minCount; i++) {
        result.push_back(pos[i]);
        result.push_back(neg[i]);
    }

    // Append leftovers (if counts differ)
    for (int i = minCount; i < pos.size(); i++)
        result.push_back(pos[i]);
    for (int i = minCount; i < neg.size(); i++)
        result.push_back(neg[i]);

    return result;
}

// Approach 2: Directly fill at alternating indices
vector<int> RearrangeBySign2(vector<int> arr, int n) {
    vector<int> result(n); // ✅ pre-allocate to size n
    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && posIndex < n)
            result[posIndex] = arr[i], posIndex += 2;
        else if (arr[i] < 0 && negIndex < n)
            result[negIndex] = arr[i], negIndex += 2;
    }

    return result;
}

vector<int> RearrangeBySign3(vector<int> arr, int n) {
    vector<int> pos, neg, res;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else if (arr[i] < 0)
            neg.push_back(arr[i]);
    }

    // Case 1: more positives than negatives
    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        // Add remaining positives
        for (int i = neg.size(); i < pos.size(); i++) {
            res.push_back(pos[i]);
        }
    }
    // Case 2: more negatives or equal
    else {
        for (int i = 0; i < pos.size(); i++) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        // Add remaining negatives
        for (int i = pos.size(); i < neg.size(); i++) {
            res.push_back(neg[i]);
        }
    }

    return res;
}

int main() {
    int no = 0;
    cout << "Enter size of array: ";
    cin >> no;
    vector<int> arr(no);

    cout << "Enter array elements: " << endl;
    for (int i = 0; i < no; i++) {
        cin >> arr[i];
    }

    // vector<int> ret = RearrangeBySign1(arr, no);
    // vector<int> ret = RearrangeBySign2(arr, no);
    vector<int> ret = RearrangeBySign3(arr, no);

    cout << "Rearranged array: " << endl;
    for (auto i : ret) cout << i << " ";
    cout << endl;

    return 0;
}
