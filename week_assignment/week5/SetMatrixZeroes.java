import java.util.Arrays;

public class SetMatrixZeroes {
    public static void main(String[] args) {
        int[][] mat = {{1,2,3},{4,0,6},{7,8,9}};
        setZero(mat);

        for(int[] row : mat) {
            System.out.println(Arrays.toString(row));
        }
    }

    public static void setZero(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;

        boolean firstRow = false;
        boolean firstCol = false;

        for(int j=0;j<c;j++) {
            if(mat[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        for(int i=0;i<r;i++) {
            if(mat[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        for(int i=1;i<r;i++) {
            for(int j=1;j<c;j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i=1;i<r;i++) {
            if(mat[i][0] == 0) {
                for(int j=1;j<c;j++) {
                    mat[i][j] = 0;
                }
            }
        }

        for(int j=1;j<c;j++) {
            if(mat[0][j] == 0) {
                for(int i=1;i<r;i++) {
                    mat[i][j] = 0;
                }
            }
        }

        if(firstRow) {
            for(int j=0;j<c;j++) {
                mat[0][j] = 0;
            }
        }

        if(firstCol) {
            for(int i=0;i<r;i++) {
                mat[i][0] = 0;
            }
        }
    }
}