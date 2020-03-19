class MatInt
{
	private:
		int rows=0;
		int cols=0;
		int** mat;
		
	public:
		MatInt(int rows, int cols) :rows(rows), cols(cols)
		{
			this->mat=generateMatrix(this->rows, this->cols);
		}
		~MatInt();
		int** generateMatrix(int rows, int cols);
		void populateMatrix(int* src, int size);
		void print();
		void transp();
		void add(MatInt &m);
		void mul(MatInt &m);
		int getValues(int i, int j); 
		int getNumRows();
		int getNumCols();
};