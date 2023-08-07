import tkinter as tk
from tkinter import filedialog, ttk
from tkinter import *
# from PIL import ImageTk, Image


class PolySpace:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("PolySpaceReportGeneration")
        self.window.geometry('650x150+100+100')  # window view size
        self.window.resizable(width=False, height=False)  # cannot be increased or decreased by the user
        self.hold_html_file_path = tk.StringVar()  # to hold value of string type for setting file path
        self.hold_excel_file_path = tk.StringVar()  # to hold value of string type for setting file path
        self.progress_var = tk.DoubleVar()  # to hold value of type float for execution percentage
        self.button_disabled = False
        self.execution_success = False
        self.zip_button = None
        self.html_button = None
        self.excel_button = None
        self.exit_button = None
        self.text_html = None
        self.text_excel = None
        self.execute_button = None
        self.progress_bar = None
        self.output = None
        self.output_log = None
        self.output_failure = None
        self.create_widgets()
        self.initial_output()

    def create_widgets(self):
        # img = Image.open("logo.png")
        # logo = ImageTk.PhotoImage(img)
        #
        # label1 = tk.Label(image=logo)
        # label1.img = logo
        # label1.place(x=0, y=0, width=80, height=70)

        # image
        label1 = tk.Label(self.window, text='Image', bg='#ffb6c1', fg='#fff')
        label1.place(x=0, y=0, width=80, height=70)

        # zip button
        self.zip_button = tk.Button(self.window, text='CREATE ZIP', bg='#000', fg='#fff',
                                    activebackground='#000', activeforeground='#fff', command=self.load_zip_file)
        self.zip_button.place(x=0, y=70, width=80, height=30)

        # html button
        self.html_button = tk.Button(self.window, text='Load Html File', bg='#FF34B3', activebackground='#FF34B3',
                                     fg='#fff', command=self.load_html_file)
        self.html_button.place(x=81, y=0, width=90, height=35)

        # xml button
        self.excel_button = tk.Button(self.window, text='Load Excel File', bg='#FF34B3', activebackground='#FF34B3',
                                      fg='#fff', command=self.load_excel_file)
        self.excel_button.place(x=81, y=35, width=90, height=35)

        # exit button
        self.exit_button = tk.Button(self.window, text='Exit', bg='#808080', fg='#fff',
                                     activebackground='#808080', command=self.exit_app)
        self.exit_button.place(x=81, y=71, width=90, height=29)

        # html holder
        self.text_html = Text(self.window)
        self.text_html.place(x=171, y=0, width=479, height=35)

        # xml holder
        self.text_excel = Text(self.window)
        self.text_excel.place(x=171, y=36, width=479, height=35)

        # execute button
        self.execute_button = tk.Button(self.window, text='EXECUTE', bg='#008000', fg='#fff',
                                        activebackground='#008000', command=self.execute)
        self.execute_button.place(x=171, y=71, width=479, height=29)

        # progress bar
        self.progress_bar = ttk.Progressbar(self.window, variable=self.progress_var, maximum=100, mode='determinate')
        self.progress_bar.place(x=0, y=101, width=650, height=24)

    # output view
    def initial_output(self):
        self.output = tk.Label(self.window, text='LOG:', bg='#4a5aff', anchor=W, fg='#fff')
        self.output.place(x=0, y=125, width=650, height=29)

    # function to handle load html file
    def load_html_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("HTML files", "*.html")])  # getting the file path in
        # file_path variable and opening a file dialog to select an html file
        if file_path:   # if file_path has got some file path then proceed
            if not self.hold_html_file_path.get():   # if file_path is empty then writing to it
                self.hold_html_file_path.set(file_path)
            else:
                self.hold_html_file_path.set(file_path)  # if hold_file_path has a data then over-riding it
            self.text_html.delete(1.0, 'end')  # clearing the text_html entry
            self.text_html.insert('end', file_path)  # appending file_path to it here
            # self.getPath()

    # function to handle load xml file
    def load_excel_file(self):
        file_path = filedialog.askopenfilename(filetypes=[('XML files', '*.xml')])
        if file_path:
            if not self.hold_excel_file_path.get():
                self.hold_excel_file_path.set(file_path)
            else:
                self.hold_excel_file_path.set(file_path)
            self.text_excel.delete(1.0, 'end')
            self.text_excel.insert('end', file_path)

    # function to handle create zip file
    def load_zip_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("Zip files", "*.zip")])
        if file_path:
            if not self.hold_file_path.get():
                self.hold_file_path.set(file_path)
            else:
                self.hold_file_path.set(file_path)
            self.text_excel.delete(1.0, 'end')
            self.text_excel.insert('end', file_path)

    # function to get the selected file path
    def get_path(self):
        return self.hold_html_file_path.get() + self.hold_excel_file_path.get()  # returning the hold_file_path data

    # execute function to handle execute button functions
    def execute(self):
        progress = 0.0  # declaring a variable to hold value of progress execution
        if len(self.hold_html_file_path.get()) > 0 and len(self.hold_excel_file_path.get()) > 0:  # on clicking execute button it checks if the file if selected or not
            while progress < 100:
                progress += 20  # incrementing progress by 20% each time
                self.progress_var.set(progress)  # setting the progress value in the variable var of progress bar
                self.execute_button.config(text=f"{progress}%")  # Update the button text
                self.window.update_idletasks()
                self.window.after(300)  # Delay for demonstration purposes
                if progress == 100:  # checking if progress is 100% done or not, if done then only showing success msg
                    self.set_execution(True)
                    self.success_msg()  # calling success function
                    # self.text_html.delete(1.0, 'end')  # deleting text inside html text area after execution
                    # self.text_excel.delete(1.0, 'end')  # deleting text inside excel text area after execution
                    # self.progress_var.set(0)  # initially progress bar is set to 0
                    self.execute_button.config(text="100.0%", fg='#000')  # Reset the button text
                    self.hold_html_file_path.set('')  # setting the file path again to zero
                    self.hold_excel_file_path.set('')
        else:
            self.output_failure = tk.Label(self.window, text='Please provide all inputs.', bg='red', anchor=W)
            self.output_failure.place(x=0, y=125, width=650, height=29)

    # function to update the execution_success variable to true
    def set_execution(self, execution_success):
        self.execution_success = execution_success
        # print(self.execution_success)
        # print('here')

    # function to show up when process executed 100%
    def success_msg(self):
        if self.execution_success:  # if execution was 100% then only
            log_report = f'SUCCESS: LOG: Report can be found at {self.get_path()}'
            self.output_log = tk.Label(self.window, text=log_report, bg='green', anchor=W, fg='#000')
            self.output_log.place(x=0, y=125, width=650, height=29)
            self.window.update_idletasks()
            self.window.after(3000)  # adding a delay of 3s so that can user can view the success msg
            # self.reset_msg()  # calling reset_msg() function

    # function to show up when execution fails
    def failure_msg(self):
        self.output_failure = tk.Label(self.window, text='Failed! Watch logs!.', bg='red', anchor=W)
        self.output_failure.place(x=0, y=125, width=650, height=29)
        self.window.update_idletasks()
        self.window.after(3000)  # adding a delay of 3s so that can user can view the success msg
        self.reset_msg()  # calling reset_msg() function

    # function to reset output log to empty
    def reset_msg(self):
        # print('before')
        self.initial_output()
        # print('after')

    # function to close app, handled by exit button
    def exit_app(self):
        self.window.quit()  # calling quit method to handle click and close the window

    # function to run the program
    def run(self):
        self.window.mainloop()


if __name__ == "__main__":
    app = PolySpace()
    app.run()
