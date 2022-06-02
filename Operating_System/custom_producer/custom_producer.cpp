#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

const int BUFFER_SIZE=5;
int buffer[BUFFER_SIZE];
int front,rear;
bool full;
HANDLE Mutex;
HANDLE Full;
HANDLE Empty;

void showBuffer(){
    cout<<"buffer: ";
    if(front!=rear||full){
        int i=front;
        do{
            cout<<buffer[i]<<" ";
            i=(i+1)%BUFFER_SIZE;
        }while(i!=rear);
    }else
        cout<<"empty";
    cout<<"\n*******************************"<<endl;
}

int insert_item(int item){
    int condition = -1;
    WaitForSingleObject(Empty,INFINITE);
    WaitForSingleObject(Mutex,INFINITE);

    if(!full){
        buffer[rear]= item;
        rear=(rear+1)%BUFFER_SIZE;
        if(rear==front)full=true;
        condition=0;
        cout<<"producer produced "<<item<<endl;
        showBuffer();
    }

    ReleaseMutex(Mutex);
    ReleaseSemaphore(Full,1,NULL);
    return condition;
}

int remove_item(int item){
    int condition = -1;
    WaitForSingleObject(Full,INFINITE); //获得信号量的一个占有权 
    WaitForSingleObject(Mutex,INFINITE);//加锁 
    if(front!=rear||full){
        item=buffer[front];
        front=(front+1)%BUFFER_SIZE;
        full=false;
        condition=0;

        cout<<"consumer comsumed "<<item<<endl;
        showBuffer();
    }
    ReleaseMutex(Mutex); //解锁 
    ReleaseSemaphore(Empty,1,NULL); // 释放信号量的一个占有权 
    return condition;
}

DWORD WINAPI producer(void *param){
    srand((unsigned)time(0));

    for(int i=0;;++i){
        Sleep((rand()%50)+2000);
        insert_item(rand()%BUFFER_SIZE);
    }
};
DWORD WINAPI consumer(void *param){
    srand((unsigned)time(0));
    for(int j=0;;j++){
        Sleep((rand()%100)+2500);
        remove_item(rand()%BUFFER_SIZE);
    }
};

int main(int argc, char *argv[]){
    front=0;
    rear=0;
    full=false;

    Mutex=CreateMutex(NULL,FALSE,NULL);
    Full=CreateSemaphore(NULL,0,5,NULL); //创建一个信号量 
    Empty=CreateSemaphore(NULL,5,5,NULL);
    CreateThread(NULL,0,producer,NULL,0,NULL);
    CreateThread(NULL,0,consumer,NULL,0,NULL);

    Sleep(400000);
    return 0;
}