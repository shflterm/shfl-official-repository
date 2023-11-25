from pathlib import Path
import shutil

import shfl



def entrypoint(ws, options, bg_mode):
    current_dir = Path(shfl.currentDirectory(ws))

    src = current_dir / options["source"]
    dest = current_dir / options["destination"]
    if not src.exists():
        print("Source path does not exist")
        return "SRC_NOT_EXIST"
    if not dest.is_dir():
        print("Destination path is not a directory")
        return "DEST_NOT_DIR"
    if not dest.exists():
        print("Destination path does not exist")
        return "DEST_NOT_EXIST"

    if src.is_dir():
        shutil.copytree(str(src), str(dest / src.name))
    else:
        shutil.copy(str(src), str(dest / src.name))

    return str(dest / src.name)