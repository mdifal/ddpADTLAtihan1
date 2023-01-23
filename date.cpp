/* File        : date.cpp */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include "date.h"

/*********** Operasi Primitif ************/
void CreateDate (date * D)
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
{
	SetTgl (01, &(* D));
	SetBln (01, &(* D));
	SetThn (1900, &(* D));
}

/******* Selector komponen **********/
int GetTgl (date D)
/* Mengambil bagian Tgl dari date */
{
	
	return(D.Tgl);
}

int GetBln (date D)
/* Mengambil bagian Bln dari date */
{
	return(D.Bln);
}


int GetThn (date D)
/* Mengambil bagian Thn dari date */
{
	return(D.Thn);
}


/****** Pengubah komponen ******/
void SetTgl (int NewTgl, date * D)
/* Memberi nilai untuk Tgl */
{
	(* D).Tgl = NewTgl;
}

void SetBln (int NewBln, date * D)
/* Memberi nilai untuk Bln */
{
	(* D).Bln = NewBln;
}


void SetThn (int NewThn, date * D)
/* Memberi nilai untuk Thn */
{
	(* D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
void BacaDate (date * D)
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
{
	int tanggal,bulan,tahun;
	
	printf("\nTanggal :");
	scanf("%d",&tanggal);
	printf("\nBulan :");
	scanf("%d",&bulan);
	printf("\nTahun :");
	scanf("%d",&tahun);

	SetTgl (tanggal, &(* D));
	SetBln (bulan, &(* D));
	SetThn (tahun, &(* D));
	

	
}

boolean isValid(date D)
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
{

	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > TglAkhir(D)))
		return (false);
	else
		return (true);
}

void PrintObj (date D)
/* Print nilai D dengan format dd/mm/yyyy */
{
	printf ("%d/%d/%d\n", GetTgl(D),GetBln(D),GetThn(D));
}

/****** Operator Relasional ******/
boolean isKabisat (date D)
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
{
	if(D.Thn%4==0){
		return true;
	}
	else{
		return false;
	}
}

/***** Predikat lain *******/
int TglAkhir (date D)
/* Memberikan tanggal terakhir dari sebuah bulan */
{
	if(GetBln(D)>7){
		if(GetBln(D)%2==0){
		return 31;
	}
	else if (GetBln(D)%2==0){
		if(GetBln(D)==2){
			if(isKabisat){
				return 29;
			}
			else{
				return 28;
			}
		}
	}
		else {
			return 30;
		}
	}
	else {
		if(GetBln(D)%2==1){
		return 31;
	}
	else if (GetBln(D)%2==0){
		if(GetBln(D)==2){
			if(isKabisat){
				return 29;
			}
			else{
				return 28;
			}
		}
	
	}
		else {
			return 30;
		}
	}
	
	
}

void DateBefore (date D)
{

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
	int tgl_sebelum,bln_sebelum,thn_sebelum;
	tgl_sebelum=GetTgl(D)-1;
	bln_sebelum=GetBln(D);
	
	thn_sebelum=GetThn(D);

	if (tgl_sebelum <1){
		bln_sebelum=bln_sebelum-1;
		tgl_sebelum=TglAkhir(D);
	}
	if (bln_sebelum < 1){
		thn_sebelum =thn_sebelum -1;
		bln_sebelum  = 12;
	}
	
	printf("Tanggal Sebelum : %d/%d/%d\n",tgl_sebelum,bln_sebelum,thn_sebelum);


}

void NextDate (date D){
	/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
	int tgl_setelah,bln_setelah,thn_setelah;
	tgl_setelah=GetTgl(D)+1;
	bln_setelah=GetBln(D);
	thn_setelah=GetThn(D);
	
	if (tgl_setelah >TglAkhir(D)){
		bln_setelah=bln_setelah+1;
		tgl_setelah=1;
	}
	
	if (bln_setelah > 12){
		thn_setelah=thn_setelah+1;
		bln_setelah = 1;
	}
	
	printf("Tanggal Setelah : %d/%d/%d\n",tgl_setelah,bln_setelah,thn_setelah);

}


void SelisihDate (date D1, date D2)
{

/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
	int tanggal1,tanggal2,bulan1,bulan2,tahun1,tahun2,selisih;
	date tanggal_selisih;
	
	
	tanggal1=GetTgl(D1);
	bulan1=GetBln(D1);
	tahun1=GetThn(D1);
	
	tanggal_selisih.Bln=bulan1-bulan2;
	
	tanggal2=GetTgl(D2);
	bulan2=GetBln(D2);
	tahun2=GetThn(D2);
	
	tanggal_selisih.Thn=selisih+((tahun1-tahun2)*(-1)*365);
	tanggal_selisih.Bln=selisih+((tanggal_selisih.Bln)*(-1)*TglAkhir(tanggal_selisih));
	tanggal_selisih.Tgl=selisih+(tanggal1-tanggal2*(-1));
	
	if(tanggal_selisih.Thn<0){
		tanggal_selisih.Thn=tanggal_selisih.Thn*(-1);
	}
	if (tanggal_selisih.Bln<0){
		tanggal_selisih.Bln=tanggal_selisih.Bln*(-1);
	}
	if(tanggal_selisih.Tgl<0){
		tanggal_selisih.Tgl=tanggal_selisih.Tgl*(-1);
	}

	if(selisih < 0){
		selisih=selisih*(-1);
	}
	
	
	selisih=tanggal_selisih.Tgl+tanggal_selisih.Bln+tanggal_selisih.Thn;
	printf("Selisih tanggal = %d hari",selisih);
}
