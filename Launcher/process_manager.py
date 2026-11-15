import os
import signal
import subprocess


class ProcessManager:
    """Centralized backend using Linux grep/pgrep to manage and monitor processes."""
    def __init__(self, processes_config):
        self.processes = processes_config
        self.managed_pids = set()
        self.last_known_state = {name: False for name in processes_config}

    def is_running(self, name):
        """Uses Linux pgrep (grep on process list) to check if a process string is active."""
        grep_str = self.processes[name]["grep_str"]
        try:
            output = subprocess.check_output(["pgrep", "-f", grep_str], text=True).strip()
            pids = [int(pid) for pid in output.splitlines() if pid.isdigit()]
            if pids:
                return True, pids
        except subprocess.CalledProcessError:
            pass
        return False, []

    def start_process(self, name, cwd):
        running, pids = self.is_running(name)
        if running:
            return f"[WARNING] '{name}' is already running (PID: {pids})."

        try:
            cmd = self.processes[name]["cmd"]
            proc = subprocess.Popen(
                cmd, cwd=cwd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True
            )
            self.managed_pids.add(proc.pid)
            self.last_known_state[name] = True
            return f"[INFO] Started '{name}' internally (PID: {proc.pid})."
        except Exception as e:
            return f"[ERROR] Failed to start '{name}': {e}"

    def stop_process(self, name):
        running, pids = self.is_running(name)
        if not running:
            return f"[WARNING] '{name}' is already stopped."

        try:
            for pid in pids:
                os.kill(pid, signal.SIGTERM)
                self.managed_pids.discard(pid)
            self.last_known_state[name] = False
            return f"[INFO] Stopped '{name}' (PID: {', '.join(map(str, pids))})."
        except ProcessLookupError:
            self.last_known_state[name] = False
            return f"[WARNING] '{name}' is already stopped."
        except PermissionError:
            return f"[ERROR] Permission denied stopping '{name}' (PID: {pids})."
