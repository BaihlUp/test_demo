//
// Created by baihl-pc on 2020/2/16.
//

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Item>
class heap{
private:
    int capacity;
    int count;
    Item *data;

public:
    heap(int n)
    {
        count = 0;
        data = new int[n + 1];
        capacity = n;
    }

    ~heap()
    {
        delete []data;
    }

    void insert(int n)
    {
        if(count + 1 > capacity) return;

        count++;
        data[count] = n;
        int i = count;
        while(i/2 > 0 && data[i/2] < data[i]){
            swap(data[i/2], data[i]);
            i = i/2;
        }
    }

    Item removeMax()
    {
        assert(count > 0);
        Item ret = data[1];
        data[1] = data[count];
        count--;
        int i = 1;
        while(true){
            int maxpos = i;
            if(2*i <= count && data[2i] > data[i]) maxpos = 2*i;
            if((2*i + 1) <= count && data[maxpos] < data[2i+1]) maxpos = 2*i+1;
            if(maxpos == i) break;
            swap(data[i], data[maxpos]);
            i = maxpos;
        }

        return ret;
    }

};

int main()
{
    heap<int> maxheap = heap<int>(100);
    srand(time(NULL));
    for(int i = 0; i < 63; i++)
        maxheap.insert( rand()%100 );

    cout<<"commplete"<<endl;
    return 0;
}