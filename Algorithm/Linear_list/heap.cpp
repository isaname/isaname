#include <iostream>
#define maxsize 10000
using namespace std;
template<typename E>
class heap{
private:
    E base[maxsize];
    size_t size;
    void swap(int a,int b){
        E tmep=base[a];
        base[a]=base[b];
        base[b]=temp;
    }
    E getfather(int position){
        return base[(position-1)/2];
    }
    E getLeft(int position){
        return base[position*2+1]
    }
    E getRight(int position){
        return base[position*2+2];
    }
    void shiftdown(int position){
        int fatherP=(position-1)/2;
        E left=getLeft(fatherP);
        E right=getRight(fatherP);
        E max;
        bool fg=false;
        if(left<right){
            max=right;
            fg=true;
        }else max=left;
        if(getfather(position)>max)return;
        if(fg){
            swap(fatherP,fatherP*2+2);
        }else swap(fatherP,fatherP*2+1);
        shiftdown(fatherP);
    }
    
public:
    heap(E[] arr){
        this->size=sizeof(base)/sizeof(E);
        for(int i=0;i<size;i++){
            (this->base)[i]=arr[i];
        }
        for(int i=size-1;i>size/2;i--){
            shiftdown(i);
        }
    }
    void showHeap(){
        for(int i=1;i<size;){
            int fg=i;
            while(i--){
                cout<<base[i-1]<<" ";
            }
            cout<<endl;
            i=fg*2;
        }
    }
};



int main()
{
    int arr[]={10,10,2,12,3,4};
    heap<int> he(arr);
    he.showHeap();
    return 0;
}