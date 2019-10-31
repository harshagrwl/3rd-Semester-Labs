
#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MaxHeap
{
        int *harr; 
        int capacity; 
        int heap_size; 
public:
        
        MaxHeap(int capacity);

        
        void MaxHeapify(int );

        int parent(int i) { return (i-1)/2; }

        
        int left(int i) { return (2*i + 1); }

        
        int right(int i) { return (2*i + 2); }

        
        int extractMax();


        
        int getMax() { return harr[0]; }


        void insertKey(int k);

        void printHeap();
        void buildHeap();
};


MaxHeap::MaxHeap(int cap)
{
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
}


void MaxHeap::insertKey(int k)
{
        if (heap_size == capacity)
        {
                cout << "\nCould not insertKey\n";
                                return;
        }

    
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        
        while (i != 0 && harr[parent(i)] <harr[i])
        {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
        }
}


int MaxHeap::extractMax()
{
        if (heap_size <= 0)
                return INT_MAX;
        if (heap_size == 1)
        {
                heap_size--;
                return harr[0];
        }


        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
}



void MaxHeap::MaxHeapify(int i)
{
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && harr[l] > harr[i])
                largest = l;
        if (r < heap_size && harr[r] > harr[largest])
                largest = r;
        if (largest != i)
        {
                swap(&harr[i], &harr[largest]);
                MaxHeapify(largest);
        }
}


void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}

void MaxHeap::buildHeap()
{
        int n;
        cout<<"Enter the number of elements->";
        cin>>n;
        heap_size=n;
        cout<<"Enter the elememts :";
        for(int i=0;i<n;i++)
                cin>>harr[i];
      
    int startIdx = (n / 2) - 1;

    
    for (int i = startIdx; i >= 0; i--) {
        MaxHeapify(i);
    }
}

void MaxHeap::printHeap()
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < heap_size; ++i)
        cout << harr[i] << " ";
    cout << "\n";
}

int main()
{
        int n,ch=1;
        MaxHeap h(30);
        do{
        cout<<"1.Insert 2.Heapify 3.build heap 4.Extract-max 5.Maximum 6.Print the heap 7.exit\n";
        cout<<"Enter your choice:";
        cin>>n;
        switch(n)
        {

                case 1: cout<<"Enter the element to insert->";
                        cin>>n;
                        h.insertKey(n);
                        break;
                case 2: cout<<"enter the index where heapify operation should be done->";
                        cin>>n;
                        h.MaxHeapify(n);
                        h.printHeap();
                        break;
                case 3: h=MaxHeap(30);
                        h.buildHeap();
                        h.printHeap();
                        break;
                
                case 4:cout<<"Maximum element->"<<h.extractMax();
                        cout<<endl;
                        h.printHeap();
                        break;
                case 5: cout<<"Maximum element ->"<<h.getMax()<<endl;
                        break;
              

                case 6: h.printHeap();
                        break;
                case 7:exit(1);
                         break;
                default:cout<<"Wrong choice";


        }

        }while(1);
        return 0;
        

}                                                                                  