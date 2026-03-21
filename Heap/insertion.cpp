#include <bits/stdc++.h>
#include <queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;

    heap(){
        arr[0]=-1;
        size=0;
    }

    //o(logn)
    void insert(int val){
        size++;
        int ind=size;
        arr[ind]=val;
        
        //maxheap
        while(ind>1){
            int parent=ind/2;
            if(arr[parent]<arr[ind]){
                swap(arr[parent],arr[ind]);
                ind=parent;
            }
            else{
                return;
            }
        }
    }

        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        //Deletion-(root)
        // o(logn)
        void del(){
            if(size==0){
                cout<<"nothing to del"<<endl;
                return;
            }
            arr[1]=arr[size];
            size--;
            //heapify
            int i=1;
            while(i<=size){
                int largest=i;
                int left=2*i;
                int right=2*i+1;
                    if(left <= size && arr[largest] < arr[left])
                        largest = left;

                    if(right <= size && arr[largest] < arr[right])
                        largest = right;

                    if(largest != i){
                        swap(arr[i], arr[largest]);
                        i = largest;
                    }
                    else{
                        return;
                    }

            }

        }
    
};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

    void heapSort(int arr[],int n){
        int size=n;
        while(size>1){
            //s1:
            swap(arr[size],arr[1]);
            size--;

            //s2:
            heapify(arr,size,1);
        }
    }

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(51);
    h.del();
    h.print();
    h.insert(55);


    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
      heapify(arr,n,i);
    }
    //heap creation
    cout<<"printing the array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;

    }
    cout<<endl;

    //heapSort
    heapSort(arr,n);
    cout<<"sorting the array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;

    }
    cout<<endl;

    cout<<"Usong priority queue"<<endl;
    //max heap
    priority_queue <int> pq;
    pq.push(4);
    pq.push(0);
    pq.push(3);
    pq.push(2);pq.push(90);
    pq.push(1);
    pq.push(5);

    cout<<"eleemnt of top"<<pq.top()<<endl;
    pq.pop();
    cout<<"eleemnt of top"<<pq.top()<<endl;
    cout<<"Size is"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //min heap
    priority_queue <int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(0);
    minheap.push(3);
   minheap.push(2);minheap.push(90);
   minheap.push(1);
    minheap.push(5);

    cout<<"eleemnt of top"<<minheap.top()<<endl;
   minheap.pop();
    cout<<"eleemnt of top"<<minheap.top()<<endl;
    cout<<"Size is"<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }




    return 0;
}