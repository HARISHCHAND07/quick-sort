#include<iostream>
using namespace std;
int partision(int arr[],int s,int e){
  int pivot=arr[s];
  int cnt=0;
  for(int i=s+1;s<=e;i++){
    if(arr[i]<=pivot){
        cnt++;
    }
  }
  int index=cnt+s;
  swap(arr[index],arr[s]);
  int i=s,j=e;
  while(i<index && j>index){
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    swap(arr[i++],arr[j--]);
  }return index;

}
void quick(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p=partision(arr,s,e);
    quick(arr,s,p);
    quick(arr,p+1,e);
}
int main(){
    int arr[60],n;
    cout<<"enter size=";
    cin>>n;
    cout<<"element=";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick(arr,0,n-1);
    cout<<"after sort=";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
