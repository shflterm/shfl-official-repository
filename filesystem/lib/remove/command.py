from pathlib import Path
import shutil
import os

import shfl



def entrypoint(ws, options, bg_mode):
    current_dir = Path(shfl.currentDirectory(ws))

    path = current_dir / options["path"]
    if not path.exists():
        print("Path does not exist")
        return "PATH_NOT_EXIST"

    try:
        if path.is_dir():
            shutil.rmtree(str(path))
        else:
            os.remove(str(path))
        print(f"Directory '{path}' deleted successfully.")
        return str(path)
    except FileNotFoundError:
        print(f"Directory '{path}' not found.")
        return "PATH_NOT_EXIST"
    except Exception as e:
        print(f"An error occurred: {e}")
        return "ERROR"
