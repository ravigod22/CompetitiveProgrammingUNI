import tkinter as tk
from tkinter import messagebox
import nltk
import random

cuadro_gramatica = None

def abrir_ventana_gramatica():
    global cuadro_gramatica
    ventana_gramatica = tk.Toplevel()
    ventana_gramatica.title("Cargar Gramatica")
    
    etiqueta_gramatica = tk.Label(ventana_gramatica, text = "Ingresa tu gramatica:")
    etiqueta_gramatica.pack()

    cuadro_gramatica_ventana = tk.Text(ventana_gramatica, height = 15, width = 60)
    cuadro_gramatica_ventana.pack()

    def leer_gramatica():
        global cuadro_gramatica
        try:
            gramatica = cuadro_gramatica_ventana.get("1.0", tk.END)
            nltk.CFG.fromstring(gramatica)  # Validación de la gramática
            messagebox.showinfo("Gramática", f"Gramática leída:\n{gramatica}")
            cuadro_gramatica.delete(1.0, tk.END)
            cuadro_gramatica.insert(tk.END, gramatica)
        except ValueError as e:
            messagebox.showerror("Error", f"Error en la gramática:\n{e}")
    
    boton_leer_gramatica = tk.Button(ventana_gramatica, text = "Cargar Gramatica", command = leer_gramatica)
    boton_leer_gramatica.pack()

def generar_cadena_gramatica(grammar, symbol):
    try
        productions = grammar.productions(lhs=symbol)
        if not productions:
            return f"\nNo hay producciones para el símbolo {symbol}\n"
        production = random.choice(productions)
        result = ''

        for part in production.rhs():
            if isinstance(part, str):
                result += part
            else:
                result += generar_cadena_gramatica(grammar, part)
        
        return result
    except IndexError:
        return f"No se pudo generar una cadena válida para el símbolo {symbol}"

def generar_cadena():
    global cuadro_gramatica
    try:
        gramatica = cuadro_gramatica.get("1.0", tk.END)
        grammar = nltk.CFG.fromstring(gramatica)
        cadena_generada = generar_cadena_gramatica(grammar, grammar.start())
        resultado_cadena.delete(1.0, tk.END)  # Limpiar el resultado anterior
        resultado_cadena.insert(tk.END, cadena_generada)
    except ValueError as e:
        messagebox.showerror("Error", f"Error al generar la cadena:\n{e}")

def insert_spaces(text):
    return ' '.join(text)

def mostrar_arbol():
    global cuadro_gramatica
    try:
        gramatica = cuadro_gramatica.get("1.0", tk.END)
        grammar = nltk.CFG.fromstring(gramatica)
        parser = nltk.ChartParser(grammar)
        input_text = resultado_cadena.get("1.0", tk.END)
        cadena = insert_spaces(input_text)
        trees = list(parser.parse(cadena.split()))  
        if trees:
            for tree in trees:
                tree.draw()
        else:
            messagebox.showinfo("Árbol de Derivación", "No se pudo generar el árbol para esta cadena.")
    except ValueError as e:
        messagebox.showerror("Error", f"Error al mostrar el árbol de derivación:\n{e}")

# Configuración de la interfaz gráfica
window = tk.Tk()
window.title("Generar Cadena")

boton_cargar_gramatica = tk.Button(window, text = "Cargar Gramatica", command = abrir_ventana_gramatica)
boton_cargar_gramatica.pack()

cuadro_gramatica = tk.Text(window, height = 15, width = 60)

boton_generar_cadena = tk.Button(window, text = "Generar Cadena", command = generar_cadena)
boton_generar_cadena.pack()

resultado_cadena = tk.Text(window, height=5, width=60)
resultado_cadena.pack()


boton_arbol_derivacion = tk.Button(window, text = "Arbol de Derivacion", command=mostrar_arbol)
boton_arbol_derivacion.pack()

window.mainloop()


