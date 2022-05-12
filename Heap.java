class Heap{

    public static void heapify(int arr[],int n,int i){
        
        int largemtIndex = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        if(leftChild < n && arr[largemtIndex] > arr[leftChild])
            largemtIndex = leftChild;
    
        if(rightChild < n && arr[largemtIndex] > arr[rightChild])
            largemtIndex = rightChild;

        if(largemtIndex != i){
            
            int temp = arr[i];
            arr[i] = arr[largemtIndex];
            arr[largemtIndex] = temp;

            heapify(arr,n,largemtIndex);
        }

    }

    public static void heapSort(int arr[],int n){

        for(int i=n-1; i>0; i--){

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr,i,0);

        }
    }

    public static void createHeap(int arr[],int n){

        int startIndex = (n/2) - 1;

        for(int i=startIndex; i>=0; i--)
            heapify(arr,n,i);

    }

    public static void printArray(int arr[],int n){

        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i]+"\t");

    }

    public static void main(String args[]){
        int arr[] = { 1, 3, 5, 4, 6, 13, 10};

        createHeap(arr,arr.length);
        heapSort(arr,arr.length);
        printArray(arr,arr.length);
    }
}
