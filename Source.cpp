#include "Header.h"
#include "AirplaneClass.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include<time.h>

// Function to return the size of the deque.

template<typename T>
int Deque<T>::size()
{
    return Size;
}

template<typename T>
bool Deque<T>::isEmpty()
{
    if (Size == 0)
        return true;
    else  return false;
}

// Function to insert an element at the beginning of the deque.
template <typename T>
void Deque<T> ::insertFront(T value)
{
    Node<T>* newNode = createnode(value);
    // If deque is empty then update the front and rear pointers.
    if (front == NULL) {
        rear = front = newNode;
    }
    // Otherwise insert at the beginning of the deque according to the algorithm described above.
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    // Increase the size of the queue by one.
    Size++;
}

// Function to insert an element at the end of the deque.
template <typename T>
void Deque<T> ::insertRear(T value)
{
    Node<T>* newNode = createnode(value);
    // If deque is empty then update the front and rear pointers.
    if (rear == NULL)
        front = rear = newNode;
    // Otherwise insert at the end of the deque according to the algorithm described above.
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    // Increase the size of the queue by one.
    Size++;
}

// Function to delete the element from the front end of the deque.
template <typename T>
void Deque<T>::deleteFront()
{
    // Check if the deque is empty.
    if (isEmpty())
        cout << "UnderFlow\n";

    // Otherwise, delete the element at the beginning of the deque according to the algorithm described above.
    else
    {
        Node<T>* temp = front;
        front = front->next;
        // If only one element was present in the deque.
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrease the size of the deque by one.
        Size--;
    }
}

// Function to delete the element from the rear end of the deque.
template <typename T>
void Deque<T>::deleteRear()
{
    // Check if the deque is empty.
    if (isEmpty())
        cout << "UnderFlow\n";
    // Otherwise delete the element at the end of the deque according to the algorithm described above.
    else
    {
        Node<T>* temp = rear;
        rear = rear->prev;
        // If only one element was present in the deque.
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Decrease the size of the deque by one.
        Size--;
    }
}

// Function to return the element at the front of the deque.
template <typename T>
T Deque<T> ::getFront()
{
    // If deque is empty, then return garbage value.
    if (isEmpty())
        return -1; // garbage value
    return front->value;
}

// Function to return the element at the back of the deque.
template <typename T>
T Deque<T> ::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->value;
}

// Function to check if the queue is full or not.
template <typename T>
bool Deque<T> ::isFull()
{
    if (size==max_size)
        return true;
    else
        return false;
}

int main() {
   
    Deque<Airplane> LandingQueue;
    AirportRunway Runway;
    int Tmax = 360; Runway.setTlanding(10);
    //int Tlanding = 10; 
    int DeltaT = 6;
    double pa = 1.0 / DeltaT;
    int t = 0, Tr = 0;
    int TotalwaitTime = 0;
    int num_planes_landed = 0;


    srand(time(NULL));
    while (t < Tmax) {
        Airplane plane;
        float R = rand() /float(32767);   
        if (R < pa) { //check max 
            
            
            plane.setTarrival(t);
            plane.setTwait(0);
            LandingQueue.insertRear(plane);
            cout << " Airplane arrived at time " << t << endl;
        }
        if (Tr == 0 && !LandingQueue.isEmpty()) { // change to boolean 
              plane = LandingQueue.getFront();
            Tr = Runway.getTlanding();
            plane.setTwait(t - plane.getTarrival());
            TotalwaitTime += plane.getTwait();
            LandingQueue.deleteFront();
            Runway.set_airplane(&plane);
            Runway.Runwayoccupied = true;
            
           for (int i=1; i<=num_planes_landed; i++)
           {
            num_planes_landed++;
            cout << "Airplane number " << i << " landed at time " << t << " with wait time " << plane.getTwait() << endl;
           }

        }
        if (Tr > 0) {
            Tr--;
        }
        t++;
    }
    double averageWaitTime = (double)TotalwaitTime / num_planes_landed;
    cout << " Number of Airplanes landed :" << num_planes_landed << endl;
    cout << " Total wait time : " << TotalwaitTime << endl;
    cout << " Average wait time: " << averageWaitTime << endl;
    return 0;
}
