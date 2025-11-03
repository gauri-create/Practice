#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Base abstraction class defining interface
class Merger {
public:
    virtual void merge(long long arr1[], long long arr2[], int n, int m) = 0;
    virtual ~Merger() = default;
};

// Helper mixin class (common utilities)
class MergeUtils {
protected:
    void swapIfGreater(long long arr1[], long long arr2[], int i, int j) {
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
    }
};

// 1. Brute-force merge (extra space O(n+m))
class BruteForceMerger : public Merger {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) override {
        long long arr3[n + m];
        int left = 0;
        int right = 0;
        int index = 0;
        while (left < n && right < m) {
            if (arr1[left] <= arr2[right]) {
                arr3[index] = arr1[left];
                left++, index++;
            } else {
                arr3[index] = arr2[right];
                right++, index++;
            }
        }
        while (left < n) {
            arr3[index++] = arr1[left++];
        }
        while (right < m) {
            arr3[index++] = arr2[right++];
        }
        for (int i = 0; i < n + m; i++) {
            if (i < n) arr1[i] = arr3[i];
            else arr2[i - n] = arr3[i];
        }
    }
};

// 2. Two pointer + sort (in-place)
class TwoPointerMerger : public Merger {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) override {
        int left = n - 1;
        int right = 0;
        while (left >= 0 && right < m) {
            if (arr1[left] > arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--, right++;
            } else {
                break;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

// 3. Gap method (optimal in-place)
class GapMerger : public Merger, protected MergeUtils {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) override {
        int len = (n + m);
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (left < n && right >= n) {
                    swapIfGreater(arr1, arr2, left, right - n);
                } else if (left >= n) {
                    swapIfGreater(arr2, arr2, left - n, right - n);
                } else {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++, right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};

// Context class (Strategy pattern)
class ArrayMerger {
private:
    Merger* strategy;
public:
    ArrayMerger(Merger* m) : strategy(m) {}
    void execute(long long arr1[], long long arr2[], int n, int m) {
        strategy->merge(arr1, arr2, n, m);
    }
};

// ----------------------------------------------------
// Main function with user input
int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    long long arr1[n], arr2[m];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++) cin >> arr2[i];

    cout << "\nChoose merge strategy:\n";
    cout << "1. Brute Force (O(n+m) space)\n";
    cout << "2. Two Pointer + Sort\n";
    cout << "3. Gap Method (Optimal)\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    Merger* mergerStrategy = nullptr;
    if (choice == 1)
        mergerStrategy = new BruteForceMerger();
    else if (choice == 2)
        mergerStrategy = new TwoPointerMerger();
    else if (choice == 3)
        mergerStrategy = new GapMerger();
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    ArrayMerger merger(mergerStrategy);
    merger.execute(arr1, arr2, n, m);

    cout << "\nMerged arrays:\n";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    for (int i = 0; i < m; i++) cout << arr2[i] << " ";
    cout << endl;

    delete mergerStrategy;
    return 0;
}
