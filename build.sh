for FILE in *; do 
    if [ -d "$FILE" ]; then
        cd $FILE
        zip $FILE.sapp -r *
        mv "$FILE.sapp" ../$FILE.sapp
        cd ..
    fi
done