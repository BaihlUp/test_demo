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

    int getSize(){
        return count;
    }

    void print(){

        for(int i = 1; i <= count; i++)
        {
            cout<< data[i] <<" ";
        }
        cout<<endl;
    }

    void heapify(int i, int n){
        while(true){
            int maxpos = i;
            if((2*i <= n) && (data[i] < data[2*i])) maxpos = 2*i;
            if((2*i + 1 <= n) && (data[maxpos] < data[2*i +1])) maxpos = 2*i+1;
            if(maxpos == i)
                break;
            swap(data[i], data[maxpos]);
            i = maxpos;
        }
    }

    //建堆
    void buildheap()
    {
        //下标count/2是堆的最后一个不是叶子节点，count/2之后都是叶子节点
        for(int i = count/2; i > 0; i--)
            heapify(i, count);
    }

    void sortheap(){
        buildheap();
        print();
        int k = count;
        //依此取出堆顶元素，放到数组最后
        while(k > 1){
            swap(data[1], data[k]);
            k--;
            heapify(1, k);
        }
        print();
    }

};

int main()
{
    heap<int> maxheap = heap<int>(100);
    srand(time(NULL));
    for(int i = 0; i < 30; i++)
        maxheap.insert( rand()%100 );

    maxheap.print();
    maxheap.sortheap();

    return 0;
}