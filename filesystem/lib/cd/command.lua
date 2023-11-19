function entrypoint()
    local to = path
    if to == nil then
        to = "."
    end

    if to == ".." then
        workspace.dir = fs.parentDir(workspace.dir)
    else
        if fs.exists(to) then
            workspace.dir = to
        else
            error("Directory does not exist.")
        end
    end

    return fs.absolute(workspace.dir)
end