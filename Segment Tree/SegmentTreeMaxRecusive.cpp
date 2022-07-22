class SegmentTree
{
private:
    vector<int> segmentArr;
public:
    SegmentTree(int n){
        //n : number of elements in given array.
        segmentArr.resize(4*n+1);
    }

    void build(int index, int low, int high, vector<int> &arr) {
        if(low==high) {
            segmentArr[index] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        segmentArr[index] = max(segmentArr[2*index+1], segmentArr[2*index+2]);
    }
    
    int query(int index, int low, int high, int &L, int &R) {
        //case 1: No Overlap [L R low high | low high L R]
        if(R < low or L > high) return INT_MIN;
        //case 2: Complete Overlap [l low high r]
        if (low >= L && high <= R) return segmentArr[index];

        //case 3: Partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * index + 1, low, mid, L, R);
        int right = query(2 * index + 2, mid + 1, high, L, R);
        return max(left, right);
    }

    void update(int index, int low, int high, int i, int val) {
        if (low == high) {
            segmentArr[index] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * index + 1, low, mid, i, val);
        else update(2 * index + 2, mid + 1, high, i, val);
        segmentArr[index] = max(segmentArr[2 * index + 1], segmentArr[2 * index + 2]);
    }
};
