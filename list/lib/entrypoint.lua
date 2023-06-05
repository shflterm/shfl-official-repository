function entrypoint()
    for _, file in pairs(fs.list(workspace.dir)) do
        if fs.isDir(file) then
            print("[44m"..file.."/")
        else
            print(file)
        end
    end
end