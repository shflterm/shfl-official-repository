function entrypoint()
    local from = args[1]
    local to = args[2]
    fs.copy(from, to)
end

function suggest()
    if suggestId == "from" or suggestId == "to" then
        local suggestions = {}
        for _, file in pairs(fs.list(workspace.dir)) do
            table.insert(suggestions, file)
        end
        return suggestions
    end
    return {}
end