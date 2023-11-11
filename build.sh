cd $1
zip $1.app -r *
mv "$1.app" ../$1.app
cd ..