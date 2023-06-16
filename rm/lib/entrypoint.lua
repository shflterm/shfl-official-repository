function entrypoint()
    local path = args[1]
    fs.remove(path);
    print(path .. " has been deleted.");
end

function suggest()
    if suggestId == "path" then
        local suggestions = {}
        for _, file in pairs(fs.list(workspace.dir)) do
            if fs.isDir(workspace.dir .. "/" .. file) then
                table.insert(suggestions, file)
            end
        end
        return suggestions
    end
    return {}
end
