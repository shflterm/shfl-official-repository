import os
from pathlib import Path

import shfl

reset_color = "\033[0m"
blue_background = "\033[44m"
black_text = "\033[30m"


def entrypoint(ws, options, bg_mode):
    dir = Path(shfl.currentDirectory(ws))

    entries = os.listdir(dir)
    for entry in entries:
        full_path = os.path.join(dir, entry)
        if os.path.isdir(full_path):
            formatted_name = f"{blue_background}{black_text} {entry} {reset_color}"
        else:
            formatted_name = entry
        print(formatted_name)
    print(reset_color, end="")
    return str(len(entries))
