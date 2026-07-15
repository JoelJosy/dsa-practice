class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        return nums;
    }

    // Merge Sort
    // O(nlogn)
    void mergesort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];
    }

    // Quick Sort
    // O(nlogn) avg, O(n^2) wors
    int partition(vector<int>& arr, int lo, int hi) {
        // randomize pivot to avoid worst case
        int randomIdx = lo + rand() % (hi - lo + 1);
        swap(arr[hi], arr[randomIdx]);

        int pivot = arr[hi];
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i+1], arr[hi]);
        return i+1;
    }

    void quicksort(vector<int>& arr, int lo, int hi) {
        if (lo < hi) {
            int pi = partition(arr, lo, hi);
            quicksort(arr, lo, pi-1);
            quicksort(arr, pi+1, hi);
        }
    }
};

