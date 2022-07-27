class MinHeap {
private:
    int capacity;
    int pointer;
    vector<int> arr;

    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int parent(int i) {return (i-1)/2;}
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        this->pointer = 0;
        arr.resize(capacity);
    }
    int size() {return pointer;}
    int top() {
        if(size()>0) return arr[0];
        else return INT_MAX;
    }
    void push(int data) {
        if(size() == capacity) {
            cout<<"Overflow! could not push the element\n";
            return;
        }
        int i = pointer;
        arr[i] = data;
        
        while(i and arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }

        pointer += 1;
    }
    int pop() {
        if(size()==0) {
            cout<<"Heap is empty!\n";
            return INT_MAX;
        }
        else if(size()==1) {
            pointer -= 1;
            return arr[0];
        }
        
        int root = arr[0];
        arr[0] = arr[pointer-1];
        pointer = pointer - 1;

        minHeapify(0);

        return root;
    }
    void minHeapify(int index) {
        int l = left(index), r = right(index);
        int smallest = index;
        if (l < pointer && arr[l] < arr[index]) smallest = l;
        if (r < pointer && arr[r] < arr[smallest]) smallest = r;
        
        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minHeapify(smallest);
        }
    }
};
