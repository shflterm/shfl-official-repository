from pathlib import Path
import sys

def entrypoint(ws, options, bg_mode):
    to = Path(options["path"])
    if to == "..":
        ws.dir = to.parent.absolute()
    else:
        if to.exists():
            ws.dir = to
        else:
            print("Directory does not exist.", file=sys.stderr)

    return ws.dir.absolute()
