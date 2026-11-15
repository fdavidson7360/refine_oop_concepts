import tkinter as tk
from tkinter import ttk

from process_manager import ProcessManager
from directory_tab import DirectoryTab
from process_control_tab import ProcessControlTab
from live_monitor_tab import LiveMonitorTab
from endpoint_launcher_tab import EndpointLauncherTab


class MainApplication(tk.Tk):
    """Main Window orchestrating the Notebook tabs and shared backend."""
    def __init__(self):
        super().__init__()
        self.title("Linux Process & Endpoint Manager")
        self.geometry("720x500")

        processes_config = {
            "Python HTTP Server": {
                "cmd": ["python3", "-m", "http.server", "8000"],
                "grep_str": "http.server 8000"
            },
            "Background Sleep Worker": {
                "cmd": ["sleep", "300"],
                "grep_str": "sleep 300"
            },
            "Ping Localhost": {
                "cmd": ["ping", "127.0.0.1"],
                "grep_str": "ping 127.0.0.1"
            }
        }

        endpoint_presets = {
            "Python HTTP Server": "http://localhost:8000",
            "Frontend Dev Server": "http://localhost:3000",
            "Backend REST API": "http://localhost:5000",
            "Admin Dashboard": "http://localhost:8080",
            "Metrics / Monitoring": "http://localhost:9090"
        }

        self.process_manager = ProcessManager(processes_config)
        self._build_notebook(endpoint_presets)

    def _build_notebook(self, endpoint_presets):
        notebook = ttk.Notebook(self)
        notebook.pack(fill="both", expand=True, padx=10, pady=10)

        self.tab1 = DirectoryTab(notebook)
        self.tab2 = ProcessControlTab(notebook, self.process_manager)
        self.tab3 = LiveMonitorTab(notebook, self.process_manager, self.tab2.append_log)
        self.tab4 = EndpointLauncherTab(notebook, endpoint_presets)

        notebook.add(self.tab1, text="1. Directory")
        notebook.add(self.tab2, text="2. Process Control")
        notebook.add(self.tab3, text="3. Live Monitor")
        notebook.add(self.tab4, text="4. Endpoint Launcher")


if __name__ == "__main__":
    app = MainApplication()
    app.mainloop()
