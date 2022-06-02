#include <iostream>
#define maxsize 10000
using namespace std;

class heap{
private:
    int base[maxsize];
    size_t size;
    void swap(int a,int b){
        int temp=base[a];
        base[a]=base[b];
        base[b]=temp;
    }
    int getfather(int position){
        return base[(position-1)/2];
    }
    int getLeft(int position){
        return base[position*2+1];
    }
    int getRight(int position){
        return base[position*2+2];
    }
    void shiftdown(int position){
        int fatherP=(position-1)/2;
        int left=getLeft(fatherP);
        int right=getRight(fatherP);
        int max;
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
    heap(int arr[],int size){
        this->size=size;
        for(int i=0;i<size;i++){
            base[i]=arr[i];
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
    heap he(arr,sizeof(arr)/sizeof(arr[0]));
    he.showHeap();
    return 0;
}