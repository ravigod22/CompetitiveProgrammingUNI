package edu.ade.simplex;
/**
 *
 * @author jose
 */
public class Simplex {
    private final int nroFilas;
    private final int nroColumnas;
    private final int nroVariables;
    private final int nroRestricciones;
    private final int[] values;
    private final double[] funcionObjetivo;
    private final double[][] tabla;
    private final double[][] tablaSimplex;

    public Simplex(int nroVariables, int nroRestricciones, double[] funcionObjetivo, double[][] tabla) {
        this.nroVariables = nroVariables;
        this.nroRestricciones = nroRestricciones;
        this.tabla = tabla;
        this.funcionObjetivo = funcionObjetivo;
        this.nroFilas = nroRestricciones + 1;
        this.nroColumnas = nroVariables + nroRestricciones + 2;
        this.tablaSimplex = new double[nroFilas][nroColumnas];
        this.values = new int[nroRestricciones];
        initTabla();
    }

    private void initTabla() {
        //
        for (int i = 0; i < nroRestricciones; ++i) {
            values[i] = -1;
        }
        //
        for (int i = 0; i < nroFilas; ++i) {
            for (int j = 0; j < nroColumnas; ++j) {
                tablaSimplex[i][j] = 0;
            }
        }
        // Z
        tablaSimplex[nroFilas - 1][0] = 1;
        
        // funcion objetivo
        for (int i = 0; i < nroVariables; i++) {
            tablaSimplex[nroFilas - 1][i + 1] = (-1) * funcionObjetivo[i];
        }
        // restricciones
        for (int i = 0; i < nroRestricciones; i++) {
            for (int j = 0; j < nroVariables; j++) {
                tablaSimplex[i][j + 1] = tabla[i][j];
            }
            tablaSimplex[i][nroColumnas - 1] = tabla[i][nroVariables + 1];
        }
        //variables basicas s1, s2, ...
        for (int i = 0; i < nroVariables; i++) {
            tablaSimplex[i][nroVariables + 1 + i] = 1;
        }
    }

    public int indiceColPivot() {
        int ind = -1;
        int row = nroFilas;
        double max_e = 1;
        for (int i = 0; i < nroColumnas; i++) {
            if (max_e > tablaSimplex[row- 1][i]) {
                ind = i;
                max_e = tablaSimplex[row - 1][i];
            }
        }
        return ind;
    }

    public int indiceRowPivot() {
        int indColPiv = indiceColPivot();
        if (indColPiv == -1) return -1;
        int row = nroFilas;
        int column = nroColumnas;
        boolean exist = false;
        double r = -1;
        int indAns = -1;
        for (int i = 0; i < row - 1; i++) {
            if (tablaSimplex[i][indColPiv] != 0 && tablaSimplex[i][column - 1] * tablaSimplex[i][indColPiv] > 0) {
                if (!exist) {
                    exist = true;
                    r = tablaSimplex[i][column - 1] / tablaSimplex[i][indColPiv];
                    indAns = i;
                } else {
                    if (r > tablaSimplex[i][column - 1] / tablaSimplex[i][indColPiv]) {
                        r = tablaSimplex[i][indColPiv];
                        indAns = i;
                    }
                }
            }
        }
        return indAns;
    }

    public void convertToOne() {
        int col = indiceColPivot();
        int row = indiceRowPivot();
        System.out.println("Escogemos como pivote a: tabla [" + row + "][" + col +"] = " + tabla[row][col]);
        if (row != -1 && col != -1) {
            values[row] = col;
            double factor = tablaSimplex[row][col];
            for (int i = 0; i < nroColumnas; i++) {
                tabla[row][i] /= factor;
            }
            ElementalOperation(col, row);
        }
    }

    public boolean allNonega() {
        int row = nroFilas;
        int column = nroColumnas;
        boolean one = true;
        for (int i = 1; i < column; i++) {
            one &= (tabla[row - 1][i] >= 0);
        }
        return one;
    }

    public void simplexMaximizar() {
        while (!allNonega()) {
            //printTabla();
            //System.out.println("==============================================================");
            convertToOne();
        }
        //printTabla();
        //printValues();
    }

    public void ElementalOperation(int column, int row) {
        int element = (int) tablaSimplex[row][column];
        for (int i = 0; i < nroFilas; i++) {
            if (i != row) {
                double r = (-1) * (tablaSimplex[i][column] / element);
                for (int j = 0; j < nroColumnas; j++) {
                    tablaSimplex[i][j] += r * tablaSimplex[row][j];
                }
            }
        }
    }

    public void printTabla() {
        for (int i = 0; i < nroFilas; i++) {
            for (int j = 0; j < nroColumnas; j++) {
                System.out.print(tablaSimplex[i][j] + " \t");
            }
            System.out.println();
        }
    }
    public void printValues() {
        for (int i = 0; i < nroRestricciones; ++i) {
            if (values[i] == -1) {
                System.out.println("X" + values[i] + " = 0.0");
            }
            else {
                System.out.println("X" + values[i] + " = " + tablaSimplex[i][nroColumnas - 1]);
            }
        }
        System.out.println("La solucion es: " + tablaSimplex[nroFilas - 1][nroColumnas - 1]);
    }
}
