from pathlib import Path
import os

import shfl



def entrypoint(ws, options, bg_mode):
    current_dir = Path(shfl.currentDirectory(ws))

    path = current_dir / options["name"]

    try:
        os.mkdir(path)
        print(f"Directory '{path}' created successfully.")
        return str(path)
    except FileExistsError:
        print(f"Directory '{path}' already exists.")
        return "PATH_EXISTS"
    except Exception as e:
        print(f"An error occurred: {e}")
        return "ERROR"
