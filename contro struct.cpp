#include<iostream>
using namespace std;
#include<cmath>

struct PhanSo
{
	int tu, mau;
};
typedef PhanSo PS;

void NhapMotPhanSo(PS *x)//x la con tro kieu SV {
	printf("\nNhap vao tu so : ");
	scanf("%d", &x->tu);
	printf("\nNhap vao mau so : ");
	scanf("%d", &x->mau);
}
void XuatMotPhanSo(PS *x) {
	printf("\nPhan so da nhap : %d/%d", x->tu, x->mau);//tu/mau
}
void RutGonPhanSo(PS *x) {
	int a = abs(x->tu);
	int b = abs(x->mau);
	while (a != b) {
		if (a > b)
			a -= b;
		else b -= a;
	}
	x.tu /= a;
	x.mau /= a;
}
PS TruHaiPhanSo(PS *x, PS *y) {
	PS hieu;
	hieu->tu = x->tu*y->mau - x->mau*y->tu;
	hieu->mau = x->mau*y->mau;
	
	return hieu;
}
int main() {
	PS x, y;
	PS *x1=&x,*x2=&y;
	printf("\nNhap gia tri cho phan so thu nhat: ");
	NhapMotPhanSo(x);
	printf("\nNhap gia tri cho phan so thu hai: ");
	NhapMotPhanSo(y);
	printf("\nCac phan so da nhap la : ");
	XuatMotPhanSo(x);
	printf("\n");
	XuatMotPhanSo(y);
	printf("\nKet qua hai phan so tru nhau la : ");
	PhanSo ketqua = TruHaiPhanSo(x, y);
	RutGonPhanSo(ketqua);
	XuatMotPhanSo(ketqua);
	system("pause");
	return 0;

}
