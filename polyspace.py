import tkinter as tk
from tkinter import filedialog, ttk, Button, Text, Label, Canvas
from tkinter import *


class HTMLFileLoaderApp:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("PolySpaceReportGeneration")
        self.window.geometry('650x150+100+100')
        self.window.resizable(width=False, height=False)
        self.hold_file_path = tk.StringVar()  # to hold value of string type for setting file path
        self.progress_var = tk.DoubleVar()  # to hold value of type float for execution percentage
        self.button_disabled = False
        self.execution_success = False
        self.create_widgets()

    # def dis(self):
    #     if self.hold_file_path.get() > 0:
    #         self.button_disabled = True

    # def get_file_path(self):
    #     return self.hold_file_path
    #
    # def set_button_status(self, button_disabled):
    #     self.button_disabled = button_disabled

    def create_widgets(self):
        image = tk.Label(self.window, text='Poly', bg='#CD3167', fg='#fff', font='Times 18 italic')
        image.place(x=0, y=0, width=80, height=70)


        # image = tk.PhotoImage(file="logo.png", height=100, width=200)
        # x = tk.Label(self.window, image=image)
        # x.place(x=0, y=0, width=80, height=70)


        # canvas = Canvas(self.window)
        # canvas.place(x=0, y=0, width=80, height=70)
        # img = tk.PhotoImage(file="logo.png")
        # canvas.create_image(10, 10, image=img)
        # def switch(self):
        #     if len(self.hold_file_path.get() > 0):
        #         self.html_button["state"] = DISABLED

        self.zip_button = tk.Button(self.window, text='CREATE ZIP', bg='#000', fg='#fff',
                                    activebackground='#000', activeforeground='#fff')
        self.zip_button.place(x=0, y=70, width=80, height=30)

        self.html_button = tk.Button(self.window, text='Load Html File', bg='#FF34B3', activebackground='#FF34B3',
                                     fg='#fff', command=self.load_html_file)
        self.html_button.place(x=81, y=0, width=90, height=35)
        # self.html_button.bind('<Button>', self.dis)

        self.excel_button = tk.Button(self.window, text='Load Excel File', bg='#FF34B3', activebackground='#FF34B3',
                                      fg='#fff', command=self.load_excel_file)
        self.excel_button.place(x=81, y=35, width=90, height=35)

        # exit button
        self.exit_button = tk.Button(self.window, text='Exit', bg='#808080', fg='#fff',
                                     activebackground='#808080', command=self.exit_app)
        self.exit_button.place(x=81, y=71, width=90, height=29)

        self.text_html = Text(self.window)
        self.text_html.place(x=171, y=0, width=479, height=35)

        self.text_excel = Text(self.window)
        self.text_excel.place(x=171, y=36, width=479, height=35)

        self.execute_button = tk.Button(self.window, text='EXECUTE', bg='#008000', fg='#fff',
                                        activebackground='#008000', command=self.execute)
        self.execute_button.place(x=171, y=71, width=479, height=29)

        # progress bar
        self.progress_bar = ttk.Progressbar(self.window, variable=self.progress_var, maximum=100, mode='determinate')
        self.progress_bar.place(x=0, y=101, width=650, height=25)

        # self.load_button = tk.Button(self.window, text="Load HTML File", command=self.load_html_file)
        # self.execute_button = tk.Button(self.window, text="Execute", command=self.execute)
        # self.file_path_text = tk.Text(self.window, height=1, width=50)
        # self.progress_bar = ttk.Progressbar(self.window, variable=self.progress_var, maximum=100, mode="determinate")
        # self.progress_bar.pack(pady=5, fill='x')

    def load_html_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("HTML files", "*.html")])
        if file_path:
            self.hold_file_path.set(file_path)
            # self.hold_file_path.delete(1.0, 'end')
            self.text_html.insert('end', file_path)

    def load_excel_file(self):
        file_path = filedialog.askopenfilename(filetypes=[('XML files', '*.xml')])
        if file_path:
            self.hold_file_path.set(file_path)
            # self.hold_file_path.delete(1.0, 'end')
            self.text_excel.insert('end', file_path)

    def execute(self):
        progress = 0  # declaring a variable to hold value of progress execution
        if len(self.hold_file_path.get()) > 0:  # on clicking execute button it checks if the file if selected or not
            while progress < 100:
                progress += 20  # incrementing progress by 20% each time
                self.progress_var.set(progress)  # setting the progress value in the variable var of progress bar
                self.execute_button.config(text=f"{progress}%")  # Update the button text
                self.window.update_idletasks()
                self.window.after(500)  # Delay for demonstration purposes
                if progress == 100:  # checking if progress is 100% done or not, if done then only showing success msg
                    self.set_execution(True)
                    self.success_msg()  # calling success function

        self.text_html.delete(1.0, 'end')  # deleting text inside html text area after execution
        self.text_excel.delete(1.0, 'end')  # deleting text inside excel text area after execution
        self.progress_var.set(0)  # initially progress bar is set to 0
        self.execute_button.config(text="EXECUTE")  # Reset the button text
        self.hold_file_path.set('')  # setting the file path again to zero

    def set_execution(self, execution_success):
        self.execution_success = execution_success
        # print(self.execution_success)
        # print('hehe')

    def success_msg(self):
        if self.execution_success:
            print('succ')
            self.outputLog = Label(self.window, text='File Parsed Successfully', bg='green')
            print('ss')
            self.outputLog.place(x=0, y=127, width=650, height=25)
            self.window.update_idletasks()
            self.window.after(3000)  # adding a delay of 3s so that can user can view the success msg
            self.reset_success_msg()  # calling reset_success_msg() function

    def reset_success_msg(self):
        print('before')
        self.output_reset_log = Label(self.window, text='reset')
        self.output_reset_log.place(x=0, y=127, width=650, height=25)
        print('after')

    def exit_app(self):
        self.window.quit()  # calling quit method to handle click and close the window

    def run(self):
        self.window.mainloop()


if __name__ == "__main__":
    app = HTMLFileLoaderApp()
    app.run()
