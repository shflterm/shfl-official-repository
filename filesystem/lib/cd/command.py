import sys
from pathlib import Path

import shfl


def entrypoint(ws, options, bg_mode):
    currentDir = Path(shfl.currentDirectory(ws))
    if options["path"] == "..":
        shfl.moveDirectory(ws, str(currentDir.parent))
    else:
        to = currentDir / options["path"]
        if to.exists():
            shfl.moveDirectory(ws, str(to))
        else:
            print("Directory does not exist.", file=sys.stderr)

    return str(currentDir.absolute())
