// INPUT: Arr[]={ 1, 2, 3, 14, 50, 69, 90 }, K=12
// OUTPUT: Numbers smaller or equal to K: 3
  
// INPUT: Arr[]={ 12, 13, 13, 13, 14, 50, 54, 100 }, K=14
// OUTPUT: Numbers smaller or equal to K: 5
// ----------------------------------------------------------------
  
int upperBound(int arr[], int n, int k) {
    int low = 0;
    int high = n-1;
    int index = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] <= k) {
            index = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    //Note:- either index + 1 would be equal to n or element at index + 1 would be greater than k.
    //That means element at index will be certaily less than or equal to k
    return index + 1;
}


// Link : https://www.tutorialspoint.com/count-of-smaller-or-equal-elements-in-the-sorted-array-in-cplusplus
