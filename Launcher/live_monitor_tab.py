from tkinter import ttk


class LiveMonitorTab(ttk.Frame):
    """Tab 3: Real-time state monitor using grep strings to detect internal/external changes."""
    def __init__(self, parent, process_manager, log_callback):
        super().__init__(parent, padding=20)
        self.pm = process_manager
        self.log_callback = log_callback
        self.status_labels = {}
        self.pid_labels = {}
        self._build_ui()
        self.poll_processes()

    def _build_ui(self):
        ttk.Label(self, text="Live Process Monitor (via Linux grep)", font=("Helvetica", 11, "bold")).pack(anchor="w", pady=(0, 15))

        grid_frame = ttk.Frame(self)
        grid_frame.pack(fill="x")

        ttk.Label(grid_frame, text="Process Name", font=("Helvetica", 10, "bold"), width=24).grid(row=0, column=0, sticky="w", pady=5)
        ttk.Label(grid_frame, text="Grep String", font=("Helvetica", 10, "bold"), width=22).grid(row=0, column=1, sticky="w", pady=5)
        ttk.Label(grid_frame, text="State", font=("Helvetica", 10, "bold"), width=14).grid(row=0, column=2, sticky="w", pady=5)
        ttk.Label(grid_frame, text="PID", font=("Helvetica", 10, "bold"), width=10).grid(row=0, column=3, sticky="w", pady=5)

        ttk.Separator(grid_frame, orient="horizontal").grid(row=1, column=0, columnspan=4, sticky="ew", pady=5)

        for idx, (name, cfg) in enumerate(self.pm.processes.items(), start=2):
            ttk.Label(grid_frame, text=name).grid(row=idx, column=0, sticky="w", pady=6)
            ttk.Label(grid_frame, text=cfg["grep_str"], font=("Courier", 9), foreground="#555555").grid(row=idx, column=1, sticky="w", pady=6)

            status_lbl = ttk.Label(grid_frame, text="Checking...", font=("Helvetica", 10, "bold"))
            status_lbl.grid(row=idx, column=2, sticky="w", pady=6)
            self.status_labels[name] = status_lbl

            pid_lbl = ttk.Label(grid_frame, text="-")
            pid_lbl.grid(row=idx, column=3, sticky="w", pady=6)
            self.pid_labels[name] = pid_lbl

    def poll_processes(self):
        for name in self.pm.processes:
            running, pids = self.pm.is_running(name)
            was_running = self.pm.last_known_state[name]

            if running:
                self.status_labels[name].config(text="● RUNNING", foreground="#1e8e3e")
                self.pid_labels[name].config(text=", ".join(map(str, pids)))

                if not was_running and not any(pid in self.pm.managed_pids for pid in pids):
                    self.log_callback(f"[EXTERNAL] '{name}' was started externally (PID: {pids}).")
            else:
                self.status_labels[name].config(text="■ STOPPED", foreground="#d93025")
                self.pid_labels[name].config(text="-")

                if was_running:
                    self.log_callback(f"[INFO] '{name}' was stopped externally.")

            self.pm.last_known_state[name] = running

        self.after(1500, self.poll_processes)
