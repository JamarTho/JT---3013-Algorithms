##Source Code:
#include <iostream>
using namespace std;

class Heap {
    int *heap;
    int bum;
    
    // Helper function to move element up to maintain heap property
    void bubble_up(int i) {
        int parent = i / 2;
        while (i > 1 && heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = i / 2;
        }
    }

    // Helper function to move element down to maintain heap property
    void bubble_down() {
        int i = 1;
        while (2 * i < bum) { // While there are children
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            // Find smallest between parent, left, and right
            if (left < bum && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < bum && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == i) break; // If parent is smaller than both children, stop

            // Swap with the smallest child
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    // Swap helper function to exchange two elements
    void swap(int &i, int &j) {
        int temp = i;
        i = j;
        j = temp;
    }

public:
    Heap() {
        heap = new int[100];
        bum = 1; // The heap starts at index 1
    }

    ~Heap() {
        delete[] heap; // Free the allocated memory
    }

    // Pop the smallest element (root)
    int pop() {
        if (bum <= 1) return -1; // Empty heap check

        int min_val = heap[1];
        bum--;
        swap(heap[1], heap[bum]);
        bubble_down(); // Restore heap property

        return min_val;
    }

    // Push a new value onto the heap
    void push(int x) {
        heap[bum] = x;
        bubble_up(bum);
        bum++;
    }

    // Print the heap elements
    void print() {
        for (int i = 1; i < bum; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    
    heap.push(13);
    heap.push(11);
    heap.push(7);
    heap.push(3);
    heap.print();  // Expected output: 3 11 7 13

    cout << "Popped: " << heap.pop() << endl;  // Expected output: 3
    heap.print();  // Expected output: 7 11 13
    
    heap.push(1);
    heap.print();  // Expected output: 1 7 13 11
    
    return 0;
}

##Deletion Method File

#include <iostream>
using namespace std;

class Heap {
    int *heap;
    int bum;
    
    // Helper function to move element up to maintain heap property
    void bubble_up(int i) {
        int parent = i / 2;
        while (i > 1 && heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = i / 2;
        }
    }

    // Helper function to move element down to maintain heap property
    void bubble_down() {
        int i = 1;
        while (2 * i < bum) { // While there are children
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            // Find smallest between parent, left, and right
            if (left < bum && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < bum && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == i) break; // If parent is smaller than both children, stop

            // Swap with the smallest child
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    // Swap helper function to exchange two elements
    void swap(int &i, int &j) {
        int temp = i;
        i = j;
        j = temp;
    }

public:
    Heap() {
        heap = new int[100];
        bum = 1; // The heap starts at index 1
    }

    ~Heap() {
        delete[] heap; // Free the allocated memory
    }

    // Pop the smallest element (root)
    int pop() {
        if (bum <= 1) return -1; // Empty heap check

        int min_val = heap[1];
        bum--;
        swap(heap[1], heap[bum]);
        bubble_down(); // Restore heap property

        return min_val;
    }

    // Push a new value onto the heap
    void push(int x) {
        heap[bum] = x;
        bubble_up(bum);
        bum++;
    }

    // Delete an element at index `idx` (1-based index)
    void delete_at(int idx) {
        if (idx < 1 || idx >= bum) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        // Swap the element with the last element
        swap(heap[idx], heap[bum - 1]);
        bum--; // Remove the last element

        // Restore the heap property by bubbling down or up
        bubble_down_from(idx);
    }

    // Helper function to restore heap property from a specific index
    void bubble_down_from(int idx) {
        int i = idx;
        while (2 * i < bum) { // While there are children
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            // Find smallest between parent, left, and right
            if (left < bum && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < bum && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == i) break; // If parent is smaller than both children, stop

            // Swap with the smallest child
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    // Print the heap elements
    void print() {
        for (int i = 1; i < bum; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    
    heap.push(13);
    heap.push(11);
    heap.push(7);
    heap.push(3);
    heap.print();  // Expected output: 3 11 7 13

    heap.delete_at(2); // Delete the element at index 2 (which is 11)
    heap.print();  // Expected output: 3 13 7

    heap.push(5);
    heap.print();  // Expected output: 3 5 7 13
    
    heap.delete_at(1); // Delete the element at index 1 (which is 3)
    heap.print();  // Expected output: 5 13 7
    
    return 0;
}
