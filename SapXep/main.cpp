#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;
void nhap(int a[], int n){
    for(int i = 0; i<n;i++){
        cout<<"a["<<i<<"]";
        cin>>a[i];
    }

}
void xuat(int a[], int n){
    for(int i = 0; i< n;i++){
        cout<<a[i]<<endl;
    }
}
void SapXepNoiBot(int a[], int n){

    for(int i = 0; i<n-1;i++){
        for(int j=n-1; j>i;j-- ){
            if(a[j] < a[j-1]){
                int tg = a[j];
                a[j] = a[j-1];
                a[j-1] = tg;
            }
        }
    }
}
void SapXepChon(int a[] , int n){
    int m;
    for(int i = 0; i<n-1;i++){
        m = i;
        for(int j = i+1; j<n-1;j++)
        {
           if(a[j] < a[m]) m = j;
        }

        if(m!=i){
            int tg = a[i];
            a[i] = a[m];
            a[m] = tg;
        }

    }
}
void SapXepChen(int a[], int n){
    for(int i = 1; i<n; i++){
        int j = i -1;
        int tg = a[i];
        while(j>=0 && a[j] > tg)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tg;
    }
}
void SapXepQuick(int a[], int left, int right)
{
    if(left<right)
    {
        int mid  = a[(left+right)/2];
        int  i = left; int j = right;
        while(i<=j)
        {
              while(a[i] < mid) i++;
              while (a[j]>mid) j--;
              if(i<=j)
              {
                    int tg = a[i];
                    a[i] = a[j];
                    a[j] = tg;
                    i++; j--;
              }
        }
        SapXepQuick(a, left, j);
        SapXepQuick(a,  i,   right);
   }
}
void MergaSort(int a[] , int left,int mid, int right)
{

    int i = left; int j = mid + 1;
    int k = 0; int  n = right - left + 1;
    int *temp; temp = new int[n];
    while(i<mid+1 && j<right+1)
    {
        if(a[i] < a[j]) { temp[k] = a[i]; k++; i++;}
        else if(a[j] < a[i]) {temp[k] = a[j]; k++;j++;}

    }
    while(i<mid+1)  { temp[k] = a[i]; k++; i++;}
    while(j<right + 1){temp[k] = a[j]; k++;j++;}
    i= left;
    for(k=0;k<n;k++)
    {
        a[i] = temp[k]; i++;
    }
    delete temp;
}
void Merga(int  a[], int left, int right)
{
    if(left < right){
     int mid = (right+ left)/2;
     MergaSort(a, left, mid);
     MergaSort(a, mid+1, right);
     Merga(a,left,right,mid);
    }
}

int TimKiemTuanTuLap(int a[], int n, int x){
    int i =0;
    while(i<n)
    {
        if(a[i] == x ) {return 1;}
        i++;
    }
    if (i >= n) return 0;
}
int TimKiemTuanTuDeQuy(int a[], int n, int x){
    if(n == 0) return 0;
    else if(a[n-1] == x) return 1;
    return TimKiemTuanTuDeQuy(a,n-1,x);
}
int TimKiemNhiPhanLap(int a[], int n, int x)
{
        int l = 0; int r = n-1; int m;
        while(l < r)
        {
            m = (l+r)/2;
            if(a[m] == x) return 1;
            if(a[m] > x) r = m -1;
            else  l = m+1;
        }
        return 0;
}
int TimKiemNhiPhanDeQuy(int a[], int x, int l, int r)
{
    int m = (l+r)/2;
    if(l>=r) return 0;
    if(a[m] == x ) return 1;
    if (a[m] > x) return TimKiemNhiPhanDeQuy(a, x ,l,m-1);
    if(a[m] < x) return TimKiemNhiPhanDeQuy(a,x,m+1,r);
}
int main()
{
    int a[100];int n;
    cout<<"Nhap n"; cin>>n;
    nhap(a,n);
    Merga(a,0,n-1);
    xuat(a,n);
    //Tim kiem

    return 0;
}
