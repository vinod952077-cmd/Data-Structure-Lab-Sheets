// Q1. Bubble Sort Ascending; display before and after every pass
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    cout<<"Before: ";for(int x:a)cout<<x<<" ";cout<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        for(int x:a)cout<<x<<" ";cout<<endl;
    }
    return 0;
}

// Q2. Bubble Sort Descending
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
        if(a[j]<a[j+1])swap(a[j],a[j+1]);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q3. Insertion Sort with Each Pass
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=1;i<n;i++){
        int k=a[i],j=i-1;
        while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}
        a[j+1]=k;
        for(int x:a)cout<<x<<" ";cout<<endl;
    }
    return 0;
}

// Q4. Selection Sort; display minimum selected
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;
        cout<<"Minimum = "<<a[m]<<endl;swap(a[i],a[m]);
    }
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q5. Merge Sort using separate functions
#include <iostream>
using namespace std;
void merge5(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort5(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort5(a,l,m);sort5(a,m+1,r);merge5(a,l,m,r);}
}
int main(){
    int a[]={5,3,8,1,2};sort5(a,0,4);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q6. Quick Sort using last element as pivot
#include <iostream>
using namespace std;
int part6(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick6(int a[],int l,int h){
    if(l<h){int p=part6(a,l,h);quick6(a,l,p-1);quick6(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2};quick6(a,0,4);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q7. Quick Sort; display array after each partition
#include <iostream>
using namespace std;
int part7(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    cout<<"Partition: ";for(int k=0;k<5;k++)cout<<a[k]<<" ";
    cout<<endl;return i+1;
}
void quick7(int a[],int l,int h){
    if(l<h){int p=part7(a,l,h);quick7(a,l,p-1);quick7(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2};quick7(a,0,4);return 0;
}

// Q8. Implement all five sorting algorithms
#include <iostream>
using namespace std;
void bubble8(int a[],int n){
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])swap(a[j],a[j+1]);
}
void insertion8(int a[],int n){
    for(int i=1;i<n;i++){int k=a[i],j=i-1;
        while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;}
}
void selection8(int a[],int n){
    for(int i=0;i<n-1;i++){int m=i;
        for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;swap(a[i],a[m]);}
}
void merge8(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort8(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort8(a,l,m);sort8(a,m+1,r);merge8(a,l,m,r);}
}
int part8(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick8(int a[],int l,int h){
    if(l<h){int p=part8(a,l,h);quick8(a,l,p-1);quick8(a,p+1,h);}
}
void show8(int a[]){for(int i=0;i<5;i++)cout<<a[i]<<" ";cout<<endl;}
int main(){
    int a[]={5,3,8,1,2},b[5];
    for(int i=0;i<5;i++)b[i]=a[i];bubble8(b,5);cout<<"Bubble: ";show8(b);
    for(int i=0;i<5;i++)b[i]=a[i];insertion8(b,5);cout<<"Insertion: ";show8(b);
    for(int i=0;i<5;i++)b[i]=a[i];selection8(b,5);cout<<"Selection: ";show8(b);
    for(int i=0;i<5;i++)b[i]=a[i];sort8(b,0,4);cout<<"Merge: ";show8(b);
    for(int i=0;i<5;i++)b[i]=a[i];quick8(b,0,4);cout<<"Quick: ";show8(b);
    return 0;
}

// Q9. Compare comparisons and swaps/shifts
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},b[]={5,3,8,1,2},c[]={5,3,8,1,2};
    int cb=0,sb=0,ci=0,si=0,cs=0,ss=0,n=5;
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++){
        cb++;if(a[j]>a[j+1]){swap(a[j],a[j+1]);sb++;}}
    for(int i=1;i<n;i++){int k=b[i],j=i-1;
        while(j>=0){ci++;if(b[j]>k){b[j+1]=b[j];si++;j--;}else break;}
        b[j+1]=k;}
    for(int i=0;i<n-1;i++){int m=i;
        for(int j=i+1;j<n;j++){cs++;if(c[j]<c[m])m=j;}
        if(m!=i){swap(c[i],c[m]);ss++;}}
    cout<<"Bubble: "<<cb<<" comparisons, "<<sb<<" swaps\n";
    cout<<"Insertion: "<<ci<<" comparisons, "<<si<<" shifts\n";
    cout<<"Selection: "<<cs<<" comparisons, "<<ss<<" swaps";
    return 0;
}

// Q10. Compare Merge Sort and Quick Sort
#include <iostream>
using namespace std;
void merge10(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort10(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort10(a,l,m);sort10(a,m+1,r);merge10(a,l,m,r);}
}
int part10(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick10(int a[],int l,int h){
    if(l<h){int p=part10(a,l,h);quick10(a,l,p-1);quick10(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2},b[]={5,3,8,1,2};
    sort10(a,0,4);quick10(b,0,4);
    cout<<"Merge: ";for(int x:a)cout<<x<<" ";
    cout<<"\nQuick: ";for(int x:b)cout<<x<<" ";
    cout<<"\nMerge: O(n log n) time, O(n) extra space";
    cout<<"\nQuick: average O(n log n), worst O(n^2)";
    return 0;
}

// Q11. Menu-driven five sorting algorithms
#include <iostream>
using namespace std;
void merge11(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort11(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort11(a,l,m);sort11(a,m+1,r);merge11(a,l,m,r);}
}
int part11(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick11(int a[],int l,int h){
    if(l<h){int p=part11(a,l,h);quick11(a,l,p-1);quick11(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2},n=5,ch;
    cout<<"1.Bubble 2.Insertion 3.Selection 4.Merge 5.Quick: ";cin>>ch;
    if(ch==1)for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])swap(a[j],a[j+1]);
    else if(ch==2)for(int i=1;i<n;i++){int k=a[i],j=i-1;
        while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;}
    else if(ch==3)for(int i=0;i<n-1;i++){int m=i;
        for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;swap(a[i],a[m]);}
    else if(ch==4)sort11(a,0,n-1);
    else if(ch==5)quick11(a,0,n-1);
    else{cout<<"Invalid choice";return 0;}
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q12. Sort Ascending and Descending
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},b[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])swap(a[j],a[j+1]);
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
        if(b[j]<b[j+1])swap(b[j],b[j+1]);
    cout<<"Ascending: ";for(int x:a)cout<<x<<" ";
    cout<<"\nDescending: ";for(int x:b)cout<<x<<" ";
    return 0;
}

// Q13. Count comparisons of Bubble, Insertion and Selection
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},b[]={5,3,8,1,2},c[]={5,3,8,1,2};
    int x=0,y=0,z=0,n=5;
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++){
        x++;if(a[j]>a[j+1])swap(a[j],a[j+1]);}
    for(int i=1;i<n;i++){int k=b[i],j=i-1;
        while(j>=0){y++;if(b[j]>k){b[j+1]=b[j];j--;}else break;}
        b[j+1]=k;}
    for(int i=0;i<n-1;i++){int m=i;
        for(int j=i+1;j<n;j++){z++;if(c[j]<c[m])m=j;}swap(c[i],c[m]);}
    cout<<"Bubble = "<<x<<"\nInsertion = "<<y<<"\nSelection = "<<z;
    return 0;
}

