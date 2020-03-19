#include<iostream>
#include<MatInt.h>

using namespace std;

int main()
{
	int m=0,n=0;
	
	cout<<"enter the size of matrix1"<<endl;
	cin>>m;
	cout<<endl;
	cin>>n;
	int size= m*n;
	int *src;
	srcA=new int[size];
	cout<<"Enter the elements of matrix"<<endl;
	for(int i=0;i< size;i++)
	{
		cin>>srcA[i];
	}
	
	cout<<"enter the size of matrix2"<<endl;
	cin>>m;
	cout<<endl;
	cin>>n;
	int size2= m*n;
	int *srcB;
	srcB=new int[size2];
	cout<<"Enter the elements of matrix"<<endl;
	for(int i=0;i< size2;i++)
	{
		cin>>srcB[i];
	}
	//int srcA[]={1,2,3,4,5,6};
	MatInt matA(m,n);
	matA.populateMatrix(srcA, size);
		
		
	//int srcB[]={6,5,4,3,2,1};
	MatInt matB(m,n);
	matB.populateMatrix(srcB,size2);
	
	matA.print();
	cout<<endl;
	matb.print();
	cout<<endl;
	matA.add(matB);
	matA.print();
	cout<<endl;
	matA.Mul(matB);
	matA.print();
	
}