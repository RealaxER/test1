//=====================LÝ THUYẾT ================
//// 1(1đ). Trình bày lưu ý khi sử dụng hàm(3 ý).//Tham số
//2(0, 5đ).Trình bày lưu ý khi sử dụng getline().//Trôi lệnh
//3(0, 5đ).Trình bày lưu ý khi sử dụng kdl struct. //Tp con trỏ
// 
// 
// 1)+ Khi truyền một biến là tham số vào hàm cần xem có muốn thay đổi giá trị trong hàm void về hàm main không
//nế muốn thì phải tham chiếu lại bằng dấu & nếu truyền mảng vào thì không cần tham chiêu nhưng nếu cấp phát động 
// cho mảng thì cũng phải tham chiếu trong hàm void để trả về giá trị ở hàm main 
// 
// + Nếu ta viết một hàm dưới hàm main thì ta phải nguyên mẫu hàm nó lại để có thể gọi trong hàm main hay hàm lồng hàm 
// nếu ta viết trên hàm main thì không càn nguyên mẫu hàm nếu có lồng hàm thì vẫn phải nguyên mẫu 
// vì vậy nguyên mẫu và viết dưới là ok nhất 
// 
//+ Ở đuôi chấm c không nếu ta truyền vào giá trị vào một hàm là biến thì nguyên mẫu hàm ta lên khai báo là con trỏ 
// trong hàm main là biến thường và truyền địa chỉ (&ten_bien) vào hàm đó mới có thể thay đổi được giá trị bên trong main 
// 
// 2) khi sử dụng getline mà trước đó ta có một cú pháp cin để lưu các kiểu dl int, float .... ta cần xóa bộ nhớ đệm để 
// tránh hiện tượng bộ nhớ đệm vẫn còn kí tự sẽ tự động trôi lệnh của chúng ta ;
// + Xoa bộ nhớ đệm : cin.ignore();
////  while (getchar () != '\n' );
// 
// 
// 3) Khi sử dụng kdl struct có con trỏ thì không được dùng toán tử gán vì nó sẽ dân đén dùng chung bộ nhớ của biến con trỏ biến này 
// với biến kia, ta nên gán lần lượt từng giá trị và với con trỏ thì là gán giá trị chứ k phải địa chri
// + nếu có con trỏ thì cần phải cấp phát bộ nhớ cho nó bên trong struct và sau khi xong thì cần giải phóng
// 
// 
// 



//===================CODE==================



#include <iostream>
using namespace std;

int i = 0;

void nhap(int a[], int n);
void xuat(int a[], int n);
void bai1(int a[], int n);
int min(int a[], int n);
int max(int a[], int n);
void bai2(int a[], int n);

struct SINHVIEN
{
	char hoten[30] = " ";
	char gt[10] = " ";
	char nams[15] = " ";
	char masv[20] = " ";
	float mac = 0, cplus = 0, toan = 0 ; 
}; typedef struct SINHVIEN sv;
void xoa_sv(sv a[], int n, int location);
istream& operator >> (istream& is, sv &a /*nhập cho ai */);
ostream& operator << (ostream& os, sv &a);
void xoamsv(sv a[], int n);
int do_dai(char chuoi[]);
int do_dai_ten(char c[]);
void nhapdiem(sv a[], int n);
void sx_nams(sv a[], int n);
void nhapdiem(sv a[], int n);
int do_dai_nams(char c[]);
void sx_ten(sv a[], int n);

