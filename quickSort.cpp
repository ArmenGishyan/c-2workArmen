#include <iostream>
#include <vector>
#include <iterator>
#include <utility>


template<class T>
int partition(std::vector<T> &inputVec,int lowIndex,int highIndex)
{

    int pivot = inputVec[highIndex];
    int i=(lowIndex-1);

    for(int j=lowIndex;j<=highIndex-1;j++)
    {
        if(inputVec[j]<=pivot)
        {
            i++;
            std::swap(inputVec[i],inputVec[j]);
        }
    }
    std::swap(inputVec[i+1],inputVec[highIndex]);

    return (i+1);
}

template<class T>
void quickSort(std::vector<T> &inputVec,int lowIndex,int highIndex)
{
    if(lowIndex<highIndex)
    {
        int pi= partition<T>(inputVec,lowIndex,highIndex);

        quickSort(inputVec,lowIndex,pi-1);
        quickSort(inputVec,pi+1,highIndex);
    }
}

int main()
{

    std::vector<int> str = {45,8,9,10,45,3,90,12};
    quickSort(str,0,7);
    copy(str.begin(),str.end(),std::ostream_iterator<int>(std::cout,", "));


    return 0;
}