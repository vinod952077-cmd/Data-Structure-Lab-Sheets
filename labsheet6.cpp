// Q1. Queue Using Array: Enqueue, Dequeue, Peek and Display
#include <iostream>
using namespace std;
int main(){
    int q[5],f=-1,r=-1,ch,x;
    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit: ";cin>>ch;
        if(ch==1){
            cin>>x;
            if(r==4)cout<<"Overflow";
            else{if(f==-1)f=0;q[++r]=x;}
        }else if(ch==2){
            if(f==-1)cout<<"Underflow";
            else{cout<<q[f++]<<" removed";
                if(f>r)f=r=-1;}
        }else if(ch==3){
            if(f==-1)cout<<"Empty";else cout<<q[f];
        }else if(ch==4){
            if(f==-1)cout<<"Empty";
            else for(int i=f;i<=r;i++)cout<<q[i]<<" ";
        }
    }while(ch!=5);
    return 0;
}

// Q2. Enqueue at Rear
#include <iostream>
using namespace std;
int main(){
    int q[5],f=-1,r=-1,x=30;
    if(r<4){if(f==-1)f=0;q[++r]=x;}
    for(int i=f;i<=r;i++)cout<<q[i]<<" ";
    return 0;
}

// Q3. Dequeue from Front
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30},f=0,r=2;
    if(f==-1||f>r)cout<<"Underflow";
    else cout<<"Removed = "<<q[f++];
    return 0;
}

// Q4. Peek at Front
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30},f=0,r=2;
    if(f==-1||f>r)cout<<"Empty";
    else cout<<"Front = "<<q[f];
    return 0;
}

// Q5. Display Queue from Front to Rear
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30,40},f=0,r=3;
    for(int i=f;i<=r;i++)cout<<q[i]<<" ";
    return 0;
}

// Q6. Demonstrate Queue Overflow
#include <iostream>
using namespace std;
int main(){
    int q[3],r=-1;
    for(int x:{10,20,30,40}){
        if(r==2)cout<<"Overflow at "<<x<<endl;
        else q[++r]=x;
    }
    return 0;
}

// Q7. Demonstrate Queue Underflow
#include <iostream>
using namespace std;
int main(){
    int f=-1,r=-1;
    if(f==-1||f>r)cout<<"Queue Underflow";
    return 0;
}

// Q8. Menu-driven Queue Operations
#include <iostream>
using namespace std;
int main(){
    int q[5],f=-1,r=-1,ch,x;
    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit: ";cin>>ch;
        if(ch==1){
            cin>>x;
            if(r==4)cout<<"Overflow";
            else{if(f==-1)f=0;q[++r]=x;}
        }else if(ch==2){
            if(f==-1)cout<<"Underflow";
            else{cout<<q[f++]<<" removed";
                if(f>r)f=r=-1;}
        }else if(ch==3){
            if(f==-1)cout<<"Empty";else cout<<q[f];
        }else if(ch==4){
            for(int i=f;i!=-1&&i<=r;i++)cout<<q[i]<<" ";
        }
    }while(ch!=5);
    return 0;
}

// Q9. Count Queue Elements
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30,40},f=0,r=3;
    cout<<"Count = "<<(f==-1?0:r-f+1);
    return 0;
}

// Q10. Search for an Element in Queue
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30,40},key=30,f=0,r=3;
    int pos=-1;
    for(int i=f;i<=r;i++)if(q[i]==key){pos=i-f+1;break;}
    if(pos!=-1)cout<<"Found at queue position "<<pos;
    else cout<<"Not found";
    return 0;
}

// Q11. Maximum and Minimum in Queue
#include <iostream>
using namespace std;
int main(){
    int q[]={10,5,30,20},f=0,r=3,mx=q[f],mn=q[f];
    for(int i=f+1;i<=r;i++){
        if(q[i]>mx)mx=q[i];
        if(q[i]<mn)mn=q[i];
    }
    cout<<"Maximum = "<<mx<<"\nMinimum = "<<mn;
    return 0;
}

// Q12. Reverse Queue Elements
#include <iostream>
using namespace std;
int main(){
    int q[]={10,20,30,40},s[4],top=-1;
    for(int x:q)s[++top]=x;
    while(top>=0)cout<<s[top--]<<" ";
    return 0;
}

// Q13. Circular Queue Using Array
#include <iostream>
using namespace std;
int main(){
    const int N=5;int q[N],f=-1,r=-1,ch,x;
    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ";cin>>ch;
        if(ch==1){
            cin>>x;
            if((r+1)%N==f)cout<<"Overflow";
            else{
                if(f==-1)f=0;
                r=(r+1)%N;q[r]=x;
            }
        }else if(ch==2){
            if(f==-1)cout<<"Underflow";
            else{
                cout<<q[f]<<" removed";
                if(f==r)f=r=-1;else f=(f+1)%N;
            }
        }else if(ch==3){
            if(f==-1)cout<<"Empty";
            else{
                int i=f;
                do{cout<<q[i]<<" ";i=(i+1)%N;}while(i!=(r+1)%N);
            }
        }
    }while(ch!=4);
    return 0;
}

// Q14. Queue Using Linked List
#include <iostream>
using namespace std;
struct N{int d;N*next;};
int main(){
    N*f=nullptr,*r=nullptr;int ch,x;
    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ";cin>>ch;
        if(ch==1){
            cin>>x;N*n=new N{x,nullptr};
            if(!r)f=r=n;else{r->next=n;r=n;}
        }else if(ch==2){
            if(!f)cout<<"Underflow";
            else{N*t=f;cout<<t->d<<" removed";f=f->next;
                if(!f)r=nullptr;delete t;}
        }else if(ch==3){
            for(N*p=f;p;p=p->next)cout<<p->d<<" ";
        }
    }while(ch!=4);
    return 0;
}

// Q15. Compare Linear Queue and Circular Queue
#include <iostream>
using namespace std;
int main(){
    cout<<"Linear Queue: rear can reach the last array index even if earlier slots are free.\n";
    cout<<"Circular Queue: reuses freed slots using modulo indexing.\n";
    cout<<"Enqueue/Dequeue: O(1) for both implementations.\n";
    cout<<"Array space: O(n) for both.";
    return 0;
}