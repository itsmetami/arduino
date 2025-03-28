import serial
import time
import keyboard
keys_pressed = {"w": False, "a": False, "s": False, "d": False}


def key_event(event):
    """Handles both key presses and releases."""
    if event.name in keys_pressed:
        keys_pressed[event.name] = event.event_type == "down"  # True if pressed, False if released


# Hook both press and release events
keyboard.hook(key_event)

print("Hold W, A, S, or D to print (Press ESC to exit)...")








# # Adjust port name based on your system

arduino = serial.Serial('COM4', 9600, timeout=1)  # Windows (check in Device Manager)
# arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)  # Linux/Mac


while True:
    signal = ""
    printed = False  # Flag to check if we printed something
    for key, pressed in keys_pressed.items():
        if pressed:
            print(key, end="", flush=True)
            printed = True  # Something was printed
            signal = key

    if printed:
        print("")  # Move to a new line
    time.sleep(0.1)  # Adjust speed
    if keyboard.is_pressed("esc"):  # Stop if ESC is pressed
        print("\nExiting...")
        break


    arduino.write((signal + '\n').encode())  # Send data with newline
    response = arduino.readline().decode().strip()  # Read response
    print("Arduino says:", response)
