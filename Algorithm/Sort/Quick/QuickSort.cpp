#include <iostream>
using namespace std;
//构建
void swap(int * arr,int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void selectsort(int * arr,int left,int right){
    if(arr[left]>arr[right])swap(arr,left,right);
}
int department(int* arr, int left, int right) {
	int key = arr[left];
	int i = left + 1;
	int j = right;
	// while (i < j) {
	// 	//要区分找成功和未找成功: 左边找到比key大，右边找到比key小
	// 	while (i < j && arr[i] <= key)
	// 		i++;//停下来时,i指向的值大于key;
	// 	if (i >= j)
	// 	{
	// 		//说明j之前的所有的元素均比key小，所以直接放到j的位置
    //         if(arr[i]>key)swap(arr,left,j-1);
    //         else
	// 		swap(arr, left, j);
	// 		return j;
	// 	}

	// 	while (i < j && arr[j] > key)
	// 		j--;//停下来时,j指向的值小于key;
		
	// 	if (i >= j)
	// 	{
	// 		//说明所有i-1之后的元素均比key大，所以直接放到i-1的位置
	// 		swap(arr, left, i - 1);
	// 		return i - 1;
	// 	}
	// 	swap(arr, i, j);
	// }//跳出循环时,i和j相等
	while (i < j) {

		//要区分找成功和未找成功: 左边找到比key大，右边找到比key小
		while (i <= j && arr[i] <= key)
			i++;//停下来时,i指向的值大于key;
		if (i > j)
		{
			//说明j之前的所有的元素均比key小，所以直接放到j的位置
			swap(arr, left, j);
			return j;
		}

		while (i < j && arr[j] > key)
			j--;//停下来时,j指向的值小于key;
		
		if (i >= j)
		{
			//说明所有i-1之后的元素均比key大，所以直接放到i-1的位置
			swap(arr, left, i - 1);
			return i - 1;
		}
		
		swap(arr, i, j);
	}//跳出循环时,i和j相等
	swap(arr, left, i);
	return i;
}

// int department(int * arr,int left,int right){
//     int key=arr[left];
//     int i=left;
//     int j=right+1;
//     while(true){
//         while(i<j&&arr[++i]<=key)if(i==right)break;//停下来时,i指向的值大于key;
//         while(i<j&&arr[--j]>=key)if(j==left)break;//停下来时,j指向的值小于key;
//         if(i>=j)break;
//         swap(arr,i,j);
//     }//跳出循环时,i和j相等
//     swap(arr,left,j);
//     return j;
// }
void sort1(int * arr,int left,int right){
    if(left>=right)return ;
    // if(right-left==1){selectsort(arr,left,right);return ;}
    int i=department(arr,left,right);
    sort1(arr,left,i-1);
    sort1(arr,i+1,right);
}

int main()
{
    int *arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=10-i;
    }
    // arr[9]=100;
    sort1(arr,0,9);
    for(int  i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}