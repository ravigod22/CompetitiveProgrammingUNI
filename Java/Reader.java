import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Reader {
    public static void main(String[] args) {
        String fileName = "in.txt"; // Nombre del archivo a leer
        int matrix[][] = readMatrixFromFile(fileName);
        
        // Imprimir la matriz
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static int[][] readMatrixFromFile(String fileName) {
        int[][] matrix = null;
        
        try (Scanner scanner = new Scanner(new File(fileName))) {
            int rows = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                int k = line.length();
                if (k == 0) {
                    break;
                }
                //System.out.println(line);
                //System.out.println(" " + k);
                //StringBuilder sb = new StringBuilder();

                String[] values = line.trim().split("\\s+");
                if (matrix == null) {
                    matrix = new int[values.length][];
                }
                matrix[rows] = new int[values.length];
                for (int col = 0; col < values.length; col++) {
                    matrix[rows][col] = Integer.parseInt(values[col]);
                }
                rows++;
                /*
                for (int i = 0; i < values.length; ++i) {
                    System.out.print(Integer.parseInt(values[i]) + " ");
                }
                System.out.println();
                */
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return matrix;
    }
}

