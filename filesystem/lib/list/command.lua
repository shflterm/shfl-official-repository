function entrypoint()
    for _, file in pairs(fs.list(workspace.dir)) do
        if fs.isDir(file) then
            info("[44m"..file.."/[0m")
        else
            info(file)
        end
    end

    return "TODO"
end