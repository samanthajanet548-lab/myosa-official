import serial
import tkinter as tk

class PostureApp:
    def __init__(self):
        # Create the hidden root window
        self.root = tk.Tk()
        self.root.withdraw()  # start hidden
        self.overlay = None

        # Serial Setup
        try:
            self.ser = serial.Serial('COM3', 115200, timeout=0.1)  # adjust COM port if needed
            self.ser.write(b'C\n')  # auto-calibration
        except Exception as e:
            print(f"Error opening serial port: {e}")
            exit()

        # Start checking loop
        self.check_serial()
        self.root.mainloop()

    def show_overlay(self):
        if not self.overlay:
            self.overlay = tk.Toplevel(self.root)
            self.overlay.attributes("-fullscreen", True)
            self.overlay.attributes("-topmost", True)
            self.overlay.configure(bg='black')
            self.overlay.config(cursor="none")
            # Emergency escape key
            self.overlay.bind('<Escape>', lambda e: self.root.destroy())

    def hide_overlay(self):
        if self.overlay:
            self.overlay.destroy()
            self.overlay = None

    def check_serial(self):
        try:
            if self.ser.in_waiting:
                line = self.ser.readline().decode('utf-8').strip()
                if line == "BAD":
                    print("Posture BAD — screen blocked with overlay")
                    self.show_overlay()
                elif line == "GOOD":
                    print("Posture GOOD — monitor stays ON")
                    self.hide_overlay()
        except Exception as e:
            print(f"Serial error: {e}")

        # Schedule next check in 100ms
        self.root.after(100, self.check_serial)

if __name__ == "__main__":
    PostureApp()
