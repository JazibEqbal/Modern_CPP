from tkinter import *

from tkinter import *

window = Tk()
window.title('PolySpaceReportGeneration')
window.geometry('650x150+200+200')
window.resizable(width=False, height=FALSE)

# 1st row 1st column
    # image
    # zip button

# 1st row 2nd column
    #Load Html Button
    #Load Xml Button
    #Exit button

# 1st row 3rd column
    # text area for loading and displaying html file
    # text area for loading and displaying xml file
    # Execute button
# 2nd row
    # progress bar

# 3rd log
    # shows path where paresd file is


# ----------------ROW 1 (Col 1)--------------------
# image
i = Button(window,text='Image')
i.place(x=0, y=0, width=80, height=70)

zipButton = Button(window, text='CREATE ZIP', bg='#000', fg='#fff', activebackground='#000', activeforeground='#fff')
zipButton.place(x=0, y=70, width=80, height=30)

htmlButton = Button(window, text='Load Html File', bg='#FF34B3', activebackground='#FF34B3', fg='#fff')
htmlButton.place(x=81, y=0, width=90, height=35)

excelButton = Button(window, text='Load Excel File', bg='#FF34B3', activebackground='#FF34B3', fg='#fff')
excelButton.place(x=81, y=35, width=90, height=35)

exitButton = Button(window, text='Exit', bg='#808080', fg='#fff', activebackground='#808080')
exitButton.place(x=81, y=71, width=90, height=29)

textHtml = Text(window)
textHtml.place(x=171, y=0, width=479, height=35)

textExcel = Text(window)
textExcel.place(x=171, y=36, width=479, height=35)

executeButton = Button(window, text='EXECUTE', bg='#008000', fg='#fff', activebackground='#008000')
executeButton.place(x=171, y=71, width=479, height=29)

progressBar = Text(window)
progressBar.place(x=0, y=101, width=650, height=25)

outputLog = Text(window)
outputLog.place(x=0, y=127, width=650, height=25)

window.mainloop()

