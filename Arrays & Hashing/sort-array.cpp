class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        countsort(nums);
        return nums;
    }

    // Count sort
    // O(n + k), k is max element
    void countsort(vector<int>& arr) {
        int n = arr.size();

        // Find maximum and minimum element
        int maxVal = arr[0];
        int minVal = arr[0];
        for (int x : arr) {
            maxVal = max(maxVal, x);
            minVal = min(minVal, x);
        }

        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);
        for (int x : arr)
            count[x - minVal]++;
        
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];
        
        vector<int> output(n);
        for (int i = n - 1; i >= 0; i--) {
            int index = arr[i] - minVal;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }
        arr = output;
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

