/*
    Merge Sort
    Keshav Dasu
    5/2/15
    Coding Interview Practice
 */

#include <iostream>
#include <vector>
using namespace std;


vector<int> merge(vector<int> L , vector<int> R)
{
    vector<int> merge;
    int i = 0;
    int j = 0;
    
    while(i < L.size() || j < R.size())
    {
        if(i < L.size() && j < R.size())
        {
            if(L[i] < R[j])
            {
                merge.push_back(L[i]);
                i++;
            }else{
                merge.push_back(R[j]);
                j++;
            }
        }else if(i < L.size())
        {
            merge.push_back(L[i]);
            i++;
        }else if(j < R.size()){
            merge.push_back(R[j]);
            j++;
        }
    }
    
    return merge;
}



vector<int> sort(vector<int> unsorted)
{
    if(unsorted.size() <= 1)
    {
        return unsorted;
    }
    
    int midpoint = unsorted.size() / 2;
    vector<int> left;
    vector<int> right;
    
    for(int i = 0; i < unsorted.size(); i++)
    {
        if(i < midpoint)
        {
            left.push_back(unsorted[i]);
        }else{
            right.push_back(unsorted[i]);
        }
    }
    
    left = sort(left);
    right = sort(right);
    return merge(left,right);
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
    
    test1 = sort(test1);
    
    for(int i = 0; i < test1.size(); i++)
    {
        printf("%d, ", test1[i]);
    }
    cout << endl;
}









int main()
{
    test1();
    return 0;
}