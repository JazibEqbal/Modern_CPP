import tkinter as tk
from tkinter import filedialog, ttk

class HTMLFileLoaderApp:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("PolySpaceReportGeneration")
        self.window.geometry('650x150+200+200')
        self.window.resizable(width=False, height=False)
        self.file_path_var = tk.StringVar()
        self.progress_var = tk.DoubleVar()
        self.create_widgets()

    def create_widgets(self):
        image = tk.Button(self.window, text='Image')
        image.place(x=0, y=0, width=80, height=70)

        zip_button = tk.Button(self.window, text='CREATE ZIP', bg='#000', fg='#fff', activebackground='#000',
                               activeforeground='#fff')
        zip_button.place(x=0, y=70, width=80, height=30)

        htmlButton = tk.Button(self.window, text='Load Html File', bg='#FF34B3', activebackground='#FF34B3', fg='#fff')
        htmlButton.place(x=81, y=0, width=90, height=35)

        excelButton = tk.Button(self.window, text='Load Excel File', bg='#FF34B3', activebackground='#FF34B3', fg='#fff')
        excelButton.place(x=81, y=35, width=90, height=35)

        exitButton = tk.Button(self.window, text='Exit', bg='#808080', fg='#fff', activebackground='#808080')
        exitButton.place(x=81, y=71, width=90, height=29)

        self.load_button = tk.Button(self.window, text="Load HTML File", command=self.load_html_file)
        self.load_button.pack(pady=10)

        self.execute_button = tk.Button(self.window, text="Execute", command=self.execute)
        self.execute_button.pack(pady=10)

        self.file_path_text = tk.Text(self.window, height=1, width=50)
        self.file_path_text.pack(pady=5)

        self.progress_bar = ttk.Progressbar(self.window, variable=self.progress_var, maximum=100, mode="determinate")
        self.progress_bar.pack(pady=5, fill='x')

    def load_html_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("HTML files", "*.html")])  # "*.html"), ("XML files", "*.xml")])
        if file_path:
            self.file_path_var.set(file_path)
            self.file_path_text.delete(1.0, 'end')
            self.file_path_text.insert('end', file_path)
            # with open(file_path, "r") as file:
            #     content = file.read()
                # You can process or display the content as needed

    def execute(self):
        # Simulate execution progress for demonstration purposes
        progress = 0
        while progress < 100:
            progress += 10
            self.progress_var.set(progress)
            self.execute_button.config(text=f"Execute {progress}%")  # Update the button text
            self.window.update_idletasks()  # Refresh the GUI
            self.window.after(500)  # Delay for demonstration purposes

        # Execution is finished; reset text area and progress bar
        self.file_path_text.delete(1.0, 'end')
        self.progress_var.set(0)
        self.execute_button.config(text="Execute")  # Reset the button text

    def run(self):
        self.window.mainloop()

if __name__ == "__main__":
    app = HTMLFileLoaderApp()
    app.run()