// Q14. Best-case Bubble and Insertion Sort
#include <iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5},b[]={1,2,3,4,5},n=5,c=0,d=0;
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){c++;
            if(a[j]>a[j+1]){swap(a[j],a[j+1]);swapped=true;}}
        if(!swapped)break;
    }
    for(int i=1;i<n;i++){int k=b[i],j=i-1;
        while(j>=0){d++;if(b[j]>k){b[j+1]=b[j];j--;}else break;}
        b[j+1]=k;}
    cout<<"Bubble comparisons = "<<c<<"\nInsertion comparisons = "<<d;
    return 0;
}

// Q15. Quick Sort on sorted, reverse and random arrays
#include <iostream>
using namespace std;
int part15(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick15(int a[],int l,int h){
    if(l<h){int p=part15(a,l,h);quick15(a,l,p-1);quick15(a,p+1,h);}
}
void show15(int a[]){for(int i=0;i<5;i++)cout<<a[i]<<" ";cout<<endl;}
int main(){
    int a[]={1,2,3,4,5},b[]={5,4,3,2,1},c[]={3,1,5,2,4};
    quick15(a,0,4);quick15(b,0,4);quick15(c,0,4);
    cout<<"Sorted: ";show15(a);
    cout<<"Reverse: ";show15(b);
    cout<<"Random: ";show15(c);
    cout<<"Last-element pivot can have O(n^2) worst-case time.";
    return 0;
}