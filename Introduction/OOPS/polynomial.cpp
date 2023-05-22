class Polynomial {
     public:
    int *degCoeff; // Name of your array (Don't change this)
    int cap;
    // Complete the class
    public:
    Polynomial()
    {
        degCoeff=new int[5];
        cap=5;
        for(int i=0;i<cap;i++)
        {   degCoeff[i]=0;   }                 
    }
//copy constructor
    Polynomial(Polynomial const & p1)
    {
        this->degCoeff= new int[p1.cap];
        for( int i=0;i<p1.cap;i++)
        {
            this->degCoeff[i]=p1.degCoeff[i];       
        }

        cap=p1.cap;           
    }
//set coefficient
    void  setCoefficient(int degree,int coff)
    {
        while(degree>=cap)
        {
            int *newarray=new int[2*cap];        
            for(int i=0;i<cap;i++)
            {
                newarray[i]=degCoeff[i];
            }
                                                
            for(int j=cap;j<2*cap;j++)
            {
                newarray[j]=0;
            }

            delete [] degCoeff;
            degCoeff=newarray;
            cap*=2;
        }
        degCoeff[degree]=coff;
    }
//print class
    void print() const
    {
        for(int i=0 ;i<cap;i++)
        {
            if(this->degCoeff[i]==0)
                continue;
            else
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
//copy assigment constructor
    void operator=(Polynomial const & p1)
    {
          this->degCoeff= new int[p1.cap];        
        for( int i=0;i<p1.cap;i++)
        {
            this->degCoeff[i]=p1.degCoeff[i];
        }

        cap=p1.cap;
    }
//addition
  Polynomial operator+( Polynomial & p2)           
    {
       int newCap=max(cap,p2.cap);

       //setting value 0 at remaining index of small array
       if(newCap==cap)
       {
           for(int i=p2.cap;i<cap;i++)
           {
               p2.setCoefficient(i,0);                            
           }                                              
       }
       if(newCap==p2.cap)
       {
        for(int i=cap;i<p2.cap;i++)
           {
               setCoefficient(i,0);
           }
       }
       Polynomial p3;
        for(int i=0;i<newCap;i++)
        {
            p3.setCoefficient(i,degCoeff[i] + p2.degCoeff[i]);  
        }
        return p3;
    }
    
//subtraction
    Polynomial operator-( Polynomial  & p2)               
    {
        int newCap=max(cap,p2.cap);

       //setting value 0 at remaining index of small array
       if(newCap==cap)
       {
           for(int i=p2.cap;i<cap;i++)
           {
               p2.setCoefficient(i,0);                                
           }
       }
       if(newCap==p2.cap)
       {
        for(int i=cap;i<p2.cap;i++)
           {
               setCoefficient(i,0);
           }
       }
       Polynomial p3;
        for(int i=0;i<newCap;i++)
        {
            p3.setCoefficient(i,degCoeff[i] - p2.degCoeff[i]);
        }
        return p3;
    }

 Polynomial operator*( Polynomial  & p2)
{
     Polynomial p3;
     for(int i=0;i<cap;i++)    
     {
         Polynomial p;
         for(int j=0;j<p2.cap;j++)   
         {
              p.setCoefficient(i+j,degCoeff[i]*p2.degCoeff[j]);
                                        
         }
         p3=p3+p;
     }
    return p3; 
     
 }

};
