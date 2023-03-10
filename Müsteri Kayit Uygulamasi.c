#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define SIZE 10  

typedef struct Musteri { 
	int numara; 
	char ad[20], soyad[20], telefon[20], adres[30]; 
	struct Musteri * next; 	
} node  ;


typedef struct HashTable {
	node * dizi [SIZE] ; 	
} hashTable  ;

hashTable ht; 

void tabloOlustur() 
{
	int i; 
	for( i=0; i<SIZE ; i++ )
	{
		ht.dizi[i] = (node * ) malloc(sizeof(node )); 
		ht.dizi[i]->next= NULL; 		
	}
}

int indexUret(int indis ) 
{
	return indis%SIZE; 	
}

int anahtarKontrolet(int numara)
{
	system("cls") ; 
	
 	int  sonuc=1 ; 
	
 
	int index= indexUret( numara) ;  
	node   *temp= ht.dizi[index]; 
	while( temp->next!=NULL  ) 
	{
	 	temp= temp->next; 
		if( temp->numara== numara  ) 
		{
			sonuc=0; 
			break; 	
		} 		
			
	} 
	if( sonuc==0)	
	printf("%d numarali musteri kaydi zaten var, lutfen verileri tekrar giriniz ! \n", numara  ) ; 	
	
	return sonuc; 
	
}

void ekle() 
{
	system("cls") ; 
	
	printf("Musteri ekleme.... \n"); 
	node *eleman = (node * ) malloc(sizeof(node )); 	
	printf("Numara    : ") ;scanf("%d", &eleman->numara  ) ; 
	printf("Ad        : ") ;scanf(" %[^\n]s", eleman->ad  ) ; 
	printf("Soyad     : ") ;scanf(" %[^\n]s", eleman->soyad  ) ; 
	printf("Telefon   : ") ;scanf(" %[^\n]s", eleman->telefon  ) ; 
	printf("Adres     : ") ;scanf(" %[^\n]s", eleman->adres ) ;
	eleman->next= NULL; 
	
	int sonuc=  anahtarKontrolet(eleman->numara); 
	if( sonuc == 1 )
	{
	int index= indexUret(eleman->numara) ;  
	node *temp= ht.dizi[index]; 
	while( temp->next!=NULL  ) 
	temp= temp->next; 
	
	temp->next= eleman; 
	printf("%d numarali musteri kaydi tamam \n", eleman->numara ) ; 
	} 	
		
}
void sil() 
{
	system("cls") ; 
	
	printf("Musteri silme ekleme.... \n"); 
	int numara, sonuc=0 ; 
	
	printf("Musteri numarasi : "); scanf("%d", &numara ) ; 

	
	int index= indexUret( numara) ;  
	char tercih; 
	node * temp2, *temp= ht.dizi[index]; 
	while( temp->next!=NULL  ) 
	{
		temp2= temp; 
		temp= temp->next; 
		if( temp->numara== numara  ) 
		{
			sonuc=1; 
			printf("%-20d%-20s%-20s%-20s%-30s\n", temp->numara, temp->ad, temp->soyad, temp->telefon, temp->adres   ) ; 
			printf("\nSilmek istediginize emin misiniz  ( E/H )  ? : ") ; scanf(" %c", &tercih ); 
			if( tercih=='e'  || tercih=='E' ) 
			{
				temp2->next= temp->next; 
				free(temp);
				printf("\n%d numarali musteri kaydi silindi \n", numara  ) 				; 
			}
			else 
			printf("\n%d numarali musteri silme islemi iptal edildi \n", numara  ); 
			
			break; 	
		}
		
			
	} 
	if( sonuc==0)	
	printf("%d numarali musteri kaydi bulunamadi ! \n", numara  ) ; 
	
}
void yazdir() 
{
	system("cls") ; 
	
	printf("Musteri yazdirma .... \n"); 
	printf("%-20s%-20s%-20s%-20s%-30s\n", "NO", "AD", "SOYAD", "TELEFON", "ADRES" ) ; 
	
	int i, sonuc=0; 
	for(i=0; i<SIZE; i++  ) 
	{
		node *temp= ht.dizi[i]; 		
		while(  temp->next!=NULL  )
		{
			sonuc=1; 
			temp= temp->next; 
			printf("%-20d%-20s%-20s%-20s%-30s\n", temp->numara, temp->ad, temp->soyad, temp->telefon, temp->adres   ) ; 			
		}
	}
	
	if( sonuc==0 )
	{
		system("cls"); 
		
		printf("Tabloda kayitli musteri yok ! \n"); 		
	}

	
	
}
void ara() 
{
	system("cls") ; 
	
	printf("Musteri arama ekleme.... \n"); 
	int numara, sonuc=0 ; 
	
	printf("Aradiginiz musteri numarasi : "); scanf("%d", &numara ) ; 

	int index= indexUret( numara) ;  
	node   *temp= ht.dizi[index]; 
	while( temp->next!=NULL  ) 
	{
	 	temp= temp->next; 
		if( temp->numara== numara  ) 
		{
			sonuc=1; 
			printf("\n%d numarali musteri bilgileri : \n ", numara  )  ; 			
			printf("%-20d%-20s%-20s%-20s%-30s\n", temp->numara, temp->ad, temp->soyad, temp->telefon, temp->adres   ) ; 					 
			break; 	
		} 		
			
	} 
	if( sonuc==0)	
	printf("%d numarali musteri kaydi bulunamadi ! \n", numara  ) ; 
	
	
	
}

int menu() 
{
	int secim; 
	printf("\nMUSTERI KAYIT UYGULMASI \n") ; 
	printf("1- Ekle \n"); 
	printf("2- Sil \n"); 
	printf("3- Yazdir \n"); 
	printf("4- Ara \n"); 
	printf("0- Kapat \n"); 
	printf("Seciminiz  :  "); scanf("%d", &secim ); 	
	system("cls") ; 	
	return secim; 
	
}



int main(int argc, char *argv[]) {
	tabloOlustur() ; 
	
	int secim= menu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: ekle(); break; 
			case 2: sil(); break; 
			case 3: yazdir(); break; 
			case 4: ara(); break; 
			case 0:  break; 
			default : printf("Hatali secim ! \n"); break; 			
		}
		secim= menu(); 
		
	}
	
	
	
	return 0;
}

