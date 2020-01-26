#! /bin/python3
# -*- coding: Utf-8 -*
##
## EPITECH PROJECT, 2019
## CPE_matchstick_2019
## File description:
## matchstick.py
##

import sys
import random
import time
import tkinter as tk
from tkinter.messagebox import showinfo

class AI():
    def __init__(self):
        self.__lvl = "Easy"
        self.strategy = {
            "Easy": self.full_random_strategy,
            "Hell": self.nim_sum_strategy
        }

    @property
    def difficulties(self):
        return list(self.strategy.keys())

    @property
    def level(self):
        return self.__lvl

    @level.setter
    def level(self, lvl):
        if lvl not in self.difficulties:
            return
        self.__lvl = lvl

    def play(self, gameboard):
        nb_sticks = gameboard.nb_sticks.copy()
        nb_lines_with_sticks = sum(1 for sticks in nb_sticks if sticks > 0)

        if nb_lines_with_sticks == 1:
            return self.play_single_line(nb_sticks)
        line, matches = self.strategy[self.level](nb_sticks)
        if matches <= 0:
            line, matches = self.full_random_strategy(nb_sticks)
        return line, matches

    def play_single_line(self, nb_sticks):
        line = 0
        for i, sticks in enumerate(nb_sticks):
            if sticks > 0:
                line = i
                break
        matches = nb_sticks[line] - 1
        if matches <= 0:
            matches = 1
        return line, matches

    def random_line(self, nb_sticks):
        lines_with_sticks = list()
        for line, sticks in enumerate(nb_sticks):
            if sticks > 0:
                lines_with_sticks.append(line)
        return random.choice(lines_with_sticks)

    def random_matches(self, nb_sticks_in_line):
        return random.randrange(nb_sticks_in_line) + 1

    def full_random_strategy(self, nb_sticks):
        line = self.random_line(nb_sticks)
        return line, self.random_matches(nb_sticks[line])

    def nim_sum_strategy(self, nb_sticks):
        nb_sticks_copy = nb_sticks.copy()
        lines_greather_than_one = 0
        lines_equal_to_one = 0
        line = 1
        matches = 1
        for i in range(1, len(nb_sticks)):
            lines_greather_than_one += 1 if nb_sticks[i] > 1 else 0
            lines_equal_to_one += 1 if nb_sticks[i] == 1 else 0
            line = i if nb_sticks[i] > 1 else line
        if lines_greather_than_one <= 1:
            if lines_greather_than_one == 0:
                line = self.random_line(nb_sticks)
            else:
                matches = nb_sticks[line]
                if lines_equal_to_one % 2 == 0:
                    matches -= 1
                return line, matches
        balance = self.get_balance(nb_sticks)
        if balance == 0:
            return -1, -1
        largest_u = self.find_largest_unbalanced(balance)
        line = self.next_matchstick_line(nb_sticks, 0, largest_u)
        if line < 0:
            return -1, -1
        matches = self.get_default_matches(nb_sticks[line], largest_u)
        nb_sticks_copy[line] -= matches
        while self.get_balance(nb_sticks_copy) != 0:
            nb_sticks_copy[line] -= 1
            matches += 1
            if nb_sticks_copy[line] == 0 and self.get_balance(nb_sticks_copy) != 0:
                nb_sticks_copy[line] = nb_sticks[line]
                line = self.next_matchstick_line(nb_sticks, line, largest_u)
                if line < 0:
                    return -1, -1
                matches = self.get_default_matches(nb_sticks[line], largest_u)
                nb_sticks_copy[line] -= matches
        return line, matches

    def get_balance(self, nb_sticks):
        balance = 0
        for sticks in nb_sticks:
            balance = balance ^ sticks
        return balance

    def find_largest_unbalanced(self, balance):
        mask = 1
        largest = 1
        while mask <= balance:
            if (balance & mask) != 0:
                largest = mask
            mask = mask << 1
        return largest

    def next_matchstick_line(self, nb_sticks, line, largest_u):
        line += 1
        try:
            while (nb_sticks[line] & largest_u) == 0:
                line += 1
        except IndexError:
            line = -1
        return line

    def get_default_matches(self, number_of_sticks, largest_u):
        mask = 1
        matches = 0
        while (largest_u & mask) == 0:
            if (number_of_sticks & mask) != 0:
                matches += mask
            mask = mask << 1
        return matches

