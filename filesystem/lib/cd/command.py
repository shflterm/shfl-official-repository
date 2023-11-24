import sys
from pathlib import Path

import shfl


def entrypoint(ws, options, bg_mode):
    to = Path(options["path"])
    currentDir = Path(shfl.currentDirectory(ws))
    if to == "..":
        shfl.moveDirectory(ws, currentDir.parent)
    else:
        if to.exists():
            shfl.moveDirectory(ws, str(to))
        else:
            print("Directory does not exist.", file=sys.stderr)

    return str(currentDir.absolute())
