#include<stdio.h>
#include<string.h>
typedef struct{
  char name[30];
	int id;
	int old;
	int group_id;
}member;
#define max 200
member tv[max];
//=======================
void scanfmem(member *data)
{          while(getchar()!='\n');
	printf("nhap ten:"); gets(data->name); 
	printf("nhap MSV: "); scanf("%d", &data->id); 
	printf("nhap tuoi: "); scanf("%d", &data->old); 
	printf("nhap nhom: "); scanf("%d", &data->group_id);
	printf("=================================\n");
}

void printfmem(member *data)
{
  	printf("%30s %8d %5d %5d\n", data->name, data->id, data->old, data->group_id);
}
void editmem(member *data,int msv)
{while(getchar()!='\n');
  data->id=msv;
  printf("Nhap ten can sua : "); gets(data->name);
  printf("Nhap tuoi: "); scanf("%d", &data->old);
  printf("Nhap nhom: "); scanf("%d", &data->group_id);
}
//=========================
int main()
{
  int n,i,choice;
  do {
    	printf("1:NHAP VA IN RA CAC THANH VIEN TRONG DOI \n");
	printf("2: THEM THANH VIEN \n");
	printf("3: SUA THANH VIEN\n");
	printf("4: XOA THANH VIEN \n");
	printf("5: TIM KIEM THONG TIN CUA THANH VIEN\n");
	printf("6: THOAT \n");
	printf("Nhap lua chon cua ban : ");
	do {
	  scanf("%d", &choice);
	  if (choice<1||choice>6) printf("Nhap lai lua chon cua ban \n");
	} while(choice<1||choice>6);
	//=============================
	switch (choice)
	  {
	  case 1: { printf("==NHAP VA IN RA THANH VIEN CUA DOI ==\n");
	      printf("Nhap so thanh vien cua doi: ");
	      do {
		scanf("%d", &n);
		if (n<1||n>200) printf("nhap lai so thanh vien doi \n");
	      } while(n<1||n>200);
	      for (i=0; i<n; i++)
		{ printf("Nhap thong tin thanh vien thu %d : \n", i+1);
		scanfmem(&tv[i]);
		}
		printf("%30s %8s %5s %5s\n","Ten", "ID", "Tuoi", "Nhom");
		 for (i=0; i<n; i++)
		   printfmem(&tv[i]);
	  } break;
	  case 2: {
	    int add;
	    printf("==THEM THANH VIEN==\n");
	    printf("Nhap so thanh vien can them :"); scanf("%d", &add);
	    for (i=n; i<n+add; i++)
	      {
		printf("Thanh vien thu  %d : \n", i+1);
		scanfmem(&tv[i]);
	      }
	    n=n+add;
	    	printf("%30s %8s %5s %5s\n","Ten", "ID", "Tuoi", "Nhom");
		for(i=0; i<n; i++)
		  printfmem(&tv[i]);
	  } break;
	  case 3: { int msv, dem=0;
	      member data;
	    printf("==SUA THANH VIEN==\n");
	    printf("Nhap ID thanh vien can sua : "); scanf("%d", &msv);
	    for (i=0; i<n; i++)
	      if (tv[i].id==msv) {dem=i; break;}
	    if (dem==0) printf("Thanh vien khong ton tai \n");
	    else {
	      editmem(&data,msv);
	    tv[dem]=data;
	    	printf("%30s %8s %5s %5s\n","Ten", "ID", "Tuoi", "Nhom");
	    for (i=0; i<n; i++)
	      printfmem(&tv[i]);}
	  } break;
	  case 4: {
	    printf("==XOA THANH VIEN==\n");
	    int msv, dem=-1;
	    printf("Nhap id cua thanh vien can xoa : "); scanf("%d", &msv);
	     for (i=0; i<n; i++)
	      if (tv[i].id==msv) {dem=i; break;}
	    if (dem==-1) printf("Thanh vien khong ton tai \n");
	    else {
	      	printf("%30s %8s %5s %5s\n","Ten", "ID", "Tuoi", "Nhom");
		for (i=0; i<n; i++)
		  { if (i==dem) { i=i+1; n=n-1;}
		    printfmem(&tv[i]);
		  }
	    }
	  } break;
	  case 5: {
	    printf("==TIM KIEM THONG TIN THANH VIEN==\n");
	    int msv, dem;
	    printf("Nhap id cua thanh vien can tim : "); scanf("%d", &msv);
	     for (i=1; i<=n; i++)
	      if (tv[i].id==msv) {dem=i; break;}
	    if (dem==0) printf("Thanh vien khong ton tai \n");
	    else {
	      printf("Ten thanh vien can tim: %s\n", tv[dem].name);
	      printf("Tuoi: %d\n", tv[dem].old);
	      printf("Nhom: %d\n", tv[dem].group_id);
	    }
	  } break;
	  default: printf("==THOAT==\n"); break;
	  }
  } while (choice!=6); }
		
		   
	    
	
