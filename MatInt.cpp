#include<iostream>
#include<MatInt.h>

using namespace std;

~MatInt(int rows, int cols)
{
	for(int i=0; i< this->rows; i++)
	{
		delete[] this->mat[i];
	}
	delete[] this->mat;
}

int** MatInt::generteMatrix(int rows, int cols)
{
	int** temp =new int*[rows];
	
	for(int i=0; i< rows; i++)
	{
		temp[i]= new int[cols];
	}
	return temp;

}

void MatInt::printMatrix(int** matrix, int rows, int cols)
{
	for(int i=0; i< rows; i++)
	{
		for(int j=0; j< cols; j++)
		{
			cout<< this->mat[i][j]<< " ";
		}
		cout<< endl;
	}
}
void MatInt::populateMatrix(int* src, int size)
{
	if(rows * cols !=size)
	{
	cout<<"size of matrix is not equal to size of source array"<<endl;
	exit(-1);
	}
	int pos=0;
	for(int i=0; i< rows; i++)
	{
		for(int j=0; j< cols; j++)
		{
			this->mat[i][j]=src[pos++];
		}
	}
}


void MatInt::transp()
{
	int** temp=generteMatrix(this->cols,this->rows);
	for(int i=0; i< this->cols; i++)
	{
		for(int j=0; j< this->rows; j++)
		{
			temp[i][j]=this->mat[i][j];
		}
	}
	
	for(int i=0; i< this->rows; i++)
	{
		delete[] this->mat[i];
	}
	delete[] this->mat;
	this->mat=temp;
	
	int temp= this->cols;
	this->cols=this->rows;
	this->rows=temp; 
	
}
void MatInt::add(MatInt &m)
{
	if(this->rows != m.getNumRows() || this->cols !=m.getNumCols())
	{
		cout<<"size of the matrices should be of same size"<<endl;
		exit(-1); 
	}
	for(int i=0; i< this->rows; i++)
	{
		for(int j=0; j< this->cols; j++)
		{
			this->mat[i][j] += m.getValue(i,j);
		}
	}
			
}

void MatInt::Mul(MatInt &m)
{
	if(this->cols != m.getNumRows())
	{
		cout<<"can not multiply these matrices"<<endl;
		exit(-1); 
	}
	
	int** result= generteMatrix(this->rows, m.getNumCols());
	
	for(int i=0; i< this->rows; i++)
	{
		for(int j=0; j< this->cols; j++)
		{
			result[i][j]=0;
		}
	}
	for(int i=0; i< this->rows; i++)
	{
		for(int j=0; j< this->cols; j++)
		{
			for(int k=0;k< this-> cols;k++)
			{
				result[i][j] += this->mat[i][k] * m.getValue(k,j);
			}
		}
	}	
	
	for(int i=0; i< this->rows; i++)
	{
		delete[] this->mat[i];
	}
	this->mat=result;
	this->cols=m.getNumCols();
}
int MatInt::getValue(int i, int j)
{
	return this->mat[i][j];
}

int MatInt::getNumRows()
{
	return this->rows;
}

int MatInt::getNumCols()
{
	return this->Cols;
}