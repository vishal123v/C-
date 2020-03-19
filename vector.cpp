#include <cmath> 
#include <iostream> 
using namespace std; 

class Vector { 
private: 
	int x, y, z; 
	

public: 
	Vector(int x, int y, int z) 
	{ 
		this->x = x; 
		this->y = y; 
		this->z = z; 
	} 
	Vector operator+(Vector v);   
	int operator^(Vector v);
	Vector operator*(Vector v);
	float magnitude() 
	{ 
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); 
	} 
	friend ostream& operator<<(ostream& out, const Vector& v); 
 
}; 

// Addition 
Vector Vector::operator+(Vector v) 
{ 
	int x1, y1, z1; 
	x1 = x + v.x; 
	y1 = y + v.y; 
	z1 = z + v.z; 
	return Vector(x1, y1, z1); 
} 
 

// Dot product
int Vector::operator^(Vector v) 
{ 
	int x1, y1, z1; 
	x1 = x * v.x; 
	y1 = y * v.y; 
	z1 = z * v.z; 
	return (x1 + y1 + z1); 
} 

// Cross product
Vector Vector::operator*(Vector v) 
{ 
	int x1, y1, z1; 
	x1 = y * v.z - z * v.y; 
	y1 = z * v.x - x * v.z; 
	z1 = x * v.y - y * v.x; 
	return Vector(x1, y1, z1); 
} 

// Display Vector 
ostream& operator<<(ostream& out, const Vector& v) 
{ 
	out << v.x << "i "; 
	if (v.y >= 0) 
		out << "+ "; 
	out << v.y << "j "; 
	if (v.z >= 0) 
		out << "+ "; 
	out << v.z << "k" << endl; 
	return out; 
} 

// Main 
int main() 
{ 
	
	float i,j,k;
	cout<<"enter 1st vector's i, j, k values"<<endl;
	cin>>i>>j>>k;
	Vector V1(i,j,k);
	cout<<"enter 2nd vector's i, j, k values"<<endl;
	cin>>i>>j>>k;
	Vector V2(i,j,k);
	

	cout << "V1 = " << V1; 
	cout << "V2 = " << V2; 

	cout << "V1 + V2 = " << (V1 + V2); 
	cout << "Dot Product is : " << (V1 ^ V2); 
	cout << "Cross Product is : " << (V1 * V2); 

	return 0; 
} 
