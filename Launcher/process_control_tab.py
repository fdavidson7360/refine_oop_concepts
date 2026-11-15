import os
import tkinter as tk
from tkinter import ttk, scrolledtext


class ProcessControlTab(ttk.Frame):
    """Tab 2: Individual and batch process controls with filtered state logging."""
    def __init__(self, parent, process_manager):
        super().__init__(parent, padding=20)
        self.pm = process_manager
        self._build_ui()

    def _build_ui(self):
        single_frame = ttk.LabelFrame(self, text="Single Process Control", padding=10)
        single_frame.pack(fill="x", pady=(0, 15))

        keys = list(self.pm.processes.keys())
        self.selected_proc = tk.StringVar(value=keys[0] if keys else "")
        self.dropdown = ttk.Combobox(
            single_frame, textvariable=self.selected_proc,
            values=keys, state="readonly", width=30
        )
        self.dropdown.pack(side="left", padx=(0, 10))

        ttk.Button(single_frame, text="Start", command=self.start_selected).pack(side="left", padx=5)
        ttk.Button(single_frame, text="Stop", command=self.stop_selected).pack(side="left", padx=5)

        batch_frame = ttk.LabelFrame(self, text="Batch Control", padding=10)
        batch_frame.pack(fill="x", pady=(0, 15))

        ttk.Button(batch_frame, text="Run All", command=self.run_all).pack(side="left", padx=(0, 10))
        ttk.Button(batch_frame, text="Stop All", command=self.stop_all).pack(side="left")

        log_frame = ttk.LabelFrame(self, text="Process State Logs", padding=10)
        log_frame.pack(fill="both", expand=True)

        self.log_area = scrolledtext.ScrolledText(log_frame, height=12, state="disabled", font=("Courier", 9))
        self.log_area.pack(fill="both", expand=True)

    def append_log(self, message):
        if not message:
            return
        self.log_area.configure(state="normal")
        self.log_area.insert(tk.END, f"{message}\n")
        self.log_area.see(tk.END)
        self.log_area.configure(state="disabled")

    def start_selected(self):
        name = self.selected_proc.get()
        self.append_log(self.pm.start_process(name, os.getcwd()))

    def stop_selected(self):
        name = self.selected_proc.get()
        self.append_log(self.pm.stop_process(name))

    def run_all(self):
        for name in self.pm.processes:
            self.append_log(self.pm.start_process(name, os.getcwd()))

    def stop_all(self):
        for name in self.pm.processes:
            self.append_log(self.pm.stop_process(name))
