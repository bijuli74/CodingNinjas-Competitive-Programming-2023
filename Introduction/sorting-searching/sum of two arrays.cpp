#include<bits/stdc++.h>
void sumOfTwoArrays(int *a, int n, int *b, int m, int *output){
    int c=0;
    int i, j;
    if(n>=m){
        for(i=n-1, j=m-1; ~i; --i, --j){
            int sum=0;
            if(j>=0){
                if(c) { sum = a[i]+b[j]+c; c=0; }
                else sum = a[i]+b[j];
            }else{
                if(c) { sum=a[i]+c; c=0;}
                else sum = a[i];
            }
            
            if(sum>9){
                output[i+1]=sum%10;
                c=1;
            }
            else output[i+1]=sum;
        }
        if(c) output[0]=1;
      
    }
    else{
        
        for(i=n-1, j=m-1; ~j; --i, --j){
            int sum=0;
            if(i>=0){
                if(c) { sum = a[i]+b[j]+c; c=0; }
                else sum = a[i]+b[j];
            }else{
                if(c) { sum=a[j]+c; c=0;}
                else sum = a[j];
            }
            
            if(sum>9){
                output[j+1]=sum%10;
                c=1;
            }
            else output[j+1]=sum;
        }
        if(c) output[0]=1;
       
    }
    
    
}
    
