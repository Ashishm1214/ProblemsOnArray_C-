#include "DynamicArray.cpp"
#include<iostream>
using namespace std;
class InheritedArray:public DynArray
{
    public:
        InheritedArray(int);
        void Sorting();
        int greatestvalue();
        int smallestvalue();
        int SearchElement(int);
        int sum();
        float Average();
        void RotationByOne();
        void removeDuplicate();
        void swapByIndex(int,int);
        void printArray();
};


//constructor that is calling parent constructor
InheritedArray::InheritedArray(int cap):DynArray(cap){}

//Sorting function to sort elements of the array in ascending order
void InheritedArray::Sorting()
{
    int i,round,temp;
    for(round=1;round<count()-1;round++)
    {
        for(i=0;i<count()-1-round;i++)
        {
            if(get(i)>get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
        }
    }
}

//greatestvalue function to find greatest element in the array
int InheritedArray::greatestvalue()
{
    int Max,i;
    if(isEmpty())
    {
        cout<<"Array is Empty";
        return -1;
    }
    Max=get(0);
    for(i=1;i<count();i++)
    {
        if(Max<get(i))
            Max=get(i);
    }
    return Max;
}

//smallestvalue to find smallest element in the array
int InheritedArray::smallestvalue()
{
    int Min,i;
    if(isEmpty())
    {
        cout<<"Array is empty";
        return -1;
    }
    Min=get(0);
    for(i=1;i<count();i++)
    {
        if(Min>get(i))
            Min=get(i);
    }
    return Min;
}

int InheritedArray::SearchElement(int data) //to find data that given element is present or not
{
    int i;
    for(i=0;i<=count();i++)
        if(get(i)==data)
            return i;
    return -1;
}

int InheritedArray::sum() //to find sum
{
    int s=0,i;
    for(i=0;i<=count()-1;i++)
        s=s+get(i);
    return s;
}

float InheritedArray::Average() //to find average
{
    return (float)sum()/count();
}

void InheritedArray::RotationByOne() //element will be rotate by one index
{
    int i,temp,lastIndex;
    if(!isEmpty())
    {
        lastIndex=count()-1;
        temp=get(lastIndex);
        for(i=lastIndex;i>0;i--)
            edit(i,get(i-1));
        edit(0,temp);
    }
}

void InheritedArray::removeDuplicate() //to remove duplicate element from the array
{
    int i,j;
    for(i=0;i<count();i++)
        for(j=i+1;j<count();j++)
        {
          if(get(i)==get(j))
          {
              Delete(j);
              j--;
          }
        }
}

void InheritedArray::swapByIndex(int i,int j) //swapping by index given by user
{
    int temp;
    if(i>=0&&i<count()&&j<count()&&j>=0)
    {
        temp=get(i);
        edit(i,get(j));
        edit(j,temp);
    }
}


void InheritedArray::printArray() //to print array
{
    int i;
    cout<<"Element in the array is/are:";
    for(i=0;i<count();i++)
        cout<<" "<<get(i);
}

//main block
int main()
{
    InheritedArray obj(15);
    obj.append(20);
    obj.append(70);
    obj.append(5);
    obj.append(10);
    obj.append(11);
    obj.append(40);
    obj.append(20);
    obj.append(13);
    obj.append(10);
    obj.append(20);
    obj.append(11);
    obj.append(5);
    obj.append(13);
    obj.printArray();
    cout<<endl<<"Sum of all elements is "<<obj.sum();
    cout<<endl<<"Average is "<<obj.Average();
    cout<<endl<<"Greatest element is "<<obj.greatestvalue();
    cout<<endl<<"Smallest element is "<<obj.smallestvalue()<<endl;
    obj.swapByIndex(0,12);
    cout<<"After swapping ";
    obj.printArray();
    cout<<endl;
    obj.removeDuplicate();
    cout<<"After removing duplicate elements from the array now ";
    obj.printArray();

    return 0;
}
