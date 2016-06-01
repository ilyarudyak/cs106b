import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by ilyarudyak on 6/1/16.
 */
public class SudokuSolver {

    private static final int SIZE = 9;
    private int[][] matrix;

    public SudokuSolver(String filename) {
        matrix = new int[SIZE][SIZE];
        parseSudoku(filename);
    }

    public boolean solve() {
        return solve(0, 0, matrix);
    }

    // helper methods
    private boolean solve(int i, int j, int[][] cells) {

        if (i < 0 || i > SIZE || j < 0 || j > SIZE || cells[i][j] != 0) {
            return false;
        }

        for (int k = 1; k <= SIZE; k++) {
            if (isLegal(i, j, k, cells)) {
                cells[i][j] = k;

                int[] indArr = findInd(cells);
                if (indArr == null) {
                    return true;
                }
                if (solve(indArr[0], indArr[1], cells)) {
                    return true;
                }
                cells[i][j] = 0;
            }
        }

        return false;
    }
    private int[] findInd(int[][] cells) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (cells[i][j] == 0) {
                    int[] res = new int[2];
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return null;
    }
    private void parseSudoku(String filename) {

        try {
            String token;
            Scanner in = new Scanner(new File(filename));
            while (in.hasNext()) {
                token = in.next();
                int i = Integer.parseInt(token.substring(0, 1));
                int j = Integer.parseInt(token.substring(1, 2));
                int val = Integer.parseInt(token.substring(2, 3));
                matrix[i][j] = val;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
    private void printSudoku() {
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0)
                System.out.println(" -----------------------");
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0) System.out.print("| ");
                System.out.print(matrix[i][j] == 0
                        ? " "
                        : Integer.toString(matrix[i][j]));

                System.out.print(' ');
            }
            System.out.println("|");
        }
        System.out.println(" -----------------------");
    }
    private boolean isLegal(int i, int j, int val, int[][] cells) {
        for (int k = 0; k < 9; ++k)  // row
            if (val == cells[k][j])
                return false;

        for (int k = 0; k < 9; ++k) // col
            if (val == cells[i][k])
                return false;

        int boxRowOffset = (i / 3)*3;
        int boxColOffset = (j / 3)*3;
        for (int k = 0; k < 3; ++k) // box
            for (int m = 0; m < 3; ++m)
                if (val == cells[boxRowOffset+k][boxColOffset+m])
                    return false;

        return true; // no violations, so it's legal
    }

    public static void main(String[] args) {

        SudokuSolver solver = new SudokuSolver("src/main/resources/sudoku2.txt");
        solver.printSudoku();

        if (solver.solve()) {
            solver.printSudoku();
        } else {
            System.out.println("no solution found ...");
        }

    }
}



