int main()
{
	int n;
	do
	{
		cout << "\nNhap gia tri n : ";
		cin >> n;
		if (n < 0)
		{
			cout << "\nHay nhap gia tri n lon hon 0 ";
		}
	} while (n < 0);
	int a[50];
	nhap(a, n);
	xuat(a,n);
	bai1(a, n); //////////////// bài 1
	bai2(a,n);////////bai 2

	//=== bài 3====
	// nhập n
	do
	{
		cout << "\nNhap gia tri n sinh vien : ";
		cin >> n;
		if (n < 0)
		{
			cout << "\nHay nhap gia tri n lon hon 0 ";
		}
	} while (n < 0);

	sv b[50];// khai báo một mảng sinh viên gồm 50 thằng sinh viên 
	// nhap sv
	for ( i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	// xuat sv
	for (i = 0; i < n; i++)
	{
		cout << b[i];
	}
	xoamsv(b, n); // xóa mã sinh viên
	sx_ten(b, n); // sắp xếp theo tên
	cout << "\n=========SAP XEP THEO TEN ===============";
	for (i = 0; i < n; i++)
	{
		cout << b[i];
	}

	nhapdiem(b, n);// nhập điểm theo masv

	sx_nams(b, n);// sắp xếp theo năm sinh
	cout << "\n=========SAP XEP THEO  NAM SINH===============";
	for (i = 0; i < n; i++)
	{
		cout << b[i];
	}
	return 0;
	system("pause");
}


//=============================== NAP CHỒNG TOÁN TỬ ====================

istream& operator >> (istream& is, sv &a /*nhập cho ai */)
{
	// Nhâp ntn  ?
	//nạp chồng toán tử cho mảng
	cout << "\n\t\t=====Nhap sinh vien====";
	while (getchar() != '\n');
	// Enter the name for student ;
	cout << "\nNhap ten sinh vien " << i << " : ";
	fgets(a.hoten, sizeof(a.hoten), stdin);

	// Enter the sex for student ;
	cout << "\nNhap gioi tinh sinh vien " << i << " : ";
	fgets(a.gt, sizeof(a.gt), stdin);

	// Enter the Year of Birth for student ;
	cout << "\nNhap ngay thang nam sinh sinh vien " << i << " : ";
	fgets(a.nams, sizeof(a.nams), stdin);


	// Enter the student code for student ;
	cout << "\nNhap ma so sinh vien " << i << " : ";
	fgets(a.masv, sizeof(a.masv), stdin);
	return is;
}
ostream& operator << (ostream& os, sv &a)
{
	cout << "\n\t\t=====xuat sinh vien====";
	os << "\nTen sinh vien " << i << " : " << a.hoten;
	os << "\nMa sinh vien " << i << " : "<< a.masv;
	os << "\nSex " << i << " : " << a.gt;
	os << "\nNgay thang nam sinh  " << i << " : " << a.nams;
	return os;
}

//=============================== LÀM VIỆC VỚI STRUCT  ====================
int do_dai_nams(char c[])
{
	int dodai = do_dai(c);
	while (dodai != 0)
	{
		if (c[dodai] == '/')
		{
			break;
		}
		dodai--;
	}
	return dodai+1;
}
void sx_nams(sv a[], int n)
{
	sv temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].hoten[do_dai_nams(a[i].nams)] > a[j].hoten[do_dai_nams(a[j].nams)])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else if (a[i].hoten[do_dai_nams(a[i].nams)] == a[j].hoten[do_dai_nams(a[j].nams)])
			{
				if (a[i].hoten[do_dai_nams(a[i].nams) + 3] > a[j].hoten[do_dai_nams(a[j].nams)] + 3)
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				else if (a[i].hoten[do_dai_nams(a[i].nams) + 3] == a[j].hoten[do_dai_nams(a[j].nams)] + 3)
				{
					if (a[i].hoten[do_dai_nams(a[i].nams)] - 1 > a[j].hoten[do_dai_nams(a[j].nams) - 1])
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}
		}
	}
}
void nhapdiem(sv a[], int n)
{
	char masv[30];
	cout << "\n\n\tNhap ma sinh vien can nhap diem : ";
	fgets(masv, sizeof(masv[i]), stdin);
	
	for (i = 0; i < n; i++)
	{
		if (a[i].masv == masv)
		{
			do {
				cout << "\nNhap diem toan  sinh vien thu " << i << " : ";
				cin >> a[i].toan;
			} while (a[i].toan < 0 && a[i].toan > 10);

			do {
				cout << "\nNhap diem c++ sinh vien thu " << i << " : ";
				cin >> a[i].cplus;
			} while (a[i].cplus < 0 && a[i].cplus > 10);

			do {
				cout << "\nNhap diem mac sinh vien thu " << i << " : ";
				cin >> a[i].mac;
			} while (a[i].mac < 0 && a[i].mac > 10);
			cout << "\n=========SAU KHI NHAP DIEM===============";
			cout << a[i];
			cout << "\nDiem toan : " << a[i].toan;
			cout << "\nDiem cplus : " << a[i].cplus;
			cout << "\nDiem mac : " << a[i].mac;
			break;
		}
	}
}
void sx_ten(sv a[], int n)
{
	sv temp;
	for (i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].hoten[do_dai_ten(a[i].hoten)] > a[i].hoten[do_dai_ten(a[j].hoten)])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else if (a[i].hoten[do_dai_ten(a[i].hoten)] == a[i].hoten[do_dai_ten(a[j].hoten)])
			{
				if (a[i].hoten[0] > a[j].hoten[0])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

int do_dai_ten(char c[])
{
	int dodai = do_dai(c);
	while (dodai != 0)
	{
		if (c[dodai] == ' ')
		{
			break;
		}
		dodai--;
	}
	return dodai+1	;
}


int do_dai(char chuoi[])
{
	int i = 0;
	while (chuoi[i] != '\0')
	{
		i++;
	}
	return i;
}

void xoamsv(sv a[], int n)
{
	char masv[20] = "";
	fgets(masv, sizeof(masv), stdin);
	for (i = 0; i < n; i++)
	{
		if (masv == a[i].masv)
		{
			xoa_sv(a, n, i);
		}
	}
}
void xoa_sv(sv a[], int n , int location)
{
	for (int i = location; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}

//=============================== LÀM VIỆC VỚI HÀM  ====================

void nhap(int a[], int n)
{
	cout << "=============NHAP==============" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nNhap gia tri thu " << i << " : ";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for (i = 0; i < n; i++)
	{
		cout << "\nGia tri thu " << i << " la : " << a[i];
	}
}
void bai1(int a[], int n)
{
	int temp = 0;
	for (i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if( (a[i] > a[j] ) && (a[j] <=0) && (a[i] <= 0))
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		for (int k = i + 1; k < n; k++)
		{
			if ((a[i] < a[k]) && (a[k] > 0) && (a[i] > 0))
			{
				temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
	}
	cout << "\n===========XUAT SAP XEP ==============";
	xuat(a, n);
}

void bai2(int a[], int n)
{
	int x; cout << "\nNhap gia tri x : "; cin >> x;
	if (abs(min(a, n) - x) > abs(max(a, n) - x))
	{
		cout << "\nGia tri xa nhat la : " << min(a, n);
	}
	else
	{
		cout << "\nGia tri xa nhat la : " << max(a, n);
	}
}
int max(int a[], int n)
{
	int MAX = a[0];
	for (i = 1; i < n; i++)
	{
		if (MAX < a[i])
		{
			MAX = a[i];
		}
	}
	return MAX;
}
int min(int a[], int n)
{
	int MIN = a[0];
	for (i = 1; i < n; i++)
	{
		if (MIN > a[i])
		{
			MIN = a[i];
		}
	}return MIN;
}