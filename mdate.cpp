/* Nama Program : mdate.cpp
	Deskripsi : Driver untuk menggunakan unit ADT Date
			yang ada di date.h dan date.cpp
*/

#include <stdio.h>
#include <conio.h>
#include "date.h"

/* P R O G R A M   U T A M A   */
int main()
{
	 date D1, D2, D3, D4;
	 char lagi = 'y';

/* Algoritma : Procedure yang isi bodynya call thd semua feature yang ada */
for (;;)
{
	 //lakukan clear screen;
	CreateDate (&D1);
	printf ("\nHasil CreateDate (&D1), maka D1 bernilai : ");
	PrintObj (D1);
	//lakukan set tanggal, bulan, dan tahun, simpan hasil ke var D2
	//tampilkan D2
	//dan seterusnya uji semua modul yang ada di file body spesification-nya (date.cpp) dengan cara memanggil dari driver (modul main) ini

}
