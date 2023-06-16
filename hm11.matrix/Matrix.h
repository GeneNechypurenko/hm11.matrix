#include <iostream>
#include <windows.h>

using namespace std;

template <typename T>
class Matrix {

private:
    int row;
    int col;
    T** data;

    static int count;

    void SafeInput(int& value, int min, int max) {

        while (!(cin >> value) || value < min || value > max) {
            cout << "ïîìèëêà, íåâ³ðíî çàäàíå çíà÷åííÿ.. ñïðîáóéòå çíîâó: ";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }

public:
    Matrix(int row, int col) : row(row), col(col) {

        cout << "Ñòâîðåííî íîâèé îá'ºêò [" << count + 1 << "]" << endl << endl;

        data = new T * [row];
        for (int i = 0; i < row; i++)
            data[i] = new T[col];

        count++;
    }

    ~Matrix() {

        cout << "Âèäàëåííî îá'ºêò [" << count << "]" << endl << endl;

        for (int i = 0; i < row; i++)
            delete[] data[i];
        delete[] data;

        count--;
    }

    void InputValue() {

        cout << "ÂÈÇÎÂ ÌÅÒÎÄÀ ÇÀÏÎÂÍÅÍÍß ÌÀÒÐÈÖ² Ç ÊËÀÂ²ÀÒÓÐÈ:" << endl << endl;

        int min = 1, max = 9;
        cout << "Ââåä³òü åëåìåíòè ìàòðèö³ â³ä " << min << " äî " << max << ":\n";

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {

                cout << "Åëåìåíò [" << i << "][" << j << "]: ";
                SafeInput(data[i][j], min, max);
            }
        cout << endl;
    }

    void InitWithRandValues() {

        cout << "ÂÈÇÎÂ ÌÅÒÎÄÀ ÇÀÏÎÂÍÅÍÍß ÌÀÒÐÈÖ² ÂÈÏÀÄÊÎÂÈÌÈ ÇÍÀ×ÅÍÍßÌÈ:" << endl << endl;

        srand(time(0));

        int min = 1, max = 9;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j] = min + rand() % (max - min + 1);
    }

    void PrintMatrix() {

        cout << "ÐÅÇÓËÜÒÀÒ:" << endl << endl;

        for (int i = 0; i < row; i++)
            Sleep(20), cout << "[i" << i << "]";
        cout << endl;

        for (int j = 0; j < row; j++) {
            for (int i = 0; i <= col; i++) {

                if (i == col)
                    Sleep(20), cout << "[j" << j << "]" << " ";

                else
                    Sleep(20), cout.width(3), cout << data[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    Matrix<T>& operator=(const Matrix<T>& object) {

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                this->data[i][j] = object.data[i][j];

        return* this;
    }

    Matrix<T> operator+(const Matrix<T>& object) const {

        cout << "ÑÊËÀÄÀÍÍß ÌÀÒÐÈÖÜ:" << endl << endl;

        Matrix<T> result(row, col);

        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) 
                result.data[i][j] = data[i][j] + object.data[i][j];

        return result;
    }

    Matrix<T> operator-(const Matrix<T>& object) const {

        cout << "Â²ÄÍ²ÌÀÍÍß ÌÀÒÐÈÖÜ:" << endl << endl;

        Matrix<T> result(row, col);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] - object.data[i][j];

        return result;
    }

    Matrix<T> operator*(const Matrix<T>& object) const {

        cout << "ÌÍÎÆÅÍÍß ÌÀÒÐÈÖÜ:" << endl << endl;

        Matrix<T> result(row, object.col);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] * object.data[i][j];

        return result;
    }

    Matrix<T> operator/(const Matrix<T>& object) const {

        cout << "Ä²ËÅÍÍß ÌÀÒÐÈÖÜ:" << endl << endl;

        Matrix<T> result(row, col);

        for (int i = 0; i < row; i++) 
            for (int j = 0; j < col; j++) 
                result.data[i][j] = data[i][j] / object.data[i][j];

        return result;
    }

    T FindMax() const {

        T max = data[0][0];

        for (int i = 0; i < row; i++) 
            for (int j = 0; j < col; j++) 
                if (data[i][j] > max) 
                    max = data[i][j];

        cout << "ÏÎØÓÊ ÌÀÊÑÈÌÀËÜÍÎÃÎ ÇÍÀ×ÅÍÍß: " << max << endl << endl;

        return max;
    }

    T FindMin() const {

        T min = data[0][0];

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (data[i][j] < min)
                    min = data[i][j];

        cout << "ÏÎØÓÊ Ì²Í²ÌÀËÜÍÎÃÎ ÇÍÀ×ÅÍÍß: " << min << endl << endl;
               
        return min;
    }
};


template <typename T>
int Matrix<T>::count = 0;