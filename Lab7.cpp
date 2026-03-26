#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
const int SIZE = 4; // Global variable for matrix size

class Matrix {
	private:
		int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
	public:
	    void readFromFile(string filePath);
		// 1. Read values from stdin into a matrix
		void readFromStdin();
		// 2. Display a matrix
		void display() const;
		// 3. Add two matrices (operator overloading for +)
		Matrix operator+(const Matrix& other) const;
		// 4. Multiply two matrices (operator overloading for *)
		Matrix operator*(const Matrix& other) const;
		// 5. Compute the sum of matrix diagonal elements
		int sumOfDiagonals() const;
		// 6. Swap matrix rows
		void swapRows(int row1, int row2);
};

Matrix Matrix::operator* (const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++) {        
        for (int j = 0; j < SIZE; j++) {     
            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}
     
}

void Matrix::swapRows(int row1, int row2){
    for(int i = 0; i < SIZE; i++){
        swap(data[row1][i], data[row2][i]); //uses swap from algorithm rather than temp values for simplicity
    }
}

int Matrix::sumOfDiagonals() const {
    int  sum = 0;
    for (int i = 0; i < SIZE; i++){
        cout << "sum:" << sum << " + "<< data[SIZE - i][i]<< endl;  //sums the primary diagnal
        sum += data[i][i];
    }
    
    for (int i = SIZE ; i > 0; i--){
        cout << "sum:" << sum << " + " <<data[SIZE - i][i] << endl; //sums the secondary diagn
        sum += data[SIZE - i][i-1];
    }
    
    return sum;
}


Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result;
    
    for (int i = 0; i < SIZE; i++){
        for (int j =0; j < SIZE; j++){
            result.data[i][j] = this->data[i][j] + other.data[i][j]; //sums the correspoding values and stores then in the result matrix
        }
    
    }
    return result     ;
}


void Matrix::readFromFile(string filePath) {
    std::ifstream file(filePath);
   
    for (int i = 0; i < SIZE; i++){
        for (int j =0; j < SIZE; j++){
            file >> data[i][j];
        }
    
    }
}
    

void Matrix::readFromStdin(){
    
    cout << "Enter values: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> data[i][j];             //adds values to the matrix
        }
    }
}

void Matrix::display() const {
    
    for(int i = 0; i < SIZE; i++){
        cout << "[";
        for (int j = 0; j < SIZE; j++){         //iterates through the matrix printing values
            cout << data[i][j] << " ";
            }
        cout << "]" << endl;
        }
    }

int main() {
    
    string filePath1 = "matrix-data.txt";
    string filePath2 = "matrix-data2.txt";

    // Matrix testMatrix;
    // Matrix testMatrix2;
    // Matrix resultMatrix;
    
    // testMatrix.readFromFile(filePath);
    // testMatrix.readFromStdin();
    // testMatrix2.readFromStdin();
    // resultMatrix = testMatrix + testMatrix2;
    // testMatrix2.swapRows(0,2);
    // testMatrix2.display();
    // cout << testMatrix2.sumOfDiagonals() << endl;
    

        //// Example usage:
    //Matrix mat1;
    //cout << "Enter values for Matrix 1:" << endl;
    //mat1.readFromStdin();
    //cout << "Matrix 1:" << endl;
    //mat1.display();
    //Matrix mat2;
    //cout << "Enter values for Matrix 2:" << endl;
    //mat2.readFromStdin();
    //cout << "Matrix 2:" << endl;
    //mat2.display();
    //Matrix sum = mat1 + mat2;
    //cout << "Sum of matrices:" << endl;
    //sum.display();
    //Matrix product = mat1 * mat2;
    //cout << "Product of matrices:" << endl;
    //product.display();
    //cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    //mat1.swapRows(0, 2);
    //cout << "Matrix 1 after swapping rows:" << endl;
    //mat1.display();
    
    return 0;
}






