from pynput import keyboard
import pyautogui
import time

# Функция для выполнения команды Command + R
def refresh_page():
    pyautogui.hotkey('command', 'r')  # Command + R

# Получение размеров экрана
screen_width, screen_height = pyautogui.size()

# Функция, которая будет вызываться при нажатии на клавишу
def on_key_press(key):
    if key == keyboard.Key.down:  # Нажатие на клавишу 'f'
        refresh_page()  # Обновить страницу
        time.sleep(1)  # Подождать перед выполнением клика
        # Выполнение клика по середине экрана
        click_x = screen_width // 2
        click_y = screen_height // 2
        while True:
            # refresh_page()  # Обновить страницу
            time.sleep(1)  # Подождать перед выполнением клика
            # pyautogui.click(click_x, click_y)
            # for i in range(981 - 30, 981, 20):
            for j in range(170, 800, 20):
                pyautogui.click(981 - 35, j)
            time.sleep(2)  # Подождать перед выполнением клика
            
        print("Clicked!")

# Начать прослушивание нажатий клавиш
with keyboard.Listener(on_press=on_key_press) as listener:
    listener.join()

# Ждать нажатия клавиши для завершения программы
keyboard.wait('esc')