class Window(tk.Tk):
    def __init__(self):
        width = 1280
        height = 720
        tk.Tk.__init__(self)
        self.width = width
        self.height = height
        self.title("Matchstick")
        self.geometry(f"{width}x{height}+0+0")
        self.resizable(False, False)
        #Game Frame
        self.game_frame = tk.Frame(self, bg="white", bd=6, relief="ridge", width=width//2, height=height)
        self.game_frame.pack(side="left")
        self.game_frame.grid_propagate(0)
        for i in range(3):
            self.game_frame.grid_rowconfigure(i, weight=1)
        for i in range(2):
            self.game_frame.grid_columnconfigure(i, weight=1)
        #Gameboard
        self.gameboard = tk.Canvas(self, bg="white", bd=6, relief="ridge", width=width//2, height=height)
        self.gameboard.pack(side="right")
        self.gameboard.grid_propagate(0)
        self.default_nb_sticks = list()
        self.nb_sticks = list()
        self.sticks = list()
        #Opponent
        self.opponent_frame = tk.Frame(self.game_frame, bd=6, relief="ridge", width=width//4, height=height//4)
        self.opponent_frame.pack_propagate(0)
        self.opponent_var = tk.StringVar(value="AI")
        self.opponent = "AI"
        tk.Label(self.opponent_frame, text="Opponent", font=("", 20, "bold")).pack()
        tk.Radiobutton(self.opponent_frame, variable=self.opponent_var, value="AI", text="AI", font=("", 20), command=self.change_opponent).pack(side="top")
        tk.Radiobutton(self.opponent_frame, variable=self.opponent_var, value="Player", text="2nd player", font=("", 20), command=self.change_opponent).pack(side="top")
        self.active_player = 1
        self.turn = {
            "AI": {1: "It's your turn", 2: "It's AI's turn..."},
            "Player": {1: "It's player 1's\nturn", 2: "It's player 2's\nturn"}
        }
        #AI difficulty
        self.ai = AI()
        self.ai_frame = tk.Frame(self.game_frame, bd=6, relief="ridge", width=width//4, height=height//4)
        self.ai_frame.pack_propagate(0)
        self.ai_difficulty = tk.StringVar(value=self.ai.difficulties[0])
        tk.Label(self.ai_frame, text="AI Difficulty", font=("", 20, "bold")).pack()
        self.difficulties = list()
        for lvl in self.ai.difficulties:
            b = tk.Radiobutton(self.ai_frame, variable=self.ai_difficulty, value=lvl, text=lvl, font=("", 18), command=self.set_level)
            b.pack(side="top")
            self.difficulties.append(b)
        #Matchstick lines
        self.lines_frame = tk.Frame(self.game_frame, bd=6, relief="ridge", width=width//4, height=height//1.7)
        self.lines_frame.pack_propagate(0)
        tk.Label(self.lines_frame, text="Matchstick lines", font=("", 20, "bold")).pack()
        self.nb_lines = tk.Scale(self.lines_frame, from_=4, to=10, resolution=1, tickinterval=1, command=self.reset_gameplay, length=height//1.7 - 50)
        self.nb_lines.pack()
        #Line and matches choose
        self.choose_frame = tk.Frame(self.game_frame, bd=6, relief="ridge", width=width//4, height=height//1.7)
        self.choose_frame.pack_propagate(0)
        tk.Label(self.choose_frame, text="Player input", font=("", 20, "bold")).pack()
        scale_len = 300
        self.line = tk.Scale(self.choose_frame, from_=1, to=1, resolution=1, tickinterval=1, orient="horizontal", length=scale_len, command=self.set_max_matches)
        self.match = tk.Scale(self.choose_frame, from_=1, to=1, resolution=1, tickinterval=1, orient="horizontal", length=scale_len)
        self.validation = tk.Button(self.choose_frame, text="Validate", font=("", 18), command=self.play)
        self.turn_display = tk.StringVar(value=self.turn[self.opponent][self.active_player])
        tk.Label(self.choose_frame, text="Line", font=("", 20, "bold")).pack()
        self.line.pack()
        tk.Label(self.choose_frame, text="Matches", font=("", 20, "bold")).pack()
        self.match.pack()
        tk.Label(self.choose_frame, text="Push to play", font=("", 20, "bold")).pack()
        self.validation.pack()
        tk.Label(self.choose_frame, textvariable=self.turn_display, font=("", 25, "bold")).pack(side="bottom")
        #Initialisation
        self.init_game_frame()
        self.init_gameboard(self.nb_lines.get())

    def init_game_frame(self):
        tk.Label(self.game_frame, bg="white", text="Matchstick", font=("", 60)).grid(row=0, column=0, columnspan=2)
        self.opponent_frame.grid(row=1, column=0, sticky="e")
        self.ai_frame.grid(row=1, column=1, sticky="w")
        self.lines_frame.grid(row=2, column=0)
        self.choose_frame.grid(row=2, column=1)

    def init_gameboard(self, nb_lines):
        nb_lines = int(nb_lines)
        for i in range(nb_lines):
            self.default_nb_sticks.append((2 * i) + 1)
        self.line["to"] = nb_lines
        self.match["to"] = 1
        self.match.set(1)
        w = (self.width / 2) // self.default_nb_sticks[-1]
        h = self.height // len(self.default_nb_sticks)
        stick_width = 7
        stick_height = int(h - (200 / len(self.default_nb_sticks)))
        x = self.width // 4
        y = h // 2
        self.nb_sticks.append(0)
        for i, nb_matches in enumerate(self.default_nb_sticks):
            y0 = (y + (h * i)) - (stick_height // 2)
            y1 = (y + (h * i)) + (stick_height // 2)
            self.sticks.append(list())
            self.sticks[i].append(self.gameboard.create_line(x, y0, x, y1, width=stick_width))
            for j in range(nb_matches // 2):
                x0 = x - (w * (j + 1))
                x1 = x + (w * (j + 1))
                self.sticks[i].insert(0, self.gameboard.create_line(x0, y0, x0, y1, width=stick_width))
                self.sticks[i].append(self.gameboard.create_line(x1, y0, x1, y1, width=stick_width))
            self.nb_sticks.append(nb_matches)

    def reset_gameplay(self, nb_lines=-1):
        nb_lines = int(nb_lines)
        if nb_lines < 0:
            nb_lines = int(self.nb_lines.get())
        self.default_nb_sticks.clear()
        for line in self.sticks:
            for stick in line:
                self.gameboard.delete(stick)
        self.sticks.clear()
        self.nb_sticks.clear()
        self.init_gameboard(nb_lines)
        self.validation["state"] = "normal"

    def set_level(self):
        if self.ai_difficulty.get() != self.ai.level:
            self.ai.level = self.ai_difficulty.get()
            self.reset_gameplay()

    def change_opponent(self, forced=False):
        opponent = self.opponent_var.get()
        if opponent == self.opponent and not forced:
            return
        for rb in self.difficulties:
            rb.config(state="normal" if opponent == "AI" else "disabled")
        self.reset_gameplay()
        if opponent == "AI":
            self.active_player = 1
        else:
            self.active_player = random.randrange(2) + 1
        self.turn_display.set(self.turn[opponent][self.active_player])
        self.opponent = opponent

    def set_max_matches(self, line, check=True):
        line = int(line)
        self.match.set(1)
        if self.nb_sticks[line] == 0:
            self.match["to"] = 1
            self.match["state"] = "disabled"
        else:
            self.match["to"] = self.nb_sticks[line]
            self.match["state"] = "normal"
        if check is True:
            self.check_validation(line)

    def check_validation(self, line):
        self.validation["state"] = "normal" if self.nb_sticks[int(line)] > 0 else "disabled"

    def play(self):
        line = int(self.line.get())
        matches = int(self.match.get())
        self.remove_matches(line, matches)
        self.line.set(1)
        self.active_player = 2 if self.active_player == 1 else 1
        self.turn_display.set(self.turn[self.opponent][self.active_player])
        self.validation["state"] = "disabled"
        if self.check_game_status() is False and self.opponent == "AI":
            self.update()
            self.update()
            time.sleep(1)
            line, matches = self.ai.play(self)
            self.remove_matches(line, matches)
            self.match.set(1)
            self.active_player = 1
            if self.check_game_status() is False:
                self.turn_display.set(self.turn["AI"][1])
        self.check_validation(1)

    def remove_matches(self, line, matches):
        try:
            for _ in range(matches):
                self.gameboard.delete(self.sticks[line - 1][-1])
                del self.sticks[line - 1][-1]
                self.nb_sticks[line] -= 1
        except IndexError:
            pass
        else:
            self.set_max_matches(line, check=False)

    def check_game_status(self):
        player_who_won = self.active_player
        ai_messages = {1: "I lost... snif... but I'll get you next time!!", 2: "You lost, too bad..."}
        for sticks in self.nb_sticks:
            if sticks > 0:
                return False
        if self.opponent == "AI":
            message = "{player} won\n\nMessage from AI:\n".format(player="You" if player_who_won == 1 else "AI") + ai_messages[player_who_won]
        else:
            message = "Player {0} won".format(player_who_won)
        showinfo("We have a winner !!!", message)
        self.change_opponent(True)
        return True

if __name__ == "__main__":
    Window().mainloop()
    sys.exit(0)