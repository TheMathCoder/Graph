#include <stdio.h>
#include <math.h>

struct muchie {
    int x,y;
}u[100];

int a[100][100]={0};
int vec[100]={0};

void nuleaza(int mat[100][100],int x){
    for(int i=1;i<=x;i++)
        for(int j=1;j<=x;j++)
            mat[i][j]=0;
}

void nuleaza_v(int v[100],int m)
{
    for(int i=0;i<=m;i++)
        v[i]=0;
}

void creeaza(int n, int &m){
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
    {
        u[++m].x=i;
        u[m].y=j;

    }
}

void completeaza(int a[100][100], int v[100],int m)
{
    for(int i=1;i<=m;i++)
        if(v[i])
            a[u[i].x][u[i].y]=a[u[i].y][u[i].x]=1;
}

void transforma_in_baza_2_pe_m_poz(int nr, int v[100], int poz){
    nuleaza_v(v,poz);
    while(nr!=0){
        v[poz--]=nr%2;
        nr/=2;
    }
}

void afiseaza(int a[100][100], int n)
{

    for(int i=1;i<=n;i++)
       {   for(int j=1;j<=n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
       }
       printf("\n");



}

void genereaza_matrice(int n){
    int m=0;
    creeaza(n,m);
    for(int k=0;k<pow(2,m);k++)
    {
        transforma_in_baza_2_pe_m_poz(k,vec,m);
        nuleaza(a,n);
        completeaza(a,vec,m);
        printf("Cazul #%d:\n",k+1);
        afiseaza(a,n);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("\n");
    genereaza_matrice(n);
}

