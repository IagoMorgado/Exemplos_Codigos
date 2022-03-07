import tkinter


from tkinter import *
#instancia a janela da interface
janela=Tk()

janela.title("Interface Grid")
#texto=Label(janela,text="Selecione dois pontos no grid para desenhar a reta")
#texto.grid(column=0,row=0,padx=10,pady=10)
c=tkinter.Canvas(janela,bg="black",height=250,width=250)

coord = 10,50,240,210
arc=c.create_arc(coord,start=0,extent=150, fill="red")

c.pack()
#abre a janela da interface
janela.mainloop()