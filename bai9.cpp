#include <bits/stdc++.h>
using namespace std;
struct SV
{
	long MSV;
	string HoTen;
	double DTB;
	string lop;
	SV *prev;
	SV *next;
};
class dsSv
{
private:
	SV *head;
	SV *tail;

public:
	dsSv()
	{
		head = NULL;
		tail = NULL;
	}
	SV *makeNode(long MSV, string HoTen, double DTB, string lop)
	{
		SV *newNode = new SV;
		newNode->MSV = MSV;
		newNode->HoTen = HoTen;
		newNode->DTB = DTB;
		newNode->lop = lop;

		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode;
	}
	int size(SV *head)
	{
		int dem = 0;
		while (head != NULL)
		{
			++dem;
			head = head->next;
		}
		return dem;
	}
	void duyet(dsSv ds)
	{
		if (ds.head == NULL)
		{
			cout << "ds rong!\n";
		}
		else
		{
			SV *temp = ds.head;
			while (temp != NULL)
			{
				cout << "masv:" << temp->MSV << " ho ten:" << temp->HoTen << " DTB:" << temp->DTB << " lop:" << temp->lop << endl;
				temp = temp->next;
			}
		}
	}
	void taoDsSv()
	{
		int MSV;
		string HoTen;
		float DTB;
		string lop;

		do
		{
			cout << "Nhap ma SV (Nhap <= 0 de ket thuc): ";
			cin >> MSV;

			if (MSV <= 0)
			{
				break;
			}

			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, HoTen);

			cout << "Nhap diem trung binh: ";
			cin >> DTB;

			cout << "Nhap ten lop: ";
			cin.ignore();
			getline(cin, lop);

			SV *s = makeNode(MSV, HoTen, DTB, lop);

			if (!head)
			{
				head = s;
			}
			else
			{
				SV *temp = head;
				while (temp->next)
				{
					temp = temp->next;
				}
				temp->next = s;
				s->prev = temp;
			}

		} while (MSV > 0);
	}

	void chenSv(dsSv *l, long MSV, string HoTen, double DTB, string lop, int k = 0)
	{
		int n = size(l->head);
		cout << "Them sinh vien:" << endl;
		cout << "Nhap ma sv:";
		cin >> MSV;
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline(cin, HoTen);
		cout << "Nhap diem trung binh: ";
		cin >> DTB;
		cout << "Nhap ten lop: ";
		cin.ignore();
		getline(cin, lop);

		SV *newNode = makeNode(MSV, HoTen, DTB, lop);
		cout << "1. Chon vi tri chen.\n";
		cout << "2. Khong chon vi tri chen.\n";
		cout << "Nhap lua chon: ";
		int chen;
		cin >> chen;
		if (chen == 1)
		{
			cout << "\nNhap vi tri chen:";
			cin >> k;
			while (k < 1 || k > n + 1)
			{
				cout << "Vi tri chen khong hop le! \nVui long nhap lai:";
				cin >> k;
			}
			if (k == 1)
			{
				if (l->head == NULL)
				{
					l->head = l->tail = newNode;
				}
				else
				{
					newNode->next = l->head;
					l->head->prev = newNode;
					l->head = newNode;
				}
			}
			else
			{
				SV *tmp = l->head;
				for (int i = 1; i <= k - 1; i++)
				{
					tmp = tmp->next;
				}
				newNode->next = tmp;
				tmp->prev->next = newNode;
				newNode->prev = tmp->prev;
				tmp->prev = newNode;
				if (tmp->next == NULL)
				{
					l->tail = newNode;
				}
			}
		}
		else if (chen == 2)
		{
			SV *temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
		else
		{
			cout << "lua chon khong hop le!\n";
		}
	}

	// sap xep chon
	void sapxepDTB(dsSv l)
	{
		SV *i, *j, *min;
		for (i = l.head; i != l.tail; i = i->next)
		{
			min = i;
			for (j = i->next; j != NULL; j = j->next)
			{
				if (min->DTB < j->DTB)
				{
					min = j;
				}
			}
			SV tmp = *min;
			min->MSV = i->MSV;
			min->HoTen = i->HoTen;
			min->DTB = i->DTB;
			min->lop = i->lop;
			i->MSV = tmp.MSV;
			i->HoTen = tmp.HoTen;
			i->DTB = tmp.DTB;
			i->lop = tmp.lop;
		}
	}

	void SvGioi(dsSv l)
	{
		SV *i;
		for (i = l.head; i != l.tail; i = i->next)
		{
			if (i->DTB >= 8)
			{
				cout << "MSV:" << i->MSV << " Ho va Ten:" << i->HoTen << " DTB:" << i->DTB << " Lop:" << i->lop << endl;
			}
		}
	}

	void timlop(dsSv l)
	{
		SV *i;
		int d = 0;
		string timlop;
		cout << "Nhap lop:";
		cin >> timlop;
		cout << "Danh sach sinh vien lop da nhap :\n";
		for (i = l.head; i != l.tail; i = i->next)
		{
			if (i->lop == timlop)
			{
				++d;
				cout << "MSV:" << i->MSV << " Ho va Ten:" << i->HoTen << " DTB:" << i->DTB << " Lop:" << i->lop << endl;
			}
		}
		if (d == 0)
		{
			cout << "Khong tim thay!" << endl;
		}
	}

	void timSv(dsSv l)
	{
		SV *i;
		int d = 0;
		long timMsv;
		cout << "Nhap MSV cam tim:";
		cin >> timMsv;
		cout << "Sinh vien co MSV can tim la:\n";
		for (i = l.head; i != l.tail; i = i->next)
		{
			++d;
			if (i->MSV == timMsv)
			{
				cout << "MSV:" << i->MSV << " Ho va Ten:" << i->HoTen << " DTB:" << i->DTB << " Lop:" << i->lop << " Vi tri:" << d << endl;
			}
		}
		if (d == 0)
		{
			cout << "Khong tim thay!" << endl;
		}
	}
	// sap xep chon
	void alphabet(dsSv l)
	{
		SV *i, *j, *min;
		for (i = l.head; i != l.tail; i = i->next)
		{
			min = i;
			for (j = i->next; j != NULL; j = j->next)
			{
				if (min->HoTen > j->HoTen)
				{
					min = j;
				}
				else if (min->HoTen == j->HoTen)
				{
					if (min->HoTen > j->HoTen)
					{
						min = j;
					}
				}
			}
			SV tmp = *min;
			min->MSV = i->MSV;
			min->HoTen = i->HoTen;
			min->DTB = i->DTB;
			min->lop = i->lop;
			i->MSV = tmp.MSV;
			i->HoTen = tmp.HoTen;
			i->DTB = tmp.DTB;
			i->lop = tmp.lop;
		}
	}

	// void xoaNode(dsSv &l, int k = 0)
	// {
	// 	if (k == 1)
	// 	{
	// 		if (l.head == NULL)
	// 			return;
	// 		SV *delNode = l.head;
	// 		l.head = l.head->next;
	// 		if (l.head == NULL)
	// 			l.tail = NULL;
	// 		delete delNode;
	// 	}
	// 	else
	// 	{
	// 		SV *tmp = l.head;
	// 		for (int i = 1; i <= k - 2; i++)
	// 		{
	// 			tmp = tmp->next;
	// 		}
	// 		SV *delNode = tmp->next;
	// 		tmp->next = delNode->next;
	// 		if (tmp->next == NULL)
	// 			l.tail = tmp;
	// 		delete delNode;
	// 	}
	// }

	void xoaSvDtbthap(dsSv l)
	{
		SV *i;
		// int k=0;
		cout << "Danh sach SV(xoa SV co DTB<5.0):\n";
		for (i = l.head; i != l.tail; i = i->next)
		{
			// k++;
			if (i->DTB >= 5)
			{
				cout << "MSV:" << i->MSV << " Ho va Ten:" << i->HoTen << " DTB:" << i->DTB << " Lop:" << i->lop << endl;
				// xoaNode(l,k);
			}
		}
	}
};

