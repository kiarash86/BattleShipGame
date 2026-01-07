#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> randomNumber()
{
    vector<int> v = {1, 2, 3, 4};

    static mt19937 rng(std::random_device{}());
    shuffle(v.begin(), v.end(), rng);

    return v;
}

void moveShips(vector<vector<int>> &matrix, vector<vector<int>> &matrix2)
{
    bool changeposition1 = false;
    bool changeposition2 = false;
    bool changeposition3 = false;
    bool changeposition4 = false;
    bool changeposition5 = false;
    bool changeposition21 = false;
    bool changeposition22 = false;
    bool changeposition23 = false;
    bool changeposition24 = false;
    bool changeposition25 = false;
    int length = 2;
    for (size_t i = 1; i < 11; i++)
    {
        // here it is 10 because the smallest we want is 2 and no need to check further
        for (size_t j = 1; j < 10; j++)
        {
            if (abs(matrix[i][j]) >= 11 and abs(matrix[i][j]) <= 15)
            {
                if (abs(matrix[i][j]) == 11 and abs(matrix[i][j + 1]) == 11)
                {
                    if (!changeposition1)
                    {

                        if ((matrix[i][j]) == -11 and (matrix[i][j + 1]) == -11)
                        {

                            changeposition1 = true;
                        }
                        else
                        {
                            length = 2;
                            changeposition1 = Matrix(i, j, matrix, length);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix[i][j]) == 12 and abs(matrix[i][j + 1]) == 12 and abs(matrix[i][j + 2]) == 12)
                {
                    if (!changeposition2)
                    {

                        if ((matrix[i][j]) == -12 and (matrix[i][j + 1]) == -12 and (matrix[i][j + 2]) == -12)
                        {

                            changeposition2 = true;
                        }
                        else
                        {
                            length = 3;
                            changeposition2 = Matrix(i, j, matrix, length);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix[i][j]) == 13 and abs(matrix[i][j + 1]) == 13 and abs(matrix[i][j + 2]) == 13)
                {

                    if (!changeposition3)
                    {

                        if ((matrix[i][j]) == -13 and (matrix[i][j + 1]) == -13 and (matrix[i][j + 2]) == -13)
                        {

                            changeposition3 = true;
                        }
                        else
                        {
                            length = 3;
                            changeposition3 = Matrix(i, j, matrix, length);
                        }
                    }
                }
                else if (j <= 7 and abs(matrix[i][j]) == 14 and abs(matrix[i][j + 1]) == 14 and abs(matrix[i][j + 2]) == 14 and abs(matrix[i][j + 3]) == 14)
                {

                    if (!changeposition4)
                    {

                        if ((matrix[i][j]) == -14 and (matrix[i][j + 1]) == -14 and (matrix[i][j + 2]) == -14 and (matrix[i][j + 3]) == -14)
                        {

                            changeposition4 = true;
                        }
                        else
                        {

                            length = 4;
                            changeposition4 = Matrix(i, j, matrix, length);
                        }
                    }
                }
                else if (j <= 6 and abs(matrix[i][j]) == 15 and abs(matrix[i][j + 1]) == 15 and abs(matrix[i][j + 2]) == 15 and abs(matrix[i][j + 3]) == 15 and abs(matrix[i][j + 4]) == 15)
                {

                    if (!changeposition5)
                    {

                        if ((matrix[i][j]) == -15 and (matrix[i][j + 1]) == -15 and (matrix[i][j + 2]) == -15 and (matrix[i][j + 3]) == -15 and (matrix[i][j + 4]) == -15)
                        {

                            changeposition5 = true;
                        }
                        else
                        {

                            length = 5;
                            changeposition5 = Matrix(i, j, matrix, length);
                        }
                    }

                    /* code */
                }
            }

            if (abs(matrix2[i][j]) >= 21 and abs(matrix2[i][j]) <= 25)
            {
                if (abs(matrix2[i][j]) == 21 and abs(matrix2[i][j + 1]) == 21)
                {
                    if (!changeposition21)
                    {

                        if ((matrix2[i][j]) == -21 and (matrix2[i][j + 1]) == -21)
                        {

                            changeposition21 = true;
                        }
                        else
                        {
                            length = 2;
                            changeposition21 = Matrix(i, j, matrix2, length);
                        }
                    }
                }
                else if (j <= 8 and abs(matrix2[i][j]) == 22 and abs(matrix2[i][j + 1]) == 22 and abs(matrix2[i][j + 2]) == 22)
                {

                    if (!changeposition22)
                    {

                        if ((matrix2[i][j]) == -22 and (matrix2[i][j + 1]) == -22 and (matrix2[i][j + 2]) == -22)
                        {

                            changeposition22 = true;
                        }
                        else
                        {

                            length = 3;
                            changeposition22 = Matrix(i, j, matrix2, length);                        }
                    }
                }
                else if (j <= 8 and abs(matrix2[i][j]) == 23 and abs(matrix2[i][j + 1]) == 23 and abs(matrix2[i][j + 2]) == 23)
                {

                    if (!changeposition23)
                    {

                        if ((matrix2[i][j]) == -23 and (matrix2[i][j + 1]) == -23 and (matrix2[i][j + 2]) == -23)
                        {

                            changeposition23 = true;
                        }
                        else
                        {
                            length = 3;
                            changeposition23 = Matrix(i, j, matrix2, length);   
                        }
                    }
                }
                else if (j <= 7 and abs(matrix2[i][j]) == 24 and abs(matrix2[i][j + 1]) == 24 and abs(matrix2[i][j + 2]) == 24 and abs(matrix2[i][j + 3]) == 24)
                {

                    if (!changeposition24)
                    {

                        if ((matrix2[i][j]) == -24 and (matrix2[i][j + 1]) == -24 and (matrix2[i][j + 2]) == -24 and (matrix2[i][j + 3]) == -24)
                        {

                            changeposition24 = true;
                        }
                        else
                        {
                            length = 4;
                            changeposition24 = Matrix(i, j, matrix2, length);   
                        }
                    }
                }
                else if (j <= 6 and abs(matrix2[i][j]) == 25 and abs(matrix2[i][j + 1]) == 25 and abs(matrix2[i][j + 2]) == 25 and abs(matrix2[i][j + 3]) == 25 and abs(matrix2[i][j + 4]) == 25)
                {

                    if (!changeposition25)
                    {

                        if ((matrix2[i][j]) == -25 and (matrix2[i][j + 1]) == -25 and (matrix2[i][j + 2]) == -25 and (matrix2[i][j + 3]) == -25 and (matrix2[i][j + 4]) == -25)
                        {

                            changeposition25 = true;
                        }
                        else
                        {
                            length = 5;
                            changeposition25 = Matrix(i, j, matrix2, length);   
                        }
                    }
                }
            }
        }
    }
}

bool Matrix(int i, int j, vector<vector<int>> &matrix, int length)
{

    vector<int> random = randomNumber();

    for (auto &&ww : random)
    {
        switch (ww)
        {
        case 1:

            if (i >= 2)
            {
                for (int test = 0; test < length; test++)
                {
                    if (matrix[i - 1][j + test] != -1)
                    {

                        break;
                    }
                }

                for (int plus = 0; plus < length; plus++)
                {
                    matrix[i - 1][j + plus] = matrix[i][j];
                    matrix[i][j + plus] = -1;
                }
                return true;
            }
            break;
        case 2:

            if (i <= 9)
            {
                for (int test = 0; test < length; test++)
                {
                    if (matrix[i + 1][j + test] != -1)
                    {

                        break;
                    }
                }

                for (int plus = 0; plus < length; plus++)
                {
                    matrix[i + 1][j + plus] = matrix[i][j];
                    matrix[i][j + plus] = -1;
                }
                return true;
            }
            break;

        case 3:

            if (j >= 2 and matrix[i][j - 1] == -1)
            {
                for (int plus = 0; plus < length; plus++)
                {
                    matrix[i][j + plus - 1] = matrix[i][j + plus];
                    // matrix[i][j + plus] = -1;
                }
                matrix[i][j + length - 1] = -1;
                return true;
            }
            break;
        case 4:
            if (j <= 8 and matrix[i][j + length] == -1)
            {

                for (int plus = length; plus >0; plus++)
                {
                    matrix[i][j + plus] = matrix[i][j + plus-1];
                    // matrix[i][j + plus] = -1;
                }
                matrix[i][j] = -1;
                return true;

            }
            break;
        }
    }
    return false;
}








// bool matrix12(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1)
//             {
//                 matrix[i - 1][j] = matrix[i][j];
//                 matrix[i - 1][j + 1] = matrix[i][j + 1];
//                 matrix[i - 1][j + 2] = matrix[i][j + 2];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }
//             break;
//         case 2:
//             if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1)
//             {
//                 matrix[i + 1][j] = matrix[i][j];
//                 matrix[i + 1][j + 1] = matrix[i][j + 1];
//                 matrix[i + 1][j + 2] = matrix[i][j + 2];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }
//             break;
//         case 3:
//             if (j >= 2 and matrix[i][j - 1] == -1)
//             {
//                 matrix[i][j - 1] = matrix[i][j];
//                 matrix[i][j] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j + 2];
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }
//             break;
//         case 4:
//             if (j <= 7 and matrix[i][j + 3] == -1)
//             {
//                 matrix[i][j + 3] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j];
//                 matrix[i][j] = -1;
//                 return true;
//             }
//             break;
//         }
//     }
//     return false;
// }
// bool matrix13(int i, int j)
// {

//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1)
//             {
//                 matrix[i - 1][j] = matrix[i][j];
//                 matrix[i - 1][j + 1] = matrix[i][j + 1];
//                 matrix[i - 1][j + 2] = matrix[i][j + 2];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1)
//             {
//                 matrix[i + 1][j] = matrix[i][j];
//                 matrix[i + 1][j + 1] = matrix[i][j + 1];
//                 matrix[i + 1][j + 2] = matrix[i][j + 2];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }
//             break;
//         case 3:
//             if (j >= 2 and matrix[i][j - 1] == -1)
//             {
//                 matrix[i][j - 1] = matrix[i][j];
//                 matrix[i][j] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j + 2];
//                 matrix[i][j + 2] = -1;
//                 return true;
//             }
//             break;
//         case 4:
//             if (j <= 7 and matrix[i][j + 3] == -1)
//             {
//                 matrix[i][j + 3] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j];
//                 matrix[i][j] = -1;
//                 return true;
//             }
//             break;
//         }
//     }

//     return false;
// }
// bool matrix14(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1 and matrix[i - 1][j + 3] == -1)
//             {
//                 matrix[i - 1][j] = matrix[i][j];
//                 matrix[i - 1][j + 1] = matrix[i][j + 1];
//                 matrix[i - 1][j + 2] = matrix[i][j + 2];
//                 matrix[i - 1][j + 3] = matrix[i][j + 3];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 matrix[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1 and matrix[i + 1][j + 3] == -1)
//             {
//                 matrix[i + 1][j] = matrix[i][j];
//                 matrix[i + 1][j + 1] = matrix[i][j + 1];
//                 matrix[i + 1][j + 2] = matrix[i][j + 2];
//                 matrix[i + 1][j + 3] = matrix[i][j + 3];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 matrix[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix[i][j - 1] == -1)
//             {
//                 matrix[i][j - 1] = matrix[i][j];
//                 matrix[i][j] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 3];
//                 matrix[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 6 and matrix[i][j + 4] == -1)
//             {
//                 matrix[i][j + 4] = matrix[i][j + 3];
//                 matrix[i][j + 3] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j];
//                 matrix[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }
//     return false;
// }
// bool matrix15(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix[i - 1][j] == -1 and matrix[i - 1][j + 1] == -1 and matrix[i - 1][j + 2] == -1 and matrix[i - 1][j + 3] == -1 and matrix[i - 1][j + 4] == -1)
//             {
//                 matrix[i - 1][j] = matrix[i][j];
//                 matrix[i - 1][j + 1] = matrix[i][j + 1];
//                 matrix[i - 1][j + 2] = matrix[i][j + 2];
//                 matrix[i - 1][j + 3] = matrix[i][j + 3];
//                 matrix[i - 1][j + 4] = matrix[i][j + 4];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 matrix[i][j + 3] = -1;
//                 matrix[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix[i + 1][j] == -1 and matrix[i + 1][j + 1] == -1 and matrix[i + 1][j + 2] == -1 and matrix[i + 1][j + 3] == -1 and matrix[i + 1][j + 4] == -1)
//             {
//                 matrix[i + 1][j] = matrix[i][j];
//                 matrix[i + 1][j + 1] = matrix[i][j + 1];
//                 matrix[i + 1][j + 2] = matrix[i][j + 2];
//                 matrix[i + 1][j + 3] = matrix[i][j + 3];
//                 matrix[i + 1][j + 4] = matrix[i][j + 4];
//                 matrix[i][j] = -1;
//                 matrix[i][j + 1] = -1;
//                 matrix[i][j + 2] = -1;
//                 matrix[i][j + 3] = -1;
//                 matrix[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix[i][j - 1] == -1)
//             {
//                 matrix[i][j - 1] = matrix[i][j];
//                 matrix[i][j] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 3];
//                 matrix[i][j + 3] = matrix[i][j + 4];
//                 matrix[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 5 and matrix[i][j + 5] == -1)
//             {
//                 matrix[i][j + 5] = matrix[i][j + 4];
//                 matrix[i][j + 4] = matrix[i][j + 3];
//                 matrix[i][j + 3] = matrix[i][j + 2];
//                 matrix[i][j + 2] = matrix[i][j + 1];
//                 matrix[i][j + 1] = matrix[i][j];
//                 matrix[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }
//     return false;
// }

// bool matrix211(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1)
//             {
//                 matrix2[i - 1][j] = matrix2[i][j];
//                 matrix2[i - 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1)
//             {
//                 matrix2[i + 1][j] = matrix2[i][j];
//                 matrix2[i + 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix2[i][j - 1] == -1)
//             {
//                 matrix2[i][j - 1] = matrix2[i][j];
//                 matrix2[i][j] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 8 and matrix2[i][j + 2] == -1)
//             {
//                 matrix2[i][j + 2] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j];
//                 matrix2[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }
//     return false;
// }
// bool matrix212(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1)
//             {
//                 matrix2[i - 1][j] = matrix2[i][j];
//                 matrix2[i - 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i - 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1)
//             {
//                 matrix2[i + 1][j] = matrix2[i][j];
//                 matrix2[i + 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i + 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix2[i][j - 1] == -1)
//             {
//                 matrix2[i][j - 1] = matrix2[i][j];
//                 matrix2[i][j] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 7 and matrix2[i][j + 3] == -1)
//             {
//                 matrix2[i][j + 3] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j];
//                 matrix2[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }
//     return false;
// }
// bool matrix213(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1)
//             {
//                 matrix2[i - 1][j] = matrix2[i][j];
//                 matrix2[i - 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i - 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1)
//             {
//                 matrix2[i + 1][j] = matrix2[i][j];
//                 matrix2[i + 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i + 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix2[i][j - 1] == -1)
//             {
//                 matrix2[i][j - 1] = matrix2[i][j];
//                 matrix2[i][j] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 7 and matrix2[i][j + 3] == -1)
//             {
//                 matrix2[i][j + 3] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j];
//                 matrix2[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }
//     return false;
// }
// bool matrix214(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1 and matrix2[i - 1][j + 3] == -1)
//             {
//                 matrix2[i - 1][j] = matrix2[i][j];
//                 matrix2[i - 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i - 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i - 1][j + 3] = matrix2[i][j + 3];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 matrix2[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1 and matrix2[i + 1][j + 3] == -1)
//             {
//                 matrix2[i + 1][j] = matrix2[i][j];
//                 matrix2[i + 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i + 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i + 1][j + 3] = matrix2[i][j + 3];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 matrix2[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix2[i][j - 1] == -1)
//             {
//                 matrix2[i][j - 1] = matrix2[i][j];
//                 matrix2[i][j] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 3];
//                 matrix2[i][j + 3] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 6 and matrix2[i][j + 4] == -1)
//             {
//                 matrix2[i][j + 4] = matrix2[i][j + 3];
//                 matrix2[i][j + 3] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j];
//                 matrix2[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }

//     return false;
// }
// bool matrix215(int i, int j)
// {
//     vector<int> random = randomNumber();

//     for (auto &&ww : random)
//     {

//         switch (ww)
//         {
//         case 1:
//             if (i >= 2 and matrix2[i - 1][j] == -1 and matrix2[i - 1][j + 1] == -1 and matrix2[i - 1][j + 2] == -1 and matrix2[i - 1][j + 3] == -1 and matrix2[i - 1][j + 4] == -1)
//             {
//                 matrix2[i - 1][j] = matrix2[i][j];
//                 matrix2[i - 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i - 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i - 1][j + 3] = matrix2[i][j + 3];
//                 matrix2[i - 1][j + 4] = matrix2[i][j + 4];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 matrix2[i][j + 3] = -1;
//                 matrix2[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 2:
//             if (i <= 9 and matrix2[i + 1][j] == -1 and matrix2[i + 1][j + 1] == -1 and matrix2[i + 1][j + 2] == -1 and matrix2[i + 1][j + 3] == -1 and matrix2[i + 1][j + 4] == -1)
//             {
//                 matrix2[i + 1][j] = matrix2[i][j];
//                 matrix2[i + 1][j + 1] = matrix2[i][j + 1];
//                 matrix2[i + 1][j + 2] = matrix2[i][j + 2];
//                 matrix2[i + 1][j + 3] = matrix2[i][j + 3];
//                 matrix2[i + 1][j + 4] = matrix2[i][j + 4];
//                 matrix2[i][j] = -1;
//                 matrix2[i][j + 1] = -1;
//                 matrix2[i][j + 2] = -1;
//                 matrix2[i][j + 3] = -1;
//                 matrix2[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 3:
//             if (j >= 2 and matrix2[i][j - 1] == -1)
//             {
//                 matrix2[i][j - 1] = matrix2[i][j];
//                 matrix2[i][j] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 3];
//                 matrix2[i][j + 3] = matrix2[i][j + 4];
//                 matrix2[i][j + 4] = -1;
//                 return true;
//             }

//             break;
//         case 4:
//             if (j <= 5 and matrix2[i][j + 5] == -1)
//             {
//                 matrix2[i][j + 5] = matrix2[i][j + 4];
//                 matrix2[i][j + 4] = matrix2[i][j + 3];
//                 matrix2[i][j + 3] = matrix2[i][j + 2];
//                 matrix2[i][j + 2] = matrix2[i][j + 1];
//                 matrix2[i][j + 1] = matrix2[i][j];
//                 matrix2[i][j] = -1;
//                 return true;
//             }

//             break;
//         }
//     }

//     return false;
// }
