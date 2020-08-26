// 螺旋矩阵

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

}

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if(matrixSize==0){
        *returnSize = 0;
        return NULL;
    }
    int top = 0, bottom = matrixSize - 1, left = 0, right = *matrixColSize - 1;
    int totalElement = *matrixColSize * matrixSize;
    *returnSize = totalElement;
    int *res = (int *)malloc(sizeof(int) * totalElement);
    int m=0, n=0;
    int direction = 0;
    // 0:right   1:down   2:left   3:up
    for(int i=0; i<totalElement; i++){
        switch (direction)
        {
            case 0:
                res[i] = matrix[m][n];
                if(n==right){
                    top++;
                    direction = 1;
                    m++;
                }
                else{
                    n++;
                }
                break;
            case 1:
                res[i] = matrix[m][n];
                if(m==bottom){
                    right--;
                    direction=2;
                    n--;
                }
                else{
                    m++;
                }
                break;

            case 2:
                res[i] = matrix[m][n];
                if(n==left){
                    bottom--;
                    direction = 3;
                    m--;
                }
                else{
                    n--;
                }
                break;

            case 3:
                res[i] = matrix[m][n];
                if(m==top){
                    left++;
                    direction=0;
                    n++;
                }
                else{
                    m--;
                }
                break;

            default:
                break;
        }
    }
    return res;
}