int main()
{
	dsSv a;
	a.taoDsSv();
	cout << "Danh sach sinh vien:\n";
	a.duyet(a);
	long MSV;
	string HoTen;
	double DTB;
	string lop;
	while (1)
	{
		cout << "-------------------------------DSSV--------------------------------\n";
		cout << "1. Them mot sinh vien vao danh sach.\n";
		cout << "2. Tim sinh vien theo ma sinh vien va in ra thong tin va vi tri trong danh sach.\n";
		cout << "3. Tim kiem lop va in ra lop do.\n";
		cout << "4. Liet ke tat ca sinh vien xep loai gioi(DTB>=8.0).\n";
		cout << "5. Liet ke danh sach sinh vien theo thu tu giam dan cua DTB.\n";
		cout << "6. Sap xep sinh vien theo thu tu alphabet.\n";
		cout << "7. Xoa toan bo sinh vien co DTB<5.0!\n";
		cout << "0. Thoat!\n";
		cout << "-------------------------------------------------------------------\n";
		cout << "Nhap lua chon: ";
		int lc;
		cin >> lc;
		if (lc == 0)
		{
			cout << "Thoat!\n";
			break;
		}
		switch (lc)
		{
		case 1:
			int k;
			a.chenSv(&a, MSV, HoTen, DTB, lop, k);
			cout << "\nDanh sach sinh vien : \n";
			a.duyet(a);
			break;
		case 2:
			a.timSv(a);
			break;
		case 3:
			a.timlop(a);
			break;
		case 4:
			cout << "Sinh vien thuoc loai gioi(DTB>=8.0)\n";
			a.SvGioi(a);
			break;
		case 5:
			cout << "Danh sach sinh vien sap xep theo thu tu giam dan cua DTB la:\n";
			a.sapxepDTB(a);
			a.duyet(a);
			break;
		case 6:
			cout << "Danh sach sinh vien sap xep theo alphabet la:\n";
			a.alphabet(a);
			a.duyet(a);
			break;
		case 7:
			a.xoaSvDtbthap(a);
			break;
		default:
			cout << "Lua chon khong hop le!!\n";
			break;
		}
	}
}
