import os
import tkinter as tk
from tkinter import ttk, messagebox


class DirectoryTab(ttk.Frame):
    """Tab 1: Change and display the current working directory."""
    def __init__(self, parent):
        super().__init__(parent, padding=20)
        self._build_ui()
        # self.build_contents_frame()

    def _build_ui(self):
        ttk.Label(self, text="Current Working Directory:", font=("Helvetica", 11, "bold")).pack(anchor="w")

        self.cwd_var = tk.StringVar(value=os.getcwd())
        ttk.Label(self, textvariable=self.cwd_var, foreground="#0052cc", font=("Courier", 10)).pack(anchor="w", pady=(5, 20))

        ttk.Label(self, text="Enter Linux Directory Path (e.g., /tmp, ~/projects):").pack(anchor="w")

        input_frame = ttk.Frame(self)
        input_frame.pack(fill="x", pady=5)

        self.path_entry = ttk.Entry(input_frame)
        self.path_entry.pack(side="left", fill="x", expand=True, padx=(0, 10))
        self.path_entry.bind("<Return>", lambda e: self.change_directory())

        ttk.Button(input_frame, text="Change Directory", command=self.change_directory).pack(side="right")

        # Add a secondary LabelFrame for displaying directory contents 
        # TODO: This needs to be updated to show the contents of the new directory after a change.
        self.contents_frame = ttk.Labelframe(self, text="Directory Contents", padding=10)
        self.contents_frame.pack(fill="x", pady=(20, 0))
        self.build_contents_frame()

    def build_contents_frame(self):
        # Clear previous contents
        for widget in self.contents_frame.winfo_children():
            widget.destroy()

        try:
            contents = os.listdir(os.getcwd())
            if not contents:
                ttk.Label(self.contents_frame, text="Directory is empty.", foreground="#555555").pack(anchor="w")
            else:
                for item in contents:
                    ttk.Label(self.contents_frame, text=item, font=("Courier", 9)).pack(anchor="w")
        except Exception as e:
            ttk.Label(self.contents_frame, text=f"Error reading directory: {e}", foreground="red").pack(anchor="w") 
            
    def change_directory(self):
        target_dir = os.path.expanduser(self.path_entry.get().strip())
        if not target_dir:
            return
        try:
            os.chdir(target_dir)
            self.cwd_var.set(os.getcwd())
            self.path_entry.delete(0, tk.END)
            successful_dir_label = ttk.Label(self, foreground="green", text="Directory changes applied successfully!")
            successful_dir_label.pack(anchor="w", pady=(20, 5))

            successful_dir_label.after(1000, successful_dir_label.destroy) # Only show success message for 1 second
            self.build_contents_frame()
        except Exception as e:
            messagebox.showerror("Directory Error", str(e))
