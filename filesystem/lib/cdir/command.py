from pathlib import Path

import shfl


def entrypoint(ws, options, bg_mode):
    dir = Path(shfl.currentDirectory(ws))
    print(dir.absolute())
    return str(dir.absolute())
