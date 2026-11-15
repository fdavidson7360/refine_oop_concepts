import webbrowser
import tkinter as tk
from tkinter import ttk


class EndpointLauncherTab(ttk.Frame):
    """Tab 4: Launch preset or custom localhost web endpoints."""
    def __init__(self, parent, presets):
        super().__init__(parent, padding=20)
        self.presets = presets
        self._build_ui()

    def _build_ui(self):
        preset_frame = ttk.LabelFrame(self, text="Preset Localhost Endpoints", padding=15)
        preset_frame.pack(fill="x", pady=(0, 20))

        for idx, (label, url) in enumerate(self.presets.items()):
            ttk.Label(preset_frame, text=label, font=("Helvetica", 10, "bold"), width=24).grid(row=idx, column=0, sticky="w", pady=5)
            ttk.Label(preset_frame, text=url, font=("Courier", 9), foreground="#0052cc", width=30).grid(row=idx, column=1, sticky="w", pady=5)
            ttk.Button(preset_frame, text="Launch", command=lambda u=url: self.open_url(u)).grid(row=idx, column=2, padx=10, pady=5)

        custom_frame = ttk.LabelFrame(self, text="Custom Localhost Endpoint", padding=15)
        custom_frame.pack(fill="x")

        self.custom_url = tk.StringVar(value="http://localhost:9000")
        ttk.Entry(custom_frame, textvariable=self.custom_url, width=40).pack(side="left", padx=(0, 10))
        ttk.Button(custom_frame, text="Launch Custom URL", command=lambda: self.open_url(self.custom_url.get())).pack(side="left")

    def open_url(self, url):
        url = url.strip()
        if not url.startswith(("http://", "https://")):
            url = "http://" + url
        webbrowser.open(url)
