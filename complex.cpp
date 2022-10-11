#include <iostream>
using namespace std;
class Complex {
private:
	int real, imag;
	double module;
	static int num_complex;
public:
	Complex() {
		num_complex++;
		real = 0;
		imag = 0;
		module = sqrt(pow(real, 2) + pow(imag, 2));
	}
	Complex(int r, int i) {
		num_complex++; 
		real = r;
		imag = i;
		module = sqrt(pow(real, 2) + pow(imag, 2));
	}
	Complex(int r) {
		num_complex++; 
		real = r;
		imag = 0;
		module = sqrt(pow(real, 2) + pow(imag, 2));
	}
	~Complex() {
		num_complex--;
		//cout << num_complex << "left\n";
	}
	Complex operator=(int r) {
		real = r;
		imag = 0;
		return *this;
	}
	Complex operator=(Complex& c2) {
		real = c2.real;
		imag = c2.imag;
		return *this;
	}
	Complex operator*(Complex& c2) {
		int r, i; 
		r = real * c2.real - imag * c2.imag;
		i = imag * c2.real + real * c2.imag;
		real = r;
		imag = i;
		return *this;
	}
	void add(Complex& c);
	void show();
};
void Complex::add(Complex& c) {
	real += c.real;
	imag += c.imag;
}
void Complex::show() {
	cout << real << "+" << imag << "i" << "\n";
}
int Complex::num_complex = 0;
int main() {
	Complex C1;
	C1.show();//C1=0+0i
	Complex C2(1, 1);
	C2.show();//C2=1+i
	Complex C3(1);
	C3.show();//C3=1+0i
	Complex C4;
	C4 = 1;
	C4.show();//C4=1+0i
	C2.add(C3);//C2=2+i
	C2.show();
	Complex C5;
	C5 = C2;
	C5.show();
	C2 * C5;
	C2.show();
	
	return 0;
}
