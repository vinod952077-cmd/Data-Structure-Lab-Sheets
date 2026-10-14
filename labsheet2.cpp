// Q1. Linear Search
#include <iostream>
using namespace std;
int main(){
    int a[]={10,25,7,18,30},key=18,pos=-1;
    for(int i=0;i<5;i++) if(a[i]==key){pos=i;break;}
    if(pos>=0) cout<<"Position = "<<pos+1;
    else cout<<"Not found";
    return 0;
}

// Q2. Binary Search
#include <iostream>
using namespace std;
int main(){
    int a[]={5,10,15,20,25,30,35},key=25,l=0,r=6,pos=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key){pos=m;break;}
        if(a[m]<key) l=m+1; else r=m-1;
    }
    if(pos>=0) cout<<"Position = "<<pos+1;
    else cout<<"Not found";
    return 0;
}

// Q3. Compare Linear and Binary Search
#include <iostream>
using namespace std;
int main(){
    int a[]={5,10,15,20,25,30,35},key=25,pos=-1;
    for(int i=0;i<7;i++) if(a[i]==key){pos=i;break;}
    cout<<"Linear: "<<(pos>=0?"Found":"Not found")<<endl;
    int l=0,r=6;pos=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key){pos=m;break;}
        if(a[m]<key)l=m+1;else r=m-1;
    }
    cout<<"Binary: "<<(pos>=0?"Found":"Not found");
    return 0;
}

// Q4. Bubble Sort Ascending with Each Pass
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        for(int x:a)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

// Q5. Bubble Sort Descending
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q6. Insertion Sort with Each Pass
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}
        a[j+1]=key;
        for(int x:a)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

// Q7. Selection Sort and Minimum Selected
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5;
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;
        cout<<"Minimum = "<<a[m]<<endl;
        swap(a[i],a[m]);
    }
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q8. Merge Sort
#include <iostream>
using namespace std;
void merge8(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort8(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort8(a,l,m);sort8(a,m+1,r);merge8(a,l,m,r);}
}
int main(){
    int a[]={5,3,8,1,2};sort8(a,0,4);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q9. Quick Sort Using Last Element as Pivot
#include <iostream>
using namespace std;
int part9(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);return i+1;
}
void quick9(int a[],int l,int h){
    if(l<h){int p=part9(a,l,h);quick9(a,l,p-1);quick9(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2};quick9(a,0,4);
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q10. Quick Sort with Partition Display
#include <iostream>
using namespace std;
int part10(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)if(a[j]<p)swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    cout<<"Partition: ";for(int k=0;k<5;k++)cout<<a[k]<<" ";
    cout<<endl;return i+1;
}
void quick10(int a[],int l,int h){
    if(l<h){int p=part10(a,l,h);quick10(a,l,p-1);quick10(a,p+1,h);}
}
int main(){
    int a[]={5,3,8,1,2};quick10(a,0,4);return 0;
}

// Q11. Menu-Driven Linear or Binary Search
#include <iostream>
using namespace std;
int main(){
    int a[]={5,10,15,20,25},key,ch,pos=-1;
    cout<<"1.Linear 2.Binary: ";cin>>ch;
    cout<<"Key: ";cin>>key;
    if(ch==1){
        for(int i=0;i<5;i++)if(a[i]==key){pos=i;break;}
    }else if(ch==2){
        int l=0,r=4;
        while(l<=r){int m=(l+r)/2;
            if(a[m]==key){pos=m;break;}
            if(a[m]<key)l=m+1;else r=m-1;}
    }else{cout<<"Invalid choice";return 0;}
    if(pos>=0)cout<<"Position = "<<pos+1;else cout<<"Not found";
    return 0;
}

// Q12. Menu-Driven Bubble, Insertion or Selection Sort
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},n=5,ch;
    cout<<"1.Bubble 2.Insertion 3.Selection: ";cin>>ch;
    if(ch==1){
        for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
    }else if(ch==2){
        for(int i=1;i<n;i++){int k=a[i],j=i-1;
            while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;}
    }else if(ch==3){
        for(int i=0;i<n-1;i++){int m=i;
            for(int j=i+1;j<n;j++)if(a[j]<a[m])m=j;
            swap(a[i],a[m]);}
    }else{cout<<"Invalid choice";return 0;}
    for(int x:a)cout<<x<<" ";
    return 0;
}

// Q13. Merge Sort then Binary Search
#include <iostream>
using namespace std;
void merge13(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=t[k++];
}
void sort13(int a[],int l,int r){
    if(l<r){int m=(l+r)/2;sort13(a,l,m);sort13(a,m+1,r);merge13(a,l,m,r);}
}
int main(){
    int a[]={8,3,5,1,7},key=5;sort13(a,0,4);
    int l=0,r=4,pos=-1;
    while(l<=r){int m=(l+r)/2;
        if(a[m]==key){pos=m;break;}
        if(a[m]<key)l=m+1;else r=m-1;}
    cout<<"Sorted: ";for(int x:a)cout<<x<<" ";
    cout<<"\n"<<(pos>=0?"Found at position ":"Not found");
    if(pos>=0)cout<<pos+1;
    return 0;
}

// Q14. Compare Two Sorting Algorithms' Comparisons
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,8,1,2},b[]={5,3,8,1,2},n=5,c1=0,c2=0;
    for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++){
        c1++;if(a[j]>a[j+1])swap(a[j],a[j+1]);}
    for(int i=0;i<n-1;i++){int m=i;
        for(int j=i+1;j<n;j++){c2++;if(b[j]<b[m])m=j;}
        swap(b[i],b[m]);}
    cout<<"Bubble comparisons = "<<c1<<"\nSelection comparisons = "<<c2;
    return 0;
}

// Q15. Display Complexities of Three Sorting Algorithms
#include <iostream>
using namespace std;
int main(){
    cout<<"Bubble Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout<<"Insertion Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout<<"Selection Sort: Best O(n^2), Average O(n^2), Worst O(n^2)\n";
    return 0;
}