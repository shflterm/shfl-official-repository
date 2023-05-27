function entrypoint()
    local to = args[1]
    if to == nil then
        to = "."
    end
    if to == ".." then
        workspace.dir = fs.parentDir(workspace.dir)
    else
        if fs.exists(workspace.dir .. "/" .. to) then
            workspace.dir = workspace.dir .. "/" .. to
        else
            error("Directory does not exist.")
        end
    end
end

function suggest()
    if suggestId == "path" then
        local suggestions = { ".." }
        for _, file in pairs(fs.list(workspace.dir)) do
            if fs.isDir(workspace.dir .. "/" .. file) then
                table.insert(suggestions, file)
            end
        end
        return suggestions
    end
    return {}
end
