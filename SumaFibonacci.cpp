#include <iostream>
#include <cstring>
#define MAXCIF 1000
using namespace std;
typedef char NrMare[MAXCIF];
void citesteNrMare(NrMare, int &);
bool nrEgalZero(NrMare, int);
void maxfibst(NrMare, int &, NrMare, int);
void scadeNrMari(NrMare, int, NrMare, int, NrMare, int &);
void afiseazaNrMare(NrMare, int);
int comparaNrMari(NrMare, int, NrMare, int);
void adunaNrMari(NrMare, int, NrMare, int, NrMare, int &);
int main()
{
	NrMare n, x;
	int nn, nx;
	cout << "n = ";
	citesteNrMare(n, nn);
	while (!nrEgalZero(n, nn))
	{
		maxfibst(x, nx, n, nn);
		scadeNrMari(n, nn, x, nx, n, nn);
		afiseazaNrMare(x, nx);
	}
	return 0;
}
void maxfibst(NrMare y, int & ny, NrMare n, int nn)
{
	// cauta cel mai mare numar <= n din sirul fib
	// retine rezultatul in NrMare a
	NrMare x, z, zro;
	int nx, nz, nzro, i;
	for (i = 0; i < MAXCIF; i++)
	{
		x[i] = y[i] = z[i] = zro[i] = 0;
	}
	nx = ny = nz = nzro = 1;
	z[0] = 1; // z = 1
	while (comparaNrMari(z, nz, n, nn) <= 0) // z <= n
	{
		adunaNrMari(y, ny, zro, nzro, x, nx); // x = y
		adunaNrMari(z, nz, zro, nzro, y, ny); // y = z
		adunaNrMari(x, nx, y, ny, z, nz); // z = x + y
	}
}
void citesteNrMare(NrMare nr, int & nrcif)
{
	int i;
	char s[MAXCIF+1];
	cin >> s;
	nrcif = strlen(s);
	for (i = nrcif-1; i >= 0; i--)
	{
		nr[nrcif-i-1] = s[i]-'0';
	}
	for (i = nrcif; i < MAXCIF; i++)
	{
		nr[i] = 0;
	}
}
bool nrEgalZero(NrMare nr, int nrcif)
{
	int i;
	for (i = 0; i < nrcif && !nr[i]; i++);
	if (i == nrcif)
	{
		return 1;
	}
	return 0;
}
int comparaNrMari(NrMare a, int na, NrMare b, int nb)
{
	int i;
	if (na < nb)
	{
		return -1;
	}
	if (na > nb)
	{
		return 1;
	}
	for (i = na-1; i >= 0 && a[i] == b[i]; i--);
	if (i < 0)
	{
		return 0;
	}
	if (a[i] < b[i])
	{
		return -1;
	}
	return 1;
}
void adunaNrMari(NrMare a, int na, NrMare b, int nb, NrMare s, int & ns)
{
	// efectueaza adunarea a doua numere mari: s = a + b
	int i, t, val;
	// completeaza numarul cel mai mic cu zerouri nesemnificative
	if (na < nb)
	{
		for (i = na; i < nb; i++)
		{
			a[i] = 0;
		}
		ns = nb;
	}
	else
	{
		for (i = nb; i < na; i++)
		{
			b[i] = 0;
		}
		ns = na;
	}
	// aduna cele doua numere si retine rezultatul in s si ns
	for (t = i = 0; i < ns; i++)
	{
		val = a[i]+b[i]+t;
		s[i] = val%10;
		t = val/10;
	}
	if (t)
	{
		s[ns++] = t;
	}
}
void scadeNrMari(NrMare a, int na, NrMare b, int nb, NrMare d, int & nd)
{
	// efectueaza scaderea a doua numere mari: d = a - b
	int i, t, val;
	for (i = nb; i < na; i++)
	{
		b[i] = 0;
	}
	for (t = i = 0; i < na; i++)
	{
		val = a[i]-b[i]+t;
		if (val < 0)
		{
			d[i] = val+10;
			t = -1;
		}
		else
		{
			d[i] = val;
			t = 0;
		}
	}
	// ignor zerourile nesemnificative si actualizez nr. de cifre al lui d
	for (nd = na; nd > 1 && d[nd-1] == 0; nd--);
}
void afiseazaNrMare(NrMare nr, int nrcif)
{
	for (int i = nrcif-1; i >= 0; i--)
	{
		cout << (int)nr[i];
	}
	cout << '\n';
}
