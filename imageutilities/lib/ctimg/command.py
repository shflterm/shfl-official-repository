from pathlib import Path
from PIL import Image

import shfl


def entrypoint(ws, options, bg_mode):
    current_dir = Path(shfl.currentDirectory(ws))

    imgName = options["img"]
    imgFormat = options["format"]

    image = Image.open(current_dir / imgName)

    newImgPath = current_dir / imgName.split(".")[0] + "." + imgFormat
    image.save(newImgPath, imgFormat)

    return str(newImgPath)
