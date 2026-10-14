/* Q1. Sum of Even and Odd Elements */
#include <stdio.h>
int main() {
    int a[]={1,2,3,4,5}, even=0, odd=0, i;
    for(i=0;i<5;i++)
        if(a[i]%2==0) even+=a[i];
        else odd+=a[i];
    printf("SumEven=%d SumOdd=%d\n",even,odd);
    return 0;
}

/* Q2. Sum of Two Unequal-Sized Arrays */
#include <stdio.h>
int main() {
    int a[]={1,2,3,4,5}, b[]={2,4,6,8,10,12,14};
    int c[7],i;
    for(i=0;i<7;i++)
        c[i]=(i<5?a[i]:0)+b[i];
    printf("Sum={");
    for(i=0;i<7;i++)
        printf("%d%s",c[i],i<6?",":"");
    printf("}\n");
    return 0;
}

/* Q3. Reverse an Array */
#include <stdio.h>
int main() {
    int a[]={1,2,3,4,5},i;
    printf("Reverse=");
    for(i=4;i>=0;i--) printf("%d ",a[i]);
    return 0;
}

/* Q4. Kth Smallest and Kth Largest */
#include <stdio.h>
int main() {
    int a[]={1,2,3,4,5},n=5,k=2,i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
    if(k<1||k>n){
        printf("Invalid k");
        return 0;
    }
    printf("%dnd Smallest=%d\n",k,a[k-1]);
    printf("%dnd Largest=%d\n",k,a[n-k]);
    return 0;
}

/* Q5. Union and Intersection of Two Arrays */
#include <stdio.h>
int main() {
    int a[]={1,2,3,4,5},b[]={2,4,6,8,10};
    int i,j,found;
    printf("Union=");
    for(i=0;i<5;i++) printf("%d ",a[i]);
    for(i=0;i<5;i++){
        found=0;
        for(j=0;j<5;j++)
            if(b[i]==a[j]) found=1;
        if(!found) printf("%d ",b[i]);
    }
    printf("\nIntersection=");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(a[i]==b[j]) printf("%d ",a[i]);
    return 0;
}

/* Q6. Find Duplicate Elements */
#include <stdio.h>
int main() {
    int a[]={1,4,3,4,5,1},n=6,i,j,k;
    printf("Duplicates=");
    for(i=0;i<n;i++){
        for(k=0;k<i;k++)
            if(a[i]==a[k]) break;
        if(k<i) continue;
        for(j=i+1;j<n;j++)
            if(a[i]==a[j]){
                printf("%d ",a[i]);
                break;
            }
    }
    return 0;
}

/* Q7. Check Whether One Array Is a Subset */
#include <stdio.h>
int main() {
    int a[]={11,1,13,21,3,7};
    int b[]={11,3,7,1},i,j,found,subset=1;
    for(i=0;i<4;i++){
        found=0;
        for(j=0;j<6;j++)
            if(b[i]==a[j]) found=1;
        if(!found){subset=0;break;}
    }
    if(subset) printf("Yes");
    else printf("No");
    return 0;
}

/* Q8. First Repeating Element */
#include <stdio.h>
int main() {
    int a[]={10,5,3,4,3,5,6},n=7,i,j,first=-1;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]==a[j]){
                first=a[i];
                break;
            }
    /* Find the first repeating element by array order */
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
            if(a[i]==a[j]){
                first=a[i];
                goto found;
            }
    }
    found:
    if(first!=-1) printf("First repeating=%d",first);
    else printf("No repeating element");
    return 0;
}