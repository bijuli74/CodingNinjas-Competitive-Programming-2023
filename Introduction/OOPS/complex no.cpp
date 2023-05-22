/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/
class ComplexNumbers {
    // Complete this class
    private:
    	int real, img;
    public:
    	ComplexNumbers(int real, int img){
            this->real = real;
            this->img = img;
        }
    	
    	void print(){
            cout << this->real << " + i" << this->img << '\n';
        }
    	
    	void plus(ComplexNumbers c2){
            // int real = real + c2.real;
            // int img = img + c2.img;
            int a=real, b=img, c=c2.real, d=c2.img;
            real=a+c;
            img =b+d;
        }
    	
    	void multiply(ComplexNumbers& c2){
            int a=real, b=img, c=c2.real, d=c2.img;
            real = a*c-b*d;
            img = b*c+a*d;
        }
    
};
