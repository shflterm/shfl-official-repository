from pathlib import Path


def entrypoint(ws, options, bg_mode):
    dir = Path(ws.dir)
    print(dir.absolute())
    return dir.absolute()
