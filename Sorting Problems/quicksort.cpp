#include <iostream>
#include <vector>
using namespace std;


template<class T>
int pivot(vector<T> & v, int first, int last){
    int p = first;
    int pivotpoint = v[first];
    
    for (int i = first + 1; i <= last; i++) {
        if(v[i] <= pivotpoint){
            p++;
            swap(v[i], v[p]);
        }
    }
    
    swap(v[p], v[first]);
    return p;
}



template<class T>
void quicksort(vector<T> & v, int first , int last){
    int pivotpoint;
    if(first < last){
        pivotpoint = pivot(v,first,last);
        quicksort(v,first, pivotpoint - 1);
        quicksort(v,pivotpoint + 1, last);
    }
}

template<class T>
void swap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

void test1()
{
    vector<int> test1;
    test1.push_back(3);
    test1.push_back(15);
    test1.push_back(4);
    test1.push_back(345);
    test1.push_back(23);
    test1.push_back(7);
    test1.push_back(81);
    test1.push_back(1);
    
    quicksort(test1,0,test1.size() - 1);
    
    for(int i = 0; i < test1.size(); i++)
    {
        printf("%d, ", test1[i]);
    }
    cout << endl;
}



int main(){
    test1();
    return 0;
}
