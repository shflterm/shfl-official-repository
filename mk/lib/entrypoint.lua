function entrypoint()
    local type = args[1]
    if type == "dir" then
        fs.mkDir(args[2])
    elseif type == "file" then
        fs.writeFile(args[2], "")
    end
end

function suggest()
    return {}
end
