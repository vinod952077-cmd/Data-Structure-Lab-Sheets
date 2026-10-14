// Q1. Stack using Array: Push, Pop, Peek and Display
#include <iostream>
using namespace std;
int main(){
    int s[5],top=-1,ch,x;
    do{
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 5.Exit: ";cin>>ch;
        if(ch==1){
            cin>>x;
            if(top==4)cout<<"Overflow";
            else s[++top]=x;
        }else if(ch==2){
            if(top==-1)cout<<"Underflow";
            else cout<<"Popped "<<s[top--];
        }else if(ch==3){
            if(top==-1)cout<<"Empty";
            else cout<<s[top];
        }else if(ch==4){
            for(int i=top;i>=0;i--)cout<<s[i]<<" ";
        }
    }while(ch!=5);
    return 0;
}

// Q2. Demonstrate Stack Overflow
#include <iostream>
using namespace std;
int main(){
    int s[3],top=-1;
    for(int x:{10,20,30,40}){
        if(top==2)cout<<"Overflow at "<<x<<endl;
        else s[++top]=x;
    }
    return 0;
}

// Q3. Demonstrate Stack Underflow
#include <iostream>
using namespace std;
int main(){
    int s[3],top=-1;
    if(top==-1)cout<<"Stack Underflow";
    else cout<<s[top--];
    return 0;
}

// Q4. Peek: Display TOP Element
#include <iostream>
using namespace std;
int main(){
    int s[]={10,20,30},top=2;
    cout<<"TOP element = "<<s[top];
    return 0;
}

// Q5. Menu-driven Stack
#include <iostream>
using namespace std;
int main(){
    int s[5],top=-1,ch,x;
    while(true){
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 5.Exit: ";cin>>ch;
        if(ch==1){cin>>x;if(top==4)cout<<"Overflow";else s[++top]=x;}
        else if(ch==2){if(top<0)cout<<"Underflow";else cout<<s[top--];}
        else if(ch==3){if(top<0)cout<<"Empty";else cout<<s[top];}
        else if(ch==4){for(int i=top;i>=0;i--)cout<<s[i]<<" ";}
        else if(ch==5)break;
        else cout<<"Invalid choice";
    }
    return 0;
}

// Q6. Stack of Integers Using Array
#include <iostream>
using namespace std;
int main(){
    int s[5],top=-1;
    for(int x:{1,2,3,4,5})if(top<4)s[++top]=x;
    while(top>=0)cout<<s[top--]<<" ";
    return 0;
}

// Q7. Reverse a String Using Stack
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="HELLO";char st[100];int top=-1;
    for(char c:s)st[++top]=c;
    while(top>=0)cout<<st[top--];
    return 0;
}

// Q8. Check Balanced Parentheses
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="{[()]}";char st[100];int top=-1;bool ok=true;
    for(char c:s){
        if(c=='('||c=='['||c=='{')st[++top]=c;
        else if(c==')'||c==']'||c=='}'){
            if(top==-1){ok=false;break;}
            char t=st[top--];
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
                {ok=false;break;}
        }
    }
    if(top!=-1)ok=false;
    cout<<(ok?"Balanced":"Not balanced");
    return 0;
}

// Q9. Convert Infix to Postfix (single-character operands)
#include <iostream>
#include <string>
using namespace std;
int prec(char c){return c=='+'||c=='-'?1:c=='*'||c=='/'?2:0;}
int main(){
    string in="A+B*C",out="";char st[100];int top=-1;
    for(char c:in){
        if(isalnum(c))out+=c;
        else if(c=='(')st[++top]=c;
        else if(c==')'){
            while(top>=0&&st[top]!='(')out+=st[top--];
            if(top>=0)top--;
        }else{
            while(top>=0&&st[top]!='('&&prec(st[top])>=prec(c))
                out+=st[top--];
            st[++top]=c;
        }
    }
    while(top>=0)out+=st[top--];
    cout<<out;
    return 0;
}

// Q10. Evaluate a Postfix Expression (single-digit operands)
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="23*54*+9-";int st[100],top=-1;
    for(char c:s){
        if(c>='0'&&c<='9')st[++top]=c-'0';
        else{
            int b=st[top--],a=st[top--],v=0;
            if(c=='+')v=a+b;
            if(c=='-')v=a-b;
            if(c=='*')v=a*b;
            if(c=='/')v=a/b;
            st[++top]=v;
        }
    }
    cout<<"Result = "<<st[top];
    return 0;
}

// Q11. Convert Infix to Prefix (single-character operands)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int prec11(char c){return c=='+'||c=='-'?1:c=='*'||c=='/'?2:0;}
int main(){
    string in="A+B*C",rev="",post="";
    reverse(in.begin(),in.end());
    for(char c:in){
        if(c=='(')c=')';else if(c==')')c='(';
        rev+=c;
    }
    char st[100];int top=-1;
    for(char c:rev){
        if(isalnum(c))post+=c;
        else if(c=='(')st[++top]=c;
        else if(c==')'){
            while(top>=0&&st[top]!='(')post+=st[top--];
            if(top>=0)top--;
        }else{
            while(top>=0&&st[top]!='('&&prec11(st[top])>prec11(c))
                post+=st[top--];
            st[++top]=c;
        }
    }
    while(top>=0)post+=st[top--];
    reverse(post.begin(),post.end());
    cout<<post;
    return 0;
}

// Q12. Two Stacks in One Array
#include <iostream>
using namespace std;
int main(){
    int a[10],t1=-1,t2=10;
    a[++t1]=10;a[++t1]=20;a[--t2]=90;a[--t2]=80;
    cout<<"Stack 1: ";
    for(int i=t1;i>=0;i--)cout<<a[i]<<" ";
    cout<<"\nStack 2: ";
    for(int i=t2;i<10;i++)cout<<a[i]<<" ";
    return 0;
}

// Q13. Stack Implemented Using a Class
#include <iostream>
using namespace std;
class Stack{
    int a[5],top;
public:
    Stack(){top=-1;}
    void push(int x){if(top==4)cout<<"Overflow\n";else a[++top]=x;}
    void pop(){if(top==-1)cout<<"Underflow\n";else cout<<a[top--]<<endl;}
    void peek(){if(top<0)cout<<"Empty\n";else cout<<a[top]<<endl;}
    void display(){for(int i=top;i>=0;i--)cout<<a[i]<<" ";}
};
int main(){
    Stack s;s.push(10);s.push(20);s.push(30);
    s.display();cout<<"\n";s.peek();s.pop();
    return 0;
}

// Q14. Demonstrate Stack Use in Recursion
#include <iostream>
using namespace std;
void countDown(int n){
    if(n==0)return;
    cout<<n<<" ";
    countDown(n-1);
}
int main(){countDown(5);return 0;}

// Q15. Time Complexity of Stack Operations
#include <iostream>
using namespace std;
int main(){
    cout<<"Push: O(1)\nPop: O(1)\nPeek: O(1)\nDisplay: O(n)\n";
    cout<<"Array storage space: O(n)";
    return 0;
}